#include "Deck.h"
#include <cstdlib>
#include <ctime>

Deck::Deck()
{
    initializeDeck();
}

int Deck::size() const
{
    return cards.size();
}

Karta Deck::drawCard(int index)
{
    Karta card = cards.at(index);
    cards.erase(cards.begin() + index);
    return card;
}

Karta Deck::drawRandomCard()
{
    if (cards.empty())
    {
        throw std::runtime_error("Prazen e shpilot!");
    }
    int index = rand() % cards.size();
    Karta card = cards[index];
    cards.erase(cards.begin() + index);
    return card;
}

void Deck::reshuffleFrom(std::vector<Karta> &discardPile)
{
    if (discardPile.empty())
        return;
    cards = std::vector<Karta>(discardPile.begin(), discardPile.end() - 1);
    discardPile = {discardPile.back()};
}

void Deck::initializeDeck()
{
    const std::vector<std::string> numbers = {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9"};
    const std::vector<Color> colors = {Color::Red, Color::Blue, Color::Yellow, Color::Green};
    for (const auto &color : colors)
    {
        for (const auto &number : numbers)
        {
            cards.emplace_back(false, color, number);
        }
    }

    const std::vector<std::string> specials = {"promena", "preskokni", "+2", "-1"};
    for (const auto &special : specials)
    {
        for (const auto &color : colors)
        {
            cards.emplace_back(true, color, special);
        }
    }

    for (int i = 0; i < 2; ++i)
    {
        cards.emplace_back(true, Color::Special, "joker");
        cards.emplace_back(true, Color::Special, "+4");
    }
}
