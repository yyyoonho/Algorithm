#include <stdio.h>
#include <algorithm>
#include <queue>
#include <iostream>

using namespace std;

//น้มุ_9663_N-Queen

int N,ans=0;
int col[15];

bool check(int level){
	for(int i=0; i<level; i++){
		if(col[i]==col[level] || abs(col[i]-col[level])==level-i) return false;
	}
	return true;
}

void nQueen(int x){
	if(x==N) ans++;
	
	else{
		for(int i=0; i<N; i++){
			col[x]=i;
			if(check(x)) nQueen(x+1);
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	//freopen("input.txt", "rt", stdin);
	cin>>N;
	
	nQueen(0);
	
	cout<<ans;
	
	return 0;
}
