#pragma once
#ifndef POINT_H
#define POINT_H
#include<iostream>
#include<conio.h>
#include<math.h>
#include<vector>
using namespace std;

class Point {
public:
	double x;
	double y;
	int flag;	//0为空，1为黑子，2为白字

	Point();
	Point(double x_, double y_);
};

//struct Point {
//	double x;
//	double y;
//	int flag = 0;
//};

#endif // !POINT_H
