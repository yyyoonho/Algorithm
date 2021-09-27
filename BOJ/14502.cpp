#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

//백준_연구소_#14502 

int N,M,max1=-2147483647;
int map[8][8];
int dx[]={-1,0,1,0};
int dy[]={0,-1,0,1};

void Virus(){
	int cnt=0;
	queue<pair<int,int> > Q;
	
	for(int i=0; i<N; i++){
		for(int j=0; j<M; j++){
			if(map[i][j]==2){
				Q.push(make_pair(i,j));
			}
		}
	}
	
	while(!Q.empty()){
		int nowX=Q.front().first;
		int nowY=Q.front().second;
		Q.pop();
		for(int i=0; i<4; i++){
			for(int j=0; j<4; j++){
				int nextX=nowX+dx[i];
				int nextY=nowY+dy[i];
				if(nextX>=0 && nextX<N && nextY>=0 && nextY<M && map[nextX][nextY]==0){
					map[nextX][nextY]=4;
					Q.push(make_pair(nextX,nextY));
				}
			}
		}
	}
	
	for(int i=0; i<N; i++){
		for(int j=0; j<M; j++){
			if(map[i][j]==0) cnt++;
		}
	}
	
	if(cnt>max1) max1=cnt;
	
	for(int i=0; i<N; i++){
		for(int j=0; j<M; j++){
			if(map[i][j]==4) map[i][j]=0;
		}
	}
	
	return;
}

void DFS(int cnt, int x, int y){
	if(cnt==3){
		Virus();
		return;
	}
	
	for(int i=x; i<N; i++){
		for(int j=y; j<M; j++){
			if(map[i][j]==0){
				map[i][j]=3;
				DFS(cnt+1,x,y);
				map[i][j]=0;
			}
		}
	}
	
}

int main(){
	ios_base::sync_with_stdio(false);
    freopen("input.txt", "rt", stdin);
	cin>>N>>M;
	for(int i=0; i<N; i++){
		for(int j=0; j<M; j++){
			cin>>map[i][j];
		}
	}
	
	DFS(0,0,0);
	
	cout<<max1<<endl;
	
	return 0;
}
