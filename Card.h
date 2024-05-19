#pragma once
#ifndef CARD_H
#define CARD_H

#include <string>

enum class Suit { Hearts, Diamonds, Clubs, Spades };
enum class Rank { Two = 2, Three, Four, Five, Six, Seven, Eight, Nine, Ten, Jack, Queen, King, Ace };

class Card {
private:
    Suit suit;
    Rank rank;

public:
    Card(Suit suit, Rank rank);
    std::string getCardString() const;
    Suit getSuit() const;
    Rank getRank() const;
    void display() const;
};

#endif // CARD_H
