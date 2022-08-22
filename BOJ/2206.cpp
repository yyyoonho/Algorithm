#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

//boj_2206
//3����
//�ܼ� BFS
//1. �׷����� ���� �����
//2. BFS ���� 

#define MAXN 1005
#define MAXM 1005
#define INF 2147483647
int N,M;
int K=2;
char map[MAXN][MAXM];
int dist[MAXN][MAXM][2]; //���������� i�� j������ ���� k�� �μ��� �̵��ϴ� �ִܰŸ� 

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
				
				//�̵��Ϸ��� ��ġ�� 0�� �ִ� ��� 
				if(map[ni][nj] == '0'){
					con[i][j][0].push_back(Node(ni,nj,0));
					con[i][j][1].push_back(Node(ni,nj,1));
				}
				//�̵��Ϸ��� ��ġ�� 1�� �ִ� ��� (���� �μ��� ���) 
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
			if(dist[nxt.x][nxt.y][nxt.cnt]!=-1) continue; //�̹� �湮 ó���� �� ����
			dist[nxt.x][nxt.y][nxt.cnt] = dist[cur.x][cur.y][cur.cnt]+1;
			Q.push(nxt);
		}
	}
	
	//���� ���
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
