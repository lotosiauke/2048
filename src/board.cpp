#include "board.h"
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <string>
#include <random>

using namespace std;
Board::Board() : vBoard(4, vector<int>(4,0)) {

    PickRandomAndSetValue();
    PickRandomAndSetValue();
}

void Board::PickRandomAndSetValue() {
    mt19937 rng;
    rng.seed(random_device()());
    uniform_int_distribution<mt19937::result_type> dist4(0,3);
    uniform_int_distribution<mt19937::result_type> dist10(0,9);
    int x = dist4(rng);
    int y = dist4(rng);
    int seed = dist10(rng);

    if ((vBoard)[x][y] == 0) {
        if (seed < 9){
            (vBoard)[x][y] = 2;
        }
        else {
            (vBoard)[x][y] = 4;
        }
    }
    else {
        PickRandomAndSetValue();
    }
}

void Board::Print() {
    for (int x = 0; x < 4; x++) {
        for (int y = 0; y < 4; y++){
            cout << (vBoard)[x][y] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void Board::MakeMove(Board::Keys key) {
    switch(key){
    case UP:
        for (int x = 0; x < 4; x++) {
            for (int y = 0; y < 4; y++){
                if (x != 3) {
                    if ((vBoard)[x][y] == (vBoard)[x+1][y]) {
                        (vBoard)[x][y] += (vBoard)[x+1][y];
                        (vBoard)[x+1][y] = 0;
                    }
                    else if ((vBoard)[x][y] == 0) {
                        (vBoard)[x][y] = (vBoard)[x+1][y];
                        (vBoard)[x+1][y] = 0;
                    }
                }
            }
        }
        PickRandomAndSetValue();
        break;
    case DOWN:
        for (int x = 3; x >= 0; x--) {
            for (int y = 0; y < 4; y++){
                if (x != 0) {
                    if ((vBoard)[x][y] == (vBoard)[x-1][y]) {
                        (vBoard)[x][y] += (vBoard)[x-1][y];
                        (vBoard)[x-1][y] = 0;
                    }
                    else if ((vBoard)[x][y] == 0) {
                        (vBoard)[x][y] = (vBoard)[x-1][y];
                        (vBoard)[x-1][y] = 0;
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
                    if ((vBoard)[x][y] == (vBoard)[x][y+1]) {
                        (vBoard)[x][y] += (vBoard)[x][y+1];
                        (vBoard)[x][y+1] = 0;
                    }
                    else if ((vBoard)[x][y] == 0) {
                        (vBoard)[x][y] = (vBoard)[x][y+1];
                        (vBoard)[x][y+1] = 0;
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
                    if ((vBoard)[x][y] == (vBoard)[x][y-1]) {
                        (vBoard)[x][y] += (vBoard)[x][y-1];
                        (vBoard)[x][y-1] = 0;
                    }
                    else if ((vBoard)[x][y] == 0) {
                        (vBoard)[x][y] = (vBoard)[x][y-1];
                        (vBoard)[x][y-1] = 0;
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

// void Board::Move(const int& h, const int& v) {
//     for (int x = 0; x < 4; x++) {
//         for (int y = 0; y < 4; y++){
//             if (x == 4)
//             (vBoard)[x][y] = (vBoard)[x+h][x+y] ;
//         }
//     }
// }
