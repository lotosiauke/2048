#include "board.h"
#include <gtest/gtest.h>


TEST(Board, DefCtorInitializeTwoNumbers) {
    Board b;

    int count = 0;
    for (int x = 0; x < 4; x++) {
        for (int y = 0; y < 4; y++){
            if (b.vBoard[x][y] == 2 || b.vBoard[x][y] == 4) {
                count++;
            }
        }
    }
    ASSERT_EQ(2, count);
}
