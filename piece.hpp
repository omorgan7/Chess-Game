#ifndef piece_hpp
#define piece_hpp
#include<iostream>

#define WHITE 0;
#define BLACK 1;
#define ALIVE 1;
#define OUT 0;

using namespace std;

class piece {
    public:
        virtual void move(int new_x, int new_y)=0;
    //methods
        void hello_piece_world(void);
        void check_alive();
        void score();        
        // virtual void get_x_coords()=0;
        // virtual void get_y_coords()=0;
    private:

    protected:
        void state(int);
        int current_x;
        int current_y;
        bool is_alive;

};
//list of public and private member variables to go here.

class queen:piece{
    public:
    queen();
    void move (int new_x, int new_y);
};
class king:piece{
    public:
    king();
    void move(int new_x, int new_y);
};
class bishop:piece{
    public:
    bishop();
    void move(int new_x, int new_y);
};
class knight:piece{
    public:
    knight();
    void move(int new_x, int new_y);
};
class rook:piece{
    public:
    rook();
        void move(int new_x, int new_y);    
};
class pawn:piece{
    public:
    pawn();
        void move(int new_x, int new_y);
    private:
    int is_initial ; 
   };
#endif 
