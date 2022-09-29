#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
 
//boj_16197
//BFS
//백트래킹 

#define MAXN 21
#define MAXM 21

int dx[4]={-1,0,1,0};
int dy[4]={0,-1,0,1};
bool visited[MAXN][MAXM][MAXN][MAXM];
int N,M;
char map[MAXN][MAXM];

struct Coin{
	int aX;
	int aY;
	int bX;
	int bY;
	int cnt;
	Coin(int a1, int a2, int b1, int b2, int c){
		aX=a1; aY=a2;
		bX=b1; bY=b2;
		cnt=c;
	}
};

queue<Coin> Q;

void Input(){
	cin>>N>>M;
	
	int aX,aY;
	int bX,bY;
	int cnt=0;
	
	for(int i=0; i<N; i++){
		for(int j=0; j<M; j++){
			cin>>map[i][j];
			if(map[i][j]=='o'){
				if(cnt==0){
					aX=i; aY=j;
					cnt++;
				}
				else{
					bX=i; bY=j;
				} 
			}
		}
	}
	
	Q.push(Coin(aX,aY,bX,bY,0));
}

void Solve(){
	while(!Q.empty()){
		Coin now = Q.front();
		Q.pop();
		
		if(now.cnt>=10) break; 
		
		//방문체크하기 
		if(visited[now.aX][now.aY][now.bX][now.bY]) continue;
		visited[now.aX][now.aY][now.bX][now.bY]=true;
		
		//코인이동시키기 
		for(int i=0; i<4; i++){
			int nextaX=now.aX+dx[i];
			int nextaY=now.aY+dy[i];
			int nextbX=now.bX+dx[i];
			int nextbY=now.bY+dy[i];
			
			//벽에 닿은경우
			if(nextaX>=0 && nextaX<N && nextaY>=0 && nextaY<M){
				if(map[nextaX][nextaY]=='#'){
					nextaX=now.aX;
					nextaY=now.aY;
				}
			} 
			if(nextbX>=0 && nextbX<N && nextbY>=0 && nextbY<M){
				if(map[nextbX][nextbY]=='#'){
					nextbX=now.bX;
					nextbY=now.bY;
				}
			}
			
			//코인이 하나만 나간 경우의 범위체크(==정답체크) 
			if((nextaX<0 || nextaX>=N || nextaY<0 ||nextaY>=M) && (nextbX>=0 && nextbX<N && nextbY>=0 && nextbY<M)){
				cout<<now.cnt+1;
				//cout<<endl<<"1번"<<endl;
				//cout<<nextaX<<" "<<nextaY<<" "<<nextbX<<" "<<nextbY;
				exit(0); 
			}
			else if((nextaX>=0 && nextaX<N && nextaY>=0 && nextaY<M) && (nextbX<0 || nextbX>=N || nextbY<0 ||nextbY>=M)){
				cout<<now.cnt+1;
				//cout<<endl<<"2번"<<endl;
				//cout<<nextaX<<" "<<nextaY<<" "<<nextbX<<" "<<nextbY;
				exit(0); 
			}
			
			if((nextaX>=0 && nextaX<N && nextaY>=0 && nextaY<M) && (nextbX>=0 && nextbX<N && nextbY>=0 && nextbY<M)){
				if(!visited[nextaX][nextaY][nextbX][nextbY]){
					Q.push(Coin(nextaX,nextaY,nextbX,nextbY,now.cnt+1));
				}
			}
		}
		
	}
	
	cout<<-1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	//freopen("input.txt", "rt", stdin);
	
	Input();
	Solve();
	
	return 0;
} 
