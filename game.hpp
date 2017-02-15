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
        void process_input(int color);
        bool Check(int color);
        bool CheckMate(int color);
        bool SearchKingSpace(int color);
        bool update_board_state(string move, int colour);
        void initialiseKingPosition(void);
        void initialiseScore(void);
        void reset();
        bool check_lineof_sight(int colour);
        bool check_knights(int colour);
        void score(int colour, int index);

    private:
        string white_pieces; 
        string white_pawns;
        string empty_line;
        string black_pieces;
        string black_pawns;
        int black_king_index;
        int white_king_index;
        int king_index;
        int white_score;
        int black_score;

};



#endif // !game_hpp