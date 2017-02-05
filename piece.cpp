#include "piece.hpp"
#include <iostream>
#include <cmath>
////////////////////////////////////
//Piece Class
void piece::hello_piece_world(void){
    cout<<"black = ♔♕♖♗♘♙\nwhite = ♚♛♜♝♞♟\n";
};

int piece::get_x_coords(void){
    return current_x;
}
int piece::get_y_coords(void){
    return current_y;
}

short piece::getColour(void){
    return team_colour;
}
/////////////////////////////////////////
//PAWN CLASS
pawn::pawn(int x_coord, int y_coord, int colour){
    current_x = x_coord;
    current_y=y_coord;
    team_colour = colour;
    is_initial=1;
    if (team_colour == WHITE){
        PieceName = "WP";
    return;
    }
     PieceName = "BP";
};
bool pawn::move(int new_x, int new_y, piece *board){  
    if (chessboard[new_x + 8*new_y] ! = nullptr){
        if (board[new_x + 8*new_y] -> getColour()==team_colour){
        return 0;
        }
            if ((abs(new_x - current_x)==1)&&((new_y-current_y)!=1*team_colour)){
                return 0;
            }
            current_x=new_x;
            current_y=new_y;
        return 1;
    }
   if (is_initial ==1){
        if ((new_x == current_x)&&((new_y==current_y+1*team_colour)|(new_y==current_y+2*team_colour))){
            current_x=new_x;
            current_y=new_y;
            is_initial=0;
            return 1;
        };
    };

    if ((new_x == current_x)&&((new_y-current_y)=1*team_colour)){
        current_x=new_x;
        current_y=new_y;
        return 1;
    };
};
/////////////////////////////////
//King Class
king::king(int colour){
    team_colour=colour;
    is_alive = ALIVE;
    if(team_colour== WHITE){
        current_x= 3;
        current_y= 0;
        PieceName = "WK";
        return;
    };
        current_x= 3;
        current_y= 7;
        PieceName = "BK";
};
bool king::move( int new_x, int new_y, piece *board){
         if (board[new_x + 8*new_y] ! = nullptr){
            if (board[new_x + 8*new_y]->getColour()==team_colour){
                return 0;
            }
         }    
        if (((current_x-new_x != 1)&&(current_x-new_x != -1))|((current_y-new_y != 1)&&(current_y-new_y != -1))){
            return 0;
        };
    current_x=new_x;
    current_y=new_y;
    return 1;
};

///////////////////////////
//Queen Class

queen::queen(int colour){
    team_colour=colour;
    if (colour==WHITE){
        current_x=4;
        current_y=0;
        PieceName="WQ";
        return;
   };
    current_x =4;
    current_y=7;
    PieceName = "BQ";
};
bool queen::move(int new_x, int new_y, piece *board){
    if (board[new_x + 8*new_y] ! = nullptr){
            if (board[new_x + 8*new_y] -> getColour()==team_colour){
                return 0;
            }
    }
    for (auto i = current_x + 8*current_y, auto i = new_x + 8*new_y, current_x + 8*current_y < new_x + 8*new_y) ? i++ : i--){
        if (board[i] ! = nullptr){
            return 0;
        }
    }
        if ((current_x - new_x !=0) && (current_y-new_y!=0)&&((abs(current_x-new_x))!=(abs(current_y-new_y)))){
            return 0;
        };
    current_x=new_x;
    current_y=new_y;
    return 1;
};
////////////////////////
//Rook Class
rook::rook(int x_coord, int y_coord, int colour){
    current_x=x_coord;
    current_y=y_coord;
    team_colour = colour;
    if (team_colour==WHITE){
        PieceName="WR";
        return;
    }
    PieceName = "BR";
};
bool rook::move(int new_x, int new_y, piece *board){
    if (board[new_x + 8*new_y] ! = nullptr){
            if (board[new_x + 8*new_y] -> getColour()==team_colour){
                return 0;
            }
    }
     for (auto i = current_x + 8*current_y, auto i = new_x + 8*new_y, current_x + 8*current_y < new_x + 8*new_y) ? i++ : i--){
            if (board[i] ! = nullptr){
                return 0;
            }
    }  
     
    } 
    if ((current_x - new_x !=0) && (current_y-new_y!=0)){
        return 0;
    };
    current_x=new_x;
    current_y=new_y;
    return 1;
};
//////////////////////
//Bishop Class
bishop::bishop(int x_coord, int y_coord, int colour){
    current_x=x_coord;
    current_y=y_coord;
    team_colour=colour;
    if (team_colour==WHITE){
        PieceName = "WB";
        return;
    }
    PieceName ="BB";
};
bool bishop::move(int new_x, int new_y, piece *board){
    if (board[new_x + 8*new_y] ! = nullptr){
            if (board[new_x + 8*new_y] -> getColour()==team_colour){
                return 0;
            }
    }
    for (auto i = current_x + 8*current_y, auto i = new_x + 8*new_y, current_x + 8*current_y < new_x + 8*new_y) ? i++ : i--){
        if (board[i] ! = nullptr){
            return 0;
        }
    }
    if ((current_x - new_x !=0) && (current_y-new_y!=0)){
        return 0;
    };
    if ((current_x - new_x !=0) && (current_y-new_y!=0)&&(abs(current_x-new_x)!=abs(current_y-new_y))){
        return 0;
    };    
    if (((current_x - new_x ==0) && (current_y-new_y!=0))|((current_x - new_x !=0) && (current_y-new_y!=0))){
        return 0;
    };
    current_x=new_x;
    current_y=new_y;
    return 1;
};
/////////////////
//Knight Class
knight::knight(int x_coord, int y_coord, int colour){
    current_x = x_coord;
    current_y=y_coord;
    team_colour = colour;
    if (team_colour==WHITE){
        PieceName = "WN";
        return;
    }
    PieceName = "BN";
};
bool knight::move(int new_x, int new_y, piece *board){  
    if (board[new_x + 8*new_y] ! = nullptr){
            if (board[new_x + 8*new_y] -> getColour()==team_colour){
                return 0;
            }
    }
    for (auto i = current_x + 8*current_y, auto i = new_x + 8*new_y, current_x + 8*current_y < new_x + 8*new_y) ? i++ : i--){
        if (board[i] ! = nullptr){
            return 0;
        }
    }
    if ((new_x == current_x - 1)&&((new_y == current_y -2)|(new_y == current_y+2))){
            current_x=new_x;
            current_y=new_y;
        return 1;
    }  ;
    if ((new_x == current_x - 2)&&((new_y == current_y -1)|(new_y == current_y+1))){
            current_x=new_x;
            current_y=new_y;
        return 1;
    };
    if ((new_x == current_x + 1)&&((new_y == current_y -2)|(new_y == current_y+2))){
            current_x=new_x;
            current_y=new_y;

        return 1;
    }  ;
    if ((new_x == current_x + 2)&&((new_y == current_y -1)|(new_y == current_y+1))){
            current_x=new_x;
            current_y=new_y;
        return 1;
    };

    return 0;
}; 

