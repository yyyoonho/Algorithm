#include <iostream>
#include <vector>
using namespace std;

// BOJ 종이의 개수 #1780 

int N;
int cnt[3];
int map[2200][2200];

bool check(int row, int col, int num){
	int start=map[row][col];
	for(int i=row; i<row+num; i++){
		for(int j=col; j<col+num; j++){
			if(start!=map[i][j]) return false;
		}
	}
	return true;
}

void Divide(int row, int col, int num){
	if(check(row, col, num)){
		if(map[row][col]==-1) cnt[0]++;
		else{
			cnt[map[row][col]+1]++;
		}
	}
	else{
		int size=num/3;
		for(int i=0; i<3; i++){
			for(int j=0; j<3; j++){
				Divide(row+size*i, col+size*j, size);
			}
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);	
	//freopen("input.txt", "rt", stdin);
	cin>>N;
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			cin>>map[i][j];
		}
	}	
	
	Divide(0,0,N);
	
	for(int i=0; i<3; i++) cout<<cnt[i]<<endl;
	
	return 0;
}
