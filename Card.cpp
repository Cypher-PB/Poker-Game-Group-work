#include "Card.h"
#include <iostream>
#include <iomanip>

Card::Card(Suit suit, Rank rank) : suit(suit), rank(rank) {}

std::string Card::getCardString() const {
    const char* suitStr[] = { "Hearts", "Diamonds", "Clubs", "Spades" };
    const char* rankStr[] = { "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King", "Ace" };
    return std::string(rankStr[static_cast<int>(rank) - 2]) + " of " + suitStr[static_cast<int>(suit)];
}

Suit Card::getSuit() const {
    return suit;
}

Rank Card::getRank() const {
    return rank;
}

void Card::display() const {
    std::cout << "\033[1;34m"  // ANSI color for blue
        << "┌─────────┐" << std::endl;
    std::cout << "│ " << std::setw(2) << getCardString() << "      │" << std::endl;
    std::cout << "│         │" << std::endl;
    std::cout << "│    " << "    │" << std::endl;
    std::cout << "│         │" << std::endl;
    std::cout << "│      " << std::setw(2) << getCardString() << " │" << std::endl;
    std::cout << "└─────────┘" << "\033[0m" << std::endl; // Reset ANSI color
}
