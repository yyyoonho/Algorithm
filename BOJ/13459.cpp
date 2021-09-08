#include <algorithm>
#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

//BOJ_±∏ΩΩ≈ª√‚ #13459 

struct bead{
	int rx;
	int ry;
	int bx;
	int by;
	int d;
	bead(int rx1, int ry1, int bx1, int by1, int d1){
		rx=rx1;
		ry=ry1;
		bx=bx1;
		by=by1;
		d=d1;
	}
};

int N,M; 
char map[10][10];
bool check[10][10][10][10]; 
int dx[]={-1,0,1,0};
int dy[]={0,-1,0,1};
queue<bead> Q;

void Move(int &x, int &y, int &c, int dx, int dy){
	while(map[x+dx][y+dy] != '#' && map[x][y] !='O'){
		x+=dx;
		y+=dy;
		c+=1;
	}
}

void BFS(){
	while(!Q.empty()){
		int rx=Q.front().rx;
		int ry=Q.front().ry;
		int bx=Q.front().bx;
		int by=Q.front().by;
		int d=Q.front().d;
		Q.pop();
		if(d>=10) break;
		for(int i=0; i<4; i++){
			int nextRx=rx;
			int nextRy=ry;
			int nextBx=bx;
			int nextBy=by;
			int rc=0, bc=0;
			Move(nextRx, nextRy, rc, dx[i], dy[i]);
			Move(nextBx, nextBy, bc, dx[i], dy[i]);
			if(map[nextBx][nextBy] =='O') continue;
			if(map[nextRx][nextRy]=='O'){
				cout<<1;
				exit(0);
			}
			if(nextRx == nextBx && nextRy == nextBy){
				if(rc>bc){
					nextRx-=dx[i];
					nextRy-=dy[i];
				}
				else{
					nextBx-=dx[i];
					nextBy-=dy[i];
				}
			}
			if(check[nextRx][nextRy][nextBx][nextBy]) continue;
			check[nextRx][nextRy][nextBx][nextBy]=true;
			Q.push(bead(nextRx, nextRy, nextBx, nextBy,d+1));
		}
	}
	cout<<0;
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	freopen("input.txt", "rt", stdin);
	cin>>N>>M;
	int rx,ry,bx,by;
	for(int i=0; i<N; i++){
		for(int j=0; j<M; j++){
			cin>>map[i][j];
			if(map[i][j]=='R'){
				rx=i;
				ry=j;
			}
			else if(map[i][j]=='B'){
				bx=i;
				by=j;
			}
		}
	}
	
	Q.push(bead(rx,ry,bx,by,0));
	check[rx][ry][bx][by]=true;
	BFS();

	return 0;
}
