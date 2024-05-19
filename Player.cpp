#include "Player.h"
#include <iostream>

Player::Player(const std::string& name) : name(name), score(0) {}

std::string Player::getName() const {
    return name;
}

std::vector<Card> Player::getHand() const {
    return hand;
}

void Player::addCard(const Card& card) {
    hand.push_back(card);
}

void Player::showHand() const {
    std::cout << "\033[1;33m" << name << "'s hand:\033[0m" << std::endl; // ANSI color for yellow
    for (const auto& card : hand) {
        card.display();
    }
    std::cout << std::endl;
}

void Player::clearHand() {
    hand.clear();
}

int Player::getScore() const {
    return score;
}

void Player::addScore(int points) {
    score += points;
}
