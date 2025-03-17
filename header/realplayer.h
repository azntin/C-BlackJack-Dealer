#ifndef REALPLAYER_H
#define REALPLAYER_H

#include "player.h"
#include "bankroll.h"
#include "betting.h"
#include <string>

class RealPlayer : public Player {
    private:
        std::string name;
        Bankroll bankroll;
        Betting betting;
    public:
        RealPlayer(const std::string& name) : name(name), betting(this->bankroll) {}
        void hit(const Card& card) override;
        const std::string& getName() const;
        // handled by betting class
        bool placeBet(int amount);
        bool doubleDown(int originalBet);
        // handled by bankroll class
        int getBalance() const;
        void adjustBalance(int amount);
};

#endif
