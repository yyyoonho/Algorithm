#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

//백준_로봇청소기_#4991

int N,M;
char map[20][20];

bool visit[21][21];
int check[21][21];

int dist[11][11];

bool Dvisit[11];
int min1=2147483647;

int index1=0;
int dx[]={-1,0,1,0};
int dy[]={0,-1,0,1};

vector<pair<int,int> > trash;
int rX,rY;

void BFS(int x, int y){
	memset(check,-1,sizeof(check));
	memset(visit,false,sizeof(visit));
	
	queue<pair<int,int> > Q;
	Q.push(make_pair(x,y));
	check[x][y]=0;
	visit[x][y]=true;
	
	while(!Q.empty()){
		int nowX=Q.front().first;
		int nowY=Q.front().second;
		Q.pop();
		for(int i=0; i<4; i++){
			int nextX=nowX+dx[i];
			int nextY=nowY+dy[i];
			if(nextX>=0 && nextX<N && nextY>=0 && nextY<M){
				if(map[nextX][nextY]!='x' && visit[nextX][nextY]==false){
					check[nextX][nextY]=check[nowX][nowY]+1;
					Q.push(make_pair(nextX,nextY));
					visit[nextX][nextY]=true;
				}
			}
		}
	}
	
	for(int i=0; i<trash.size(); i++){
		int tmpX=trash[i].first;
		int tmpY=trash[i].second;
		dist[index1][i+1]=check[tmpX][tmpY];
		dist[i+1][index1]=check[tmpX][tmpY];
	}
	index1++;
	
}

void DFS(int cnt, int sum, int nowIdx){
	if(cnt==trash.size()-1){
		min1=min(min1,sum);
	}
	else{
		for(int i=1;i<=trash.size(); i++){
			if(Dvisit[i]) continue;
			Dvisit[i]=true;
			DFS(cnt+1,sum+dist[nowIdx][i],i);
			Dvisit[i]=false;
		}
	}
	
} 

int main(){
	ios_base::sync_with_stdio(false);
    //freopen("input.txt", "rt", stdin);
    
    while(true){
    	index1=0;
    	bool flag=true;
    	
	    cin>>M>>N;
	    
    	if(M==0 && N==0) break;
    	
 		memset(dist,0,sizeof(dist));
 		memset(map,0,sizeof(map));
 		while(!trash.empty()) trash.pop_back();
 	   
 	    for(int i=0; i<N; i++){
  			for(int j=0; j<M; j++){
  	  			cin>>map[i][j];
    			if(map[i][j]=='o'){
    				rX=i;
    				rY=j;
				}
				else if(map[i][j]=='*'){
					trash.push_back(make_pair(i,j));
				}
			}
		}
	
		//로봇청소기에서 각 쓰레기간 거리구하기. 
		BFS(rX,rY);
	
		//로봇청소기가 쓰레기에 갈 수 없는 경우.
		for(int i=1; i<=trash.size(); i++){
			//cout<<dist[0][i]<<" ";
			if(dist[0][i]==-1){
				flag=false;
				break;
			}
		}
		
		if(flag==false){
			cout<<-1<<endl;
			continue;
		}
		
		//쓰레기간 거리 구하기. 
		for(int i=0; i<trash.size(); i++){
			BFS(trash[i].first,trash[i].second);
		} 
	
		//순열로 최소거리값 구하기. 
		for(int i=1; i<=trash.size(); i++){
			memset(Dvisit,false,sizeof(Dvisit));
			Dvisit[i]=true;
			DFS(0,dist[0][i],i);
		}
		cout<<min1<<endl;
		min1=2147483647;
	}
	
	return 0;
}
