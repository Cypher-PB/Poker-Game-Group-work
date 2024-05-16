#pragma once
#ifndef POKERHAND_H
#define POKERHAND_H

#include <vector>
#include "player.h"

class PokerHand {
public:
    static int getCardRank(const Card& card);
    static int getHandRank(const Player& player);
    static Player determineWinner(const std::vector<Player>& players, const Player& computer);
    static Player determineHighCardWinner(const std::vector<Player>& players, const Player& computer);
};

#endif // POKERHAND_H

