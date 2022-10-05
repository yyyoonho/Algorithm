#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
 
//boj_1325
//TLE 조심
//메모리초과 조심 

#define MAXN 10001
int N,M;
vector<int> com[MAXN];
bool visited[MAXN];
int faithCnt[MAXN];
queue<int> Q;

void Input(){
	cin>>N>>M;
	int a,b;
	for(int i=0; i<M; i++){
		cin>>a>>b;
		com[b].push_back(a);
	}
}

void Solve(){
	for(int i=1; i<=N; i++){
		memset(visited,0,sizeof(visited));
		Q.push(i);
		visited[i]=true;
		
		while(!Q.empty()){
			int now = Q.front();
			Q.pop();
			
			for(int j=0; j<com[now].size(); j++){
				int next = com[now].at(j);
				if(visited[next]) continue;
				
				Q.push(next);
				visited[next]=true;
				faithCnt[i]++;
				//cout<<"i: "<<i<<" "<<faithCnt[i]<<endl; 
			}
		}
	}
	
	int maxAns=-1;
	for(int i=1; i<=N; i++){
		maxAns=max(maxAns,faithCnt[i]);
	}
	for(int i=1; i<=N; i++){
		if(maxAns==faithCnt[i]) cout<<i<<" ";
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	//freopen("input.txt", "rt", stdin);
	
	Input();
	Solve();
	
	return 0;
} 
