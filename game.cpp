#include "game.hpp"

void game::display_board_state(void){
    //Temporary function to display the initial state of the board_state
    //should be replaced with superior class that reads the state from some series of variables
    //this function MUST be rewritten.
    string letters = "    a    b    c    d    e    f    g    h";
    cout<<letters<<"\n";
    white_pieces = "WRWNWBWKWQWBWNWR";
    white_pawns = "WPWPWPWPWPWPWPWP";
    empty_line = "                ";
    black_pieces = "BRBNBBBKBQBBBNBR";
    black_pawns = "BPBPBPBPBPBPBPBP";
    auto count = 0;
    cout<<++count<<" ";
    print_chessboard_line(&black_pieces);
    cout<<++count<<" ";
    print_chessboard_line(&black_pawns);
    for(auto i = 0; i<4; i++){
        cout<<++count<<" ";
        print_chessboard_line(&empty_line);
    }
    cout<<++count<<" ";
    print_chessboard_line(&white_pawns);  
   
    cout<<++count<<" ";
    print_chessboard_line(&white_pieces);
}

void game::print_chessboard_line(string *stateString){
    for(auto it = stateString->begin(); it!=stateString->end(); it++){
        cout<<"| "<<*it;
        it++;
        cout<<*it<<" ";
    }
    cout<<"|\n";
}
