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
    void MoveTiles(Board::Keys key);
    std::vector< std::vector<int> > GetBoard();
    // void UndoMove();
private:
    void CopyBoard(std::vector< std::vector<int> > main);
    std::string TileString(int val);
    void PickRandomAndSetValue();
    std::vector< std::vector<int> > mainBoard;
    std::vector< std::vector<int> > boardCopy;
};

#endif
