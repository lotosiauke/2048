#ifndef BOARD_H
#define BOARD_H
#include <vector>
#include <string>

class Board {
public:
    enum Keys {RIGHT, LEFT, UP, DOWN};

    Board();

    void InitializeGameBoard();
    void SetTile(int x, int y, int val);
    int GetTile(int x, int y);
    void Print();
    void Move(Board::Keys key);
    std::vector< std::vector<int> > GetBoard();
    // void UndoMove();
private:
    std::vector< std::vector<int> > board;
    std::vector< std::vector<int> > boardCopy;

    void MoveLeft(int x, int y);
    void MoveRight(int x, int y);
    void MoveUp(int x, int y);
    void MoveDown(int x, int y);
    void CopyBoard(std::vector< std::vector<int> > main);
    std::string TileString(int val);
    void FillRandomTile();
};

#endif
