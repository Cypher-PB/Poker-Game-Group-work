#include "player.h"
#include <algorithm>
#include <iostream>

using namespace std;

Player::Player(const string& playerName) : name(playerName) {}

void Player::receiveCard(const Card& card) {
    cards.emplace_back(card);
}

void Player::displayCards() const {
    cout << name << "'s cards:\n";
    for (const auto& card : cards) {
        card.display();
    }
}

string Player::getName() const {
    return name;
}

vector<Card> Player::getCards() const {
    return cards;
}

Card Player::getHighestCard() const {
    return *std::max_element(cards.begin(), cards.end(), [](const Card& a, const Card& b) {
        return a.getNumber() < b.getNumber();
        });
}
