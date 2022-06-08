#include "Assassin.hpp"
#include "Game.hpp"
constexpr int COUP_M_A = 3;
constexpr int MAXCOP = 7;
using namespace coup;

Assassin::Assassin(Game &g,const string & nm):Player(g,nm){
    this->role_p = "Assassin";
    g.add_p(nm);
}
Assassin::~Assassin(){};
void Assassin::coup(Player &player){
    check_t();
    if(this->s_coin<COUP_M_A){
        throw("need at least 3 coins to coup as an assassin");
    }
    for (size_t i = 0; i < gamei->playersim.size(); i++)
    {
        if(gamei->playersim.at(i)==player.name){
            if(gamei->playersim_health.at(i)!="good"){
                throw(player.name + " already dead");
            }
        }
    }
    if(this->s_coin>MAXCOP){
        this->s_coin-=MAXCOP;
        this->killed.push(player);
        this->gamei->player_rem(player.name);
    }
    else{
    this->s_coin-=COUP_M_A;
    this->killed.push(player);
    this->gamei->player_rem(player.name);
    this->l_act = "coup";
    }
    gamei->next_t();
};
