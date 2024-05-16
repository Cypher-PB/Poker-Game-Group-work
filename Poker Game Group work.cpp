// poker game build to meet academic requirements 
/*
* Question statement 
*You have been asked to design a simple gambling system for your local casino. Due to the lack of funds you are expected to design a Console application.

SECTION A
For the card gambling system to work , you application needs the ability to display cards.
In this section build a program that receives two inputs from he user-- the card number and the card type-- and displayed the card on your console. This display may look like fig 1 below

  
Fig 1

SECTION B
Thanks to your colleague’s success you have a fully functional card display system . Now using your friends system designed above you are expected to expand the system to accommodate a minimum of a single player and a maximum of 4 players.
Each player should be given 3 cards each including the PC(NPC or your computer).
Your program should track which player receives which card .
The card given to each player should be displayed on screen except the PC(NPC or your computer) cards.

SECTION C
If all went well you now have a system that can share and displayed the cards shared to the user.
Now using your group mates code from above implement the combinations in poker to determine a winner .
This system matches each individuals card with the PC to create combination. This combinations determine the winner . more details can be found online or check link
 ( https://youtu.be/cNaUXwu4MzQ?si=iDB9Y_HbkQ0ZsWRa )

SECTION D
with this you have developed a fully working poker system, now a casino can’t run with one card game now can it ?
In this section you are expected to use at least two of your friends code from above to develop or implement a card game of your design or that already exist.


* 

*/

// section A
// include necesary libraries
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <random>
#include <algorithm>
#include <iomanip>
#include <limits>
#include "Player.h"
#include "Card.h"
#include "PokerHand.h"


using namespace std;

// ANSI color codes
const string RESET = "\033[0m";
const string GREEN = "\033[32m";
const string RED = "\033[31m";
const string CYAN = "\033[36m";

class PokerHand;  // Forward declaration






string randomCardNumber() {
    const vector<string> numbers = { "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A" };
    static random_device rd;
    static mt19937 gen(rd());
    uniform_int_distribution<> dis(0, numbers.size() - 1);
    return numbers[dis(gen)];
}

string randomCardType() {
    const vector<string> types = { "Hearts", "Diamonds", "Clubs", "Spades" };
    static random_device rd;
    static mt19937 gen(rd());
    uniform_int_distribution<> dis(0, types.size() - 1);
    return types[dis(gen)];
}

void howToPlay() {
    cout << CYAN << "How to Play:" << RESET << endl;
    cout << "1. Choose the level of difficulty for the computer opponent." << endl;
    cout << "2. Each player, including the computer, will receive 3 cards." << endl;
    cout << "3. The player with the highest total card rank wins." << endl;
    cout << "4. In the High Card game, the player with the single highest card wins." << endl;
    cout << "5. Have fun and enjoy the game!" << endl;
    cout << "Press Enter to go back to the main menu." << endl;
    cin.ignore();
    cin.get();
}

int validateInput(int lower, int upper) {
    int choice;
    while (true) {
        cin >> choice;
        if (cin.fail() || choice < lower || choice > upper) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a number between " << lower << " and " << upper << ": ";
        }
        else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            break;
        }
    }
    return choice;
}

void congratulations() {
    cout << GREEN << "Congratulations! You won!" << RESET << endl;
    cout << "Press Enter to return to the main menu." << endl;
    cin.get();
}

void gameOver() {
    cout << RED << "Game Over! You lost!" << RESET << endl;
    cout << "Press Enter to play again or return to the main menu." << endl;
    cin.get();
}

void playGame(int difficulty) {
    int playerCount;
    cout << "Enter number of players (1-4): ";
    playerCount = validateInput(1, 4);

    vector<Player> players;
    for (int i = 1; i <= playerCount; ++i) {
        players.emplace_back("Player " + to_string(i));
    }

    Player computer("Computer");

    for (int i = 0; i < 3; ++i) {
        for (auto& player : players) {
            player.receiveCard(Card(randomCardNumber(), randomCardType()));
        }
        computer.receiveCard(Card(randomCardNumber(), randomCardType()));
    }

    for (const auto& player : players) {
        player.displayCards();
    }

    // Determine the winner based on difficulty
    Player winner("Winner");
    if (difficulty == 1) { // Easy
        winner = PokerHand::determineHighCardWinner(players, computer);
    }
    else if (difficulty == 2) { // Medium
        winner = PokerHand::determineWinner(players, computer);
    }
    else { // Hard
        winner = PokerHand::determineWinner(players, computer);
    }

    if (winner.getName() == "Computer") {
        gameOver();
    }
    else {
        congratulations();
    }
}

void showMenu() {
    while (true) {
        cout << CYAN << "Welcome to the Console Casino!" << RESET << endl;
        cout << "1. Play Game" << endl;
        cout << "2. How to Play" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice: ";

        int choice = validateInput(1, 3);

        if (choice == 1) {
            cout << "Select difficulty level: " << endl;
            cout << "1. Easy" << endl;
            cout << "2. Medium" << endl;
            cout << "3. Hard" << endl;
            cout << "Enter your choice: ";
            int difficulty = validateInput(1, 3);
            playGame(difficulty);
        }
        else if (choice == 2) {
            howToPlay();
        }
        else if (choice == 3) {
            cout << "Thank you for playing! Goodbye!" << endl;
            break;
        }
    }
}

int main() {
    showMenu();
    return 0;
}
