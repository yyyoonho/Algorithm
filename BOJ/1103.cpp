#include <stdio.h>
#include <algorithm>
#include <queue>
#include <iostream>
#include <set>

using namespace std;

//백준_1103_게임  

char map[51][51];
int dp[51][51];
bool visited[51][51];
int N,M;
int ans;

int dx[]={-1,0,1,0};
int dy[]={0,-1,0,1};

bool DFS(int x, int y, int cnt){
	if(ans==-1) return true;
	
	ans=max(ans,cnt);
	
	visited[x][y]=true;
	dp[x][y]=cnt;
	
	for(int i=0; i<4; i++){
		int nextX=x+dx[i]*(map[x][y]-'0');
		int nextY=y+dy[i]*(map[x][y]-'0');
		
		if(nextX<0 || nextX>=N || nextY<0 || nextY>=M || map[nextX][nextY]=='H') continue;
		
		if(visited[nextX][nextY]==true){
			ans=-1;
			return true;
		}
		
		if(dp[nextX][nextY]>0 && dp[nextX][nextY]>cnt) continue;
		
		if(DFS(nextX,nextY,cnt+1)) return true;
	}
	
	visited[x][y]=false;
	return false;
	
}

int main(){
	ios_base::sync_with_stdio(false);
	//freopen("input.txt", "rt", stdin);
	cin>>N>>M;
	
	for(int i=0; i<N; i++){
		for(int j=0; j<M; j++){
			char input;
			cin>>input;
			map[i][j]=input;
		}
	}
	
	DFS(0,0,1);

	cout<<ans<<endl;
	
	return 0;
}
