#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

//14500
//하드코딩도 필요할지도? 

#define MAXN 501
#define MAXM 501

int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
int N,M;
int maxValue;
int map[MAXN][MAXM];
bool visited[MAXN][MAXM];

void Input(){
	cin>>N>>M;
	for(int i=0; i<N; i++){
		for(int j=0; j<M; j++){
			cin>>map[i][j];
		}
	}
}

void DFS(int x, int y, int v, int cnt){
	if(cnt==4){
		maxValue=max(maxValue,v);
		return;
	}
	else{
		for(int i=0; i<4; i++){
			int nextX=x+dx[i];
			int nextY=y+dy[i];
			
			if(nextX<0 || nextX>=N || nextY<0 || nextY>=M) continue;
			if(visited[nextX][nextY]) continue;
			
			visited[nextX][nextY]=true;
			DFS(nextX,nextY,v+map[nextX][nextY],cnt+1);
			visited[nextX][nextY]=false;
		}
	}
}

void Shape1(int x, int y){
	int sum=0;
	sum=map[x][y]+map[x-1][y]+map[x][y-1]+map[x][y+1];
	maxValue=max(maxValue,sum);
}

void Shape2(int x, int y){
	int sum=0;
	sum=map[x][y]+map[x-1][y]+map[x+1][y]+map[x][y-1];
	maxValue=max(maxValue,sum);
}

void Shape3(int x, int y){
	int sum=0;
	sum=map[x][y]+map[x+1][y]+map[x][y-1]+map[x][y+1];
	maxValue=max(maxValue,sum);
}

void Shape4(int x, int y){
	int sum=0;
	sum=map[x][y]+map[x+1][y]+map[x-1][y]+map[x][y+1];
	maxValue=max(maxValue,sum);
}

void Solve(){
	for(int i=0; i<N; i++){
		for(int j=0; j<M; j++){
			visited[i][j]=true;
			DFS(i,j,map[i][j],1);
			visited[i][j]=false;
			
			if(i>0 && j>0 && j<M-1) Shape1(i,j);
			if(i>0 && j>0 && i<N-1) Shape2(i,j);
			if(i<N-1 && j>0 && j<M-1) Shape3(i,j);
			if(i>0 && i<N-1 && j<M-1) Shape4(i,j);
			
		}
	}
	
	cout<<maxValue;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	//freopen("input.txt", "rt", stdin);
	
	Input();
	Solve();
	
	return 0;
} 
