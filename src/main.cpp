#include "board.h"

int main()
{
    Board gameBoard;
    gameBoard.Print();
    gameBoard.MoveTiles(Board::UP);
    gameBoard.Print();
    gameBoard.MoveTiles(Board::UP);
    gameBoard.Print();
    gameBoard.MoveTiles(Board::UP);
    gameBoard.Print();
    gameBoard.MoveTiles(Board::UP);
    gameBoard.Print();
}
