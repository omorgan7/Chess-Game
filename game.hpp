#ifndef game_hpp
#define game_hpp
#include<iostream>
#include<string>
#include<regex>
#include<list>

using namespace std;

//list of public and private member variables to go here.
class game {
    public:
        game();
        void display_board_state(void);
        void print_chessboard_line(string *statestring);
        bool process_input(int color);
        bool CheckMate(int color);
		bool update_board_state(string move, int colour);
		void reset();

    private:
        string white_pieces; 
        string white_pawns;
        string empty_line;
        string black_pieces;
        string black_pawns;

};



#endif // !game_hpp