#include "GameRules.h"

bool GameRules::isPlayable(const Karta &top, const Karta &candidate)
{
    if (candidate.getPower() == "joker" || candidate.getPower() == "+4")
    {
        return true;
    }

    if (candidate.getColor() == top.getColor())
    {
        return true;
    }

    if (candidate.getPower() == top.getPower())
    {
        return true;
    }

    return false;
}
