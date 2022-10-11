#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//16235
//시뮬레이션 구현
//정렬을 해야한다는 이유로 priority_queue를 남용하지말자.
//데이터의 입출력이 있을때마다 정렬-> TLE 유발 

#define MAXN 11
struct treeInfo{
	int x; 
	int y; 
	int z;
	treeInfo(int x1, int y1, int z1){
		x=x1; y=y1; z=z1;
	}
};
int N,M,K;
int A[MAXN][MAXN];
int map[MAXN][MAXN];
vector<int> treePQ[MAXN][MAXN];
vector<treeInfo> deadTree;
int dx[8]={-1,-1,-1,0,0,1,1,1};
int dy[8]={-1,0,1,-1,1,-1,0,1};
int ans=0;

void Input(){
	cin>>N>>M>>K;
	for(int i=1; i<=N; i++){
		for(int j=1; j<=N; j++){
			cin>>A[i][j];
			map[i][j]=5;
		}
	}
	
	int x,y,z;
	for(int i=0; i<M; i++){
		cin>>x>>y>>z;
		treePQ[x][y].push_back(z);
	}
}

void Spring(){
	for(int i=1; i<=N; i++){
		for(int j=1; j<=N; j++){
			sort(treePQ[i][j].begin(),treePQ[i][j].end());
			
			for(int q=0; q<treePQ[i][j].size(); q++){
				if(map[i][j]<treePQ[i][j][q]){
					deadTree.push_back(treeInfo(i,j,treePQ[i][j][q]));
					treePQ[i][j].erase(treePQ[i][j].begin()+q);
					q--;
					continue;
				}
				
				map[i][j]-=treePQ[i][j][q];
				treePQ[i][j][q]++;
			}
		}
	}
}

void Summer(){
	for(int i=0; i<deadTree.size(); i++){
		int x=deadTree[i].x;
		int y=deadTree[i].y;
		int z=deadTree[i].z;
		map[x][y]=map[x][y]+z/2;
	}
	deadTree.clear();
	vector<treeInfo>().swap(deadTree);
}

void Fall(){
	for(int i=1; i<=N; i++){
		for(int j=1; j<=N; j++){
			for(int q=0; q<treePQ[i][j].size(); q++){
				if(treePQ[i][j][q]%5!=0) continue;
				for(int k=0; k<8; k++){
					int nextX=i+dx[k];
					int nextY=j+dy[k];
					
					if(nextX<1||nextX>N||nextY<1||nextY>N) continue;
					
					treePQ[nextX][nextY].push_back(1); 
				} 
			}
		}
	}
}

void Winter(){
	for(int i=1; i<=N; i++){
		for(int j=1; j<=N; j++){
			map[i][j]+=A[i][j];
		}
	}
}

void CountTree(){
	for(int i=1; i<=N; i++){
		for(int j=1; j<=N; j++){
			ans+=treePQ[i][j].size();
		}
	}
}

void Solve(){
	for(int i=0; i<K; i++){
		Spring();
		Summer();
		Fall();
		Winter();
	}
	
	CountTree();
	cout<<ans;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	//freopen("input.txt", "rt", stdin);
	
	Input();
	Solve();
	
	return 0;
} 
