#include "Ambassador.hpp"
#include "Game.hpp"
using namespace std;
// using namespace coup;
constexpr int STEAL_MONEY = 2;

namespace coup{
Ambassador::Ambassador(Game &g,const string & nm):Player(g,nm){
    this->role_p = "Ambassador";
    g.add_p(nm);
}
Ambassador::~Ambassador(){};

void Ambassador::block(Player &player){
    check_t_b();
    if((player.l_act=="steal")&&(player.role()=="Captain")){
        player.s_coin-=STEAL_MONEY;
        player.s_f.top()->s_coin+=STEAL_MONEY;
    }
    else{
        throw("Last action of" + player.name + " wasnt steal");
    }
};
void Ambassador::transfer(Player &player , Player &player2){
    check_t();
    if(player.s_coin<1){
        throw(player.name + " dont have enogh money to tranfer");
    }
    player.s_coin-=1;
    player2.s_coin+=1;
    this->l_act = "transfer";
    gamei->next_t();

};
}