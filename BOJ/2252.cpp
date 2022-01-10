#include <bits/stdc++.h>

using namespace std;

//백준_2252_줄 세우기 

#define MAXN 32001
int indegree[MAXN]; 
int N,M;
vector<int> v[MAXN];
queue<int> Q;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	//freopen("input.txt", "rt", stdin);
	cin>>N>>M;
	
	int x,y;
	for(int i=1; i<=M; i++){
		cin>>x>>y;
		indegree[y]++;
		v[x].push_back(y);
	}
	
	for(int i=1; i<=N; i++){
		if(indegree[i]==0) Q.push(i);
	}
	
	while(!Q.empty()){
		int tmp=Q.front();
		Q.pop();
		
		cout<<tmp<<" ";
		
		for(int i=0; i<v[tmp].size(); i++){
			indegree[v[tmp].at(i)]--;
			if(indegree[v[tmp].at(i)] == 0) Q.push(v[tmp].at(i));
		}
	}
	
	return 0; 
}
