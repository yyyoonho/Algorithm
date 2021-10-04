#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

//백준_미로탈출_#14923

int N,M;
int Hx,Hy; // 홍익이가 미로에 떨어진 위치.
int Ex,Ey; // 탈출위치.
int map[1000][1000];
bool visit[1000][1000][2];
int dx[]={-1,0,1,0};
int dy[]={0,-1,0,1};

struct Edge{
	int x,y,d,key; 
	Edge(int x1, int y1, int d1, int key1){
		x=x1; y=y1;
		d=d1; key=key1;
	}
};

void BFS(int Hx, int Hy){
	queue<Edge> Q;
	Q.push(Edge(Hx,Hy,0,1));
	visit[Hx][Hy][1]=true;
	
	while(!Q.empty()){
		Edge tmp=Q.front();
		int x= tmp.x;
		int y= tmp.y;
		int d= tmp.d;
		int key=tmp.key;
		Q.pop();
		
		if(x==Ex && y==Ey){
			cout<<d<<endl;
			return;
		}
		
		for(int i=0; i<4; i++){
			int nextX=x+dx[i];
			int nextY=y+dy[i];
			
			if(nextX>=0 && nextX<N && nextY>=0 && nextY<M && visit[nextX][nextY][key]==false){
				if(map[nextX][nextY]==0){
					Q.push(Edge(nextX,nextY,d+1,key));
					visit[nextX][nextY][key]=true;
				}
				if(map[nextX][nextY]==1 && key==1){
					Q.push(Edge(nextX,nextY,d+1,0));
					visit[nextX][nextY][0]=true;
				}
			}
		}
		
	}
	
	cout<<-1<<endl;
}

int main(){
	ios_base::sync_with_stdio(false);
    freopen("input.txt", "rt", stdin);
    cin>>N>>M>>Hx>>Hy>>Ex>>Ey;
	Hx--;Hy--;Ex--;Ey--;
	
	for(int i=0; i<N; i++){
		for(int j=0; j<M; j++){
			cin>>map[i][j];
		}
	}
	
	BFS(Hx, Hy);
	
	
	return 0;
}
