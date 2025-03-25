#pragma once
#include "Karta.h"
#include <vector>
#include <string>

class Deck
{
public:
    Deck();
    int size() const;
    Karta drawCard(int index);
    void reshuffleFrom(std::vector<Karta> &discardPile);
    Karta drawRandomCard();

private:
    std::vector<Karta> cards;
    void initializeDeck();
};
