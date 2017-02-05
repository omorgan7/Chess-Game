#include "game.hpp"
#include "piece.hpp"
#include "board.hpp"
const regex expression("([RNBKQP])([abcdefg])([12345678])([=])([RNBKQP])|([RNBKQP])([abcdefg])([12345678])|([RNBKQP])([abcdefg]|[12345678])([abcdefg])([12345678])");
Board B;

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
        if(B.chess_board[i]== nullptr){
            cout << "|   ";
        }
        else{
            cout << "| " <<B.chess_board[i]->PieceName<<" ";
        }
		
        if(i%8 == 0){
            cout<< "|\n"<< ++count << " ";
        } 
	}
}


bool game::update_board_state(string move, int colour)
// Takes in inputted move, and uses this to update board e.g. BNc3
{
	string letters = "    a    b    c    d    e    f    g    h";
	cout << letters << "\n";
	white_pieces = "WRWNWBWKWQWBWNWR";
	white_pawns = "WPWPWPWPWPWPWPWP";
	black_pieces = "BRBNBBBKBQBBBNBR";
	black_pawns = "BPBPBPBPBPBPBPBP";
	/*string piece_moved = move.at(0);
	string new_coordinate = move.at(1) + move.at(2);
	string whites[6] = { string R[2], string N[2], string B[2], string K[1], string Q[1], string P[8] };
	string blacks[6] = { string R[2], string N[2], string B[2], string K[1], string Q[1], string P[8] };
	for (auto i = 0; i < whites.length; i++) {
	if whites[i] = piece_moved
	}*/
}

void game::reset()
{
	cout << "Another game?\n";
}

bool game::CheckMate(int color) {

};

