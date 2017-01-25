#include <iostream>
#include "game.hpp"
#include "piece.hpp"

using namespace std;
int main(){
    cout<<"hello chess world!\n";
    game G;
    piece P;
    G.hello_game_world();
    P.hello_piece_world();
    return 0;
}