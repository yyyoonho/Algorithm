#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;

//boj_1012
//BFS

#define MAXM 50

int T;
int M,N,K;
bool map[MAXM][MAXM];
queue<pair<int,int> > Q;

int ans=0;

int dx[4]={-1,0,1,0};
int dy[4]={0,-1,0,1};

void BFS(){
	int nowX;
	int nowY;
	
	while(true){
		if(Q.empty()) break;
		
		nowX=Q.front().first;
		nowY=Q.front().second;
		Q.pop();
		
		for(int i=0; i<4; i++){
			if(nowX+dx[i]<0 || nowX+dx[i]>=N || nowY+dy[i]<0 || nowY+dy[i]>=M) continue;
			if(map[nowX+dx[i]][nowY+dy[i]]){
				 Q.push(make_pair(nowX+dx[i],nowY+dy[i]));
				 map[nowX+dx[i]][nowY+dy[i]]=false;
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	freopen("input.txt", "rt", stdin);
	
	cin>>T;
	
	for(int tc=0; tc<T; tc++){
		memset(map,false,sizeof(map));
		ans=0;
		
		cin>>M>>N>>K;
		
		int a,b;
		for(int i=0; i<K; i++){
			cin>>a>>b;
			map[b][a]=true;
		}
		
		for(int i=0; i<N; i++){
			for(int j=0; j<M; j++){
				if(map[i][j]){
					Q.push(make_pair(i,j));
					map[i][j]=false;
					BFS();
					ans++;
				} 
			}
		}
		cout<<ans<<endl;
	}

	return 0;
} 
