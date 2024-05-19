#include "Game.h"
#include "Card.h"
#include "Deck.h"
#include "Player.h"
#include "NPC.h"
#include "PokerHand.h"
#include <iostream>
#include <fstream>

void displayMenu() {
    std::cout << "===== Poker Game Menu =====" << std::endl;
    std::cout << "1. How to Play" << std::endl;
    std::cout << "2. Play Game" << std::endl;
    std::cout << "3. High Scores" << std::endl;
    std::cout << "4. Save and Exit" << std::endl;
    std::cout << "Enter your choice: ";
}

void displayHowToPlay() {
    std::cout << "Here are the rules of Texas Hold'em Poker:" << std::endl;
    std::cout << "..." << std::endl;
}

void loadHighScores(std::map<std::string, int>& highScores) {
    std::ifstream infile("highscores.txt");
    if (infile.is_open()) {
        std::string name;
        int score;
        while (infile >> name >> score) {
            highScores[name] = score;
        }
        infile.close();
    }
}

void saveHighScores(const std::map<std::string, int>& highScores) {
    std::ofstream outfile("highscores.txt");
    if (outfile.is_open()) {
        for (const auto& entry : highScores) {
            outfile << entry.first << " " << entry.second << std::endl;
        }
        outfile.close();
    }
}

void displayHighScores(const std::map<std::string, int>& highScores) {
    std::cout << "===== High Scores =====" << std::endl;
    for (const auto& entry : highScores) {
        std::cout << entry.first << ": " << entry.second << std::endl;
    }
    std::cout << std::endl;
}

void playGame(std::map<std::string, int>& highScores, int& npcLevel) {
    Deck deck;
    std::vector<Player> players;
    for (int i = 1; i <= 4; ++i) {
        players.emplace_back("Player " + std::to_string(i));
    }
    NPC npc("PC", npcLevel);

    for (int i = 0; i < 2; ++i) {
        for (auto& player : players) {
            player.addCard(deck.dealCard());
        }
        npc.addCard(deck.dealCard());
    }

    for (const auto& player : players) {
        player.showHand();
    }

    std::string winner = PokerHand::determineWinner(players, npc);
    std::cout << "The winner is: " << winner << std::endl;

    if (winner != "PC") {
        highScores[winner] += 1;
    }
    else {
        npc.levelUp();
    }

    saveHighScores(highScores);
    saveGameState(highScores, npcLevel);
}

void saveGameState(const std::map<std::string, int>& highScores, int npcLevel) {
    std::ofstream outfile("gamestate.txt");
    if (outfile.is_open()) {
        outfile << npcLevel << std::endl;
        for (const auto& entry : highScores) {
            outfile << entry.first << " " << entry.second << std::endl;
        }
        outfile.close();
    }
}

void loadGameState(std::map<std::string, int>& highScores, int& npcLevel) {
    std::ifstream infile("gamestate.txt");
    if (infile.is_open()) {
        infile >> npcLevel;
        std::string name;
        int score;
        while (infile >> name >> score) {
            highScores[name] = score;
        }
        infile.close();
    }
}
