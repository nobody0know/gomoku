#include "main.h"
#include "chess_ai.h"

using namespace std;

// ������Һ͵��Ե�����
string PLAYER_PIECE1 = "  $";//man
string PLAYER_PIECE2 = "  #";//ai


Line line[45];  //x�����ֱ����0-14�y������15-29�z������30-44��

void checkerBoardInit(Node **checkerboard)  //���̳�ʼ��
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
    int k = 0; //line�����±�
    int len = 8;  //line�����Ӧλ�õĽ�����
    //x�����ֱ�߳�ʼ��
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
    //y�����ֱ�߳�ʼ��
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
    //z�����ֱ�߳�ʼ��
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

void display(Node **checkerboard) //�������
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

int check(string str)  //�ж�����λ���Ƿ����
{
    if (str == "  0")
        return 1;
    else
        return 0;
}

int isWin(Node **checkerboard, int row, int col, string status)
{
    int count = 0, m, n, i, flag = 0;
    //�ж�x����
    i = checkerboard[row][col].Line_x;  //��ȡ��x������һ��ֱ��
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
    //�ж�y����
    i = checkerboard[row][col].Line_y;  //��ȡ��y������һ��ֱ��
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
    //�ж�z����
    i = checkerboard[row][col].Line_z;  //��ȡ��z������һ��ֱ��
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

int judge()  //�ж��ǲ���ƽ��(����û��λ����)
{
    for (int i = 0; i < 15; i++)
    {
        if (line[i].state != 2)
            return 0;
    }
    return 1;
}

void people(Node **checkerboard) //˫�˶�սģʽ
{
    cout << "��ѡ����Ϸģʽ��1Ϊ�ҷ����֣�2Ϊ�Է�����" << endl;
    int type, row, col;
    while(cin >> type)
    {
        if(type == 1||type ==2)
            break;
        else
            cout<<"��ѡ����ȷ������˳��"<<endl;
    }
    if (type == 1)
    {
        while (1)
        {
            cout << "�������ҷ�λ��(�к���)" << endl;
            while (cin >> row >> col)
            {
                if (check(checkerboard[row][col].status) == 1)
                {
                    checkerboard[row][col].status = PLAYER_PIECE1;
                    display(checkerboard);
                    if (isWin(checkerboard, row, col, PLAYER_PIECE1))
                    {
                        cout << "��Ӯ�ˣ�" << endl;
                        exit(0);
                    }
                    else if (judge())
                    {
                        cout << "ƽ��" << endl;
                        exit(0);
                    }
                    break;
                }
                else
                {
                    cout << "�������λ�ò���������������" << endl;
                }
            }
            cout << "������Է�λ��(�к���)" << endl;
            while (cin >> row >> col)
            {
                if (check(checkerboard[row][col].status) == 1)
                {
                    checkerboard[row][col].status = PLAYER_PIECE2;
                    display(checkerboard);
                    if (isWin(checkerboard, row, col, PLAYER_PIECE2))
                    {
                        cout << "������..." << endl;
                        exit(0);
                    }
                    else if (judge())
                    {
                        cout << "ƽ��" << endl;
                        exit(0);
                    }
                    break;
                }
                else
                {
                    cout << "�������λ�ò���������������" << endl;
                }
            }
        }
    }
    else if (type == 2)
    {
        while (1)
        {
            cout << "������Է�λ��(�к���)" << endl;
            while (cin >> row >> col)
            {
                if (check(checkerboard[row][col].status) == 1)
                {
                    checkerboard[row][col].status = PLAYER_PIECE2;
                    display(checkerboard);
                    if (isWin(checkerboard, row, col, PLAYER_PIECE2))
                    {
                        cout << "������..." << endl;
                        exit(0);
                    }
                    else if (judge())
                    {
                        cout << "ƽ��" << endl;
                        exit(0);
                    }
                    break;
                }
                else
                {
                    cout << "�������λ�ò���������������" << endl;
                }
            }
            cout << "�������ҷ�λ��(�к���)" << endl;
            while (cin >> row >> col)
            {
                if (check(checkerboard[row][col].status) == 1)
                {
                    checkerboard[row][col].status = PLAYER_PIECE1;
                    display(checkerboard);
                    if (isWin(checkerboard, row, col, PLAYER_PIECE1))
                    {
                        cout << "��Ӯ�ˣ�" << endl;
                        exit(0);
                    }
                    else if (judge())
                    {
                        cout << "ƽ��" << endl;
                        exit(0);
                    }
                    break;
                }
                else
                {
                    cout << "�������λ�ò���������������" << endl;
                }
            }
        }
    }
    else
        cout << "������ѡ������" << endl;
}

void AI(Node **checkerboard)  //�˻���սģʽ
{
    cout<<"AI ����"<<endl;
    while (1)
    {
        int row=12,col=7;
        cout << "AI �ж�" << endl;
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
                    cout << "������..." << endl;
                    exit(0);
                }
                else if (judge())
                {
                    cout << "ƽ��" << endl;
                    exit(0);
                }
                break;
            }
            else
            {
                cout << "ai ��������" << endl;
            }
        }
        cout << "�������ҷ�λ��(�к���)" << endl;
        while (cin >> row >> col)
        {
            if (check(checkerboard[row][col].status) == 1)
            {
                checkerboard[row][col].status = PLAYER_PIECE1;
                display(checkerboard);
                if (isWin(checkerboard, row, col, PLAYER_PIECE1))
                {
                    cout << "��Ӯ�ˣ�" << endl;
                    exit(0);
                }
                else if (judge())
                {
                    cout << "ƽ��" << endl;
                    exit(0);
                }
                break;
            }
            else
            {
                cout << "�������λ�ò���������������" << endl;
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
    cout << " ��ѡ����Ϸģʽ��1Ϊ˫�˶�սģʽ��2Ϊ�˻���սģʽ" << endl;
    /*for (int i = 0; i < 45; i++)   //���45��ֱ�߶�Ӧ�ĳ����Ƿ���ȷ
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
            cout<<"��ѡ����ȷ����Ϸģʽ"<<endl;
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
        cout << "������ѡ����Ϸģʽ" << endl;
}