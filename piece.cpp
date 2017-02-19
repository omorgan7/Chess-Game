#include "piece.hpp"
#include <iostream>
#include <cmath>
////////////////////////////////////
//Piece Class
void piece::hello_piece_world(void){
    cout<<"black = ♔♕♖♗♘♙\nwhite = ♚♛♜♝♞♟\n";
};

int piece::get_x_coords(void){
    return c_x;
}
int piece::get_y_coords(void){
    return c_y;
}
short piece::getColour(void){
    return team_colour;
}
int piece::get_piece_value(void){
    return piece_value;
}
int piece::get_is_initial(void){
    return is_initial;
}
int piece::space_free(int new_x, int new_y, piece **board){
    if (board[new_x + 8*new_y] == nullptr){
        return 1;
    }
    if (board[new_x + 8*new_y] -> getColour()==team_colour){
        return 0;
    }
    return -1;
}
int piece::line_search_diagonal(int new_x, int new_y, piece **board){
    auto it = 8*pow(-1,new_y>c_y);
    it = it+pow(-1,new_x<c_x);        
    for (auto i = c_x + 8*c_y; i != new_x + 8*new_y; i+=it){
        if (board[i] != nullptr){
            return 0;
        }
    }
    return 1;
}
void piece::basic(int x_coord, int y_coord,int colour){
    c_x = x_coord;
    c_y=y_coord;
    team_colour = colour;
    is_initial=1;
}
void piece::not_initial(void){
    is_initial=0;
}
/////////////////////////////////////////
//Pawn Class
pawn::pawn(int x_coord, int y_coord, int colour){
    basic(x_coord,y_coord, colour);
        piece_value = pawn_value;
    if (team_colour == WHITE){
        PieceName = "WP";
    return;
    }
    PieceName = "BP";
};
bool pawn::initial_move(int new_x, int new_y, piece **board){ 
    if (is_initial!=1){
        return 0;
    }  
     if ((new_x == c_x)&&((new_y==c_y+1*team_colour)|(new_y==c_y+2*team_colour))){
            is_initial=0;
            return 1;
    }
    return 0;
}
bool pawn::move(int new_x, int new_y, piece **board){  
    if (board[new_x + 8*new_y] != nullptr){    
        if (board[new_x + 8*new_y] -> getColour()==team_colour){
            return 0;
        }    
        if ((abs(new_x - c_x)==1)&&((new_y-c_y)==(1*team_colour))){
            return 1;
        }
        return 0;
    }

    if (is_initial==1){
        if ((new_x == c_x)&&(((new_y-c_y)==(1*team_colour))|((new_y-c_y)==(2*team_colour)))){
            return 1;
        }
        return 0;
    }
    if ((new_x == c_x)&&((new_y-c_y)==(1*team_colour))){
        return 1;
    }
    return 0;
}
bool pawn::en_passant(int new_x, int new_y, piece **board){
    if((new_x = c_x)&&(new_y = c_y + team_colour)){}
    return 0;
}

/////////////////////////////////
//King Class
king::king(int x_coord, int y_coord, int colour){
    basic(x_coord,y_coord, colour);
    if(team_colour== WHITE){
        PieceName = "WK";
    return;
    };
        PieceName = "BK";
};
// bool king::castling(piece **board, int side){
//     int index = c_x+8*c_y;
//     int new_pos;
//     if (side==queenside){
//         int new_pos = index - 2;
//     }
//     else{
//         int new_pos = index + 2;
//     }
//     if ((board[index]->get_is_initial() == 0)|(board[index+side]->get_is_initial() == 0)|(board[new_pos]!=nullptr)){
//         return 0;
//     }
//     return 1;
// }
bool king::move( int new_x, int new_y, piece **board){
    if (board[new_x + 8*new_y] != nullptr){
        if (board[new_x + 8*new_y] -> getColour()==team_colour){
            return 0;
        }
        if((abs(c_x-new_x)<2)&& (abs(c_y-new_y)<2)){
            return 1;
        }
        return 0;
    }
    if((abs(c_x-new_x)<2)&& (abs(c_y-new_y)<2)){
        return 1;
    }
    return 0;
}

///////////////////////////
//Queen Class

queen::queen(int x_coord, int y_coord,int colour){
   basic(x_coord,y_coord, colour);
    piece_value = queen_value;
    if (colour==WHITE){
        PieceName="WQ";
        return;
   }
    PieceName = "BQ";
}

bool queen::move(int new_x, int new_y, piece **board){
    if (board[new_x + 8*new_y] != nullptr){
        if (board[new_x + 8*new_y] -> getColour()==team_colour){
            return 0;
        }
        if ((new_x==c_x)|(new_y==c_y)){
            int it =(new_x==c_x)*8*pow(-1, new_y<c_y)+(new_y==c_y)*pow(-1, new_x<c_x);
            for (int i = c_x + 8*c_y+it; i != new_x + 8*new_y; i+=it){
                if (board[i] != nullptr){
                    return 0;
                }
            } 
            return 1;
        }
        if (((abs(c_x + 8*c_y -  new_x - 8*new_y))%7==0)|((abs(c_x + 8*c_y -  new_x - 8*new_y))%9==0)){
            int it = 8*pow(-1,new_y<c_y);
            it = it+pow(-1,new_x<c_x); 
            for (int i = c_x + 8*c_y+it; i != new_x + 8*new_y; i+=it){
                if (board[i] != nullptr){
                    return 0;
                }
            } 
                return 1;  
        }
            return 0;
    }

    if ((new_x==c_x)|(new_y==c_y)){
        int it =(new_x==c_x)*8*pow(-1, new_y<c_y)+(new_y==c_y)*pow(-1, new_x<c_x);
            for (int i = c_x + 8*c_y+it; i != new_x + 8*new_y; i+=it){
                if (board[i] != nullptr){
                    return 0;
                }
            }
            return 1;  
        }
    if (((abs(c_x + 8*c_y -  new_x - 8*new_y))%7==0)|((abs(c_x + 8*c_y -  new_x - 8*new_y))%9==0)){
        int it = 8*pow(-1,new_y<c_y);
        it = it+pow(-1,new_x<c_x); 
        for (auto i = c_x + 8*c_y+it; i != new_x + 8*new_y; i+=it){
            if (board[i] != nullptr){
                return 0;
            }
        } 
        return 1;  
    }
    return 0;
}
////////////////////////
//Rook Class
rook::rook(int x_coord, int y_coord, int colour){
    basic(x_coord,y_coord, colour);
    piece_value = rook_value;
    if (team_colour==WHITE){
        PieceName="WR";
        return;
    }
    PieceName = "BR";
};
bool rook::move(int new_x, int new_y, piece **board){
    if (board[new_x + 8*new_y] != nullptr){
        if (board[new_x + 8*new_y] -> getColour()==team_colour){
            return 0;
        }  
        if (((new_x==c_x)&&(new_y!=c_y))|((new_y==c_y)&&(new_x!=c_x))){
            int it =(new_x==c_x)*8*pow(-1, new_y<c_y)+(new_y==c_y)*pow(-1, new_x<c_x);
            for (auto i = c_x + 8*c_y+it; i != new_x + 8*new_y; i+=it){
                if (board[i] != nullptr){
                    return 0;
                }
            } 
            return 1;
        }
        return 0;
    }
    if (((new_x==c_x)&&(new_y!=c_y))|((new_y==c_y)&&(new_x!=c_x))){
        int it =(new_x==c_x)*8*pow(-1, new_y<c_y)+(new_y==c_y)*pow(-1, new_x<c_x);
        for (auto i = c_x + 8*c_y+it; i != new_x + 8*new_y; i+=it){
            if (board[i] != nullptr){
                return 0;
            }
        }
        return 1;
    }
    return 0;
}
//////////////////////
//Bishop Class
bishop::bishop(int x_coord, int y_coord, int colour){
   basic(x_coord,y_coord, colour);
    piece_value = bishop_value;
    if (team_colour==WHITE){
        PieceName = "WB";
        return;
    }
    PieceName ="BB";
};
bool bishop::move(int new_x, int new_y, piece **board){   
    if (board[new_x + 8*new_y] != nullptr){
        if (board[new_x + 8*new_y] -> getColour()==team_colour){
            return 0;
        }
        if (((abs(c_x + 8*c_y -  new_x - 8*new_y))%7==0)|((abs(c_x + 8*c_y -  new_x - 8*new_y))%9==0)){
            int it = 8*pow(-1,(new_y<c_y));
            it = it+pow(-1,(new_x<c_x));      
            for (auto i = c_x + 8*c_y+it; i != new_x + 8*new_y; i+=it){
                if (board[i] != nullptr){
                    return 0;
                }
            }
            return 1;
        }
        return 0;
    }
    if (((abs(c_x + 8*c_y -  new_x - 8*new_y))%7==0)|((abs(c_x + 8*c_y -  new_x - 8*new_y))%9==0)){
        int it = 8*pow(-1,new_y<c_y);
        it = it+pow(-1,new_x<c_x); 
        for (auto i = c_x + 8*c_y+it; i != new_x + 8*new_y; i+=it){
            if (board[i] != nullptr){
                return 0;
            }
        }
        return 1;
    }   
    return 0;
};


/////////////////
//Knight Class
knight::knight(int x_coord, int y_coord, int colour){
  basic(x_coord,y_coord, colour);
    piece_value = knight_value ;
    if (team_colour==WHITE){
        PieceName = "WN";
        return;
    }
    PieceName = "BN";
};
bool knight::move(int new_x, int new_y, piece **board){  
    if (board[new_x + 8*new_y] != nullptr){
            if (board[new_x + 8*new_y] -> getColour()==team_colour){
                return 0;
            }
    }

    if ((new_x == c_x - 1)&&((new_y == c_y -2)|(new_y == c_y+2))){
        return 1;
    }  ;
    if ((new_x == c_x - 2)&&((new_y == c_y -1)|(new_y == c_y+1))){
        return 1;
    };
    if ((new_x == c_x + 1)&&((new_y == c_y -2)|(new_y == c_y+2))){
        return 1;
    }  ;
    if ((new_x == c_x + 2)&&((new_y == c_y -1)|(new_y == c_y+1))){
        return 1;
    };

    return 0;
}; 

