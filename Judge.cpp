#include"Jude.h"

bool Judge(Point* p) {
	int x = p->x, y = p->y;
	int count1 = 0;
	int count2 = 0;

	//检测竖直方向是否连五子
	if (p->flag == 1) {
		//向下寻找连子
		while (Match(x, y) && Match(x, y)->flag == 1) {	//有棋子且为黑
			count1++;
			y += 50;
		}
		//向上寻找连子
		y = p->y;
		while (Match(x, y) && Match(x, y)->flag == 1) {	//有棋子且为黑
			count2++;
			y -= 50;
		}

		if ((count1 + count2) >= 6) {
			cout << "Black Win!" << endl;
			return 1;
		}
	}
	else if (p->flag == 2) {
		//向下寻找连子
		while (Match(x, y) && Match(x, y)->flag == 2) {	//有棋子且为白
			count1++;
			y += 50;
		}
		//向上寻找连子
		y = p->y;
		while (Match(x, y) && Match(x, y)->flag == 2) {	//有棋子且为白
			count2++;
			y -= 50;
		}

		if ((count1 + count2) >= 6) {
			cout << "White Win!" << endl;
			return 1;
		}
	}

	count1 = 0, count2 = 0;
	x = p->x, y = p->y;
	//检测斜线‘/’方向是否连五子
	if (p->flag == 1) {
		//向左下寻找连子
		while (Match(x, y) && Match(x, y)->flag == 1) {	//有棋子且为黑
			count1++;
			x -= 45;
			y += 25;
		}
		//向右上寻找连子
		x = p->x, y = p->y;
		while (Match(x, y) && Match(x, y)->flag == 1) {	//有棋子且为黑
			count2++;
			x += 45;
			y -= 25;
		}

		if ((count1 + count2) >= 6) {
			cout << "Black Win!" << endl;
			return 1;
		}
	}
	else if (p->flag == 2) {
		//向左下寻找连子
		while (Match(x, y) && Match(x, y)->flag == 2) {	//有棋子且为白
			count1++;
			x -= 45;
			y += 25;
		}
		//向右上寻找连子
		x = p->x, y = p->y;
		while (Match(x, y) && Match(x, y)->flag == 2) {	//有棋子且为白
			count2++;
			x += 45;
			y -= 25;
		}

		if ((count1 + count2) >= 6) {
			cout << "White Win!" << endl;
			return 1;
		}
	}

	count1 = 0, count2 = 0;
	x = p->x, y = p->y;
	//检测斜线‘\’方向是否连五子
	if (p->flag == 1) {
		//向左上寻找连子
		while (Match(x, y) && Match(x, y)->flag == 1) {	//有棋子且为黑
			count1++;
			x -= 45;
			y -= 25;
		}
		//向右下寻找连子
		x = p->x, y = p->y;
		while (Match(x, y) && Match(x, y)->flag == 1) {	//有棋子且为黑
			count2++;
			x += 45;
			y += 25;
		}

		if ((count1 + count2) >= 6) {
			cout << "Black Win!" << endl;
			return 1;
		}
	}
	else if (p->flag == 2) {
		//向左上寻找连子
		while (Match(x, y) && Match(x, y)->flag == 2) {	//有棋子且为白
			count1++;
			x -= 45;
			y -= 25;
		}
		//向右下寻找连子
		x = p->x, y = p->y;
		while (Match(x, y) && Match(x, y)->flag == 2) {	//有棋子且为白
			count2++;
			x += 45;
			y += 25;
		}

		if ((count1 + count2) >= 6) {
			cout << "White Win!" << endl;
			return 1;
		}
	}

	return 0;
}