#include "game.hpp"
#include "piece.hpp"
#include "board.hpp"
const regex expression("([RNBKQP])([abcdefg])([12345678])([=])([RNBKQP])|([RNBKQP])([abcdefg])([12345678])|([RNBKQP])([abcdefg]|[12345678])([abcdefg])([12345678])");
const int SearchIntervals[] = {-9,-8,-7,-1,+1,7,8,9};
const int KnightIntervals[]={-17, -15,-10,-6, 6, 10, 15, 17};
Board B;

game::game(){
	initialiseKingPosition();
	initialiseScore();
}

void game::process_input(int color) {
	string response;
	smatch matcher;
	bool matched_expression = 0;
	while (1) {
		getline(cin, response);
		cout << "\n";
		regex_search(response, matcher, expression);
		matched_expression = response == matcher[0];
		if (matched_expression == 1) {
			break;
		}
		if (update_board_state(response, color) == 1) {
			break;
		};
		cout << "Please enter a valid move (e.g. Be5, Pe8=Q, Bef6 or B5f6):\n";
	}
}

void game::display_board_state(void) {
	string letters = "    a    b    c    d    e    f    g    h";
	cout << letters << "\n";
	auto count = 0;
	cout << ++count << " ";
    for (auto i = 0; i<64; i++){
        if(i%8 == 0 && i != 0){
            cout<< "|\n"<< ++count << " ";
        } 
        if(B.chess_board[i] == nullptr){
            cout << "|    ";
        }
        else{
            cout << "| " <<B.chess_board[i]->PieceName<<" ";
        }
	}
    cout<<"|\n";
}
bool game::update_board_state(string move, int colour)
// Takes in inputted move, and uses this to update board e.g. BNc3
{
	string col_char;

	if (colour == WHITE) {
		col_char = "W";
	}
	else {
		col_char = "B";
	}
	string letters = "abcdefgh";
	int x = letters.find(to_string(move[1]));
	//int y = atoi((const char*) move[2]);//needs debugging
	int y = atoi(&move[2]);
	if(move.length() == 3) {
		for (auto i = 0; i < 64; i++){
			if(B.chess_board[i]->PieceName == (col_char + to_string(move[0]))){
				if(B.chess_board[x + 8 * y]->move(x, y, B.chess_board) == 1)){
					delete[] B.chess_board[i];
					B.chess_board[i] = nullptr;
					if(B.chess_board[x + 8 * y] != nullptr){
						delete[] B.chess_board[x + 8 * y];
					}
					switch (move[0]) {
						case 'R' :
							B.chessboard[x + 8 * y] = new rook(x, y, colour);
						case 'N' :
							B.chessboard[x + 8 * y] = new knight(x, y, colour);
						case 'B' :
							B.chessboard[x + 8 * y] = new bishop(x, y, colour);
						case 'K':
							B.chessboard[x + 8 * y] = new king(x, y, colour);
						case 'Q':
							B.chessboard[x + 8 * y] = new queen(x, y, colour);
					}
					B.chess_board[x + 8 * y] = new Piece(); // Type of piece to go here...

				}
			}
			else if (B.chess_board[x + 8 * y]->move(x, y, B.chess_board) == False {
				return False;
			}
			else {
				continue;
			}
		}
	}
	/*else if (move.length() == 4) {
		int z;
		for (auto i = 0; i < 64; i++) {
			if (isdigit(move[1])){
				z = atoi(&move[1]);
			}
			else if{
				z = letters.find(to_string(move[1]));
			}
		}
	}*/
	return 0;
}

void game::reset()
{
	cout << "Another game?\n";

}

void game::initialiseScore(void){
	white_score = 0;
	black_score = 0;
}
void game::initialiseKingPosition(void){
	black_king_index = 3;
	white_king_index = 59;
}

bool game::Check(int colour){
	//Should be run at the end of every move to see if this would put a piece in check.
	SetKingColorIndex(colour);
	if(check_lineof_sight(colour)==1){
		return 1;
	}
	if(check_knights(colour)==1){
		return 1;
	}
	return 0;
}
bool game::Check(int colour, int target_x, int target_y){
	//modified version of the checking function specifically for checkmate purposes.
	SetKingColorIndex(colour);
	king_index = target_x + 8*target_y;
	if(check_lineof_sight(colour)==1){
		return 1;
	}
	if(check_knights(colour)==1){
		return 1;
	}
	return 0;
}

	
bool game::check_lineof_sight(int colour){
	for (auto j = 1; j<9; j++){
		for(auto i = 0; i<8; i++){
			auto index = j*SearchIntervals[i]+king_index;
			if(index >= 0 && index < 64){
				if(B.chess_board[index]!=nullptr){
					if (B.chess_board[index]->getColour() != colour){
						if(B.chess_board[index]->move(index%8,index/8,B.chess_board)==1){
							return 1;
						}		
					}
				}
			}
		}
	}
	return 0;
}

bool game::check_knights(int colour){
	for (auto i = 0; i<8; i++){
		auto index = KnightIntervals[i]+king_index;
		if(index >= 0 && index <= 63){	
			if(B.chess_board[index]!=nullptr){
				if (B.chess_board[index]->getColour() != colour){
					if(B.chess_board[index]->PieceName[1]=='N'){
						return 1;
					}		
				}
			}
		}
	}
	return 0;
}

bool game::CheckMate(int color){
//Assumption: King should already be in check when this function is called.
	SetKingColorIndex(color);
	if(SearchKingSpace(color) == 1){
		return 0;
	}
	vector<int> AttackingPieceIndices;
	for(auto i = 0; i<64; i++){
		if(B.chess_board[i] != nullptr){
			if(B.chess_board[i]->move(king_index%8,king_index/8,B.chess_board)==1){
				AttackingPieceIndices.push_back(i);
			}
		}
	}
	if(AttackingPieceIndices.size()>1){
		return 1;
	}
	if(CanBeKilled(AttackingPieceIndices[0], color)==1){
		return 0;
	}
	if(B.chess_board[AttackingPieceIndices[0]]->PieceName[1] == 'N'){
		return 1;
	}
	return !CanBeBlocked(AttackingPieceIndices[0], color);
}

bool game::SearchKingSpace(int color){
	for(auto i = 0; i<8; i++){
		auto index = SearchIntervals[i]+king_index;
		if(index >= 0 && index <= 63){
			if(B.chess_board[index]==nullptr){
				if(Check(color,index%8, index/8)==0){
					return 1;
				}
			}
			else{
				if(B.chess_board[index]->move(index%8,index/8,B.chess_board)==1){
					if(Check(color,index%8, index/8)==0){
						return 1;
					}
				}
			}
		}
	}
	return 0;
}

void game::SetKingColorIndex(int color){
	if(color==WHITE){
		king_index = white_king_index;
	}
	else{
		king_index = black_king_index;
	}
}

bool game::CanBeKilled(int index,int color){
	for(auto i = 0; i<64; i++){
		if(B.chess_board[i]!=nullptr){
			if(B.chess_board[i]->move(index%8,index/8,B.chess_board)==1){
				auto temp_ptr = B.chess_board[i];
				B.chess_board[i] = nullptr;
				if(Check(color,index%8, index/8)==0){
					B.chess_board[i] = temp_ptr;
					return 1;
				}
				B.chess_board[i] = temp_ptr;
			}
		}	
	}
}

bool game::CanBeBlocked(int index, int color){
	SetKingColorIndex(color);
	auto king_x = king_index%8;
	auto king_y = king_index/8;
	auto attacker_x = index%8;
	auto attacker_y = index/8;
	if ((attacker_x==king_x)|(attacker_y==king_y)){
        auto it = (attacker_x-king_x)*pow(-1, attacker_x<king_x)+8*(attacker_y-king_y)*pow(-1, attacker_y<king_y);
        for (auto i = king_x + 8*king_y; i != attacker_x + 8*attacker_y; i+=it){
			for(auto j =0; j<64; j++){
				if(B.chess_board[j] != nullptr){
					if(B.chess_board[j]->move(i%8, i/8,B.chess_board)==1){
						auto temp_ptr = B.chess_board[j];
						B.chess_board[j] = nullptr;
						if(Check(color)==0){
							B.chess_board[j] = temp_ptr;
							return 1;
						}
						B.chess_board[j] = temp_ptr;
					}
				}
			}
        }  
    }
    else{
        auto it = 8*pow(-1,attacker_y>king_y);
        it = it+pow(-1,attacker_x<king_x);
        for (auto i = king_x + 8*king_y; i != attacker_x + 8*attacker_y; i+=it){
			for(auto j =0; j<64; j++){
				if(B.chess_board[j] != nullptr){
					if(B.chess_board[j]->move(i%8, i/8,B.chess_board)==1){
						auto temp_ptr = B.chess_board[j];
						B.chess_board[j] = nullptr;
						if(Check(color)==0){
							B.chess_board[j] = temp_ptr;
							return 1;
						}
						B.chess_board[j] = temp_ptr;
					}
				}
			}
        }   
    }
}

