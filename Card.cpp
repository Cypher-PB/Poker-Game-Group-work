#include "card.h"
#include <iostream>
#include <iomanip>

using namespace std;

Card::Card(const string& num, const string& typ) : number(num), type(typ) {}

string Card::getNumber() const {
    return number;
}

string Card::getType() const {
    return type;
}

void Card::display() const {
    cout << "┌─────────┐ ";
}

void Card::displayNumber() const {
    cout << "│" << setw(2) << left << number << "       │ ";
}

void Card::displayType() const {
    cout << "│    ";
    if (type == "Hearts" || type == "Diamonds")
        cout << "\033[1;31m"; // Red color for Hearts and Diamonds
    else
        cout << "\033[1;30m"; // Black color for Clubs and Spades
    cout << type[0] << "    \033[0m│ ";
}

void Card::displayReverseNumber() const {
    cout << "│       ";
    if (type == "Hearts" || type == "Diamonds")
        cout << "\033[1;31m"; // Red color for Hearts and Diamonds
    else
        cout << "\033[1;30m"; // Black color for Clubs and Spades
    cout << setw(2) << right << number << "│\033[0m ";
}

void Card::displayEnd() const {
    cout << "└─────────┘ ";
}
