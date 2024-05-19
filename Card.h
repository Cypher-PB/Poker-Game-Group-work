#pragma once
#ifndef CARD_H
#define CARD_H

#include <string>

using namespace std;

class Card {
private:
    string number;
    string type;

public:
    explicit Card(const string& num, const string& typ);

    string getNumber() const;
    string getType() const;

    void display() const;
    void displayNumber() const;
    void displayType() const;
    void displayReverseNumber() const;
    void displayEnd() const;
};

#endif // CARD_H
