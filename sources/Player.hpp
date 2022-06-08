#pragma once
#include <iostream>
#include <vector>
using namespace std;
using std::string;
using std::vector;
#include "Game.hpp"
#include <stack>

namespace coup
{
    class Player
    {
        public:
        bool life;
        string name;
        Game *gamei;
        int s_coin;
        string role_p;
        string l_act;
        stack <Player*> s_f;
        stack <Player> killed;
        // string s_f;
        // string killed; 

        public:
         Player(Game &g, string nm);
         ~Player();
         void income();
         void foreign_aid();
         void coup(Player &p);
         int coins() const;
         string role() const;
         void check_t() const;
         void check_t_b() const;
         void check_t_c() const;
         void add_coin(Player &pl);
    };}