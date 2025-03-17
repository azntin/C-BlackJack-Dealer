#ifndef BETTING_H
#define BETTING_H

#include "bankroll.h"

class Betting {
    private:
        Bankroll& bankroll;
    public:
        Betting(Bankroll& playerBankroll) : bankroll(playerBankroll) {}
        bool placeBet(int amount);
        bool doubleDown(int originalBet);
};

#endif