#ifndef POKERHAND_H
#define POKERHAND_H

#include "Player.h"
#include <vector>
#include <string>

class PokerHand {
public:
    static int cardValue(const Card& card);
    static std::string determineWinner(const std::vector<Player>& players, const NPC& npc);
    static std::string evaluateHand(const std::vector<Card>& hand);
};

#endif // POKERHAND_H
