#include "board.h"

int main()
{
    Board gameBoard;
    gameBoard.Print();
    gameBoard.MakeMove(Board::UP);
    gameBoard.Print();
    gameBoard.MakeMove(Board::UP);
    gameBoard.Print();
    gameBoard.MakeMove(Board::UP);
    gameBoard.Print();
    gameBoard.MakeMove(Board::UP);
    gameBoard.Print();
}
