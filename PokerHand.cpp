#include "PokerHand.h"
#include <algorithm>
#include <set>

std::string PokerHand::determineWinner(const std::vector<Player>& players, const NPC& npc) {
    std::map<std::string, std::pair<HandRank, std::vector<Card>>> playerHands;

    // Evaluate hands for all players
    for (const auto& player : players) {
        auto bestHand = findBestHand(player.getHand(), npc.getCommunityCards());
        playerHands[player.getName()] = bestHand;
    }

    // Evaluate NPC's hand
    auto npcBestHand = findBestHand(npc.getHand(), npc.getCommunityCards());
    playerHands[npc.getName()] = npcBestHand;

    // Determine winner based on hand ranks
    std::string winner;
    HandRank winningRank = HandRank::HighCard;
    std::vector<Card> winningHand;

    for (const auto& entry : playerHands) {
        const auto& playerName = entry.first;
        const auto& handRank = entry.second.first;
        const auto& handCards = entry.second.second;

        if (handRank > winningRank) {
            winningRank = handRank;
            winner = playerName;
            winningHand = handCards;
        } else if (handRank == winningRank) {
            // Compare hands in case of tie
            // For simplicity, we compare the highest card in the hand
            if (handCards > winningHand) {
                winner = playerName;
                winningHand = handCards;
            }
        }
    }

    return winner;
}

HandRank PokerHand::evaluateHand(const std::vector<Card>& hand, const std::vector<Card>& communityCards) {
    std::vector<Card> allCards = hand;
    allCards.insert(allCards.end(), communityCards.begin(), communityCards.end());

    // Sort cards by rank
    std::sort(allCards.begin(), allCards.end(), [](const Card& a, const Card& b) {
        return a.getRank() < b.getRank();
    });

    if (isFlush(allCards) && isStraight(allCards)) {
        // Royal flush (Ace, King, Queen, Jack, 10 all of the same suit)
        if (allCards.back().getRank() == Card::Rank::Ace) {
            return HandRank::RoyalFlush;
        }
        // Straight flush (five consecutive cards of the same suit)
        return HandRank::StraightFlush;
    }

    // Four of a kind (four cards of the same rank)
    std::map<Card::Rank, int> rankCount;
    for (const auto& card : allCards) {
        rankCount[card.getRank()]++;
    }
    for (const auto& pair : rankCount) {
        if (pair.second == 4) {
            return HandRank::FourOfAKind;
        }
    }

    // Full house (three of a kind and a pair)
    bool hasThreeOfAKind = false;
    bool hasPair = false;
    for (const auto& pair : rankCount) {
        if (pair.second == 3) {
            hasThreeOfAKind = true;
        }
        if (pair.second == 2) {
            hasPair = true;
        }
    }
    if (hasThreeOfAKind && hasPair) {
        return HandRank::FullHouse;
    }

    // Flush (five cards of the same suit)
    if (isFlush(allCards)) {
        return HandRank::Flush;
    }

    // Straight (five consecutive cards)
    if (isStraight(allCards)) {
        return HandRank::Straight;
    }

    // Three of a kind (three cards of the same rank)
    for (const auto& pair : rankCount) {
        if (pair.second == 3) {
            return HandRank::ThreeOfAKind;
        }
    }

    // Two pairs (two pairs of the same rank)
    int pairCount = 0;
    for (const auto& pair : rankCount) {
        if (pair.second == 2) {
            pairCount++;
        }
    }
    if (pairCount == 2) {
        return HandRank::TwoPairs;
    }

    // One pair (one pair of the same rank)
    if (pairCount == 1) {
        return HandRank::OnePair;
    }

    // High card (highest card in the hand)
    return HandRank::HighCard;
}

std::pair<HandRank, std::vector<Card>> PokerHand::findBestHand(const std::vector<Card>& hand, const std::vector<Card>& communityCards) {
    std::vector<Card> allCards = hand;
    allCards.insert(allCards.end(), communityCards.begin(), communityCards.end());

    // Generate all possible 5-card combinations
    std::vector<std::vector<Card>> combinations;
    for (size_t i = 0; i < allCards.size(); ++i) {
        for (size_t j = i + 1; j < allCards.size(); ++j) {
            for (size_t k = j + 1; k < allCards.size(); ++k) {
                for (size_t l = k + 1; l < allCards.size(); ++l) {
                    for (size_t m = l + 1; m < allCards.size(); ++m) {
                        std::vector<Card> combo = { allCards[i], allCards[j], allCards[k], allCards[l], allCards[m] };
                        combinations.push_back(combo);
                    }
                }
            }
        }
    }

    // Evaluate each combination and find the best hand
    HandRank bestRank = HandRank::HighCard;
    std::vector<Card> bestHand;
    for (const auto& combo : combinations) {
        HandRank rank = evaluateHand(combo, {});
        if (rank > bestRank) {
            bestRank = rank;
            bestHand = combo;
        } else if (rank == bestRank) {
            // Compare hands in case of tie
            // For simplicity, we compare the highest card in the hand
            if (combo > bestHand) {
                bestHand = combo;
            }
        }
    }

    return { bestRank, bestHand };
}

bool PokerHand::isFlush(const std::vector<Card>& cards) {
    // Check if all cards have the same suit
    Card::Suit firstSuit = cards[0].getSuit();
    for (const auto& card : cards) {
        if (card.getSuit() != firstSuit) {
            return false;
        }
    }
    return true;
}

bool PokerHand::isStraight(const std::vector<Card>& cards) {
    // Sort cards by rank
    std::vector<Card> sortedCards = cards;
    std::sort(sortedCards.begin(), sortedCards.end(), [](const Card& a, const Card& b) {
        return a.getRank() < b.getRank();
    });

    // Check for consecutive ranks
    for (size_t i = 1; i < sortedCards.size(); ++i) {
        if (static_cast<int>(sortedCards[i].getRank()) != static_cast<int>(sortedCards[i - 1].getRank()) + 1) {
            return false;
        }
    }

    return true;
}

int PokerHand::rankCardToScore(Card::Rank rank) {
    // Converts card rank to a score for evaluation purposes
    // Adjust as needed based on the actual game logic
    return static_cast<int>(rank);
}
