#include "board.hpp"


Board::Board(){
    chess_board = new piece*[64];
    initialise();
}

Board::~Board(){
    for (auto i = 0; i<64; i++){
        if(chess_board[i] != nullptr){
            delete[] chess_board[i];
        }
	}
    delete[] chess_board;
}

void Board::initialise(void){
    
    for (auto i = 0; i < 64; i++) {
        chess_board[i] = nullptr;
    }
    chess_board[0] = new rook(0, 0, BLACK);
    chess_board[1] = new knight(1, 0, BLACK);
    chess_board[2] = new bishop(2, 0, BLACK);
    chess_board[3] = new king(BLACK);
    chess_board[4] = new queen(BLACK);
    chess_board[5] = new bishop(5, 0, BLACK);
    chess_board[6] = new knight(6, 0, BLACK);
    chess_board[7] = new rook(7, 0, BLACK);

    for (auto i = 0; i < 8; i++) {
        chess_board[8+i] = new pawn(i, 1, BLACK);
        chess_board[48+i] = new pawn(i, 6, WHITE);
    }

    chess_board[56] = new rook(0, 7, WHITE);
    chess_board[57] = new knight(1, 7, WHITE);
    chess_board[58] = new bishop(2, 7, WHITE);
    chess_board[59] = new king(WHITE);
    chess_board[60] = new queen(WHITE);
    chess_board[61] = new bishop(5, 7,WHITE);
    chess_board[62] = new knight(6, 7, WHITE);
    chess_board[63] = new rook(7, 7, WHITE);
}

void Board::reset(void){
    for (auto i = 0; i<64; i++){
        if(chess_board[i] != nullptr){
            delete[] chess_board[i];
            chess_board[i] = nullptr;
        }
	}
    initialise();
}