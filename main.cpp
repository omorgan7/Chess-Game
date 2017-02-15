#include <iostream>
#include <regex>

#include "game.hpp"

#define WHITE -1
#define BLACK 1

using namespace std;
int main(){
     cout<<"Welcome to text chess!\n";

    game G;
    G.display_board_state();
    while(1){
        cout<<"Player 1 (white) enter your move:\n";
        G.process_input(WHITE);
        if(G.CheckMate(WHITE) == 1){
            break;
        }
        G.display_board_state();    
        cout<<"Player 2 (black) enter your move:\n";
        G.process_input(BLACK);
        if(G.CheckMate(BLACK) == 1){
            break;
        }
    }

    return 0;
}