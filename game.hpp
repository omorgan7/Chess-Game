#ifndef game_hpp
#define game_hpp
#include<iostream>
#include<string>

using namespace std;

//list of public and private member variables to go here.
class game {
    public:
        void display_board_state(void);
        void print_chessboard_line(string *statestring);

    private:
        string white_pieces; 
        string white_pawns;
        string empty_line;
        string black_pieces;
        string black_pawns;
};



#endif // !game_hpp