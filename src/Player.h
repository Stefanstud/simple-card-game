#pragma once
#include "Karta.h"
#include <string>
#include <vector>

class Player
{
public:
    Player(const std::string &name = "Player");
    ~Player() = default;

    const std::string &getName() const;
    int getCardCount() const;
    bool isEmpty() const;

    void drawCard(const Karta &card);
    const Karta &peekCard(int index) const;
    Karta playCard(int index);

    void printHand() const;

private:
    std::string name;
    std::vector<Karta> hand;
};
