#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

//7576
//BFS
//범위체크를 잘하자 

#define MAXN 1001
#define MAXM 1001
int M,N;
int map[MAXN][MAXM];
bool visited[MAXN][MAXM];
int day[MAXN][MAXM];
int dx[4]={-1,0,1,0};
int dy[4]={0,-1,0,1};

struct Tomato{
	int x;
	int y;
	Tomato(int x1, int y1){
		x=x1;
		y=y1;
	}
};
queue<Tomato> Q;

void Input(){
	cin>>M>>N;
	for(int i=0; i<N; i++){
		for(int j=0; j<M; j++){
			cin>>map[i][j];
			if(map[i][j]==1){
				Q.push(Tomato(i,j));
				visited[i][j]=true;
			}
			day[i][j]=map[i][j];
		}
	}
}

void BFS(){
	while(!Q.empty()){
		Tomato now=Q.front();
		Q.pop();
		
		for(int i=0; i<4; i++){
			int nextX=now.x+dx[i];
			int nextY=now.y+dy[i];
			
			if(nextX<0||nextX>=N||nextY<0||nextY>=M) continue;
			if(map[nextX][nextY]==-1) continue;
			if(visited[nextX][nextY]) continue;
			
			Q.push(Tomato(nextX,nextY));
			visited[nextX][nextY]=true;
			day[nextX][nextY]=day[now.x][now.y]+1;
		}
	}
}

void Solve(){
	BFS();
	
	int maxDay=-1;
	for(int i=0; i<N; i++){
		for(int j=0; j<M; j++){
			if(day[i][j]==0){
				cout<<-1;
				return;
			}
			maxDay=max(maxDay,day[i][j]);
		}
	}

	cout<<maxDay-1;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	//freopen("input.txt", "rt", stdin);
	
	Input();
	Solve();
	
	return 0;
} 
