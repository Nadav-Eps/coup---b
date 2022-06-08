#pragma once
#include "Game.hpp"
#include "Player.hpp"
namespace coup
{
    class Duke : public Player{
    public:

        Duke(Game &g,const string & nm);
        ~Duke();
        void tax();
        void block(Player &player);

    };
}