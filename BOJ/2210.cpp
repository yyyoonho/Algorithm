#include <iostream>

using namespace std;

// BOJ 숫자판 점프 #2210 

int map[5][5]; 
bool check[999999];
int dx[]={-1,0,1,0};
int dy[]={0,-1,0,1};
int answer;

void DFS(int x, int y, int cnt, int total){
	if(cnt==6){
		if(check[total]==false){
			check[total]=true;
			//cout<<total<<endl;
			answer++;
		}
		return;
	}
	else{
		for(int i=0; i<4; i++){
			int nextX=x+dx[i];
			int nextY=y+dy[i];
			if(nextX>=0 && nextX<5 && nextY>=0 && nextY<5){
				DFS(nextX, nextY, cnt+1, total*10+map[nextX][nextY]);
			}
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);	
	freopen("input.txt", "rt", stdin);
	for(int i=0; i<5; i++){
		for(int j=0; j<5; j++){
			cin>>map[i][j];
		}
	}
	
	for(int i=0; i<5; i++){
		for(int j=0; j<5; j++){
			DFS(i,j,1,map[i][j]);
		}
	}
	
	cout<<answer;
	
	return 0;
}
