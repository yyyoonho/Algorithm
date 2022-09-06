#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
 
//boj_17070
//DFS
//시뮬레이션 

#define MAXN 18
int map[MAXN][MAXN];
int N;
int ans;

int dx[3]={0,1,1};
int dy[3]={1,0,1};

//dir(0==가로, 1==세로, 2==대각) 
void DFS(int x, int y, int dir){
	if(x==N && y==N){
		ans++;
		return;
	} 
	
	for(int i=0; i<3; i++){
		if((dir==0 && i==1) || (dir==1 && i==0)) continue;
		
		int nextX=x+dx[i];
		int nextY=y+dy[i];
		if(nextX>N || nextY>N || map[nextX][nextY]==1) continue;
		
		if(i==2 && (map[x+1][y]==1 || map[x][y+1]==1)) continue;
		
		DFS(nextX,nextY,i);
	}
}

void Input(){
	cin>>N;
	for(int i=1; i<=N; i++){
		for(int j=1; j<=N; j++){
			cin>>map[i][j];
		}
	}
}

void Solve(){
	DFS(1,2,0);
	cout<<ans;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	//freopen("input.txt", "rt", stdin);
	
	Input();
	Solve();
	
	return 0;
} 
