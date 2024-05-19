#include "player.h"
#include <iostream>

using namespace std;


Player::Player(const string& playerName) : name(playerName) {}

void Player::receiveCard(const Card& card) {
    cards.push_back(card);
}

void Player::displayCards() const {
    for (const Card& card : cards) {
        card.display();
    }
    cout << endl;

    for (const Card& card : cards) {
        card.displayNumber();
    }
    cout << endl;

    for (const Card& card : cards) {
        card.displayType();
    }
    cout << endl;

    for (const Card& card : cards) {
        card.displayReverseNumber();
    }
    cout << endl;

    for (const Card& card : cards) {
        card.displayEnd();
    }
    cout << endl;
}

string Player::getName() const {
    return name;
}

const vector<Card>& Player::getCards() const {
    return cards;
}
