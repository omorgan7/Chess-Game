#include <iostream>
#include <regex>

#include "game.hpp"

#define WHITE -1
#define BLACK 1

using namespace std;
int main(){
    game G;
    while(1){
        cout<<"Welcome to text chess!\nType QUIT to end the game immediately.\n";
        G.display_board_state();
        while(1){
            cout<<"Player 1 (White) enter your move:\n";
            if(G.process_input(WHITE) == 0){
                return EXIT_SUCCESS;
            }
            G.display_board_state();
            if(G.Check(BLACK) == 1){
                cout<<"Black is in check.\n";
                if(G.CheckMate(BLACK)==1){
                    cout<<"Checkmate for Black. Game over.\n";
                    G.reset();
                    break;
                }
            }    
            cout<<"Player 2 (Black) enter your move:\n";
            if(G.process_input(BLACK) == 0){
                return EXIT_SUCCESS;
            }
            G.display_board_state();
            if(G.Check(WHITE) == 1){
                cout<<"White is in check.\n";
                if(G.CheckMate(WHITE)==1){
                    cout<<"Checkmate for White. Game over.\n";
                    G.reset();
                    break;
                }
            }      
        }
    }


    return 0;
}