#include "Deck.h"

Deck::Deck() {
    for (int suit = 0; suit < 4; ++suit) {
        for (int rank = 2; rank <= 14; ++rank) {
            cards.emplace_back(static_cast<Suit>(suit), static_cast<Rank>(rank));
        }
    }
    currentCardIndex = 0;
    shuffle();
}

void Deck::shuffle() {
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(cards.begin(), cards.end(), g);
    currentCardIndex = 0;
}

Card Deck::dealCard() {
    return cards[currentCardIndex++];
}
