#ifndef piece_hpp
#define piece_hpp
#include<iostream>

#define WHITE -1
#define BLACK 1
#define ALIVE 1
#define OUT 0

using namespace std;

class piece {
    public:
        virtual bool move(int new_x, int new_y)=0;
    //methods
        void hello_piece_world(void);
        void score();        
        int get_x_coords();
        int get_y_coords();
        int getColor();
        piece(int x, int y);
    private:

    protected:
        void state(int);
        int current_x;
        int current_y;
        int team_colour;
        int piece_value; 
        piece *chessboard;   
};

class queen: public piece{
    public:
        queen(int colour, piece *board);
        void reset(void);
        bool move (int new_x, int new_y);

};
class king: public piece{
    public:
        king(int colour);
        void reset(void);

        bool move(int new_x, int new_y);
};
class bishop: public piece{
    public:
        bishop(int x_coord, int y_coord, int colour);
        bool move(int new_x, int new_y);
};
class knight: public piece{
    public:
        knight(int x_coord, int y_coord, int colour);
        bool move(int new_x, int new_y);
};
class rook: public piece{
    public:
        rook(int x_coord, int y_coord, int colour);
        bool move(int new_x, int new_y);    
};
class pawn: public piece{
    public:
        pawn(int x_coord, int y_coord, int colour);
        bool move(int new_x, int new_y);

    private:
        int is_initial ; 
   };
#endif 
