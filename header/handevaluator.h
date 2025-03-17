#ifndef HANDEVALUATOR_H
#define HANDEVALAUTOR_H

#include <vector>
#include "card.h"

class HandEvaluator {
    public:
    int getHandValue(const std::vector<Card>& hand) const;
    bool isBusted(const std::vector<Card>& hand) const;
    bool isBlackjack(const std::vector<Card>& hand) const;
};


#endif