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

TEST(Board, TilesMoveUpAndAddRandomTile) {
    Board b;
    int count = 0;

    b.SetTile(0, 1, 2);
    b.SetTile(1, 0, 2);
    b.SetTile(3, 2, 16);
    b.MoveTiles(Board::UP);

    for (const auto vec : b.GetBoard()) {
        for (const auto &val : vec) {
            if (val != 0) count++;
        }
    }

    EXPECT_EQ(2, b.GetTile(0, 1));
    EXPECT_EQ(2, b.GetTile(0, 0));
    EXPECT_EQ(16, b.GetTile(0, 2));
    EXPECT_EQ(4, count);

}

TEST(Board, TilesDontMoveUpAndDontAddRandomTile) {
    Board b;
    int count = 0;

    b.SetTile(0, 0, 4);
    b.SetTile(0, 2, 2);
    b.MoveTiles(Board::UP);

    for (const auto vec : b.GetBoard()) {
        for (const auto &val : vec) {
            if (val != 0) count++;
        }
    }

    EXPECT_EQ(4, b.GetTile(0, 0));
    EXPECT_EQ(2, b.GetTile(0, 2));
    EXPECT_EQ(2, count);
}

TEST(Board, TilesMoveDownAndMerge) {
    Board b;
    int count = 0;

    b.SetTile(0, 2, 2);
    b.SetTile(1, 2, 2);
    b.SetTile(2, 2, 4);
    b.SetTile(2, 3, 16);
    b.SetTile(3, 2, 4);
    b.SetTile(3, 3, 16);
    b.SetTile(3, 1, 32);
    b.MoveTiles(Board::DOWN);

    for (const auto vec : b.GetBoard()) {
        for (const auto &val : vec) {
            if (val != 0) count++;
        }
    }

    EXPECT_EQ(32, b.GetTile(3, 1));
    EXPECT_EQ(32, b.GetTile(3, 3));
    EXPECT_EQ(8, b.GetTile(3, 2));
    EXPECT_EQ(4, b.GetTile(2, 2));
    EXPECT_EQ(5, count);

}
