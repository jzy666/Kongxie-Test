#include <cstdio>
#include <algorithm>
#include <queue>
#define M 205
using namespace std;
int n,m,sx,sy;
char g[M][M];
int G[M][M];
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
struct Point{
  int x,y,step;
  Point(){}
  Point(int _x,int _y,int _step):x(_x),y(_y),step(_step){}
};
int main(){
  int t;
  scanf("%d",&t);
  while(t--){
    scanf("%d%d",&m,&n);
    for(int i=0;i<m;i++){
      scanf("%s",g[i]);
      for(int j=0;j<n;j++){
        if(g[i][j]=='x')G[i][j]=2;
        else if(g[i][j]=='@'||g[i][j]=='a')G[i][j]=1;
        else if(g[i][j]=='r'){G[i][j]=0;sx=i;sy=j;}
        else G[i][j]=0;
      }
    }
    queue<Point> q;
    q.push(Point(sx,sy,0));
    int res=0x3f3f3f3f;
    while(!q.empty()){
      Point p=q.front();
      if(g[p.x][p.y]=='a'){
        res=min(res,p.step);
        q.pop();
        break;
      }
      if(g[p.x][p.y]=='x'&&G[p.x][p.y]==1){
        q.push(Point(p.x,p.y,p.step+1));
        G[p.x][p.y]=0;
      }else{
        for(int i=0;i<4;i++){
          int x=p.x+dx[i];
          int y=p.y+dy[i];
          if(x>=0&&x<m&&y>=0&&y<n&&G[x][y]){
            if(g[x][y]=='x'&&G[x][y]==2){
              q.push(Point(x,y,p.step+1));
              G[x][y]=1;
            }
            else if(g[x][y]!='x'){
              q.push(Point(x,y,p.step+G[x][y]));
              G[x][y]=0;
            }
          }
        }
      }
      q.pop();
    }
    if(res!=0x3f3f3f3f)printf("%d\n",res);
    else printf("Impossible\n");
  }
  return 0;
}