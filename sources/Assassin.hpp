#pragma once
#include "Game.hpp"
#include "Player.hpp"
namespace coup
{
    class Assassin : public Player{
    public:

        Assassin(Game &g,const string & nm);
        ~Assassin();
        void coup(Player &player);

    };
}