#pragma once
#include "Karta.h"

class GameRules
{
public:
    static bool isPlayable(const Karta &top, const Karta &candidate);
};
