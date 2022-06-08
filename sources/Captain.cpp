#include "Captain.hpp"
#include "Game.hpp"
constexpr int MIN_ST = 2;
using namespace coup;

Captain::Captain(Game &g,const string & nm):Player(g,nm){
    this->role_p = "Captain";
    g.add_p(nm);
}
Captain::~Captain(){};
void Captain::block(Player &player){
    check_t_b();
    if(player.role_p!="Captain"){
        throw("you cant block not captains");
    }
    if(player.l_act!="steal"){
        throw("last action of player wasnt steal so cant block");
    }
    player.s_f.top()->s_coin+=MIN_ST;
    player.s_coin-=MIN_ST;
    this->l_act="block";
    

    }


void Captain::steal(Player &player){
    check_t();
    if(player.s_coin<1){
        throw(player.name + " dont have enogh money to steal");
    }
    if(player.s_coin==1){
        this->s_f.push(&player);
        this->s_coin+=1;
        player.s_coin-=1;
        l_act = "steal";
        this->gamei->next_t();
    }
    if(player.s_coin>1){
    this->s_f.push(&player);
    this->s_coin+=MIN_ST;
    player.s_coin-=MIN_ST;
    l_act = "steal";
    this->gamei->next_t();
    }
};