#include "pokerhand.h"
#include <algorithm>
#include <map>

using namespace std;

int PokerHand::getHandRank(const vector<Card>& hand) {
    // Simplified logic to determine hand rank
    map<string, int> valueMap = {
        {"2", 2}, {"3", 3}, {"4", 4}, {"5", 5}, {"6", 6}, {"7", 7}, {"8", 8}, {"9", 9},
        {"10", 10}, {"J", 11}, {"Q", 12}, {"K", 13}, {"A", 14}
    };

    map<string, int> suitMap = {
        {"Hearts", 1}, {"Diamonds", 2}, {"Clubs", 3}, {"Spades", 4}
    };

    vector<int> values;
    for (const Card& card : hand) {
        values.push_back(valueMap[card.getNumber()]);
    }

    sort(values.begin(), values.end());

    // Add more detailed hand ranking logic here...

    return values.back(); // Simplified ranking just for the highest card
}

string PokerHand::rankToString(int rank) {
    switch (rank) {
    case 1: return "One Pair";
    case 2: return "Two Pairs";
    case 3: return "Three of a Kind";
    case 4: return "Straight";
    case 5: return "Flush";
    case 6: return "Full House";
    case 7: return "Four of a Kind";
    case 8: return "Straight Flush";
    case 9: return "Royal Flush";
    default: return "High Card";
    }
}
