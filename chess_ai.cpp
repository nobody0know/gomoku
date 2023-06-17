//
// Created by lc201 on 2023/6/17.
//
#include "chess_ai.h"

using namespace std;
extern std::string PLAYER_PIECE1;
extern std::string PLAYER_PIECE2;
extern Line line[45];

int score(int ai, int man) {
    if (ai > 5) return 200000;
    if (ai == 5 && man == 0) return 200000;
    if (ai == 5 && man == 1) return 200000;
    if (ai == 5 && man == 2) return 200000;
    if (ai == 4 && man == 1) return 3000;
    if (ai == 4 && man == 0) return 50000;
    if (ai == 4 && man >= 2) return 200000;
    if (ai == 3 && man == 0) return 3000;
    if (ai == 3 && man == 1) return 1000;
    if (ai == 3 && man >= 2) return 200000;
    if (ai == 2 && man == 0) return 500;
    if (ai == 2 && man == 1) return 200;
    if (ai == 2 && man >= 2) return 200000;
    if (ai == 1 && man == 0) return 100;
    if (ai == 1 && man == 1) return 50;
    if (ai == 1 && man >= 2) return 200000;
    return 0;
}

int getYScore(int row, int colum, Node **checkerboard, int mode) {
    int ai = 1;
    int man = 0;
    //向上遍历

    for (int i = row - 2; i >= 0; i -= 2) {
        if (mode == 1 && checkerboard[i][colum].status == PLAYER_PIECE2) {
            ai++;
        } else if (checkerboard[i][colum].status == "  0") {
            break;
        } else if(checkerboard[i][colum].status == PLAYER_PIECE1) {
            man++;
//            break;
        }
    }

    //向下遍历

    for (int i = row + 2;; i += 2) {
        if (i > 28 || checkerboard[i][colum].status == "   ")
            break;
        if (mode == 2 && checkerboard[i][colum].status == PLAYER_PIECE2) {
            ai++;
        } else if (checkerboard[i][colum].status == "  0") {
            break;
        } else if(checkerboard[i][colum].status == PLAYER_PIECE1) {
            man++;
//            break;
        }
    }

    return score(ai, man);
}

int getLeftScore(int row, int colum, Node **checkerboard, int mode) {
    int ai = 1;
    int man = 0;
    //左斜下

    for (int i = row + 1, j = colum - 1;; i++, j--) {
        if (i > 28 || j < 0 || checkerboard[i][j].status == "   ")
            break;
        if (mode == 1 && checkerboard[i][j].status == PLAYER_PIECE2) {
            ai++;
        } else if (checkerboard[i][j].status == "  0") {
            break;
        } else if(checkerboard[i][j].status == PLAYER_PIECE1) {
            man++;
//            break;
        }
    }

    //左斜上
    for (int i = row - 1, j = colum + 1;; i--, j++) {
        if (i < 0 || j > 14 || checkerboard[i][j].status == "   ")
            break;
        if (mode == 2 && checkerboard[i][j].status == PLAYER_PIECE2) {
            ai++;
        } else if (checkerboard[i][j].status == "  0") {
            break;
        } else if(checkerboard[i][j].status == PLAYER_PIECE1) {
            man++;
//            break;
        }
    }

    return score(ai, man);
}

int getRightScore(int row, int colum, Node **checkerboard, int mode) {
    int ai = 1;
    int man = 0;
    //右斜下
    for (int i = row + 1, j = colum + 1;; i++, j++) {
        if (i > 28 || j > 14 || checkerboard[i][j].status == "   ")
            break;
        if (mode == 1 && checkerboard[i][j].status == PLAYER_PIECE2) {
            ai++;
        } else if (checkerboard[i][j].status == "  0") {
            break;
        } else if(checkerboard[i][j].status == PLAYER_PIECE1) {
            man++;
//            break;
        }
    }

    //右斜上

    for (int i = row - 1, j = colum - 1;; i--, j--) {
        if (i < 0 || j < 0 || checkerboard[i][j].status == "   ")
            break;
        if (mode == 2 && checkerboard[i][j].status == PLAYER_PIECE2) {
            ai++;
        } else if (checkerboard[i][j].status == "  0") {
            break;
        } else if(checkerboard[i][j].status == PLAYER_PIECE1) {
            man++;
//            break;
        }
    }

    return score(ai, man);
}

int getScore(int x, int y, Node **checkerboard) {
    int numY1 = getYScore(x, y, checkerboard, 1);
    int numY2 = getYScore(x, y, checkerboard, 2);
    int left1 = getLeftScore(x, y, checkerboard, 1);
    int left2 = getLeftScore(x, y, checkerboard, 2);
    int right1 = getRightScore(x, y, checkerboard, 1);
    int right2 = getRightScore(x, y, checkerboard, 2);
    if (numY2 >= 200000 || left2 >= 200000 || right2 >= 200000) {
        return 200000;
    }
    if (numY1 >= 200000 || left1 >= 200000 || right1 >= 200000) {
        return 200000;
    }
    int yScore = getYScore(x, y, checkerboard, 1) + getYScore(x, y, checkerboard, 2);
    int skewScore1 = getLeftScore(x, y, checkerboard, 1) + getLeftScore(x, y, checkerboard, 2);
    int skewScore2 = getRightScore(x, y, checkerboard, 1) + getRightScore(x, y, checkerboard, 2);
    return yScore + skewScore1 + skewScore2;
}

int *concluate(int row, int colum, Node **checkerboard) {
    int *res = new int[2];
    int max = 0;
    for (int i = 0; i <= 28; i++) {
        for (int j = 0; j <= 14; j++) {
            if (checkerboard[i][j].status != "  0") {
                continue;
            }
            int num = getScore(i, j, checkerboard);
            if (num == 200000) {
                res[0] = i;
                res[1] = j;
                return res;
            }
            if (num > max) {
                max = num;
                res[0] = i;
                res[1] = j;
            }
        }
    }

    return res;
}


