#include "NPC.h"
#include <iostream>

NPC::NPC(const std::string& name, int difficultyLevel)
    : Player(name), difficultyLevel(difficultyLevel) {}

void NPC::playTurn() {
    // Implement NPC behavior based on difficultyLevel
    if (difficultyLevel == 1) {
        std::cout << "NPC is playing at Beginner level.\n";
        // Simple random decisions
    }
    else if (difficultyLevel == 2) {
        std::cout << "NPC is playing at Intermediate level.\n";
        // Basic strategy
    }
    else if (difficultyLevel == 3) {
        std::cout << "NPC is playing at Advanced level.\n";
        // Advanced strategy
    }
}

void NPC::levelUp() {
    if (difficultyLevel < 3) {
        ++difficultyLevel;
    }
}

int NPC::getDifficultyLevel() const {
    return difficultyLevel;
}
