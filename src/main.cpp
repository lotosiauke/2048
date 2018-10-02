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
    gameBoard.Move(Board::RIGHT);
    gameBoard.Print();
    gameBoard.Move(Board::RIGHT);
    gameBoard.Print();
    gameBoard.Move(Board::RIGHT);
    gameBoard.Print();
    gameBoard.Move(Board::UP);
    gameBoard.Print();
    gameBoard.Move(Board::UP);
    gameBoard.Print();
    gameBoard.Move(Board::DOWN);
    gameBoard.Print();
    gameBoard.Move(Board::DOWN);
    gameBoard.Print();

}
