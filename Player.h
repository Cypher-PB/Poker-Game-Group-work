#pragma once
#ifndef PLAYER_H
#define PLAYER_H

#include "card.h"
#include <vector>
#include <string>

class Player {
private:
    std::string name;
    std::vector<Card> cards;

public:
    explicit Player(const std::string& playerName);

    void receiveCard(const Card& card);
    void displayCards() const;
    std::string getName() const;
    const std::vector<Card>& getCards() const;
};

#endif // PLAYER_H
