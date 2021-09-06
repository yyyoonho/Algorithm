#include <algorithm>
#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

//BOJ_´Á´ë¿Í ¾ç  #16956

char map[500][500]; 
int R,C;
int dx[4]={-1,0,1,0};
int dy[4]={0,-1,0,1};

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "rt", stdin);
	queue<pair<int, int> > Q;
	cin>>R>>C;
	for(int i=0; i<R; i++){
		for(int j=0; j<C; j++){
			cin>>map[i][j];	
			if(map[i][j]=='W') Q.push(make_pair(i,j));	
		}
	}
	
	while(!Q.empty()){
		int x=Q.front().first;
		int y=Q.front().second;
		Q.pop();
		for(int i=0; i<4; i++){
			int nextX=x+dx[i];
			int nextY=y+dy[i];
			if(nextX>=0 && nextX<R && nextY>=0 && nextY<C){
				if(map[nextX][nextY]=='.') map[nextX][nextY]='D';
				else if(map[nextX][nextY]=='S'){
					cout<<0;
					exit(0);
				}
			}
		}
	}
	
	cout<<1<<endl;
	for(int i=0; i<R; i++){
		for(int j=0; j<C; j++){
			cout<<map[i][j];
		}
		cout<<endl;
	}
	
	
	return 0;
}
