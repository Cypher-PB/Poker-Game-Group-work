#include "card.h"
#include <iostream>
#include <iomanip>

Card::Card(const std::string& num, const std::string& typ) : number(num), type(typ) {}

std::string Card::getNumber() const {
    return number;
}

std::string Card::getType() const {
    return type;
}

void Card::display() const {
    std::cout << "┌─────────┐\n";
    std::cout << "│" << std::setw(2) << std::left << number << "       │\n";
    std::cout << "│         │\n";
    std::cout << "│         │\n";
    std::cout << "│    " << type[0] << "    │\n";
    std::cout << "│         │\n";
    std::cout << "│         │\n";
    std::cout << "│       " << std::setw(2) << std::right << number << "│\n";
    std::cout << "└─────────┘\n";
}
