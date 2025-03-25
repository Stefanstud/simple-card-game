#pragma once
#include <iostream>
#include <string>

enum class Color
{
    Red,
    Blue,
    Yellow,
    Green,
    Special
};

class Karta
{
public:
    Karta();
    Karta(bool isSpecial, Color color, const std::string &power);
    Karta(const Karta &other);
    Karta &operator=(const Karta &other);

    Color getColor() const;
    bool isSpecialCard() const;
    std::string getPower() const;
    void print() const;

private:
    bool special;
    Color color;
    std::string power;
};
