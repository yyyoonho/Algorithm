#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

//백준_연구소2_#17141

int ori[50][50]; //오리지널 맵 
int map[50][50]; //바이러스가 퍼질 맵 

bool check[10]; //combination을 위한 check

int dx[]={-1,0,1,0};
int dy[]={0,-1,0,1};

int N,M,minTime=2147483647;

int room; //바이러스가 퍼질 수 있는 사이즈 

vector<pair<int,int> > virus; //바이러스를 놓을 수 있는 장소 

struct v{
	int x;
	int y;
	int time;
	v(int x1, int y1, int time1){
		x=x1;
		y=y1;
		time=time1;
	}
};

void CopyMap(){
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			map[i][j]=ori[i][j];
		}
	}
}

int DoVirus(){
	CopyMap();
	queue<v> Q;
	
	int maxTime=-2147483647;
	int spreadRoom=0;
	
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			if(map[i][j]==3){
				Q.push(v(i,j,0));
			}
		}
	}
	
	//Spread
	while(!Q.empty()){
		spreadRoom++;
		int x=Q.front().x;
		int y=Q.front().y;
		int time=Q.front().time;
		Q.pop();
		
		maxTime=max(maxTime,time);
		
		for(int i=0; i<4; i++){
			int nextX=x+dx[i];
			int nextY=y+dy[i];
			int nextT=time+1;
			if(nextX>=0 && nextX<N && nextY>=0 && nextY<N){
				if(map[nextX][nextY]==2 || map[nextX][nextY]==0){
					map[nextX][nextY]=3;
					Q.push(v(nextX,nextY,nextT));
				}
			}
		}
		
	}
	
	if(spreadRoom==room) return maxTime;
	else return -1;
}

void DFS(int cnt, int idx){;
	if(cnt==M){
		int maxTime = DoVirus();
		
		//모든 공간이 바이러스로 채워지지 않은 경우 
		if(maxTime==-1) return;
		
		//모든 공간을 바이러스로 경우 
		else{
			minTime=min(minTime,maxTime); 
			return;
		}
	}
	
	for(int i=idx; i<virus.size(); i++){
		if(check[i]==false){
			check[i]=true;
			ori[virus[i].first][virus[i].second]=3;
			DFS(cnt+1, i);
			ori[virus[i].first][virus[i].second]=2;
			check[i]=false;
		}
	}
	
}

int main(){
	ios_base::sync_with_stdio(false);
    //freopen("input.txt", "rt", stdin);
	cin>>N>>M;
	room=N*N;
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			cin>>ori[i][j];
			if(ori[i][j]==2) virus.push_back(make_pair(i,j));
			else if(ori[i][j]==1) room--;
		}
	}
	
	DFS(0,0);
	if(minTime==2147483647){
		cout<<-1<<endl;
		return 0;
	}
	cout<<minTime<<endl;
	
	return 0;
}
