#include "pokerhand.h"
#include <map>

int PokerHand::getCardRank(const Card& card) {
    std::map<std::string, int> rankMap = {
        {"2", 2}, {"3", 3}, {"4", 4}, {"5", 5}, {"6", 6},
        {"7", 7}, {"8", 8}, {"9", 9}, {"10", 10},
        {"J", 11}, {"Q", 12}, {"K", 13}, {"A", 14}
    };
    return rankMap[card.getNumber()];
}

int PokerHand::getHandRank(const Player& player) {
    int totalRank = 0;
    for (const auto& card : player.getCards()) {
        totalRank += PokerHand::getCardRank(card);
    }
    return totalRank;
}

Player PokerHand::determineWinner(const std::vector<Player>& players, const Player& computer) {
    Player winner = computer;
    int highestRank = PokerHand::getHandRank(computer);

    for (const auto& player : players) {
        int playerRank = PokerHand::getHandRank(player);
        if (playerRank > highestRank) {
            winner = player;
            highestRank = playerRank;
        }
    }

    return winner;
}

Player PokerHand::determineHighCardWinner(const std::vector<Player>& players, const Player& computer) {
    Player winner = computer;
    Card highestCard = computer.getHighestCard();

    for (const auto& player : players) {
        Card playerHighestCard = player.getHighestCard();
        if (PokerHand::getCardRank(playerHighestCard) > PokerHand::getCardRank(highestCard)) {
            winner = player;
            highestCard = playerHighestCard;
        }
    }

    return winner;
}
