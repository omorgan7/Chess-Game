#ifndef piece_hpp
#define piece_hpp
#include<iostream>
#include<string>

#define WHITE -1
#define BLACK 1
#define ALIVE 1
#define OUT 0
#define pawn_value 1
#define rook_value 5
#define knight_value 3
#define bishop_value 3
#define queen_value 9
#define queenside -4
#define kingside 3


using namespace std;

class piece {
    public:
        virtual bool move(int new_x, int new_y, piece **board)=0;
        void hello_piece_world(void);      
        int get_x_coords(void);
        int get_y_coords(void);
        int get_piece_type(void);
        int get_piece_value(void);
        short getColour(void);
        void basic(int x_coord, int y_coord, int colour);
        string PieceName;
        int get_is_initial(void);
        int line_search_diagonal(int new_x, int new_y, piece **board);
        // int line_search_straight();
        int space_free(int new_x, int new_y, piece **board);
    private:
    protected:
        void state(int);
        int c_x;
        int c_y;
        int team_colour;
        int piece_value; 
        int piece_type;
        piece *chessboard; 
        int is_initial;  
};

class queen: public piece{
    public:
        queen(int x_coord, int y_coord, int colour);
        void reset(void);
        bool move (int new_x, int new_y, piece **board);
        int line_search_diagonal(int new_x, int new_y, piece **board);

};
class king: public piece{
    public:
        king(int x_coord, int y_coord, int colour);
        void reset(void);
        bool move(int new_x, int new_y, piece **board);
        bool castling(piece **board, int side);
};
class bishop: public piece{
    public:
        bishop(int x_coord, int y_coord, int colour);
        bool move(int new_x, int new_y, piece **board);
        int line_search_diagonal(int new_x, int new_y, piece **board);
};
class knight: public piece{
    public:
        knight(int x_coord, int y_coord, int colour);
        bool move(int new_x, int new_y, piece **board);
};
class rook: public piece{
    public:
        rook(int x_coord, int y_coord, int colour);
        bool move(int new_x, int new_y, piece **board);  
};
class pawn: public piece{
    public:
        pawn(int x_coord, int y_coord, int colour);
        bool move(int new_x, int new_y, piece **board);
        bool en_passant(int new_x, int new_y, piece **board);
        bool initial_move(int new_x, int new_y, piece **board);
   };
#endif 
