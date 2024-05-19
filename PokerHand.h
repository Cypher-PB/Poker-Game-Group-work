#pragma once
#ifndef POKERHAND_H
#define POKERHAND_H

#include "player.h"
#include <vector>

class PokerHand {
public:
    static int getHandRank(const std::vector<Card>& hand);
    static std::string rankToString(int rank);
};

#endif // POKERHAND_H

