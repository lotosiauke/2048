#include "../inc/board.h"
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <random>

using namespace std;
Board::Board() : board(4, vector<int>(4,0)),
                 boardCopy(4, vector<int>(4,0)) {
}

void Board::InitializeGameBoard() {
    FillRandomTile();
    FillRandomTile();
}

vector< vector<int> > Board::GetBoard() {
    return board;
}

void Board::SetTile(int x, int y, int val) {
    (board)[x][y] = val;
}

int Board::GetTile(int x, int y) {
    return (board)[x][y];
}

void Board::CopyBoard(vector <vector<int> > main) {
    boardCopy.swap(main);
}

// void Board::UndoMove() {
//      board.swap(boardCopy);
// }

void Board::FillRandomTile() {
    mt19937 rng;
    rng.seed(random_device()());
    uniform_int_distribution<mt19937::result_type> dist4(0,3);
    uniform_int_distribution<mt19937::result_type> dist10(0,9);
    int x = dist4(rng);
    int y = dist4(rng);
    int seed = dist10(rng);

    if ((board)[x][y] == 0) {
        if (seed < 9){
            (board)[x][y] = 2;
        }
        else {
            (board)[x][y] = 4;
        }
    }
    else {
        FillRandomTile();
    }
}

bool Board::MoveLeft(int x, int y) {
    if ( GetTile(x, y) == 0 ) {
        int i = y;
        do {
            ++i;
            if(GetTile(x, i) != 0) {
                SetTile(x, y, GetTile(x, i));
                SetTile(x, i, 0);
                return true;
            }
        }
        while (i < 3);
    }
    else if ( GetTile(x, y) != 0 ) {
        int i = y;
        do {
            ++i;
            if ( GetTile(x, y) == GetTile(x, i) ) {
                SetTile(x, y, GetTile(x, y)*2);
                SetTile(x, i, 0);
                return true;
            }
            else if ( GetTile(x, i) != 0 && GetTile(x, y) != GetTile(x, i)) {
                SetTile(x, y+1, GetTile(x, i));
                if (y+1 != i){
                    SetTile(x, i, 0);
                }
                return true;
            }
        }
        while (i < 3);
    }
    return false;
}


void Board::Move(Board::Keys key) {
    switch(key) {
    case LEFT:
        bool hasMoved = false;
        for (int x = 0; x < 4; x++) {
            for (int y = 0; y < 4; y++) {
                if (MoveLeft(x, y)) {
                    hasMoved = true;
                }
            }
        }
        if (hasMoved) FillRandomTile();
        break;
    }
}

void Board::Print() {
    for (int x = 0; x < 4; x++) {
        for (int y = 0; y < 4; y++){
            cout << TileString( (board)[x][y] );
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
