#include "../header/handevaluator.h"

int HandEvaluator::getHandValue(const std::vector<Card>& hand) const {
    int value = 0;
    int numAces = 0;
    for (const Card& card : hand) {
        if (card.getRank() == 1) {
            numAces++;
            value += 11;
        } else if (card.getRank() >= 10) {
            value += 10;
        } else {
            value += card.getRank();
        }
    }
    while (value > 21 && numAces > 0) {
        value -= 10;
        numAces--;
    }
    return value;
}

bool HandEvaluator::isBusted(const std::vector<Card>& hand) const {
    return getHandValue(hand) > 21;
}

bool HandEvaluator::isBlackjack(const std::vector<Card>& hand) const {
    return hand.size() == 2 && getHandValue(hand) == 21;
}