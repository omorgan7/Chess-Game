#include "game.hpp"
#include "piece.hpp"
const regex expression ("([RNBKQP])([abcdefg])([12345678])([=])([RNBKQP])|([RNBKQP])([abcdefg])([12345678])|([RNBKQP])([abcdefg]|[12345678])([abcdefg])([12345678])");


game::game() {
	/*list<pawn> white_pawns = {};
	list<rook> white_rook = {};
	list<night> white_night = {};
	list<bish> white_bish = {};
	list<king> white_king = {};
	list<queen> white_queen = {};
	list<pawn> black_pawns = {};
	list<rook> black_rook = {};
	list<night> black_night = {};
	list<bish> black_bish = {};
	list<king> black_king = {};
	list<queen> black_queen = {};*/
}


//game::game(){};


bool game::process_input(int color){
    string response;
    smatch matcher;
    bool matched_expression = 0;
    while(1){
        getline(cin,response);
        cout<<"\n";
        regex_search(response,matcher,expression);
        matched_expression = response==matcher[0];
        if(matched_expression==1){
            break;
        }
        if(update_board_state(response,color) == 1){
            break;
        };
        cout<<"Please enter a valid move (e.g. Be5, Pe8=Q, Bef6 or B5f6):\n";
    }
    return 0;
}

void game::display_board_state(void){
    //Temporary function to display the initial state of the board_state
    //should be replaced with superior class that reads the state from some series of variables
    //this function MUST be rewritten.
    string letters = "    a    b    c    d    e    f    g    h";
    cout<<letters<<"\n";
    white_pieces = "WRWNWBWKWQWBWNWR";
    white_pawns = "WPWPWPWPWPWPWPWP";
    empty_line = "                ";
    black_pieces = "BRBNBBBKBQBBBNBR";
    black_pawns = "BPBPBPBPBPBPBPBP";
    auto count = 0;
    cout<<++count<<" ";
    print_chessboard_line(&black_pieces);
    cout<<++count<<" ";
    print_chessboard_line(&black_pawns);
    for(auto i = 0; i<4; i++){
        cout<<++count<<" ";
        print_chessboard_line(&empty_line);
    }
    cout<<++count<<" ";
    print_chessboard_line(&white_pawns);  
   
    cout<<++count<<" ";
    print_chessboard_line(&white_pieces);
}

void game::print_chessboard_line(string *stateString){
    for(auto it = stateString->begin(); it!=stateString->end(); it++){
        cout<<"| "<<*it;
        it++;
        cout<<*it<<" ";
    }
    cout<<"|\n";
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
    return 0;
}

void game::reset()
{
	cout << "Another game?\n";
}

bool game::CheckMate(int color){
    return 0;   
};  

