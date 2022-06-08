#pragma once
#include "Game.hpp"
#include "Player.hpp"
namespace coup
{
    class Contessa : public Player{
    public:

        Contessa(Game &g,const string & nm);
        ~Contessa();
        void block(Player &player);

    };
}