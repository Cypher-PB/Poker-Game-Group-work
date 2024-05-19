#pragma once
#ifndef PLAYER_H
#define PLAYER_H

#include "Card.h"
#include <vector>
#include <string>

class Player {
protected:
    std::string name;
    std::vector<Card> hand;
    int score;

public:
    Player(const std::string& name);

    std::string getName() const;
    std::vector<Card> getHand() const;
    void addCard(const Card& card);
    void showHand() const;
    void clearHand();
    int getScore() const;
    void addScore(int points);
};

#endif // PLAYER_H
