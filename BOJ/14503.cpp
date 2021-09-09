#include <algorithm>
#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

//BOJ_로봇청소기 #14503

int N,M;
int r,c,d,cnt,rotateCnt;
int map[50][50]; 
int nextDx[]={0,-1,0,1};
int nextDy[]={-1,0,1,0};
int backDx[]={1,0,-1,0};
int backDy[]={0,-1,0,1};

int Direction(int nowD){
	if(nowD-1<0) return 3;
	return nowD-1;
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "rt", stdin);
	cin>>N>>M;
	cin>>r>>c>>d;
	for(int i=0; i<N; i++){
		for(int j=0; j<M; j++){
			cin>>map[i][j];
		}
	}
	
	while(true){
		//clean
		if(map[r][c]==0){
			map[r][c]=2;
			rotateCnt=0;
			cnt++;
			
//			for(int i=0; i<N; i++){
//				for(int j=0; j<M; j++){
//					cout<<map[i][j]<<" ";
//				}
//				cout<<endl;
//			}
//			cout<<endl<<endl;
		}
		
		//보고있는곳의 왼쪽방향.
		int Lx=nextDx[d];
		int Ly=nextDy[d];
		
		//case1
		if(map[r+Lx][c+Ly]==0){
			r+=Lx;
			c+=Ly;
			d=Direction(d);
		}
		
		//case2
		else if(rotateCnt<4 && (map[r+Lx][c+Ly]==1 || map[r+Lx][c+Ly]==2)){
			d=Direction(d);
			rotateCnt++;
		} 
		
		//case3 & case 4
		else if(rotateCnt==4){
			//case3
			if(map[r+backDx[d]][c+backDy[d]]!=1){
				r+=backDx[d];
				c+=backDy[d];
				rotateCnt=0;
			}
			//case4
			else{
				cout<<cnt;
				break;
			}
		} 		
	}
	
	return 0;
}
