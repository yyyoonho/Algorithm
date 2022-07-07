#include <iostream>
#include <vector>
#include <queue>
using namespace std;

//boj_2644
//BFS DFS

int n,m;
int a,b;

vector<int> chonsu[101];
queue<int> Q;
bool visited[101];
int ans[101];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	//freopen("input.txt", "rt", stdin);
	cin>>n;
	cin>>a>>b;
	cin>>m;
	
	int x,y;
	bool aCheck=false;
	bool bCheck=false;
	for(int i=0; i<m; i++){
		cin>>x>>y;
		chonsu[x].push_back(y);
		chonsu[y].push_back(x);
	}
	
	Q.push(a);
	visited[a]=true;
	ans[a]=0;
	while(true){
		int now = Q.front();
		Q.pop();
		
		if(now==b){
			if(ans[b]==0) cout<<"-1";
			else cout<<ans[b];
			break;
		}
		
		for(int i=0; i<chonsu[now].size();i++){
			if(visited[chonsu[now][i]]) continue;
			Q.push(chonsu[now][i]);
			visited[chonsu[now][i]] = true;
			ans[chonsu[now][i]] = ans[now]+1;
		}
		
		if(Q.empty()){
			cout<<"-1";
			break;
		}
	}
	
	return 0;
}
