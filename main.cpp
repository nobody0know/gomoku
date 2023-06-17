#include "main.h"
#include "chess_ai.h"

using namespace std;

// 定义玩家和电脑的棋子
string PLAYER_PIECE1 = "  $";//man
string PLAYER_PIECE2 = "  #";//ai


Line line[45];  //x方向的直线在0-14里，y方向在15-29里，z方向在30-44里

void checkerBoardInit(Node **checkerboard)  //棋盘初始化
{
    for (int i = 0; i <= 7; i++)
    {
        for (int j = 7 + i; j >= 7 - i; j = j - 2)
        {
            checkerboard[i][j].set(i, j, 1);
        }
    }
    for (int i = 8; i <= 20; i++)
    {
        int j;
        if (i % 2 == 0)
            j = 1;
        else
            j = 0;
        for (; j < 15; j = j + 2)
        {
            checkerboard[i][j].set(i, j, 1);
        }
    }
    for (int i = 21; i < 29; i++)
    {
        for (int j = i - 21; j < 36 - i; j = j + 2)
        {
            checkerboard[i][j].set(i, j, 1);
        }
    }
}

void lineInit(Line *line, Node **checkerboard)
{
    int j = 7;
    int i;
    int k = 0; //line数组下标
    int len = 8;  //line数组对应位置的结点个数
    //x方向的直线初始化
    for (i = 0; i < 7; i++)
    {
        line[k].row = i;
        line[k].lenth = len++;
        line[k++].column = j;
        j++;
    }
    for (; i < 22; i += 2)
    {
        line[k].row = i;
        line[k].lenth = len--;
        line[k++].column = j;
    }
    //y方向的直线初始化
    j = 0;
    len = 8;
    for (i = 7; i >= 0; i--)
    {
        line[k].row = i;
        line[k].lenth = len++;
        line[k++].column = j;
        j++;
    }
    len = 14;
    for (i = 1; i <= 7; i++)
    {
        line[k].row = i;
        line[k].lenth = len--;
        line[k++].column = j;
        j++;
    }
    //z方向的直线初始化
    j = 7;
    len = 8;
    for (i = 0; i < 7; i++)
    {
        line[k].row = i;
        line[k].lenth = len++;
        line[k++].column = j;
        j--;
    }
    j = 0;
    for (i = 7; i < 22; i++)
    {
        line[k].row = i;
        line[k].lenth = len--;
        line[k++].column = j;
    }
}

void display(Node **checkerboard) //棋盘输出
{
    cout << "    0  1  2  3  4  5  6  7  8  9 10 11 12 13 14" << endl;
    for (int i = 0; i < 29; i++)
    {
        cout << i;
        if (i <= 9)
            cout << ' ';
        for (int j = 0; j < 15; j++)
        {
            cout << checkerboard[i][j].status;
        }
        cout << endl;
    }
}

int check(string str)  //判断落棋位置是否合理
{
    if (str == "  0")
        return 1;
    else
        return 0;
}

int isWin(Node **checkerboard, int row, int col, string status)
{
    int count = 0, m, n, i, flag = 0;
    //判断x方向
    i = checkerboard[row][col].Line_x;  //获取是x方向哪一条直线
    m = line[i].row;
    n = line[i].column;
    while (1)
    {
        if (m > 28 || n < 0  || checkerboard[m][n].status == "   ")
            break;
        if (count == flag && checkerboard[m][n].status == status)
        {
            count++;
            flag++;
        }
        else if (count > 0 && checkerboard[m][n].status != status)
        {
            line[i].state = 1;
            if (count >= 5)
                break;
            count = 0;
            flag = 0;
        }
        m++;
        n--;
    }
    if (count == line[i].lenth)
        line[i].state = 2;
    if (count >= 5)
        return 1;
    count = 0;
    flag = 0;
    //判断y方向
    i = checkerboard[row][col].Line_y;  //获取是y方向哪一条直线
    i += 15;
    m = line[i].row;
    n = line[i].column;
    while (1)
    {
        if (m > 28 || checkerboard[m][n].status == "   ")
            break;
        if (count == flag && checkerboard[m][n].status == status)
        {
            count++;
            flag++;
        }
        else if (count > 0 && checkerboard[m][n].status != status)
        {
            line[i].state = 1;
            if (count >= 5)
                break;
            count = 0;
            flag = 0;
        }
        m += 2;

    }
    if (count == line[i].lenth)
        line[i].state = 2;
    if (count >= 5)
        return 1;
    count = 0;
    flag = 0;
    //判断z方向
    i = checkerboard[row][col].Line_z;  //获取是z方向哪一条直线
    i += 30;
    m = line[i].row;
    n = line[i].column;
    while (1)
    {
        if (m > 28 || n > 14 || checkerboard[m][n].status == "   ")
            break;
        if (count == flag && checkerboard[m][n].status == status)
        {
            count++;
            flag++;
        }
        else if (count > 0 && checkerboard[m][n].status != status)
        {
            line[i].state = 1;
            if (count >= 5)
                break;
            count = 0;
            flag = 0;
        }
        m++;
        n++;
    }
    if (count == line[i].lenth)
        line[i].state = 2;
    if (count >= 5)
        return 1;
    return 0;
}

int judge()  //判断是不是平局(棋盘没有位置了)
{
    for (int i = 0; i < 15; i++)
    {
        if (line[i].state != 2)
            return 0;
    }
    return 1;
}

void people(Node **checkerboard) //双人对战模式
{
    cout << "请选择游戏模式，1为我方先手，2为对方先手" << endl;
    int type, row, col;
    while(cin >> type)
    {
        if(type == 1||type ==2)
            break;
        else
            cout<<"请选择正确的下棋顺序"<<endl;
    }
    if (type == 1)
    {
        while (1)
        {
            cout << "请输入我方位置(行和列)" << endl;
            while (cin >> row >> col)
            {
                if (check(checkerboard[row][col].status) == 1)
                {
                    checkerboard[row][col].status = PLAYER_PIECE1;
                    display(checkerboard);
                    if (isWin(checkerboard, row, col, PLAYER_PIECE1))
                    {
                        cout << "你赢了！" << endl;
                        exit(0);
                    }
                    else if (judge())
                    {
                        cout << "平局" << endl;
                        exit(0);
                    }
                    break;
                }
                else
                {
                    cout << "您输入的位置不合理，请重新输入" << endl;
                }
            }
            cout << "请输入对方位置(行和列)" << endl;
            while (cin >> row >> col)
            {
                if (check(checkerboard[row][col].status) == 1)
                {
                    checkerboard[row][col].status = PLAYER_PIECE2;
                    display(checkerboard);
                    if (isWin(checkerboard, row, col, PLAYER_PIECE2))
                    {
                        cout << "你输了..." << endl;
                        exit(0);
                    }
                    else if (judge())
                    {
                        cout << "平局" << endl;
                        exit(0);
                    }
                    break;
                }
                else
                {
                    cout << "您输入的位置不合理，请重新输入" << endl;
                }
            }
        }
    }
    else if (type == 2)
    {
        while (1)
        {
            cout << "请输入对方位置(行和列)" << endl;
            while (cin >> row >> col)
            {
                if (check(checkerboard[row][col].status) == 1)
                {
                    checkerboard[row][col].status = PLAYER_PIECE2;
                    display(checkerboard);
                    if (isWin(checkerboard, row, col, PLAYER_PIECE2))
                    {
                        cout << "你输了..." << endl;
                        exit(0);
                    }
                    else if (judge())
                    {
                        cout << "平局" << endl;
                        exit(0);
                    }
                    break;
                }
                else
                {
                    cout << "您输入的位置不合理，请重新输入" << endl;
                }
            }
            cout << "请输入我方位置(行和列)" << endl;
            while (cin >> row >> col)
            {
                if (check(checkerboard[row][col].status) == 1)
                {
                    checkerboard[row][col].status = PLAYER_PIECE1;
                    display(checkerboard);
                    if (isWin(checkerboard, row, col, PLAYER_PIECE1))
                    {
                        cout << "你赢了！" << endl;
                        exit(0);
                    }
                    else if (judge())
                    {
                        cout << "平局" << endl;
                        exit(0);
                    }
                    break;
                }
                else
                {
                    cout << "您输入的位置不合理，请重新输入" << endl;
                }
            }
        }
    }
    else
        cout << "请重新选择先手" << endl;
}

void AI(Node **checkerboard)  //人机对战模式
{
    cout<<"AI 先手"<<endl;
    while (1)
    {
        int row=12,col=7;
        cout << "AI 行动" << endl;
        while (1)
        {
            int * res;
            res = concluate(row,col,checkerboard);
            row = res[0];
            col = res[1];
            if (check(checkerboard[row][col].status) == 1)
            {
                checkerboard[row][col].status = PLAYER_PIECE2;
                display(checkerboard);
                if (isWin(checkerboard, row, col, PLAYER_PIECE2))
                {
                    cout << "你输了..." << endl;
                    exit(0);
                }
                else if (judge())
                {
                    cout << "平局" << endl;
                    exit(0);
                }
                break;
            }
            else
            {
                cout << "ai 计算有误" << endl;
            }
        }
        cout << "请输入我方位置(行和列)" << endl;
        while (cin >> row >> col)
        {
            if (check(checkerboard[row][col].status) == 1)
            {
                checkerboard[row][col].status = PLAYER_PIECE1;
                display(checkerboard);
                if (isWin(checkerboard, row, col, PLAYER_PIECE1))
                {
                    cout << "你赢了！" << endl;
                    exit(0);
                }
                else if (judge())
                {
                    cout << "平局" << endl;
                    exit(0);
                }
                break;
            }
            else
            {
                cout << "您输入的位置不合理，请重新输入" << endl;
            }
        }

    }
}

int main()
{
    Node **checkerboard = new Node*[29];
    for (int i = 0; i < 29; i++)
        checkerboard[i] = new Node[15];
    checkerBoardInit(checkerboard);
    display(checkerboard);
    lineInit(line, checkerboard);
    cout << " 请选择游戏模式，1为双人对战模式，2为人机对战模式" << endl;
    /*for (int i = 0; i < 45; i++)   //检查45条直线对应的长度是否正确
    {
        cout << line[i].lenth << "   ";
        if (i == 14 || i == 29)
            cout << endl;
    }*/
    int type;
    while(cin >> type)
    {
        if(type == 1||type ==2)
            break;
        else
            cout<<"请选择正确的游戏模式"<<endl;
    }
    if (type == 1)
    {
        people(checkerboard);
    }
    else if (type == 2)
    {
        AI(checkerboard);
    }
    else
        cout << "请重新选择游戏模式" << endl;
}