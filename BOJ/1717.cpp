#include <bits/stdc++.h>

using namespace std;

//백준_1717_집합의표현 

#define MAXN 1000002 

int n,m;
int unf[MAXN];

int findFunc(int a){
	if(unf[a]==a) return a;
	else return unf[a]=findFunc(unf[a]); 
}

void unionFunc(int x, int y){
	unf[findFunc(x)] = findFunc(y);
}

int main(){
	//ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	//freopen("input.txt", "rt", stdin);
	cin>>n>>m;
	for(int i=0; i<=n; i++) unf[i]=i;
	
	int cmd,x,y;
	for(int j=0; j<m; j++){
		scanf("%d %d %d", &cmd, &x, &y);
		if(cmd==0){
			unionFunc(x,y);
		}
		else if(cmd==1){
			if(findFunc(x)==findFunc(y)) printf("YES\n");
			else printf("NO\n");
		}
	}
	
	
	return 0; 
}
