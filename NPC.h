#pragma once
#ifndef NPC_H
#define NPC_H

#include "Player.h"

class NPC : public Player {
private:
    int difficultyLevel;

public:
    NPC(const std::string& name, int difficultyLevel);
    void playTurn();
    void levelUp();
    int getDifficultyLevel() const;
};

#endif // NPC_H
