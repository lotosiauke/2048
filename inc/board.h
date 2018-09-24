#ifndef BOARD_H
#define BOARD_H
#include <vector>


class Board {
public:
    enum Keys {RIGHT, LEFT, UP, DOWN};

    Board();
    void Print();
    void MakeMove(Board::Keys key);
private:
    void Move(const int& h, const int& v);
    void PickRandomAndSetValue();
    std::vector< std::vector<int> > vBoard;

};

#endif
