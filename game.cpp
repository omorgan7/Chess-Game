#include "game.hpp"

void game::display_board_state(void){
    //Temporary function to display the initial state of the board_state
    //should be replaced with superior class that reads the state from some series of variables
    //this function MUST be rewritten.
    string letters = "    a   b   c   d   e   f   g   h";
    cout<<letters<<"\n";
    white_pieces = U"♖♘♗♔♕♗♘♖";
    white_pawns = U"♙♙♙♙♙♙♙♙";
    empty_line = U"        ";
    black_pieces = U"♜♞♝♚♛♝♞♜";
    black_pawns = U"♟♟♟♟♟♟♟♟";
    auto count = 0;
    cout<<++count<<" ";
    print_chessboard_line(&white_pieces);
    cout<<++count<<" ";
    print_chessboard_line(&white_pawns);
    for(auto i = 0; i<4; i++){
        cout<<++count<<" ";
        print_chessboard_line(&empty_line);
    }
    cout<<++count<<" ";
    print_chessboard_line(&black_pawns);  
   
    cout<<++count<<" ";
    print_chessboard_line(&black_pieces);
}

void game::print_chessboard_line(u32string *stateString){
    wstring_convert<codecvt_utf8<char32_t>,char32_t> converter;
    for(char32_t c: *stateString){
        cout<<"| "<<converter.to_bytes(c)<<" ";
    }
    cout<<"|\n";
}
