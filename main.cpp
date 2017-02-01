#include <iostream>
#include "game.hpp"
#include "piece.hpp"

using namespace std;
int main(){
    //cout<<"hello chess world!\n";
    game G;
    piece P;
    cout<<"Welcome to text chess!\n";

    G.display_board_state();
    
    return 0;
}