#include"ChessAI.h"
extern vector<Point> Points;
//Point* p;
bool isWithinRange(int x, int y) {
    // 判断 x 的范围
    if (x >= 75 && x <= 735) {
        // 判断 y1 和 y2 的范围
        if ((y >= 225 && y <= 350) || (y >= 600 && y <= 425)) {
            return true;
        }
    }

    // 判断 x1, y1, x2, y2 的范围
    if (x >= 390 && x <= 750 && y >= 50 && y <= 450) {
        return true;
    }

    // 如果以上条件都不满足，则坐标不在指定范围内
    return false;
}
 //在棋盘上查找当前落子点周围的空位，并计算得分
int GetScore(Point *point)
{
   /* for (int i = 0; i < Points.size(); i++)
        cout << Points[i].flag << endl;
    cout << "kacsckccccjcjjccj";*/
    int score = 0;
    int count1 = 0, count2 = 0;  // 连续的空位和己方棋子数
    int count3 = 0, count4 = 0;
    int count5 = 0, count6 = 0;
    int count7 = 0, count8 = 0;
    int count9 = 0, count10 = 0;
    int count11 = 0, count12 = 0;
    //向上查找
    for (int j = 1; j <5; ++j)
    {
        Point* next_point = point;
        if (next_point->flag == 0)  // 如果是空位，增加连续的空位数
        {
            count1++;
        }
        else if (next_point->flag == 1)  // 如果是己方棋子，增加连续的己方棋子数
        {
            count2++;
        }
        else  // 如果是对方棋子或者越界，停止查找
        {
            break;
        }
        if (Match(next_point->x, next_point->y) == NULL)
            break;
        next_point->y += 50;
    }
    //向下查找
    for (int j = 1; j <5; ++j)
    {
        Point* next_point = point;
        if (next_point->flag == 0)  // 如果是空位，增加连续的空位数
        {
            count3++;
        }
        else if (next_point->flag == 1)  // 如果是己方棋子，增加连续的己方棋子数
        {
            count4++;
        }
        else  // 如果是对方棋子或者越界，停止查找
        {
            break;
        }
        if (Match(next_point->x, next_point->y) == NULL)
            break;
        next_point->y -= 50;
    }
    //检测斜线‘/’方向是否连五子
    //向左下寻找
    for (int j = 1; j < 5; ++j)
    {
        Point* next_point = point;
        if (next_point->flag == 0)  // 如果是空位，增加连续的空位数
        {
            count5++;
        }
        else if (next_point->flag == 1)  // 如果是己方棋子，增加连续的己方棋子数
        {
            count6++;
        }
        else  // 如果是对方棋子或者越界，停止查找
        {
            break;
        }
        if (Match(next_point->x, next_point->y) == NULL)
            break;
        next_point->x -= 45;
        next_point->y += 25;
    }
    //向右上寻找
    for (int j = 1; j < 5; ++j)
    {
        Point* next_point = point;
        if (next_point->flag == 0)  // 如果是空位，增加连续的空位数
        {
            count7++;
        }
        else if (next_point->flag == 1)  // 如果是己方棋子，增加连续的己方棋子数
        {
            count8++;
        }
        else  // 如果是对方棋子或者越界，停止查找
        {
            break;
        }
        if (Match(next_point->x, next_point->y) == NULL)
            break;
        next_point->x += 45;
        next_point->y -= 25;
    }
    //检测斜线‘\’方向是否连五子
    //向左上寻找连子
    for (int j = 1; j <5; ++j)
    {
        Point* next_point = point;
        if (next_point->flag == 0)  // 如果是空位，增加连续的空位数
        {
            count9++;
        }
        else if (next_point->flag == 1)  // 如果是己方棋子，增加连续的己方棋子数
        {
            count10++;
        }
        else  // 如果是对方棋子或者越界，停止查找
        {
            break;
        }
        if (Match(next_point->x, next_point->y) == NULL)
            break;
        next_point->x -= 45;
        next_point->y -= 25;
    }
    //向右下寻找
    for (int j = 1; j < 5; ++j)
    {
        Point* next_point = point;
        if (next_point->flag == 0)  // 如果是空位，增加连续的空位数
        {
            count11++;
        }
        else if (next_point->flag == 1)  // 如果是己方棋子，增加连续的己方棋子数
        {
            count12++;
        }
        else  // 如果是对方棋子或者越界，停止查找
        {
            break;
        }
        if (Match(next_point->x, next_point->y) == NULL)
            break;
        next_point->x += 45;
        next_point->y += 25;
    }
    score = count1 * 5 + count2 * 10 + count3 * 5 + count4 * 10 + count5 * 5 + count6 * 10 + count7 * 5 + count8 * 10 + count9 * 5 + count10 * 10 + count11 * 5 + count12 * 10;

    return score;
}



Point* AiMatch()
{
    int max_score = 0;
    Point* max_point = NULL;

    // 遍历所有空位，选择最优落子点
    int index = 0;
    for (int i = 0; i < 169; ++i)
    {
        //cout << "mmm";
        if (Points[i].flag == 0)  // 如果是空位
        {
            //Points[i].flag = 2;  // AI假设在此处下子
            int score = GetScore(&Points[i]);  // 计算当前位置的得分
            if (score > max_score)  // 如果得分更高，更新最优策略
            {
                
                max_score = score;
                index = i;

            }
            //Points[i].flag = 0;  // 恢复棋盘状态，以便查询其他位置的得分
        }
    }
    return &Points[index];
}

void Choose1()
{
    int count = 1;  // 计数器，奇数次是玩家落子，偶数次是AI落子
    while (1)
    {
        if (count % 2 != 0)  // 轮到玩家落子
        {
//            n = GetMouseMsg();
//            if (n.uMsg == WM_LBUTTONDOWN)
            {
                int x,y;
                cout<<"please input your chequer:x y"<<endl;
                cin>>x>>y;
                Point* Tem = Match(x, y);
                //p = Tem;
                if (Tem && Tem->flag == 0)  // 只能下在空位上
                {
                    Tem->flag = 1;
//                    setfillcolor(BLACK);
//                    fillcircle(Tem->x, Tem->y, 20);
                    count++;
                    if (Judge(Tem))  // 判断是否胜负已分
                    {
                        return;
                    }
                }
            }
        }
        else  // 轮到AI落子
        {
            Point* Tem = AiMatch();  // AI选择一个点下棋
            Tem->flag = 2;
            cout<<"AI input x:"<<Tem->x<<" y:"<<Tem->y<<endl;
//            setfillcolor(WHITE);
//            fillcircle(Tem->x, Tem->y, 20);
            count++;
            if (Judge(Tem))
            {
                return;
            }
        }
    }
}


