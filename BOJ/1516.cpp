#include <bits/stdc++.h>

using namespace std;

//백준_1516_게임개발 

#define MAXN 501
int indegree[MAXN];
int cost[MAXN];
int DP[MAXN];
vector<int> v[MAXN];
queue<int> Q;

int N,input;

void init(){
	memset(indegree,0,sizeof(indegree));
	memset(cost,0,sizeof(cost));
	memset(DP,0,sizeof(DP));
	for(int i=0; i<MAXN; i++) v[i].clear();
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	//freopen("input.txt", "rt", stdin);
	cin>>N;
	
	init();
	
	for(int i=1; i<=N; i++){
		cin>>input;
		cost[i]=input;
		while(true){
			cin>>input;
			if(input==-1)break;
			v[input].push_back(i);
			indegree[i]++;
		}
	}
	
	for(int i=1; i<=N; i++){
		if(indegree[i]==0){
			Q.push(i);
			DP[i]=cost[i];
		}
	}
	
	while(!Q.empty()){
		int tmp=Q.front();
		Q.pop();
		
		//인접노드 카운트 -1
		for(int i=0; i<v[tmp].size(); i++){
			DP[v[tmp][i]] = max(cost[v[tmp][i]]+DP[tmp],DP[v[tmp][i]]);
			indegree[v[tmp][i]]--;
			if(indegree[v[tmp][i]]==0) Q.push(v[tmp][i]);
		} 
	}
	
	for(int i=1; i<=N; i++){
		cout<<DP[i]<<endl;
	}
	
	
	return 0; 
}
