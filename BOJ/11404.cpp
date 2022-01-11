#include <bits/stdc++.h>

using namespace std;

//백준_11404_플루이드 

#define MAXN 101
#define INF 987654321
int n,m;
int map1[MAXN][MAXN];

void init(){
	for(int i=0; i<MAXN; i++){
		for(int j=0; j<MAXN; j++){
			//if(i==j) map1[i][j]=0;
			map1[i][j]=INF;
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	//freopen("input.txt", "rt", stdin);
	cin>>n>>m;
	
	init();
	
	int x,y,w;
	for(int i=1; i<=m; i++){
		cin>>x>>y>>w;
		map1[x][y]=min(w,map1[x][y]);
	}
	
	//플루이드-워샬 
	for(int i=1; i<=n; i++){ //i -> 경유지 
		for(int j=1; j<=n; j++){
			for(int k=1; k<=n; k++){
				if(j==k) continue; 
				if(map1[j][i]==INF || map1[i][k]==INF) continue;
				map1[j][k]=min(map1[j][k],map1[j][i]+map1[i][k]);
			}
		}
	}

	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++){
			if(map1[i][j]==INF){
				cout<<0<<" ";
			}
			else{
				cout<<map1[i][j]<<" ";
			}
		}
		cout<<endl;
	}
	
	return 0; 
}
