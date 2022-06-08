#include "Duke.hpp"
#include "Game.hpp"
constexpr int MIN_ST = 2;
using namespace coup;

Duke::Duke(Game &g,const string & nm):Player(g,nm){
    this->role_p = "Duke";
    g.add_p(nm);
}
Duke::~Duke(){};
void Duke::block(Player &player){
    if(player.l_act!="forgein_aid"){
        throw("can only block forgein_aid");
    }
    if(player.s_coin<MIN_ST){
        throw("not enogh money");
    }
    player.s_coin-=MIN_ST;
    this->l_act="block";
};
void Duke::tax(){
    check_t();
    this->s_coin+=MIN_ST;
    this->s_coin++;
    this->l_act="tax";
    gamei->next_t();
};