#pragma once
#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <vector>
#include "card.h"

class Player {
private:
    std::vector<Card> cards;
    std::string name;

public:
    explicit Player(const std::string& playerName);

    void receiveCard(const Card& card);
    void displayCards() const;

    [[nodiscard]] std::string getName() const;
    [[nodiscard]] std::vector<Card> getCards() const;
    [[nodiscard]] Card getHighestCard() const;
};

#endif // PLAYER_H
