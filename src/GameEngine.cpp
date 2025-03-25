#include "GameEngine.h"
#include "GameRules.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

void GameEngine::setup()
{
    std::srand(static_cast<unsigned>(std::time(nullptr)));

    int numPlayers = 4;
    for (int i = 0; i < numPlayers; ++i)
    {
        std::string name;
        std::cout << "Vnesi ime za igrac " << i + 1 << ": ";
        std::cin >> name;
        Player p(name);
        for (int j = 0; j < 7; ++j)
        {
            p.drawCard(deck.drawRandomCard());
        }
        players.push_back(p);
    }
}

std::string GameEngine::play()
{
    std::vector<Karta> pile;
    pile.push_back(deck.drawRandomCard());

    int turn = 0;
    while (true)
    {
        Player &current = players[turn % players.size()];
        std::cout << "\nNa red e: " << current.getName() << "\n";
        std::cout << "Posledna karta: ";
        pile.back().print();
        current.printHand();

        int choice;
        std::cout << "\nOdberi broj na karta za da frlis ili 0 za da vlecesh: ";
        std::cin >> choice;

        if (choice == 0)
        {
            current.drawCard(deck.drawRandomCard());
        }
        else if (choice > 0 && choice <= current.getCardCount())
        {
            Karta chosen = current.peekCard(choice - 1);
            if (GameRules::isPlayable(pile.back(), chosen))
            {
                pile.push_back(current.playCard(choice - 1));
                std::cout << "Frlena karta!\n";
            }
            else
            {
                std::cout << "Ne mozhesh da ja frlish taa karta.\n";
            }
        }

        if (current.isEmpty())
            return current.getName();
        turn++;
    }
}
