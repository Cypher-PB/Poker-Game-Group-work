#pragma once
#ifndef GAME_H
#define GAME_H

#include <map>
#include <string>

void displayMenu();
void displayHowToPlay();
void loadHighScores(std::map<std::string, int>& highScores);
void saveHighScores(const std::map<std::string, int>& highScores);
void displayHighScores(const std::map<std::string, int>& highScores);
void playGame(std::map<std::string, int>& highScores, int& npcLevel);
void saveGameState(const std::map<std::string, int>& highScores, int npcLevel);
void loadGameState(std::map<std::string, int>& highScores, int& npcLevel);

#endif // GAME_H
