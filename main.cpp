#include <iostream>
#include<regex>

#include "game.hpp"
#include "piece.hpp"

using namespace std;
int main(){

    game G;
    string response;
    smatch matcher;
    bool matched_expression = 0;
    regex expression ("([RNBKQP])([abcdefg])([12345678])([=])([RNBKQP])|([RNBKQP])([abcdefg])([12345678])|([RNBKQP])([abcdefg]|[12345678])([abcdefg])([12345678])");
    cout<<"Welcome to text chess!\n";
    G.display_board_state();
    while(1){
        cout<<"Player 1 (white) enter your move:\n";
        while(1){
            getline(cin,response);
            cout<<"\n";
            regex_search(response,matcher,expression);
            matched_expression = response==matcher[0];
            if(matched_expression != 0){
                break;
            }
            cout<<"Please enter a valid move (e.g. Be5, Pe8=Q, Bef6 or B5f6):\n";
            G.some_function_that_takes_the_input(response);
        }
    }
    return 0;
}