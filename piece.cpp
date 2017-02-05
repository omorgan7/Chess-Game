#include "piece.hpp"

void piece::hello_piece_world(void){
    cout<<"black = ♔♕♖♗♘♙\nwhite = ♚♛♜♝♞♟\n";
};


pawn::pawn(){
    current_x = 0;
    current_y=1;
    is_initial=1;
};
void pawn::move(int new_x, int new_y){
     if (is_initial ==1){
        if ((new_x == current_x)&&((new_y==current_y+1)|(new_y=current_y+2))){
            current_x=new_x;
            current_y=new_y;
            is_initial=0;
        return;
        };
    };
    if ((new_x == current_x)&&(new_y==current_y+1)){
        current_x=new_x;
        current_y=new_y;
        return;
    }
    cout<<"Invalid Move"<<'\n';
    return;
    };

king::king(){
  //  if WHITE {
        current_x= 3;
        current_y= 0;
    //return;
    //};
      //  current_x= 3;
        //current_y= 7;
};

void king::move( int new_x, int new_y){
    if (((current_x-new_x != 1)&&(current_x-new_x != -1))|((current_y-new_y != 1)&&(current_y-new_y != -1))){
            cout<<"Invalid Move"<<'\n';
    return;
    };
    if ((new_x <0)|(new_x >7)|(new_y<0)|(new_y>7)){
            cout<<"Invalid Move"<<'\n';
        return;
    };
    current_x=new_x;
    current_y=new_y;
        return;
};

 queen::queen(){
// if WHITE{
  current_x=4;
     current_y=0;
//     return;
//    };
//  current_x =4;
//     current_y=7;
 };


void queen::move(int new_x, int new_y){
    if ((new_x <0)|(new_x >7)|(new_y<0)|(new_y>7)){
                cout<<"Invalid Move"<<'\n';
            return;
    };
    if ((current_x - new_x !=0) && (current_y-new_y!=0)&&((current_x-new_x)*(current_x-new_x)!=(current_y-new_y)*(current_y-new_y))){
                cout<<"Invalid Move" << '\n';
            return;
        };
            current_x=new_x;
            current_y=new_y;
        return;
};

rook::rook(){
current_x=7;
current_y=0;
};

void rook::move(int new_x, int new_y){
    if ((current_x - new_x !=0) && (current_y-new_y!=0)){
        cout<<"Invalid Move"<<'\n';
        return;
    };
    if ((new_x <0)|(new_x >7)|(new_y<1)|(new_y>8)){
            cout<<"Invalid Move"<<'\n';
        return;
    };
        current_x=new_x;
        current_y=new_y;
    return;
};

bishop::bishop(){
    current_x=2;
    current_y=0;
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
      current_x=new_x;
      current_y=new_y;
    return;
};

knight::knight(){
    current_x = 1;
    current_y=0;
};

void knight::move(int new_x, int new_y){
    if ((new_x <0)|(new_x >7)|(new_y<0)|(new_y>7)){
            cout<<"Invalid Move"<<'\n';
        return;
    };
    if ((new_x == current_x - 1)&&((new_y == current_y -2)|(new_y == current_y+2))){
            current_x=new_x;
            current_y=new_y;
        return;
    }  ;
    if ((new_x == current_x - 2)&&((new_y == current_y -1)|(new_y == current_y+1))){
            current_x=new_x;
            current_y=new_y;
        return;
    };
    if ((new_x == current_x + 1)&&((new_y == current_y -2)|(new_y == current_y+2))){
            current_x=new_x;
            current_y=new_y;
        return;
    }  ;
    if ((new_x == current_x + 2)&&((new_y == current_y -1)|(new_y == current_y+1))){
            current_x=new_x;
            current_y=new_y;
        return;
    };
    cout<<"Invalid Move"<<'\n';
    return;
    };

