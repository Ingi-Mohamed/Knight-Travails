#include <iostream>
#include <iomanip>
#include <conio.h>
#include <bits/stdc++.h>
#include <ctime>
#include<windows.h>
#include <chrono>

using namespace std;


void possible();
void exits(int);
void setup();
void draw();
void input();
void setup();
void check();

const int l=18,w=18;//board (display) length ,width
int x,y,x2,y2;
int Hor=0,vert=0;
int counts = 1;
bool printed=false;
bool rightmove=false;
const int ver[]={-1,-2,-2,-1,1,2,2,1};
const int hor[]={2,1,-1,-2,-2,-1,1,2};
const int n=8;
int row,col;
int board[n][n]={0};
 int dx[]={ 2, 1, -1, -2, -2, -1, 1, 2 }; //steps it can take on board like a knight for row
 int dy[]={ 1, 2, 2, 1, -1, -2, -2, -1 };//steps it can take on board like a knight for column
struct player { bool lose = false; };
player p;

int main()
{
     auto start = chrono::steady_clock::now();

    setup();

    while(!p.lose)
    {

        draw();
        input();
Sleep(100);//in milliseconds
    }
cout << "\nYou lose\n";

auto end = chrono::steady_clock::now();
cout << "Elapsed time in milliseconds: "
        << chrono::duration_cast<chrono::milliseconds>(end - start).count()
        << " ms" << endl;

    return 0;
}


void input(){
      if(_kbhit())
    {
char c = _getch();
        switch(c){
        case 'm': {cin.ignore();cin>>Hor>>vert;
        rightmove=false;
        check();
         break;}
        case 'x':exit(0); break;
        default: cout<<"wrong entry";
}
 x2=x+vert;//-ve left
 y2=y+Hor;//-ve upward
if(x2>=0&&y2>=0&&x2<n&&y2<n&&board[x2][y2]==0)
    {
x=x2; y=y2;
counts++;
board[x][y]=counts;//initial position=1
}
else  p.lose=true;
}
}
void setup()
{
//random initial position
srand(time(NULL));
x = (rand() %(n) );//0-->n-1
y = (rand() %(n) );//0-->n-1
board[x][y]=1;
p.lose=false;
}
void draw()
{
    system("cls");
cout<<" Once upon a time in a kingdom far away lived a king who loved his people \n He wanted to make sure that they were living comfortably and without a worry \n So he ordered the best knight in the kingdom to visit all the villages\n But the knight loved to challenge himself not to visit the villagers more than once."<<endl<<endl;
cout<<" you can't visit a square more than once \n press m->move then enter horizontal distance then vertical one \n -ve entry is left or up ,+ve is right or down\n possible entries are 1,2,-1,2 \n Example 3>>1 is forbidden \n each time you are allowed to enter a combination of 2 transitions in x or y and 1 in the other dimension \n";//instructions

   for(int i =0 ; i< l; i++)
    {
        for(int j=0; j<w; j++)
        {

              printed=false;
                for(int k=0;k<n;k++){
           for(int l=0;l<n;l++){
               if (board[k][l]!=0&& i==2*k+1 &&j==2*l+1) {cout<<board[k][l];
               printed=true;}}

              }
              if(printed==false)
              {if(i%2==0&&j%2==0) cout <<"-";
              else
                  cout <<" ";
              }

        }
        cout << endl;
    }
}
void check(){
for(int m=0;m<n;m++)
{
  if (vert==dx[m]&&Hor==dy[m])
       {

        rightmove=true;
        break;}
}
if(rightmove==false) exit (0);


}




