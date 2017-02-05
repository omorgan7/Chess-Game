#ifndef board_hpp
#define board_hpp
#include<vector>
#include "piece.hpp"

using namespace std;
class Board{
    public:
        piece** chess_board;
        Board();
        ~Board();
        void reset(void);
    private:
        void initialise();

};

#endif