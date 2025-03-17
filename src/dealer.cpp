#include <iostream>
#include "../header/dealer.h"

Dealer::Dealer() {}

Dealer::~Dealer() {}

void Dealer::hit(const Card& card) {
    hand.push_back(card);
}