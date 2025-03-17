#include "../header/card.h"
#include <iostream>

using namespace std;

Card::Card(){
suit = 'c';
rank =2;
}
Card::Card(char s, int r){
suit = s;
rank=r;
}
char Card::getSuit() const{
return suit;

}
int Card::getRank() const {
    return rank;
}
ostream & operator<<(ostream & out, const Card & kek){
    string name;
    if(kek.suit=='c'){
        name="Clubs";
    }else if(kek.suit=='d'){
        name="Diamonds";
    }else if(kek.suit=='h'){
        name="Hearts";
    }else if(kek.suit=='s'){
        name="Spades";
    }
    if(kek.rank==1){
        out<<"Ace of "<<name;
    }
    if(kek.rank==11){
        out<<"Jack of "<<name;
    }
    if(kek.rank==12){
        out<<"Queen of "<<name;
    }
    if(kek.rank==13){
        out<<"King of "<<name;
    }
    if(kek.rank>1&&kek.rank<11){
    out<< kek.rank<<" of "<<name;
    }
    return out;
}