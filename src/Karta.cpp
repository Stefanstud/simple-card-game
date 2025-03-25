#include "Karta.h"

Karta::Karta() : special(false), color(Color::Red), power("") {}

Karta::Karta(bool isSpecial, Color colorVal, const std::string &powerVal)
    : special(isSpecial), color(colorVal), power(powerVal) {}

Karta::Karta(const Karta &other)
    : special(other.special), color(other.color), power(other.power) {}

Karta &Karta::operator=(const Karta &other)
{
    if (this != &other)
    {
        special = other.special;
        color = other.color;
        power = other.power;
    }
    return *this;
}

Color Karta::getColor() const
{
    return color;
}

bool Karta::isSpecialCard() const
{
    return special;
}

std::string Karta::getPower() const
{
    return power;
}

void Karta::print() const
{
    if (special)
    {
        std::cout << "Special card: " << power;
    }
    else
    {
        std::cout << "Number: " << power;
    }

    if (color != Color::Special)
    {
        std::cout << " of color ";
        switch (color)
        {
        case Color::Red:
            std::cout << "Red";
            break;
        case Color::Blue:
            std::cout << "Blue";
            break;
        case Color::Yellow:
            std::cout << "Yellow";
            break;
        case Color::Green:
            std::cout << "Green";
            break;
        default:
            break;
        }
    }
    std::cout << std::endl;
}
