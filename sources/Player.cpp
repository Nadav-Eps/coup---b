#include "Player.hpp"
#include "Game.hpp"
using namespace coup;
using namespace std;
constexpr int MAX_M = 10;
constexpr int COUP_M = 7;


Player::Player(Game &g, string nm):gamei(&g), s_coin(0){
      this->name = std::move(nm);
      this->role_p = "";
      this->l_act = "";
      this->life = true;
      
    }


Player::~Player(){};

void Player::income(){
check_t();
this->s_coin++;
this->l_act = "income";
this->gamei->next_t();
};

void Player::foreign_aid(){
check_t();
this->s_coin++;
this->s_coin++;
this->l_act = "forgein_aid";
this->gamei->next_t();
};

void Player::coup(Player &player){
check_t_c();
if(this->s_coin<COUP_M){
    throw("not enough money to coup");
}
for (size_t i = 0; i < gamei->playersim.size(); i++)
    {
        if(gamei->playersim.at(i)==player.name){
            if(gamei->playersim_health.at(i)!="good"){
                throw(player.name + " already dead");
            }
        }
    }
gamei->player_rem(player.name);
this->s_coin-=COUP_M;
this->l_act = "coup";
this->gamei->next_t();
};

string Player::role() const{
    return role_p;
};

int Player::coins() const{
    return s_coin;
};


void Player::add_coin(Player &pl){

}

void Player::check_t() const{
if(this->gamei->playersim_health.at(gamei->curr_t)!="good"){
    gamei->next_t();
} 
if (gamei->players().size()<2){
    throw("need more players to play the game");
}
if(gamei->turn()!= this->name){
    throw("Its not yor turn");
}
if(this->s_coin>MAX_M){
    throw("Youve reached the max money , you gonna have to coup");
}
};
void Player::check_t_b() const{
if(this->gamei->playersim_health.at(gamei->curr_t)!="good"){
    throw("you are dead!");
} 
if (gamei->players().size()<2){
    throw("need more players to play the game");
}
};
void Player::check_t_c() const{
if (gamei->players().size()<2){
    throw("need more players to play the game");
}

if(gamei->turn()!= this->name){
    throw("Its not yor turn");
}
};