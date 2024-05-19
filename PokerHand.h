#ifndef POKERHAND_H
#define POKERHAND_H

#include "Player.h"
#include "NPC.h"
#include <vector>
#include <map>

enum class HandRank {
    HighCard,
    OnePair,
    TwoPairs,
    ThreeOfAKind,
    Straight,
    Flush,
    FullHouse,
    FourOfAKind,
    StraightFlush,
    RoyalFlush
};

class PokerHand {
public:
    static std::string determineWinner(const std::vector<Player>& players, const NPC& npc);
    static HandRank evaluateHand(const std::vector<Card>& hand, const std::vector<Card>& communityCards);

private:
    static std::pair<HandRank, std::vector<Card>> findBestHand(const std::vector<Card>& hand, const std::vector<Card>& communityCards);
    static bool isFlush(const std::vector<Card>& cards);
    static bool isStraight(const std::vector<Card>& cards);
    static int rankCardToScore(Card::Rank rank);
};

#endif // POKERHAND_H
