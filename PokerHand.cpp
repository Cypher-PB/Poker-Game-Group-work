#include "PokerHand.h"

int PokerHand::cardValue(const Card& card) {
    return static_cast<int>(card.getRank());
}

std::string PokerHand::determineWinner(const std::vector<Player>& players, const NPC& npc) {
    int highestValue = -1;
    std::string winner = npc.getName();
    std::vector<Card> bestHand = npc.getHand();

    for (const auto& player : players) {
        std::string playerHandRank = evaluateHand(player.getHand());
        std::string npcHandRank = evaluateHand(npc.getHand());
        if (playerHandRank > npcHandRank) {
            winner = player.getName();
            bestHand = player.getHand();
        }
    }

    return winner;
}

std::string PokerHand::evaluateHand(const std::vector<Card>& hand) {
    // Simplified hand evaluation logic
    // This function should determine the hand ranking
    return "High Card";
}
