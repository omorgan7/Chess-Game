#ifndef piece_hpp
#define piece_hpp
#include<iostream>
#include<string>

#define WHITE -1
#define BLACK 1
#define ALIVE 1
#define OUT 0

using namespace std;

class piece {
    public:
        virtual bool move(int new_x, int new_y, piece **board)=0;
        void hello_piece_world(void);
        void score();        
        int get_x_coords();
        int get_y_coords();
        short getColour();
            string PieceName;
    private:

    protected:
        void state(int);
        int c_x;
        int c_y;
        int team_colour;
        int piece_value; 
        piece *chessboard;   
};

class queen: public piece{
    public:
        queen(int colour);
        void reset(void);
        bool move (int new_x, int new_y, piece **board);

};
class king: public piece{
    public:
        king(int colour);
        void reset(void);

        bool move(int new_x, int new_y, piece **board);
};
class bishop: public piece{
    public:
        bishop(int x_coord, int y_coord, int colour);
        bool move(int new_x, int new_y, piece **board);
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

    private:
        int is_initial ; 
   };
#endif 
