#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
 
//boj_1197
//MST
//prim 

#define MAXV 100001
#define MAXE 100001
int V,E;
long long ans=0;

struct Edge{
	int nextNode;
	int val;
	Edge(int n, int v){
		nextNode=n;
		val=v;
	}
	bool operator<(const Edge& b)const{
		return val>b.val;
	}
};

vector<Edge> map[MAXV];
bool visited[MAXV];
priority_queue<Edge> pQ;

void Input(){
	cin>>V>>E;
	int a,b,v;
	for(int i=0; i<E; i++){
		cin>>a>>b>>v;
		map[a].push_back(Edge(b,v));
		map[b].push_back(Edge(a,v));
	}
}

void Solve(){
	// 1번노트부터 출발 
	int cnt=1;
	visited[1]=true;
	for(int i=0; i<map[1].size(); i++){
		pQ.push(map[1][i]);
	}
	
	while(true){
		if(cnt==V) break;
		
		Edge now=pQ.top();
		if(visited[now.nextNode]){
			pQ.pop();
			continue;
		} 
		
		pQ.pop();
		visited[now.nextNode]=true;
		cnt++;
		ans+=now.val;
		for(int i=0; i<map[now.nextNode].size(); i++){
			pQ.push(map[now.nextNode][i]);
		}
	}
	
	cout<<ans;
	
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	//freopen("input.txt", "rt", stdin);
	
	Input();
	Solve();
	
	return 0;
} 
