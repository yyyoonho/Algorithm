#include <string>
#include <queue>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <cmath>

//BOJ #16234 인구이동 

using namespace std;

int map[50][50];
bool visited[50][50];
int dx[]={-1,0,1,0};
int dy[]={0,-1,0,1};
int N,L,R;
int unionCnt;
int dayCnt;
bool flag;

void BFS(int x1, int y1){
	queue<pair<int,int> > Q;
	queue<pair<int,int> > unionQ;
	Q.push(make_pair(x1,y1));
	unionQ.push(make_pair(x1,y1));
	
	int totalPopular=map[x1][y1];
	unionCnt=0;
	visited[x1][y1]=true;
	
	while(!Q.empty()){
		int x=Q.front().first;
		int y=Q.front().second;
		Q.pop();
		unionCnt++;
		
		for(int i=0; i<4; i++){
			int nextX=x+dx[i];
			int nextY=y+dy[i];
			if(nextX>=0 && nextX<N && nextY>=0 && nextY<N){
				int car=abs(map[x][y]-map[nextX][nextY]);
				if(visited[nextX][nextY]==false && car>=L && car<=R){
					Q.push(make_pair(nextX,nextY));
					visited[nextX][nextY]=true;
					unionQ.push(make_pair(nextX,nextY));
					totalPopular+=map[nextX][nextY];
				}
			}
		}
	}
	
	int newPopular;
	if(unionCnt>1){
		newPopular=totalPopular/unionCnt;
		flag=false;
		
		while(!unionQ.empty()){
			int x=unionQ.front().first;
			int y=unionQ.front().second;
			unionQ.pop();
			map[x][y]=newPopular;
		}
	}
}

bool needBFS(int i, int j){
	for(int k=0; k<4; k++){
		int nextX=i+dx[k];
		int nextY=j+dy[k];
		if(nextX>=0 && nextX<N && nextY>=0 && nextY<N){
			int car=abs(map[i][j]-map[nextX][nextY]);
			if(visited[nextX][nextY]==false && car>=L && car<=R){
				return true;
			}
		}
	}
	
	return false;
}

int main(){
	ios_base::sync_with_stdio(false);
	//freopen("input.txt", "rt", stdin);
	cin>>N>>L>>R;
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			cin>>map[i][j];
		}
	}
	
	while(true){
		//초기화
		memset(visited,false,sizeof(visited));
		flag=true;
		
		//시뮬레이션 
		for(int i=0; i<N; i++){
			for(int j=0; j<N; j++){
				if(visited[i][j]==false){
					if(needBFS(i,j)){
						BFS(i,j);
					}
				}
			}
		}
		
		//종료조건
		if(flag){
			break;
		}
		
		//종료가 아니라면 하루+1 
		dayCnt++;	
	}
	
	cout<<dayCnt<<endl;
	
	
	return 0;
}
