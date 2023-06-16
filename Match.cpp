#include"Match.h"

extern vector<Point> Points;

//寻找最近的一个棋盘点位
Point* Match(double x, double y) {
	for (int i = 0; i < Points.size(); i++) {
		if (sqrt(pow(Points[i].x - x, 2) + pow(Points[i].y - y, 2)) < 25) {
			return &Points[i];
		}
	}
	return NULL;
}