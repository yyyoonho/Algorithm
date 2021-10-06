#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

//백준_로봇_#1726

int N,M;
int map[101][101];
int visit[101][101][4];
int rX,rY,rD;
int oX,oY,oD;
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};

struct Edge{
	int x;
	int y;
	int d;
	Edge(int x1, int y1, int d1){
		x=x1;
		y=y1;
		d=d1;
	}
};

void BFS(){
	queue<Edge> Q;
	Q.push(Edge(rX,rY,rD));
	visit[rX][rY][rD]=0;
	
	while(!Q.empty()){
		Edge tmp = Q.front();
		int x=tmp.x;
		int y=tmp.y;
		int d=tmp.d;
		Q.pop();
		
		//도착
		if(x==oX && y==oY && d==oD){
			cout<<visit[x][y][d]<<endl;
			return;
		}
		
		//현재방향으로 Go K (k=1,2,3)
		for(int k=1; k<=3; k++){
			int nextX=x+dx[d]*k;
			int nextY=y+dy[d]*k;
			
			if(visit[nextX][nextY][d]!=-1) continue;
			
			if(nextX>=0 && nextX<N && nextY>=0 && nextY<M && map[nextX][nextY]==0){
				visit[nextX][nextY][d]=visit[x][y][d]+1;
				Q.push(Edge(nextX,nextY,d));
			}
			else
				break;
		} 
		
		//방향 바꾸기.
		if(d==0 || d==1){
			int nextD=2;
			if(visit[x][y][nextD]==-1){
				visit[x][y][nextD]=visit[x][y][d]+1;
				Q.push(Edge(x,y,nextD));
			}
			nextD=3;
			if(visit[x][y][nextD]==-1){
				visit[x][y][nextD]=visit[x][y][d]+1;
				Q.push(Edge(x,y,nextD));
			}
		}
		if(d==2 || d==3){
			int nextD=1;
			if(visit[x][y][nextD]==-1){
				visit[x][y][nextD]=visit[x][y][d]+1;
				Q.push(Edge(x,y,nextD));
			}
			nextD=0;
			if(visit[x][y][nextD]==-1){
				visit[x][y][nextD]=visit[x][y][d]+1;
				Q.push(Edge(x,y,nextD));
			}
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
    //freopen("input.txt", "rt", stdin);
    
    cin>>N>>M;
    for(int i=0; i<N; i++){
    	for(int j=0; j<M; j++){
    		cin>>map[i][j];			
		}
	}
	
	memset(visit,-1,sizeof(visit));
	
	cin>>rX>>rY>>rD;
	cin>>oX>>oY>>oD;
	rX--;rY--;rD--;
	oX--;oY--;oD--;
	
	BFS();
	
	
	return 0;
}
