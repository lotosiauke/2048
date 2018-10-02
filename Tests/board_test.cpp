#include "../inc/board.h"
#include "../src/board.cpp"
#include <gtest/gtest.h>


TEST(Board, CtorInitializeEmptyBoard) {
    Board b;
    int count = 0;

    for (const auto vec : b.GetBoard()) {
        for(const auto &val : vec) {
            if (val == 0) count++;
        }
    }

    ASSERT_EQ(16, count);
}

TEST(Board, InitializeGameBoardWithTwoRandom2Or4) {
    Board b;
    int count = 0;

    b.InitializeGameBoard();

    for (const auto vec : b.GetBoard()) {
        for(const auto &val : vec) {
            if (val == 2 || val == 4) count++;
        }
    }

    ASSERT_EQ(2, count);
}

TEST(Board, TileSetterWorks) {
    Board b;
    int count = 0;

    b.SetTile(0, 1, 2);
    b.SetTile(1, 0, 2);
    b.SetTile(3, 2, 16);

    for (const auto vec : b.GetBoard()) {
        for (const auto &val : vec) {
            if (val != 0) count++;
        }
    }

    EXPECT_EQ(b.GetTile(0, 1), 2);
    EXPECT_EQ(b.GetTile(1, 0), 2);
    EXPECT_EQ(b.GetTile(3, 2), 16);
    EXPECT_EQ(3, count);
}

TEST(Board, MoveLeft_MovesToBorderAndAddTile) {
    Board b;
    int count = 0;

    b.SetTile(0, 1, 2);
    b.Move(Board::LEFT);

    EXPECT_EQ(2, b.GetTile(0,0));
    EXPECT_EQ(0, b.GetTile(0,1));
}
