#ifndef game_hpp
#define game_hpp
#include<iostream>
#include<string>
#include <codecvt>
#include <locale>

using namespace std;

//list of public and private member variables to go here.
class game {
    public:
        void display_board_state(void);
        void print_chessboard_line(u32string *statestring);

    private:
        u32string white_pieces; 
        u32string white_pawns;
        u32string empty_line;
        u32string black_pieces;
        u32string black_pawns;
};



#endif // !game_hpp