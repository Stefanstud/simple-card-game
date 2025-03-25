#pragma once
#include "Player.h"
#include "Deck.h"
#include <vector>

class GameEngine
{
public:
    void setup();
    std::string play();

private:
    Deck deck;
    std::vector<Player> players;
};
