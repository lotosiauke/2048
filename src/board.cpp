#include "../inc/board.h"
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <random>

using namespace std;
Board::Board() : mainBoard(4, vector<int>(4,0)),
                 boardCopy(4, vector<int>(4,0)) {
}

void Board::InitializeGameBoard() {
    PickRandomAndSetValue();
    PickRandomAndSetValue();
}

void Board::SetTile(int x, int y, int val) {
    (mainBoard)[x][y] = val;
}

int Board::GetTile(int x, int y) {
    return (mainBoard)[x][y];
}

void Board::CopyBoard(vector <vector<int> > main) {
    boardCopy.swap(main);
}

// void Board::UndoMove() {
//      mainBoard.swap(boardCopy);
// }

void Board::PickRandomAndSetValue() {
    mt19937 rng;
    rng.seed(random_device()());
    uniform_int_distribution<mt19937::result_type> dist4(0,3);
    uniform_int_distribution<mt19937::result_type> dist10(0,9);
    int x = dist4(rng);
    int y = dist4(rng);
    int seed = dist10(rng);

    if ((mainBoard)[x][y] == 0) {
        if (seed < 9){
            (mainBoard)[x][y] = 2;
        }
        else {
            (mainBoard)[x][y] = 4;
        }
    }
    else {
        PickRandomAndSetValue();
    }
}


void Board::MoveTiles(Board::Keys key) {
    switch(key){
    case UP:
        CopyBoard(mainBoard);
        for (int x = 0; x < 4; x++) {
            for (int y = 0; y < 4; y++){
                if (x != 3) {
                    if ((mainBoard)[x][y] == (mainBoard)[x+1][y]) {
                        (mainBoard)[x][y] += (mainBoard)[x+1][y];
                        (mainBoard)[x+1][y] = 0;
                    }
                    else if ((mainBoard)[x][y] == 0) {
                        (mainBoard)[x][y] = (mainBoard)[x+1][y];
                        (mainBoard)[x+1][y] = 0;
                    }
                }
            }
        }
        if (mainBoard != boardCopy){
            CopyBoard(mainBoard);
            PickRandomAndSetValue();
        }
        break;
    case DOWN:
        for (int x = 3; x >= 0; x--) {
            for (int y = 0; y < 4; y++){
                if (x != 0) {
                    if ((mainBoard)[x][y] == (mainBoard)[x-1][y]) {
                        (mainBoard)[x][y] += (mainBoard)[x-1][y];
                        (mainBoard)[x-1][y] = 0;
                    }
                    else if ((mainBoard)[x][y] == 0) {
                        (mainBoard)[x][y] = (mainBoard)[x-1][y];
                        (mainBoard)[x-1][y] = 0;
                    }
                }
            }
        }
        PickRandomAndSetValue();
        break;
    case LEFT:
        for (int x = 0; x < 4; x++) {
            for (int y = 0; y < 4; y++){
                if (y != 3) {
                    if ((mainBoard)[x][y] == (mainBoard)[x][y+1]) {
                        (mainBoard)[x][y] += (mainBoard)[x][y+1];
                        (mainBoard)[x][y+1] = 0;
                    }
                    else if ((mainBoard)[x][y] == 0) {
                        (mainBoard)[x][y] = (mainBoard)[x][y+1];
                        (mainBoard)[x][y+1] = 0;
                    }
                }
            }
        }
        PickRandomAndSetValue();
        break;
    case RIGHT:
        for (int x = 0; x < 4; x++) {
            for (int y = 3; y >= 0; y--){
                if (y != 0) {
                    if ((mainBoard)[x][y] == (mainBoard)[x][y-1]) {
                        (mainBoard)[x][y] += (mainBoard)[x][y-1];
                        (mainBoard)[x][y-1] = 0;
                    }
                    else if ((mainBoard)[x][y] == 0) {
                        (mainBoard)[x][y] = (mainBoard)[x][y-1];
                        (mainBoard)[x][y-1] = 0;
                    }
                }
            }
        }
        PickRandomAndSetValue();
        break;
    default:
        break;
    }
}

void Board::Print() {
    for (int x = 0; x < 4; x++) {
        for (int y = 0; y < 4; y++){
            cout << TileString( (mainBoard)[x][y] );
        }
        cout << endl;
    }
    cout << endl;
}

string Board::TileString(int val) {
    string str;
    str += to_string(val);
    while (str.length() <= 6) {
        str += " ";
    }
    return str;
}

vector< vector<int> > Board::GetBoard() {
    return mainBoard;
}
