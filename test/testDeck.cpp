#include <gtest/gtest.h>
#include "../header/card.h"
#include "../header/deck.h"
TEST(DeckTest, InitialDeckSize) {
    Deck deck;
    EXPECT_EQ(deck.deckSize(), 52);
}


TEST(DeckTest, DealCardReducesDeckSize) {
    Deck deck;
    Card dealt = deck.dealCard();
    EXPECT_EQ(deck.deckSize(), 51);
}

TEST(DeckTest, DealAllCards) {
    Deck deck;
    for (int i = 0; i < 52; ++i) {
        deck.dealCard();
    }
    EXPECT_EQ(deck.deckSize(), 0);
}




TEST(DeckTest, ShuffleMaintainsDeckSize) {
    Deck deck;
    deck.shuffleDeck();
    EXPECT_EQ(deck.deckSize(), 52);
}


