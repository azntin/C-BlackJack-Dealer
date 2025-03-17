#pragma once
#include "../header/player.h"

class Dealer : public Player {
    public:
        Dealer();
        ~Dealer();
        void hit(const Card& card) override;
};