#include <iostream>
#include <limits>
#include <cctype>
#include "../header/game.h"
using namespace std;

Game::Game(string name){
    dealer = new Dealer(); 
    player = new RealPlayer(name);
}

Game::~Game() {
    delete dealer;
    delete player;
}

int Game::intInputCheck() {
    string input;
    int amount;
    while (true) {
        cin >> input;
        bool isValid = true;
        for (char ch : input) {
            if (!isdigit(ch)) {
                isValid = false;
                break;
            }
        }
        if (isValid) {
            amount = stoi(input);
            break;
        }
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input, try again: ";
    }
    return amount;
}

char Game::charInputCheck() {
    string choice;
    while (true) {
        cin >> choice;
        if (choice.length() == 1 && isalpha(choice[0])) {
            return choice[0]; 
        } else {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input, please enter exactly one letter: ";
        }
    }
}

void Game::handleBet(){
    cout << "Your current balance is $" << player->getBalance() << endl;
    cout << "How much do you want to bet?: ";
    int amount = intInputCheck();
    cout << endl;

    while(!player->placeBet(amount)){
        if (amount <= 0) {
            cout << "You cannot bet that amount, enter a new amount: ";
        }
        else {
            cout << "You don't have enough money to play. Please enter a new bet amount: ";
        }
        amount = intInputCheck();
        cout << endl;
    }
    playRound(amount);
}

void Game::playRound(int amount) {
    deck.shuffleDeck();
    for(int i = 0; i < 2; i++){
        player->hit(deck.dealCard());
        dealer->hit(deck.dealCard());
    }

    cout << player->getName() << "'s Hand: ";
    for(const auto& card : player->getHand()){
        cout << card << " | ";
    }
    cout << endl;

    cout << player->getName() << "'s Hand Total: " << player->getHandValue() << endl;
    cout << "Dealer's Hand: " << dealer->getHand().at(0) << endl; 

    if(player->isBlackjack()){
        if(dealer->isBlackjack()){
            determineWinner(amount); // Both player and dealer have blackjack, it's a tie
        }
        playerWon(amount);
        return;
    }

    if (dealer->isBlackjack()) {
        dealerWon();
        return;
    }

    handlePlayerTurn(amount);

}

void Game::handlePlayerTurn(int amount) {
    while((!player->isBusted()) && (player->getStatus())){
        cout << "Do you want to hit, stand, or double down? (h, s, or d): ";
        char choice = charInputCheck();
        cout << endl;
        if(choice == 'd'){
            if(player->doubleDown(amount)){
                amount *= 2;
                player->hit(deck.dealCard());
                player->stand(); // Automatically stand after doubling down
                cout << "You doubled down and drew: " << player->getHand().back() << endl;
            } else {
                cout << "You don't have enough money to double down." << endl; 
            }
        }
        else if(choice == 'h'){
            player->hit(deck.dealCard());
            cout << "You drew: " << player->getHand().back() << endl;
            cout << "Your hand total is now: " << player->getHandValue() << endl;
            if(player->isBusted()){
                cout << "Your hand value is over 21." << endl;
                player->stand(); // Automatically stand if busted
            }
            if(player->getHandValue() == 21){
                player->stand();
            }
        }
        else if(choice == 's'){
            player->stand();
        }
        
    }

    if(player->isBusted()){
        dealerWon();
    }
    else{
        handleDealerTurn(amount);
    }
}

void Game::handleDealerTurn(int amount){
    cout << "Dealer's hand: ";
    for(const auto& card : dealer->getHand()){
        cout << card << " | ";
    }
    cout << endl;

    if(dealer->getHandValue() >= 17){
        dealer->stand(); // Dealer stands on 17 or higher
    }
    
    while((!dealer->isBusted()) && (dealer->getStatus())){
        dealer->hit(deck.dealCard());
        cout << "Dealer drew: " << dealer->getHand().back() << endl;

        if(dealer->getHandValue() >= 17){
            dealer->stand(); // Dealer stands on 17 or higher
        }
    }

    if(dealer->isBusted()){
        playerWon(amount);
    }
    else{
        determineWinner(amount);
    }
}

void Game::determineWinner(int amount){
    int playerPoints = player->getHandValue();
    int dealerPoints = dealer->getHandValue();

    cout << player->getName() <<"'s Total Points: " << playerPoints << endl;
    cout << "Dealer's Total Points: " << dealerPoints << endl;

    if(dealerPoints > playerPoints){
        dealerWon();
    }
    else if(dealerPoints < playerPoints){
        playerWon(amount);
    }
    else{
        cout << "It's a tie." << endl;
        player->adjustBalance(amount); // Return the bet amount to the player
    }

    resetGame();
}

void Game::playerWon(int amount){
    if(player->isBlackjack()){
        cout << "You got Blackjack! Congrats, you won! :)" << endl;
        player->adjustBalance(amount * 2.5); // Player wins 2.5 times the bet amount
        resetGame();
        return;
    }
    else if(dealer->isBusted()){
        cout << "Dealer has busted! Congrats, you won! :)" << endl;
    }
    else{
        cout << "You have more points than dealer! Congrats, you won! :)" << endl;
    }

    player->adjustBalance(amount * 2); // Player wins double the bet amount
    resetGame();
}

void Game::dealerWon(){ // changed header
    if(dealer->isBlackjack()){
        cout << "Dealer got Blackjack. Sorry, you lost. :(" << endl;
    }
    else if(player->isBusted()){
        cout << "You busted. Sorry, you lost. :(" << endl;
    }
    else{
        cout << "Dealer has more points than you. Sorry, you lost. :(" << endl;
    }
    resetGame();
}

void Game::resetGame(){
    player->clearHand();  
    dealer->clearHand();
    deck.shuffleDeck();
    player->resetStatus();
    dealer->resetStatus();
}
