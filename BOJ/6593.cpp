#include <algorithm>
#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

//BOJ_»ó¹ü ºôµù  #6593

int L,R,C;
char map[30][30][30];
int check[30][30][30];
int dx[6]={0,0,1,-1,0,0};
int dy[6]={1,-1,0,0,0,0};
int dz[6]={0,0,0,0,1,-1};
bool flag;

struct Edge{
	int x;
	int y;
	int z;
	int time;
	Edge(int x1, int y1, int z1, int time1){
		x=x1;
		y=y1;
		z=z1;
		time=time1;
	}
};

void Initialize(){
	memset(map, NULL ,sizeof(map));
	memset(check, 0, sizeof(check));
	flag=false; 
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "rt", stdin);
	queue<Edge> Q;
	while(true){
		cin>>L>>R>>C;
		if(L==0 && R==0 && C==0){
			return 0;
		}
		
		Initialize();
		while(!Q.empty()) Q.pop();
		
		for(int i=0; i<L; i++){
			for(int j=0; j<R; j++){
				for(int k=0; k<C; k++){
					cin>>map[i][j][k];
					if(map[i][j][k]=='S'){
						Q.push(Edge(i,j,k,0));
						check[i][j][k]=1;
					}
				}
			}
		}
		
		while(!Q.empty()){
			Edge tmp=Q.front();
			Q.pop();
			int nowX=tmp.x;
			int nowY=tmp.y;
			int nowZ=tmp.z;
			int nowTime=tmp.time;
			for(int i=0; i<6; i++){
				int nextX=nowX+dx[i];
				int nextY=nowY+dy[i];
				int nextZ=nowZ+dz[i];
				if(map[nextX][nextY][nextZ]=='E'){
					flag=true;
					cout<<"Escaped in "<<nowTime+1<<" minute(s)."<<endl;
					while(!Q.empty()) Q.pop();
					break;
				}
				if(nextX>=0 && nextX<L && nextY>=0 && nextY<R && nextZ>=0 && nextZ<C
				&& map[nextX][nextY][nextZ]=='.' && check[nextX][nextY][nextZ]==0){
					Q.push(Edge(nextX,nextY,nextZ,nowTime+1));
					check[nextX][nextY][nextZ]=1;
				}
			}
		}
		
		if(flag==false) cout<<"Trapped!"<<endl;
	}
	
	return 0;
}
