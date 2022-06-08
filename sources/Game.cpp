#include "Game.hpp"
constexpr int MAX_PLAYERS = 6;
constexpr int MIN_P = 1;

namespace coup{

Game::Game(){
    this->turn_p = "";
    this->player_am = 0;
    curr_t = 0;
    started = false;
};
Game::~Game(){};

vector <string> Game::players() const {
    vector <string> ans;
    for (size_t i = 0; i < playersim.size(); i++)
    {
        if(playersim_health.at(i)=="good"){
            ans.push_back(playersim.at(i));
        }
    }
    
    return ans;
};
 string Game::turn(){
    return playersim.at(curr_t);
};
 string Game::winner() const{
     if(winner_p.empty()){
         throw("GAme not Over");
     }
    return winner_p;
};
void Game::next_t(){
    started = true ;
    curr_t = (curr_t+1)%playersim.size();
    if(playersim_health.at(curr_t)!="good"){
        this->next_t();
    }
};


void Game::add_p(string const &ply){
    if(this->playersim.size()>=MAX_PLAYERS){
        throw invalid_argument("Already 6 players");
    }
    if(started){
        throw("cant add while started");
    }
    this->playersim.push_back(ply);
    this->playersim_health.push_back("good");
    player_am++;

};
void Game::player_rem(string const &name){
    for (size_t i = 0; i < playersim.size(); i++)
    {
        if(playersim.at(i)==name){
            playersim_health.at(i)="bad";
            player_am--;
            int ans = 0;
            int check =0;
            if(player_am==MIN_P){
                for (size_t j = 0; j < playersim.size(); j++)
                {
                    if(playersim_health.at(j)=="good"){
                        ans =j;
                        check++;
                        // winner_p = playersim.at(j);
                    }
                }
                if(check==1){
                    winner_p = playersim.at((size_t)ans);
                }
            }
            return;
            }
    }
    throw("player already dead");
}
void Game::revive(string const &name){
      for (size_t i = 0; i < playersim.size(); i++)
    {
        if((playersim.at(i)==name)&&(playersim_health.at(i)=="bad")){
            playersim_health.at(i)="good";
            player_am++;
            return;
            }
    }
    throw("already alive");
}
}