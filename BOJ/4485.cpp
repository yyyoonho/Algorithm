#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

#define MAXN 130 
#define INF 2147483647

//πÈ¡ÿ 4485_≥Ïªˆ ø  ¿‘¿∫ æ÷∞° ¡©¥Ÿ¡ˆ? 

struct Data{
	int vertexX;
	int vertexY;
	int weight;
	Data(int v1, int v2, int w1){
		vertexX=v1;
		vertexY=v2;
		weight=w1;
	}
	bool operator<(const Data& b)const{
		return weight>b.weight;
	}
};

int dx[4]={-1,0,1,0};
int dy[4]={0,-1,0,1};
priority_queue<Data> pQ;
int dist[MAXN][MAXN];
bool visit[MAXN][MAXN];
int map[MAXN][MAXN];
int N;

void init(){
	while(!pQ.empty()) pQ.pop();
	for(int i=0; i<MAXN; i++){
		for(int j=0; j<MAXN; j++){
			map[i][j]=0;
			dist[i][j]=INF;
			visit[i][j]=false;
		}
		
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	freopen("input.txt", "rt", stdin);
	
	int cnt=0;
	while(true){
		cnt++;
		
		cin>>N;
		if(N==0) break;
		
		init();
		
		for(int i=0; i<N; i++){
			for(int j=0; j<N; j++){
				cin>>map[i][j];
			}
		}
		
		pQ.push(Data(0,0,map[0][0]));
		dist[0][0]=map[0][0];
		
		while(!pQ.empty()){
			Data now=pQ.top();
			pQ.pop();
			
			if(visit[now.vertexX][now.vertexY]) continue;
			
			for(int i=0; i<4; i++){
				int nextX=now.vertexX+dx[i];
				int nextY=now.vertexY+dy[i];
				if(nextX<0 || nextX>=N || nextY<0 || nextY>=N) continue;
				
				if(dist[nextX][nextY]>dist[now.vertexX][now.vertexY]+map[nextX][nextY]){
					if(visit[nextX][nextY]) continue;
					dist[nextX][nextY]=dist[now.vertexX][now.vertexY]+map[nextX][nextY];
					pQ.push(Data(nextX,nextY,dist[nextX][nextY]));
				}
			}
		}
		
		cout<<"Problem "<<cnt<<": "<<dist[N-1][N-1]<<"\n";
	}
	

	return 0; 
}
