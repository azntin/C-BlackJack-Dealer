#include <gtest/gtest.h>
#include "../header/card.h"
#include "../header/deck.h"

TEST(CardTest, DefaultConstructor) {
    Card card;
    EXPECT_EQ(card.getSuit(), 'c');  // Default suit should be 'c' (Clubs)
    EXPECT_EQ(card.getRank(), 2);    // Default rank should be 2
}


TEST(CardTest, ParameterizedConstructor) {
    Card card('h', 10);
    EXPECT_EQ(card.getSuit(), 'h');  // Suit should be Hearts
    EXPECT_EQ(card.getRank(), 10);   // Rank should be 10
}


TEST(CardTest, GetSuit) {
    Card card('s', 5);
    EXPECT_EQ(card.getSuit(), 's');  // Suit should be Spades
}


TEST(CardTest, GetRank) {
    Card card('d', 1);
    EXPECT_EQ(card.getRank(), 1);  // Rank should be 1 (Ace)
}

TEST(CardTest, OutputOperatorFaceCards) {
    std::ostringstream out;
    Card king('h', 13);
    out << king;
    EXPECT_EQ(out.str(), "King of Hearts");

    std::ostringstream out2;
    Card queen('s', 12);
    out2 << queen;
    EXPECT_EQ(out2.str(), "Queen of Spades");

    std::ostringstream out3;
    Card jack('d', 11);
    out3 << jack;
    EXPECT_EQ(out3.str(), "Jack of Diamonds");

    std::ostringstream out4;
    Card ace('c', 1);
    out4 << ace;
    EXPECT_EQ(out4.str(), "Ace of Clubs");
}


TEST(CardTest, OutputOperatorNumberCards) {
    std::ostringstream out;
    Card card('h', 7);
    out << card;
    EXPECT_EQ(out.str(), "7 of Hearts");
}