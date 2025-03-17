#include <gtest/gtest.h>
#include "../header/dealer.h"
#include "../header/realplayer.h"

TEST(DealerFunctions, testHitExists) {
    Dealer* d1 = new Dealer;
    Card newCard;
    d1->hit(newCard);
    ASSERT_NE(d1->getHand().size(), 0);
}

TEST(DealerFunctions, testHitValue) {
    Dealer* d1 = new Dealer;
    Card newCard;
    d1->hit(newCard);
    ASSERT_EQ(d1->getHand().at(0).getSuit(), 'c');
    ASSERT_EQ(d1->getHand().at(0).getRank(), 2);
}

TEST(DealerFunctions, testStand) {
    Dealer* d1 = new Dealer;
    d1->stand();
    ASSERT_FALSE(d1->getStatus());
    d1->resetStatus();
    ASSERT_TRUE(d1->getStatus());
}

TEST(DealerFunctions, testHandValue) {
    Dealer* d1 = new Dealer;
    Card newCard('c', 9);
    Card newCard2('h', 5);
    d1->hit(newCard);
    d1->hit(newCard2);
    ASSERT_EQ(d1->getHandValue(), 14);
}

TEST(DealerFunctions, testIsBusted) {
    Dealer* d1 = new Dealer;
    Card nineOfClubs('c', 9);
    d1->hit(nineOfClubs);
    ASSERT_FALSE(d1->isBusted());
    d1->hit(nineOfClubs);
    ASSERT_FALSE(d1->isBusted());
    d1->hit(nineOfClubs);
    ASSERT_TRUE(d1->isBusted());
}

TEST(DealerFunctions, testIsBlackJack) {
    Dealer* d1 = new Dealer;
    Card aceOfHearts('h', 1);
    Card jackOfSpades('s', 11);
    d1->hit(aceOfHearts);
    d1->hit(jackOfSpades);
    ASSERT_TRUE(d1->isBlackjack());
}

// testing realplayer functions //

TEST(RealPlayerFunctions, testPlayerCtor) {
    RealPlayer* p1 = new RealPlayer("Axel");
    ASSERT_EQ(p1->getName(), "Axel");
}

TEST(RealPlayerFunctions, testHitExists) {
    RealPlayer* p1 = new RealPlayer("tester");
    Card newCard;
    p1->hit(newCard);
    ASSERT_NE(p1->getHand().size(), 0);
}

TEST(RealPlayerFunctions, testHitValue) {
    RealPlayer* p1 = new RealPlayer("tester");
    Card newCard;
    p1->hit(newCard);
    ASSERT_EQ(p1->getHand().at(0).getSuit(), 'c');
    ASSERT_EQ(p1->getHand().at(0).getRank(), 2);
}

TEST(RealPlayerFunctions, testStand) {
    RealPlayer* p1 = new RealPlayer("tester");
    p1->stand();
    ASSERT_FALSE(p1->getStatus());
    p1->resetStatus();
    ASSERT_TRUE(p1->getStatus());
}

TEST(RealPlayerFunctions, testHandValue) {
    RealPlayer* p1 = new RealPlayer("tester");
    Card newCard('c', 3);
    Card newCard2('h', 8);
    p1->hit(newCard);
    p1->hit(newCard2);
    ASSERT_EQ(p1->getHandValue(), 11);
}

TEST(RealPlayerFunctions, testIsBusted) {
    RealPlayer* p1 = new RealPlayer("tester");
    Card nineOfClubs('c', 9);
    p1->hit(nineOfClubs);
    ASSERT_FALSE(p1->isBusted());
    p1->hit(nineOfClubs);
    ASSERT_FALSE(p1->isBusted());
    p1->hit(nineOfClubs);
    ASSERT_TRUE(p1->isBusted());
}

TEST(RealPlayerFunctions, testIsBlackJack) {
    RealPlayer* p1 = new RealPlayer("tester");
    Card aceOfHearts('h', 1);
    Card jackOfSpades('s', 11);
    p1->hit(aceOfHearts);
    p1->hit(jackOfSpades);
    ASSERT_TRUE(p1->isBlackjack());
}

TEST(RealPlayerFunctions, testActiveBalance) {
    RealPlayer* p1 = new RealPlayer("tester");
    ASSERT_TRUE(p1->getBalance());
    ASSERT_EQ(p1->getBalance(), 1000);
}

TEST(RealPlayerFunctions, testPlaceBet) {
    RealPlayer* p1 = new RealPlayer("tester");
    p1->placeBet(500);
    ASSERT_EQ(p1->getBalance(), 500); 
}

TEST(RealPlayerFunctions, testDoubleDown) {
    RealPlayer* p1 = new RealPlayer("tester");
    p1->doubleDown(1000);
    ASSERT_EQ(p1->getBalance(), 0);
}

TEST(RealPlayerFunctions, testPlaceOverbet) {
    RealPlayer* p1 = new RealPlayer("tester");
    ASSERT_FALSE(p1->placeBet(1001));
    ASSERT_EQ(p1->getBalance(), 1000);
}

