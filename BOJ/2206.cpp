#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

//boj_2206
//3차원
//단순 BFS
//1. 그래프의 간선 만들기
//2. BFS 실행 

#define MAXN 1005
#define MAXM 1005
#define INF 2147483647
int N,M;
int K=2;
char map[MAXN][MAXM];
int dist[MAXN][MAXM][2]; //시작점에서 i행 j열까지 벽을 k개 부수고 이동하는 최단거리 

int dx[4]={-1,0,1,0};
int dy[4]={0,-1,0,1};

struct Node{
	int x,y,cnt;
	Node(int x1, int y1, int c1){
		x=x1;
		y=y1;
		cnt=c1;
	}
}; 

vector<Node> con[MAXN][MAXM][2]; 

void Input(){
	cin>>N>>M;
	for(int i=1; i<=N; i++){
		for(int j=1; j<=M; j++){
			cin>>map[i][j];
		}
	}
}

void GraphConstruction(){
	for(int i=1; i<=N; i++){
		for(int j=1; j<=M; j++){
			for(int D=0; D<4; D++){
				int ni = i+dx[D];
				int nj = j+dy[D];
				
				if(ni<1 || ni>N || nj<1 || nj>M) continue;
				
				//이동하려는 위치에 0이 있는 경우 
				if(map[ni][nj] == '0'){
					con[i][j][0].push_back(Node(ni,nj,0));
					con[i][j][1].push_back(Node(ni,nj,1));
				}
				//이동하려는 위치에 1이 있는 경우 (벽을 부수는 경우) 
				else{
					con[i][j][0].push_back(Node(ni,nj,1));
				} 
			}
		}
	}
}

void Pro(){
	GraphConstruction();
	
	//BFS initialize
	for(int i=1; i<=N; i++){
		for(int j=1; j<=M; j++){
			for(int k=0; k<K; k++){
				dist[i][j][k]=-1;
			}
		}
	}
	
	dist[1][1][0]=1;
	queue<Node> Q;
	Q.push(Node(1,1,0));
	
	//BFS
	while(!Q.empty()){
		Node cur=Q.front();
		Q.pop();
		for(auto& nxt : con[cur.x][cur.y][cur.cnt]){
			if(dist[nxt.x][nxt.y][nxt.cnt]!=-1) continue; //이미 방문 처리가 된 정점
			dist[nxt.x][nxt.y][nxt.cnt] = dist[cur.x][cur.y][cur.cnt]+1;
			Q.push(nxt);
		}
	}
	
	//정답 출력
	if(dist[N][M][0]==-1) dist[N][M][0]=INF; 
	if(dist[N][M][1]==-1) dist[N][M][1]=INF; 
	int ans = min(dist[N][M][0], dist[N][M][1]);
	if(ans==INF) ans=-1;
	cout<<ans;
	
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	//freopen("input.txt", "rt", stdin);
	
	Input();
	Pro();
	
	return 0;
} 
