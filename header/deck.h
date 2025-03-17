#ifndef __DECK_H__
#define __DECK_H__
#include <vector>
#include "card.h"
using namespace std;

class Deck{
    private:
        vector<Card> deckOfCards;
        vector<Card> dealtCards;
    public:

        Deck();

        Card dealCard();

        void shuffleDeck();

        unsigned deckSize() const;



};



#endif
