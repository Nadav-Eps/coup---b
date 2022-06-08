#include <iostream>
#include <vector>
#pragma once
using std::string;
using std::vector;
using std::invalid_argument;
namespace coup
{
    class Player;
    class Game
    {
        public:
        size_t curr_t;
        string turn_p;
        vector<string> playersim_health;
        vector<string> playersim;
        string winner_p;
        int player_am;
        bool started;

     
        Game();
        ~Game();
        string turn();
        vector <string> players() const;
        string winner() const;
        void next_t();
        void add_p(string const &ply);
        void player_rem(string const &name);
        void revive(string const &name);
        

    };
    }