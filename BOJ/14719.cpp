#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

//boj_14719

#define MAXHW 505
int H,W;
int water[MAXHW];
int ans;

void Input(){
	cin>>H>>W;
	for(int i=0; i<W; i++){
		cin>>water[i];
	}
}

void Solve(){
	int tmpCnt=0;
	for(int i=0; i<H; i++){
		bool wall = false;
		tmpCnt=0;
		
		for(int j=0; j<W; j++){
			if(wall==true && water[j]==0){
				tmpCnt++;
			}
			else if(wall){
				ans+=tmpCnt;
				tmpCnt=0;
			}
			else if(!wall && water[j]!=0){
				wall=true;
			}
			
			if(water[j]>=1) water[j]--;
		}
	}
	
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
