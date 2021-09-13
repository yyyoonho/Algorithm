#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

//BOJ_구슬탈출4 #15653

struct Bead{
	int redX;
	int redY;
	int blueX;
	int blueY;
	int cnt;
	Bead(int x1, int y1, int x2, int y2, int cnt1){
		redX=x1;
		redY=y1;
		blueX=x2;
		blueY=y2;
		cnt=cnt1;
	}
};

queue<Bead> Q;
int N,M; 
char map[10][10];
bool visited[10][10][10][10];
int dx[]={0,-1,0,1};
int dy[]={1,0,-1,0};

int move(int& nowX, int& nowY, int directX, int directY){
	int moveDis=0;
	while(map[nowX+directX][nowY+directY]!='#' && map[nowX][nowY]!='O'){
		nowX+=directX;
		nowY+=directY;
		moveDis++;
	}
	return moveDis;
}

void BFS(){
	while(!Q.empty()){
		Bead tmp = Q.front();
		int nowRx = tmp.redX;
		int nowRy = tmp.redY;
		int nowBx = tmp.blueX;
		int nowBy = tmp.blueY;
		int cnt = tmp.cnt;
		Q.pop();
		
		//move
		for(int i=0; i<4; i++){
			int nextRx=nowRx;
			int nextRy=nowRy;
			int nextBx=nowBx;
			int nextBy=nowBy;
			
			int redMoveDistance=move(nextRx, nextRy, dx[i], dy[i]);
			int blueMoveDistance=move(nextBx, nextBy, dx[i], dy[i]);
			
			//check
			if(map[nextBx][nextBy]=='O') continue;
			if(map[nextRx][nextRy]=='O'){
				cout<<cnt+1;
				exit(0);
			}
			
			//move 후 빨간공과 파란공의 위치가 같은 경우 
			if(nextRx==nextBx && nextRy==nextBy){
				if(redMoveDistance>blueMoveDistance){
					nextRx-=dx[i];
					nextRy-=dy[i];
				}
				else{
					nextBx-=dx[i];
					nextBy-=dy[i];
				}
			}
			
			//Q push
			if(visited[nextRx][nextRy][nextBx][nextBy]==false){
				visited[nextRx][nextRy][nextBx][nextBy]=true;
				Q.push(Bead(nextRx,nextRy,nextBx,nextBy,cnt+1));
			} 
		} 
	}
	cout<<-1;
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	freopen("input.txt", "rt", stdin);
	
	int redX, redY, blueX, blueY;
	cin>>N>>M;
	for(int i=0; i<N; i++){
		for(int j=0; j<M; j++){
			cin>>map[i][j];
			if(map[i][j]=='R'){
				redX=i;
				redY=j;
			}
			else if(map[i][j]=='B'){
				blueX=i;
				blueY=j;
			}
		}
	}
	
	visited[redX][redY][blueX][blueY]=true;
	Q.push(Bead(redX,redY,blueX,blueY,0));
	BFS();
	
	return 0;
}
