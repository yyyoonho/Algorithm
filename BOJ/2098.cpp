#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

//백준_외판원순회_#2098

int N;
const int IMP=1987654321;
int map[16][16];
int dp[16][1<<16];

int TSP(int current, int visited){
	int& ret=dp[current][visited];
	
	if(ret!=-1){
		return ret;
	}
	
	//모든 마을을 방문한경우
	if(visited==(1<<N)-1){
		if(map[current][0]!=0)
			return map[current][0];
		return IMP;
	}
	
	ret=IMP;
	
	for(int i=0; i<N; i++){
		if(visited&(1<<i) || map[current][i]==0) continue;
		ret=min(ret,TSP(i,visited|(1<<i))+map[current][i]);
	}
	
	return ret;
}

int main(){
	ios_base::sync_with_stdio(false);
    freopen("input.txt", "rt", stdin);
    cin>>N;
    for(int i=0; i<N; i++){
    	for(int j=0; j<N; j++){
    		cin>>map[i][j];
		}
	}
	
	memset(dp,-1,sizeof(dp));
	int answer=TSP(0,1);
	cout<<answer<<endl;
	
	return 0;
}
