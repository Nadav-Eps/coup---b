#include "Contessa.hpp"
#include "Game.hpp"
using namespace coup;

Contessa::Contessa(Game &g,const string & nm):Player(g,nm){
    this->role_p = "Contessa";
    g.add_p(nm);
}
Contessa::~Contessa(){};
void Contessa::block(Player &player){
    check_t_b();
    if(player.role_p!="Assassin"){
        throw("can only block assassins");
    }
    if(player.l_act!="coup"){
        throw("cant block because he didnt killde in this round");
    }
    gamei->revive(player.killed.top().name);
    player.killed.pop();
    this->l_act="block";

};