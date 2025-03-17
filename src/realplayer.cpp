#include "../header/realplayer.h"

void RealPlayer::hit(const Card& card){
    hand.push_back(card);
}

const std::string& RealPlayer::getName() const {
    return name;
}

bool RealPlayer::placeBet(int amount) {
    return betting.placeBet(amount);
}

bool RealPlayer::doubleDown(int originalBet) {
    return betting.doubleDown(originalBet);
}


int RealPlayer::getBalance() const {
    return bankroll.getBalance(); 
}

void RealPlayer::adjustBalance(int amount) {
    bankroll.adjustBalance(amount);
}