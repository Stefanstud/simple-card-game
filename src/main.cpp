#include "GameEngine.h"

int main()
{
    GameEngine game;
    game.setup();
    std::string winner = game.play();
    std::cout << "🏆 POBEDNIK E: " << winner << " 🏆" << std::endl;
    return 0;
}
