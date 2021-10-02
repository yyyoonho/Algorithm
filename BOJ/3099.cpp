#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

//น้มุ_ลปรโ_#3099

struct Hedge{
	int x,y,time;
	Hedge(int x1, int y1 ,int time1){
		x=x1;
		y=y1;
		time=time1;
	}
};

int R,C; 
int dx[]={-1,0,1,0};
int dy[]={0,-1,0,1};
char map[50][50];
bool visit[50][50];
queue<pair<int,int> > waterQ;
queue<Hedge> hedgeQ;


void SpreadHedgehog(){
	Hedge tmp = hedgeQ.front();
	int x=tmp.x;
	int y=tmp.y;
	int time=tmp.time;
	hedgeQ.pop();
	
	if(map[x][y]=='D'){
		cout<<time<<endl;
		exit(0);
	}
	
	for(int i=0; i<4; i++){
		int nextX=x+dx[i];
		int nextY=y+dy[i];
		if(nextX>=0 && nextX<R && nextY>=0 && nextY<C){
			if(visit[nextX][nextY]==false){
				hedgeQ.push(Hedge(nextX,nextY,time+1));
				visit[nextX][nextY]=true;
			}
		}
	}
}

void SpreadWater(){
	int x=waterQ.front().first;
	int y=waterQ.front().second;
	waterQ.pop();
	
	for(int i=0; i<4; i++){
		int nextX=x+dx[i];
		int nextY=y+dy[i];
		if(nextX>=0 && nextX<R && nextY>=0 && nextY<C){
			if(map[nextX][nextY]=='D') continue;
			if(visit[nextX][nextY]==false){
				waterQ.push(make_pair(nextX,nextY));
				visit[nextX][nextY]=true;
			}
		}	
	}
}

void BFS(){
	while(!hedgeQ.empty()){	
		int a,b;
		a=waterQ.size();
		b=hedgeQ.size();
		
		for(int i=0; i<a; i++){
			SpreadWater();
		}
		
		for(int i=0; i<b; i++){
			SpreadHedgehog();
		}
		
	}
	cout<<"KAKTUS"<<endl;
}

int main(){
	ios_base::sync_with_stdio(false);
    //freopen("input.txt", "rt", stdin);
	cin>>R>>C;
	for(int i=0; i<R; i++){
		for(int j=0; j<C; j++){
			cin>>map[i][j];
			if(map[i][j]=='*'){
				waterQ.push(make_pair(i,j));
				visit[i][j]=true;
			}
			if(map[i][j]=='S'){
				visit[i][j]=true;
				hedgeQ.push(Hedge(i,j,0));
			}
			if(map[i][j]=='X'){
				visit[i][j]=true;
			}
		}
	}
	
	BFS();
	
	return 0;
}
