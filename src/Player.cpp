#include "Player.h"
#include <iostream>

Player::Player(const std::string &nameVal) : name(nameVal) {}

const std::string &Player::getName() const
{
    return name;
}

int Player::getCardCount() const
{
    return static_cast<int>(hand.size());
}

bool Player::isEmpty() const
{
    return hand.empty();
}

void Player::drawCard(const Karta &card)
{
    hand.push_back(card);
}

const Karta &Player::peekCard(int index) const
{
    return hand.at(index);
}

Karta Player::playCard(int index)
{
    Karta card = hand.at(index);
    hand.erase(hand.begin() + index);
    return card;
}

void Player::printHand() const
{
    std::cout << name << " has the following cards:\n";
    for (size_t i = 0; i < hand.size(); ++i)
    {
        std::cout << i + 1 << ": ";
        hand[i].print();
    }
}
