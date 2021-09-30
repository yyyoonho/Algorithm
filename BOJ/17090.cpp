#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

//백준_미로탈출하기_#17090

int N,M;
char map[500][500]; 
int visited[500][500];
int dx[]={-1,0,1,0};
int dy[]={0,1,0,-1};
int cnt;
queue<pair<int,int> > history;

void Move(int &x, int &y){
	if(map[x][y]=='U'){
		x=x+dx[0];
		y=y+dy[0];
	}
	else if(map[x][y]=='R'){
		x=x+dx[1];
		y=y+dy[1];
	}
	else if(map[x][y]=='D'){
		x=x+dx[2];
		y=y+dy[2];
	}
	else if(map[x][y]=='L'){
		x=x+dx[3];
		y=y+dy[3];
	}
}

void SuccessFunc(){
	while(!history.empty()){
		int tmpX=history.front().first;
		int tmpY=history.front().second;
		visited[tmpX][tmpY]=2;
		history.pop();
	}
	cnt++;
	return;
}

void FailedFunc(){
	while(!history.empty()){
		int tmpX=history.front().first;
		int tmpY=history.front().second;
		visited[tmpX][tmpY]=1;
		history.pop();
	}
	return;
}

void DFS(int x, int y){
	int nextX=x;
	int nextY=y;
	Move(nextX, nextY);
	
	//탈출성공 
	if(nextX<0 || nextX>=N || nextY<0 || nextY>=M){
		SuccessFunc();
	}
	
	//다음 칸으로 
	if(nextX>=0 && nextX<N && nextY>=0 && nextY<M){
		if(visited[nextX][nextY]==0){
			history.push(make_pair(nextX,nextY));
			visited[nextX][nextY]=3;
			DFS(nextX, nextY);
		}
		else if(visited[nextX][nextY]==2){
			SuccessFunc();
		}
		else if(visited[nextX][nextY]==1 || visited[nextX][nextY]==3){
			FailedFunc();
			return;
		}
	}
	
	return; 
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
	
	for(int i=0; i<N; i++){
		for(int j=0; j<M; j++){
			history.push(make_pair(i,j));
			visited[i][j]=3;
			DFS(i,j);
		}
	}
	
	cout<<cnt<<endl;
	
	return 0;
}
