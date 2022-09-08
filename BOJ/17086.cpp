#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
 
//boj_17086
//BFS 

#define MAXN 51
int N,M;
int map[MAXN][MAXN];
int dx[8]={-1,-1,-1,0,0,1,1,1};
int dy[8]={-1,0,1,-1,1,-1,0,1};
queue<pair<int,int> > Q;

void Input(){
	cin>>N>>M;
	for(int i=0; i<N; i++){
		for(int j=0; j<M; j++){
			cin>>map[i][j];
			if(map[i][j]==1){
				Q.push(make_pair(i,j));
			}
		}
	}
}

void Solve(){
	int maxCnt=-999999;
	
	while(!Q.empty()){
		int nowX=Q.front().first;
		int nowY=Q.front().second;
		int value=map[nowX][nowY];
		Q.pop();
		
		for(int i=0; i<8; i++){
			int nextX=nowX+dx[i];
			int nextY=nowY+dy[i];
			
			//범위확인
			if(nextX<0 || nextX>=N || nextY<0 || nextY>=M) continue;
			
			//방문했던 곳인지 확인
			if(map[nextX][nextY]!=0) continue;
			
			Q.push(make_pair(nextX,nextY));
			map[nextX][nextY]=value+1;
		}
	}
	
	for(int i=0; i<N; i++){
		for(int j=0; j<M; j++){
			maxCnt=max(maxCnt,map[i][j]);
		}
	}
	
	cout<<maxCnt-1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	//freopen("input.txt", "rt", stdin);
	
	Input();
	Solve();
	
	return 0;
} 
