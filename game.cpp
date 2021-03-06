#include "game.hpp"
#include "piece.hpp"
#include "board.hpp"
const regex expression("([RNBKQP])([a-h])([1-8])=([RNBQP])|([RNBKQP])([a-h])([1-8])|([RNBKQP])([a-h]|[1-8])([a-h])([1-8])|O(-O){1,2}");

const int SearchIntervals[] = {-9,-8,-7,-1,+1,7,8,9};
const int KnightIntervals[]={-17, -15,-10,-6, 6, 10, 15, 17};
Board B;

game::game(){
	initialiseKingPosition();
	initialiseScore();
}

bool game::process_input(int color) {
	string response;
	smatch matcher;
	bool matched_expression = 0;
	while (1) {
		getline(cin, response);
		cout << "\n";
		if(response == "QUIT"){
			return 0;
		}
		regex_search(response, matcher, expression);
		matched_expression = response == matcher[0];
		if (matched_expression == 1) {
			if (update_board_state(response, color) == 1) {
				break;
			};
		}
		cout << "Please enter a valid move (e.g. Be5, Pe8=Q, Bef6 or B5f6):\n";
	}
	return 1;
}

void game::display_board_state(void) {
	string letters = "    a    b    c    d    e    f    g    h";
	cout<<"Player One Score "<<white_score<<"\n";
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
	cout<<"Player Two Score "<<black_score<<"\n";
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
	int x = letters.find(move[1]);
	int y = atoi(&move[2])-1;
	int z;
	if(move.length() == 3) {
		for (auto i = 0; i < 64; i++){
			if(B.chess_board[i] != nullptr){
				if(B.chess_board[i]->PieceName == (col_char + move[0]) ){
					if(B.chess_board[i]->move(x, y, B.chess_board) == 1){
						return movePieces(move[0],i,x,y,colour);
					}
				}
			}
		}
		return 0;
	}
	else if (move.length() == 4) {
		int x = letters.find(move[2]);
		int y = atoi(&move[3]) - 1;
		for (auto i = 0; i < 8; i++) {
			if (isdigit(move[1])) {
				z = ((atoi(&move[1]) - 1) * 8) + i;
			}
			else if (isalpha(move[1])) {
				z = letters.find(move[1]) + (8 * i);
			}
			if (B.chess_board[z] != nullptr) {
				if (B.chess_board[z]->PieceName == (col_char + move[0])) {
					if (B.chess_board[z]->move(x, y, B.chess_board) == 1) {
						return movePieces(move[0], z, x, y, colour);
					}
				}
			}
		}
		return 0;
	}
	else if (move.length() == 5) {
		if (col_char == "W") {
			z = 1;
		}
		else {
			z = 6;
		}
		for (auto i = 0; i < 8; i++) {
			int j = z * 8 + i;
			if (B.chess_board[j] != nullptr) {
				if (B.chess_board[j]->PieceName == (col_char + move[0])) {
					if (B.chess_board[j]->move(x, y, B.chess_board) == 1) {
						return promotePieces(move[4], j, x, y, colour);
					}
				}
			}
		}
		return 0;
	}
	return 0;
}

void game::reset()
{
	B.reset();
	initialiseScore();
	initialiseKingPosition();
}

bool game::movePieces(char piece, int index, int x, int y, int colour){
	delete B.chess_board[index];
	char old_piece;
	auto old_piece_flag = 0;
	B.chess_board[index] = nullptr;
	if(B.chess_board[x + 8 * y] != nullptr){
		old_piece_flag = 1;
		old_piece = B.chess_board[x + 8*y]->PieceName[1];
		delete B.chess_board[x + 8*y];
		score(colour, (x + 8*y));
	}
	switchPieces(piece, x, y, colour);
	//display_board_state();
	bool checkResult;
	if(piece == 'K'){
		SetKingColorIndex(colour, x+8*y);
		checkResult = Check(colour,x,y);
	}
	else{
		checkResult = Check(colour);
	}

	if(checkResult == 1){
		switchPieces(piece, index%8, index/8, colour);
		SetKingColorIndex(colour,index);
		delete B.chess_board[x + 8*y];
		B.chess_board[x+8*y] = nullptr;
		if(old_piece_flag==1){
			switchPieces(old_piece, x,y,inverseColor(colour));
		}
		cout<<"That move puts you in check!\n";
		return 0;
	}

	return 1;
}

bool game::promotePieces(char new_piece, int index, int x, int y, int colour) {
	delete B.chess_board[index];
	B.chess_board[index] = nullptr;
	switchPieces(new_piece, x, y, colour);
	return 1;
}

int game::inverseColor(int colour){
	if(colour == WHITE){
		return BLACK;
	}
	return WHITE;
}

void game::switchPieces(char piece, int x, int y, int colour){
	switch (piece) {
		case 'P' :
			B.chess_board[x + 8 * y] = new pawn(x, y, colour);
			B.chess_board[x + 8 * y]->not_initial();
			break;
		case 'R' :
			B.chess_board[x + 8 * y] = new rook(x, y, colour);
			break;
		case 'N' :
			B.chess_board[x + 8 * y] = new knight(x, y, colour);
			break;
		case 'B' :
			B.chess_board[x + 8 * y] = new bishop(x, y, colour);
			break;
		case 'K':
			B.chess_board[x + 8 * y] = new king(x, y, colour);
			break;
		case 'Q':
			B.chess_board[x + 8 * y] = new queen(x, y, colour);
			break;
	}
}

void game::initialiseScore(void){
	white_score = 0;
	black_score = 0;
}
void game::score(int colour, int index){
	if (colour ==WHITE){
		white_score = white_score + B.chess_board[index]->get_piece_value();
	}
	else{
		black_score = black_score + B.chess_board[index]->get_piece_value();
	}
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
	auto old_king_index = king_index;
	king_index = target_x + 8*target_y;
	if(check_lineof_sight(colour)==1){
		king_index = old_king_index;
		return 1;
	}
	if(check_knights(colour)==1){
		king_index = old_king_index;
		return 1;
	}
	king_index = old_king_index;
	return 0;
}

	
bool game::check_lineof_sight(int colour){
	for (auto j = 1; j<9; j++){
		for(auto i = 0; i<8; i++){
			auto index = j*SearchIntervals[i]+king_index;
			if(index >= 0 && index < 64){
				if(B.chess_board[index]!=nullptr){
					if (B.chess_board[index]->getColour() != colour){
						if(B.chess_board[index]->move(king_index%8,king_index/8,B.chess_board)==1){
							cout<<"Check function ended inside loop\n";
							return 1;
						}		
					}
				}
			}
		}
	}
	cout<<"Check function ended outside loop\n";
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
	//This function is needed to switch the king index between white and black for the purposes of Check calculation.
	if(color==WHITE){
		king_index = white_king_index;
	}
	else{
		king_index = black_king_index;
	}
}
void game::SetKingColorIndex(int color, int index){
	//This function updates the white/black king index, to be called whenever king's position moves.
	if(color==WHITE){
		white_king_index = index;
	}
	else{
		black_king_index = index;
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
	return 0;
}

bool game::CanBeBlocked(int index, int color){
	SetKingColorIndex(color);
	auto king_x = king_index%8;
	auto king_y = king_index/8;
	auto attacker_x = index%8;
	auto attacker_y = index/8;
	int it = 0;
	if ((attacker_x==king_x)|(attacker_y==king_y)){
        it = 8*(attacker_y-king_y)*pow(-1, attacker_y<king_y);
		it += (attacker_x-king_x)*pow(-1, attacker_x<king_x);
    }
    else{
        it = 8*pow(-1,attacker_y>king_y);
        it += pow(-1,attacker_x<king_x);  
    }
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
	return 0;
}

