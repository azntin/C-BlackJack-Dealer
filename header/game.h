#pragma once
#include "../header/dealer.h"
#include "../header/realplayer.h"
#include "../header/player.h"
#include "../header/deck.h"
// #include "../header/handevaluator.h"
#include "../header/bankroll.h"
#include "../header/betting.h"
using namespace std;

class Game{
    private:
        Deck deck;
        RealPlayer *player;
        Dealer *dealer;

    public:
        Game(string name);
        ~Game();
        void playRound(int amount);
        void handlePlayerTurn(int amount);
        void handleDealerTurn(int amount);
        void determineWinner(int amount);
        void resetGame();
        void playerWon(int amount);
        void dealerWon();
        void handleBet();
        int getPlayerBalance() const {return player->getBalance();}
        int intInputCheck();
        char charInputCheck();

};