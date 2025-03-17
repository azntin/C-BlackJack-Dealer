#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <vector>
#include "card.h"
#include "handevaluator.h"

class Player {
    protected:
        std::vector<Card> hand;
        HandEvaluator handEvaluator;
        bool status = true;
    public:
    // constructor
        Player() = default;
    // player actions
        virtual void hit(const Card& card) = 0;
        void stand() {status = false;};
    //getters
        const std::vector<Card>& getHand() const { return hand; }
        int getHandValue() const { return handEvaluator.getHandValue(hand); }
        bool isBusted() const { return handEvaluator.isBusted(hand); }
        bool isBlackjack() const { return handEvaluator.isBlackjack(hand); }
        bool getStatus() const {return status;}
        void resetStatus() {status = true;}
    // utility
        void clearHand() { hand.clear(); }
};

#endif