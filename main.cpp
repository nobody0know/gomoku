#include <iostream>
#include"ChessBoard.h"
#include"ChessMan.h"
#include"ChessAI.h"

extern vector<Point> Points;

int main() {
	cout << "please choose mode" << endl;
	cout << "1.PVP" << endl;
	cout << "2.PVE"<< endl;
	int flag;
	cin >> flag;
	if (flag == 1)//人人
	{
		ChessBoard();	//启动棋盘
		Choose();	//双方落子
	}
	else if (flag == 2)//人机
	{
		ChessBoard();	//启动棋盘
		Choose1();	//双方落子
	}
	else
	{
		cout << "error" << endl;
	}

	

	while (1);
}