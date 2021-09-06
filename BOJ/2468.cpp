#include <algorithm>
#include <iostream>
#include <cstring>
using namespace std;

//BOJ_안전영역 #2468

int map[100][100]; 
int check[100][100];
int dx[4]={-1,0,1,0};
int dy[4]={0,-1,0,1};
int N,cnt;
int highArea=-2147483647;
int max1=-2147483647;

struct Edge{
	int x;
	int y;
	Edge(int x1, int y1){
		x=x1;
		y=y1;
	}
};

void DFS(int wave, Edge now){
	int nowX=now.x;
	int nowY=now.y;
	for(int i=0; i<4; i++){
		int nextX=nowX+dx[i];
		int nextY=nowY+dy[i];
		if(nextX>=0 && nextX<N && nextY>=0 && nextY<N 
				&& check[nextX][nextY]==0 && map[nextX][nextY]>wave){
			check[nextX][nextY]=1;
			DFS(wave, Edge(nextX, nextY));
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "rt", stdin);
	cin>>N;
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			cin>>map[i][j];
			highArea=max(highArea,map[i][j]);
		}
	}
	
	for(int k=0; k<highArea; k++){
		memset(check,0,sizeof(check));
		cnt=0;
		for(int i=0; i<N; i++){
			for(int j=0; j<N; j++){
				if(map[i][j]>k && check[i][j]==0) {
					check[i][j]=1;
					DFS(k, Edge(i,j));
					cnt++;
				}
			}
		}
		max1=max(cnt,max1);
	}
	
	cout<<max1;
	
	return 0;
}
