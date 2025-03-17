#include <iostream>
#include "../header/deck.h"
#include <algorithm>
#include <ctime>
using namespace std;
Deck::Deck(){
    vector<char> suits;
    suits.push_back('s');
    suits.push_back('h');
    suits.push_back('d');
    suits.push_back('c');
    for(unsigned int i=0;i<suits.size();++i){
        for(int j=13;j>0;--j){
            Card temp(suits.at(i),j);
            deckOfCards.push_back(temp);
        }
    }

}
Card Deck::dealCard(){
    if(deckSize()==0){

        return Card();
    }
    Card hand=deckOfCards.back();
    deckOfCards.pop_back();
    dealtCards.push_back(hand);
    return hand;
}
void Deck::shuffleDeck(){
    srand(time(0));
    for(unsigned int i = 0; i < dealtCards.size(); ++i){
        
        deckOfCards.push_back(dealtCards.at(i));
    }
    
    dealtCards.clear();

    random_shuffle(deckOfCards.begin(), deckOfCards.end());
}
unsigned Deck::deckSize() const{
    return deckOfCards.size();
}