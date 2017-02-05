#include "piece.hpp"

void piece::hello_piece_world(void){
    cout<<"black = ♔♕♖♗♘♙\nwhite = ♚♛♜♝♞♟\n";
};



void pawn::move(int new_x, int new_y){

    if ((new_y<current_y)&&(current_x == new_x) && ((new_y) -1 == current_y)&&(current_y !=8)){
        return;
    }
    if ((new_y>current_y)&&(current_x == new_x) && (new_y +1 == current_y)&&(current_y !=1)){
        return;
    }
        cout<<"Invalid Move"<<'\n';
        return ;
};
king::king(){
  //  if WHITE {
        current_x= 4;
        current_y= 1;
    //return;
    //};
      //  current_x= 4;
        //current_y= 8;
};

void king::move( int new_x, int new_y){
    if (((current_x-new_x != 1)&&(current_x-new_x != -1))|((current_y-new_y != 1)&&(current_y-new_y != -1))){
            cout<<"Invalid Move"<<'\n';
    return;
    };
    if ((new_x <1)|(new_x >8)|(new_y<1)|(new_y>8)){
            cout<<"Invalid Move"<<'\n';
        return;
    };
        return;
};

 queen::queen(){
// if WHITE{
  current_x=5;
     current_y=1;
//     return;
//    };
//  current_x =5;
//     current_y=8;
 };


void queen::move(int new_x, int new_y){
    if ((new_x <1)|(new_x >8)|(new_y<1)|(new_y>8)){
                cout<<"Invalid Move"<<'\n';
            return;
    };
    if ((current_x - new_x !=0) && (current_y-new_y!=0)&&((current_x-new_x)*(current_x-new_x)!=(current_y-new_y)*(current_y-new_y))){
                cout<<"Invalid Move" << '\n';
            return;
        };
        return;
};

rook::rook(){
current_x=8;
current_y=1;
};

void rook::move(int new_x, int new_y){
    if ((current_x - new_x !=0) && (current_y-new_y!=0)){
        cout<<"Invalid Move"<<'\n';
        return;
    };
if ((new_x <1)|(new_x >8)|(new_y<1)|(new_y>8)){
            cout<<"Invalid Move"<<'\n';
        return;
    };
    return;
};

bishop::bishop(){
    current_x=3;
    current_y=1;
};

void bishop::move(int new_x, int new_y){
    if ((current_x - new_x !=0) && (current_y-new_y!=0)){
        cout<<"Invalid Move"<<'\n';
        return;
    };

    if ((current_x - new_x !=0) && (current_y-new_y!=0)&&((current_x-new_x)*(current_x-new_x)!=(current_y-new_y)*(current_y-new_y))){
            cout<<"Invalid Move" << '\n';
        return;
    };
    
    if (((current_x - new_x ==0) && (current_y-new_y!=0))|((current_x - new_x !=0) && (current_y-new_y!=0))){
            cout<<"Invalid Move" << '\n';
            return;
    };
    return;

};

