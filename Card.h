#pragma once
#ifndef CARD_H
#define CARD_H

#include <string>

class Card {
private:
    std::string number;
    std::string type;

public:
    explicit Card(const std::string& num, const std::string& typ);

    [[nodiscard]] std::string getNumber() const;
    [[nodiscard]] std::string getType() const;
    void display() const;
};

#endif // CARD_H
