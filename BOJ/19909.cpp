#include <string>
#include <queue>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <cmath>

//BOJ #17144 ¹Ì¼¼¸ÕÁö ¾È³ç! 

using namespace std;

int dx[]={0,-1,0,1};
int dy[]={1,0,-1,0};
int map[50][50];
int tmpMap[50][50];
int R,C,T;
vector<pair<int,int> > CM;

int tmp1,tmp2;

void Wind(int loc, int &x, int &y, int mX, int mY){
	//À­ ºÎºÐ 
	if(loc==0){
		while(true){
			if((x+mX)<0 || (x+mX)>=R || (y+mY)<0 || (y+mY)>=C) break;
			if(map[x+mX][y+mY]==-1) break;
			
			x+=mX;
			y+=mY;
			
			tmp2=map[x][y];
			map[x][y]=tmp1;
			tmp1=tmp2;
			
		}
	}
	
	//¾Æ·§ºÎºÐ
	else if(loc==1){
		while(true){
			if((x+(mX*-1))<0 || (x+(mX*-1))>=R || (y+mY)<0 || (y+mY)>=C) break;
			if(map[(x+(mX*-1))][(y+mY)]==-1) break;
			
			x+=(mX*-1);
			y+=mY;
			
			tmp2=map[x][y];
			map[x][y]=tmp1;
			tmp1=tmp2;
		}
	} 
}

void Cleaner(){
	for(int i=0; i<2; i++){
		int x=CM[i].first;
		int y=CM[i].second;
		
		tmp1=0;
		tmp2=0;
		
		for(int j=0; j<4; j++){
			Wind(i, x, y, dx[j], dy[j]);
		}
	}	
}

void Spread(){
	memset(tmpMap,0,sizeof(tmpMap));
	for(int i=0; i<R; i++){
		for(int j=0; j<C; j++){
			if(map[i][j]==-1) continue;
			int tmp=map[i][j]/5;
			for(int k=0; k<4; k++){
				int nextX=i+dx[k];
				int nextY=j+dy[k];
				if(nextX<0 || nextX>=R || nextY<0 || nextY>=C || map[nextX][nextY]==-1) continue;
				tmpMap[nextX][nextY]+=tmp;
				map[i][j]-=tmp;
			}
		}
	}
	
	for(int i=0; i<R; i++){
		for(int j=0; j<C; j++){
			map[i][j]+=tmpMap[i][j];
		}
	}

}

int main(){
	ios_base::sync_with_stdio(false);
	//freopen("input.txt", "rt", stdin);
	cin>>R>>C>>T;
	for(int i=0; i<R; i++){
		for(int j=0; j<C; j++){
			cin>>map[i][j];
			if(map[i][j]==-1){
				CM.push_back(make_pair(i,j));
			}
		}
	}
	
	for(int i=0; i<T; i++){
		Spread();
		Cleaner();
	}
	
	int answer=0;
	for(int i=0; i<R; i++){
		for(int j=0; j<C; j++){
			if(map[i][j]==-1) continue;
			answer+=map[i][j];
		}
	}
	
	cout<<answer<<endl;
	
	
	return 0;
}
