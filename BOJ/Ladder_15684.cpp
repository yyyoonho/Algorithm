#include <algorithm>
#include <iostream>
#include <cstring>
using namespace std;

//BOJ_사다리조작 #15684

int N,M,H,mini=2147483647; 
bool visit[31][31];

bool PlayGame(){
	for(int i=1; i<=N; i++){
		int start=i;
		for(int j=1; j<=H; j++){
			if(visit[j][start]) start++;
			else if(visit[j][start-1]) start--;
		}
		if(start!=i) return false;
	}
	return true;
}

void DFS(int idx, int cnt){
	//3을 초과한 경우. 
	if(cnt>3) return;
	
	//정답인 경우.
	if(PlayGame()){
		mini=min(mini,cnt);
		return;
	} 
	
	//추가할 선 고르기.
	for(int i=idx; i<=H; i++){
		for(int j=1; j<=N; j++){
			if(visit[i][j] || visit[i][j-1] || visit[i][j+1]) continue;
			visit[i][j]=true;
			DFS(i,cnt+1);
			visit[i][j]=false;
		}
	} 
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    cout.tie(NULL);
	//freopen("input.txt", "rt", stdin);
	memset(visit,false,sizeof(visit));
	cin>>N>>M>>H;
	for(int i=0; i<M; i++){
		int a,b;
		cin>>a>>b;
		visit[a][b]=true;
	}
	
	DFS(1,0);
	if(mini==2147483647) cout<<-1;
	else cout<<mini;
	
	return 0;
}
