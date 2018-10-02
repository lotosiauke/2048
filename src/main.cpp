#include "board.h"

int main()
{
    Board gameBoard;
    gameBoard.InitializeGameBoard();
    gameBoard.Print();
    gameBoard.Move(Board::LEFT);
    gameBoard.Print();
    gameBoard.Move(Board::LEFT);
    gameBoard.Print();
    gameBoard.Move(Board::LEFT);
    gameBoard.Print();
    gameBoard.Move(Board::LEFT);
    gameBoard.Print();
    gameBoard.Move(Board::LEFT);
    gameBoard.Print();
    gameBoard.Move(Board::LEFT);
    gameBoard.Print();
    gameBoard.Move(Board::LEFT);
    gameBoard.Print();
    gameBoard.Move(Board::LEFT);
    gameBoard.Print();
}
