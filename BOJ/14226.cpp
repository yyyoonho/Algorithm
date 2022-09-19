#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
 
//boj_14226
//BFS 

int S;
bool visited[1001][1001];

struct Emo{
	int nowEmoCnt;
	int clipBoard;
	int sec;
	Emo(int n1, int c1, int s1){
		nowEmoCnt=n1;
		clipBoard=c1;
		sec=s1;
	}
};

void Input(){
	cin>>S;
}

queue<Emo> Q;

void Solve(){
	visited[1][0]=true;
	Q.push(Emo(1,0,0));
	
	while(!Q.empty()){
		int nowEmoCnt=Q.front().nowEmoCnt;
		int clipBoard=Q.front().clipBoard;
		int sec=Q.front().sec;
		Q.pop();
		
		if(nowEmoCnt==S){
			cout<<sec;
			break;
		}
		
		//복사
		if(nowEmoCnt!=clipBoard){
			if(!visited[nowEmoCnt][nowEmoCnt]){
				visited[nowEmoCnt][nowEmoCnt]=true;
				Q.push(Emo(nowEmoCnt,nowEmoCnt,sec+1));
			}
		}
		
		//붙여넣기
		if(nowEmoCnt+clipBoard<=1000){
			if(!visited[nowEmoCnt+clipBoard][clipBoard]){	
				visited[nowEmoCnt+clipBoard][clipBoard]=true;
				Q.push(Emo(nowEmoCnt+clipBoard,clipBoard,sec+1));
			}
		}
		
		//삭제
		if(nowEmoCnt-1>1){
			if(!visited[nowEmoCnt-1][clipBoard]){
				visited[nowEmoCnt-1][clipBoard]=true;
				Q.push(Emo(nowEmoCnt-1,clipBoard,sec+1));
			}	
		}
	}
	
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	//freopen("input.txt", "rt", stdin);
	
	Input();
	Solve();
	
	return 0;
} 
