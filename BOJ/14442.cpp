#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

//boj_14442
//BFS
//그래프를 먼저 만들고 BFS 돌리면 시간초과
//실시간으로 갈 수 있는 곳을 탐색해서 만들어주자. GetConnection() 

#define MAXN 1005
#define MAXM 1005
#define MAXK 11
#define INF 2147483647
int N,M,K;
char map[MAXN][MAXM];
int dist[MAXN][MAXM][MAXK];

int dx[4]={-1,0,1,0};
int dy[4]={0,-1,0,1};

struct Node{
	int x,y,cnt;
	Node(int x1, int y1, int cnt1){
		x=x1;
		y=y1;
		cnt=cnt1;
	}
};

void Input(){
	cin>>N>>M>>K;
	for(int i=1; i<=N; i++){
		for(int j=1; j<=M; j++){
			cin>>map[i][j];
		}
	}
}

vector<Node> GetConnection(int i, int j, int k){
	vector<Node> con;	
		for(int p=0; p<4; p++){
			int nx= i+dx[p];
			int ny= j+dy[p];
			
			if(nx<1 || nx>N || ny <1 || ny>M) continue;
		//이동할 곳이 0 인 경우
			if(map[nx][ny]=='0'){
				con.push_back(Node(nx,ny,k));
			}
			//이동할 곳이 1(=벽) 인경우 
			else{
				if(k+1<=K){
					con.push_back(Node(nx,ny,k+1));
				}
			}
		}
	return con;
}

void Solve(){
	//GraphConstruction();
	
	//BFS initialize
	for(int i=0; i<=N; i++){
		for(int j=0; j<=M; j++){
			for(int k=0; k<=K; k++){
				dist[i][j][k]=-1;
			}
		}
	} 
	
	//BFS
	queue<Node> Q;
	Q.push(Node(1,1,0));
	dist[1][1][0]=1;
	
	while(!Q.empty()){
		Node now=Q.front();
		Q.pop();
		
		for(auto& nxt: GetConnection(now.x,now.y,now.cnt)){
			if(dist[nxt.x][nxt.y][nxt.cnt]!=-1) continue;
			dist[nxt.x][nxt.y][nxt.cnt] = dist[now.x][now.y][now.cnt]+1;
			Q.push(nxt);
		}
	}
	
	int ans = INF;
    for (int k = 0; k <= K; k++) {
        if (dist[N][M][k] != -1) ans = min(ans, dist[N][M][k]);
    }
    if (ans == INF) ans = -1;
    cout << ans;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	//freopen("input.txt", "rt", stdin);
	
	Input();
	Solve();
	
	return 0;
} 
