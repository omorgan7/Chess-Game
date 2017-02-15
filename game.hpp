#ifndef game_hpp
#define game_hpp
#include<iostream>
#include<string>
#include<regex>
#include<vector>

using namespace std;

//list of public and private member variables to go here.
class game {
    public:
        game();
        void display_board_state(void);
        void print_chessboard_line(string *statestring);
        void process_input(int color);
        bool Check(int color);
        bool CheckMate(int color);
        bool SearchKingSpace(void);
	bool update_board_state(string move, int colour);
        void initialiseKingPosition(void);
        bool CanBeKilled(int index);
        bool CanBeBlocked(int index);
	void reset();

    private:
        string white_pieces; 
        string white_pawns;
        string empty_line;
        string black_pieces;
        string black_pawns;
        int black_king_index;
        int white_king_index;
        int king_index;

};



#endif // !game_hpp