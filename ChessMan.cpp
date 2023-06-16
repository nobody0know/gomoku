#include"ChessMan.h"
extern vector<Point> Points;


//落子
void Choose() 
{		
	int count = 1;
	while (1)
	{
        {
            if(count % 2 != 0)
            {
                cout<<"you are black"<<endl;
            }
            else cout<<"you are white"<<endl;
            int x,y;
            cout<<"please input your chequer:x y"<<endl;
            cin>>x>>y;
			Point* Tem = Match(x, y);
			if (Tem && Tem->flag==0)
			{
				//奇数次，落黑子
				if (count % 2 != 0) {	
					Tem->flag = 1;	
//					setfillcolor(BLACK);
//					fillcircle(Tem->x, Tem->y, 20);
				}

				//偶数次，落白子
				else {					
					Tem->flag = 2;	
//					setfillcolor(WHITE);
//					fillcircle(Tem->x, Tem->y, 20);
				}
				count++;
				//Judge(Tem);
				if (Judge(Tem)) {
					return;
				}
			}
		}
	}
}

