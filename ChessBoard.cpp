#include"ChessBoard.h"
//
vector<Point> Points;
//void ChessBoard() {
//	initgraph(800, 800, SHOWCONSOLE);
//	setcolor(BLACK);				//前景颜色
//	setbkcolor(WHITE);				//设置背景颜色
//	cleardevice();					//使用当前背景色清空绘图设备
//	setlinestyle(PS_SOLID, 4);
//
//	double x1, y1, x2, y2;
//	int count = 1;	//绘制次数
//
//	//绘制竖线“|”
//	for (x1 = 75, y1 = 225, y2 = y1 + 350; count <= 15; x1 += 45, count++) {
//		x2 = x1;
//		line(x1, y1, x2, y2);
//
//		for (int i = y1; i <= y2; i += 50) {	//记录棋盘点位
//			Point point;
//			point.x = x1;
//			point.y = i;
//			Points.push_back(point);
//		}
//
//		if (count < 8) {
//			y1 -= 25;
//			y2 += 25;
//		}
//		else {
//			y1 += 25;
//			y2 -= 25;
//		}
//
//	}
//
//	//绘制斜线“/”
//	count = 1;
//	for (x1 = 390, y1 = 50, x2 = 75, y2 = 225; count <= 15; count++) {
//		line(x1, y1, x2, y2);
//
//		if (count < 8) {
//			x1 += 45;
//			y1 += 25;
//			y2 += 50;
//		}
//		else {
//			x2 += 45;
//			y1 += 50;
//			y2 += 25;
//		}
//	}
//
//	//绘制斜线“\”
//	count = 1;
//	for (x1 = 390, y1 = 50, x2 = 705, y2 = 225; count <= 15; count++) {
//		line(x1, y1, x2, y2);
//
//		if (count < 8)
//		{
//			x1 -= 45;
//			y1 += 25;
//			y2 += 50;
//		}
//		else {
//			y1 += 50;
//			x2 -= 45;
//			y2 += 25;
//		}
//	}
//}
