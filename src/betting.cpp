#include "../header/betting.h"

bool Betting::placeBet(int amount) {
    if (bankroll.getBalance() < amount || amount <= 0) {
        return false;
    }
    bankroll.adjustBalance(-amount);
    return true;
}

bool Betting::doubleDown(int originalBet) {
    return placeBet(originalBet);
}