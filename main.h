//
// Created by lxj on 2023/6/17.
//
#ifndef GOMOKU_NEW_MAIN_H
#define GOMOKU_NEW_MAIN_H
#include <iostream>
#include <cmath>
#include <string>
class Node
{
public:
    std::string status;
    int Line_x;
    int Line_y;
    int Line_z;
    Node()
    {
        status = "   ";
    }
    void set(int row, int column, int type)  //row为行,column为列
    {
        Line_x = abs(column + row - 7) / 2;
        Line_y = column;
        Line_z = abs(row - column + 7) / 2;
        if (type == 1)
            status = "  0";
    }
};

class Line
{
public:
    int row;  //这条直线头节点的行下标
    int column;  // 这条直线头节点的列下标
    int state;  // 这条直线上结点的状态（是否有棋子，是否已经下满棋子）
    int lenth;
    Line() { state = 0; }
    void set(int ro,int co)  //设置这条直线头节点的下标
    {
        row = ro;
        column = co;
    }
    void setState(int sta)  //设置直线状态，1为直线上有棋子，2为直线已满（全是棋子）
    {
        state = sta;
    }
};
#endif //GOMOKU_NEW_MAIN_H
