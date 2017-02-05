#include "piece.hpp"
#include <iostream>     // std::cout
#include <cmath>

void piece::hello_piece_world(void){
    cout<<"black = ♔♕♖♗♘♙\nwhite = ♚♛♜♝♞♟\n";
};

int piece::get_x_coords(void){
    return current_x;
}
int piece::get_y_coords(void){
    return current_y;
}
pawn::pawn(int x_coord, int y_coord, int colour){
    current_x = x_coord;
    current_y=y_coord;
    team_colour = colour;
    is_initial=1;
};
void pawn::move(int new_x, int new_y){
    if (is_initial ==1){
        if ((new_x == current_x)&&((new_y==current_y+1*team_colour)|(new_y==current_y+2*team_colour))){
            current_x=new_x;
            current_y=new_y;
            is_initial=0;
        return;
        };
    };
    if ((new_x == current_x)&&(new_y==current_y+1*team_colour)){
        current_x=new_x;
        current_y=new_y;
        return;
    };
    cout<<"Invalid Move"<<'\n';
    return;
};

king::king(int colour){
    team_colour=colour;
    if(team_colour== WHITE){
        current_x= 3;
        current_y= 0;
        return;
    };
        current_x= 3;
        current_y= 7;
};

void king::move( int new_x, int new_y){
    if (((current_x-new_x != 1)&&(current_x-new_x != -1))|((current_y-new_y != 1)&&(current_y-new_y != -1))){
            cout<<"Invalid Move"<<'\n';
            return;
    };
    current_x=new_x;
    current_y=new_y;
    return;
};


queen::queen(int colour){
    team_colour=colour;
    if (colour==WHITE){
        current_x=4;
        current_y=0;
        return;
    };
    current_x =4;
    current_y=7;
};


void queen::move(int new_x, int new_y){
    if ((current_x - new_x !=0) && (current_y-new_y!=0)&&((abs(current_x-new_x))!=(abs(current_y-new_y)))){
            cout<<"Invalid Move" << '\n';
        return;
    };
    current_x=new_x;
    current_y=new_y;
    return;
};

rook::rook(int x_coord, int y_coord, int colour){
    current_x=x_coord;
    current_y=y_coord;
    team_colour = colour;
};

void rook::move(int new_x, int new_y){
    if ((current_x - new_x !=0) && (current_y-new_y!=0)){
        cout<<"Invalid Move"<<'\n';
        return;
    };
    current_x=new_x;
    current_y=new_y;
    return;
};

bishop::bishop(int x_coord, int y_coord, int colour){
    current_x=x_coord;
    current_y=y_coord;
    team_colour=colour;
};

void bishop::move(int new_x, int new_y){
    if ((current_x - new_x !=0) && (current_y-new_y!=0)){
        cout<<"Invalid Move"<<'\n';
        return;
    };
    if ((current_x - new_x !=0) && (current_y-new_y!=0)&&(abs(current_x-new_x)!=abs(current_y-new_y))){
            cout<<"Invalid Move" << '\n';
        return;
    };    
    if (((current_x - new_x ==0) && (current_y-new_y!=0))|((current_x - new_x !=0) && (current_y-new_y!=0))){
            cout<<"Invalid Move" << '\n';
            return;
    };
      current_x=new_x;
      current_y=new_y;
    return;
};

knight::knight(int x_coord, int y_coord, int colour){
    current_x = x_coord;
    current_y=y_coord;
    team_colour = colour;
};

void knight::move(int new_x, int new_y){
  
    if((new_x == current_x - 1)&&((new_y == current_y -2)|(new_y == current_y+2))){
            current_x=new_x;
            current_y=new_y;
        return;
    };
    if ((new_x == current_x - 2)&&((new_y == current_y -1)|(new_y == current_y+1))){
            current_x=new_x;
            current_y=new_y;
        return;
    };
    if ((new_x == current_x + 1)&&((new_y == current_y -2)|(new_y == current_y+2))){
            current_x=new_x;
            current_y=new_y;
        return;
    };
    if ((new_x == current_x + 2)&&((new_y == current_y -1)|(new_y == current_y+1))){
            current_x=new_x;
            current_y=new_y;
        return;
    };
    cout<<"Invalid Move"<<'\n';
    return;
};
    
    
