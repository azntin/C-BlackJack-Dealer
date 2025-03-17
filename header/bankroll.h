#ifndef BANKROLL_H
#define BANKROLL_H

class Bankroll {
    private:
        int balance = 1000;
    public:
        int getBalance() const { return balance; }
        void adjustBalance(int amount) { balance += amount; }
};

#endif