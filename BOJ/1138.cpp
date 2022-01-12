#include <bits/stdc++.h>

using namespace std;

//백준_1238_파티
//트랜스포스 그래프를 이용하자! 

struct Data{
	int v;
	int w;
	Data(){
	}
	Data(int v1, int w1):v(v1),w(w1){
	}
	bool operator<(const Data& b)const{
		return w>b.w;
	}
}; 

#define MAXN 1001
#define INF 98765432

int N,M,X;
priority_queue<Data> pQ[2];
vector<Data> v[MAXN][2];
int dist[MAXN][2];
bool isVisited[MAXN][2];

void init(){
	for(int i=0; i<MAXN; i++){
		for(int j=0; j<2; j++){
			 dist[i][j]=INF;
		}
	}
	memset(isVisited,0,sizeof(isVisited));
}

void dijkstra(int num){
	while(!pQ[num].empty()){
		Data now = pQ[num].top();
		pQ[num].pop();
		
		if(isVisited[now.v][num]) continue;
		isVisited[now.v][num]=true;
		
		for(int i=0; i<v[now.v][num].size(); i++){
			Data next=v[now.v][num].at(i);
			if(dist[next.v][num]>dist[now.v][num]+next.w){
				dist[next.v][num]=dist[now.v][num]+next.w;
				pQ[num].push(Data(next.v,dist[next.v][num]));
			}
		}
	} 
	
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	//freopen("input.txt", "rt", stdin);
	cin>>N>>M>>X;
	
	init();
	
	int x,y,w;
	for(int i=0; i<M; i++){
		cin>>x>>y>>w;
		v[x][0].push_back(Data(y,w));
		v[y][1].push_back(Data(x,w));
	}
	

	
	for(int i=0; i<2; i++){
		dist[X][i]=0;
		pQ[i].push(Data(X,0));
		dijkstra(i);
	}
	
	int answer=-1;
	for(int i=1; i<=N; i++){
		answer=max(answer, dist[i][0]+dist[i][1]);
	}
	
	cout<<answer<<endl;
	
	return 0; 
}
