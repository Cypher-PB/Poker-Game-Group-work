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
#include "PokerHand.h"
#include <ctime>
#include <cstdlib>
#include <random>
#include "Card.h"



using namespace std;

// ANSI color codes
const string RESET = "\033[0m";
const string GREEN = "\033[32m";
const string RED = "\033[31m";
const string CYAN = "\033[36m";
const string YELLOW = "\033[33m";
const string MAGENTA = "\033[35m";
const string BOLD = "\033[1m";
const string UNDERLINE = "\033[4m";
const string REVERSED = "\033[7m";
const string HIDDEN = "\033[8m";
const string BLACK = "\033[30m";
const string BLUE = "\033[34m";
const string WHITE = "\033[37m";
const string BG_BLACK = "\033[40m";
const string BG_BLUE = "\033[44m";
const string BG_WHITE = "\033[47m";
const string BG_RESET = "\033[49m";
const string BG_RED = "\033[41m";
const string BG_GREEN = "\033[42m";
const string BG_YELLOW = "\033[43m";
const string BG_MAGENTA = "\033[45m";
const string BG_CYAN = "\033[46m";
const string BG_LIGHT_GRAY = "\033[47m";
const string BG_DARK_GRAY = "\033[100m";
const string BG_LIGHT_RED = "\033[101m";
const string BG_LIGHT_GREEN = "\033[102m";
const string BG_LIGHT_YELLOW = "\033[103m";
const string BG_LIGHT_BLUE = "\033[104m";
const string BG_LIGHT_MAGENTA = "\033[105m";
const string BG_LIGHT_CYAN = "\033[106m";


//class PokerHand;  // Forward declaration





/*
* 
* 
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
*/


void displayInstructions() {
    cout << "Welcome to Texas Hold'em Poker!\n";
    cout << "The hand rankings from weakest to strongest are:\n";
    cout << "1. One Pair\n2. Two Pairs\n3. Three of a Kind\n4. Straight\n";
    cout << "5. Flush\n6. Full House\n7. Four of a Kind\n8. Straight Flush\n";
    cout << "9. Royal Flush\n";
}

int main() {
    srand(static_cast<unsigned int>(time(nullptr)));

    vector<Card> deck;
    vector<string> numbers = { "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A" };
    vector<string> types = { "Hearts", "Diamonds", "Clubs", "Spades" };

    for (const string& type : types) {
        for (const string& number : numbers) {
            deck.push_back(Card(number, type));
        }
    }

    random_shuffle(deck.begin(), deck.end());

    Player player("Player 1");
    Player computer("Computer");

    for (int i = 0; i < 2; ++i) {
        player.receiveCard(deck.back());
        deck.pop_back();
        computer.receiveCard(deck.back());
        deck.pop_back();
    }

    cout << "Your cards:\n";
    player.displayCards();

    vector<Card> communityCards;
    for (int i = 0; i < 5; ++i) {
        communityCards.push_back(deck.back());
        deck.pop_back();
    }

    cout << "Community cards:\n";
    for (const Card& card : communityCards) {
        card.display();
    }
    cout << endl;

    for (const Card& card : communityCards) {
        card.displayNumber();
    }
    cout << endl;

    for (const Card& card : communityCards) {
        card.displayType();
    }
    cout << endl;

    for (const Card& card : communityCards) {
        card.displayReverseNumber();
    }
    cout << endl;

    for (const Card& card : communityCards) {
        card.displayEnd();
    }
    cout << endl;

    vector<Card> playerHand = player.getCards();
    playerHand.insert(playerHand.end(), communityCards.begin(), communityCards.end());

    vector<Card> computerHand = computer.getCards();
    computerHand.insert(computerHand.end(), communityCards.begin(), communityCards.end());

    int playerRank = PokerHand::getHandRank(playerHand);
    int computerRank = PokerHand::getHandRank(computerHand);

    cout << "Your best hand: " << PokerHand::rankToString(playerRank) << endl;
    cout << "Computer's best hand: " << PokerHand::rankToString(computerRank) << endl;

    if (playerRank > computerRank) {
        cout << "\033[1;32mCongratulations! You win!\033[0m\n";
    }
    else if (playerRank < computerRank) {
        cout << "\033[1;31mYou lose! Better luck next time.\033[0m\n";
    }
    else {
        cout << "\033[1;33mIt's a tie!\033[0m\n";
    }

    return 0;
}

