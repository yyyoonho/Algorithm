#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
 
//boj_9470
//위상정렬(topological sort) 
//테스트케이스가 2개 이상일땐 전역변수(공통변수) 초기화를 신경쓰자. 

#define MAXN 1001
int T;
int K,M,P;
vector<int> map[MAXN];
vector<int> inputLineValue[MAXN];
int inputLineCnt[MAXN];
int strahler[MAXN];
bool visited[MAXN];
queue<int> Q;


void InputTC(){
	cin>>T;
}

void Init(){
	K=0;
	M=0;
	P=0;
	for(int i=0; i<MAXN; i++){
		map[i].clear();
		inputLineValue[i].clear();
		inputLineCnt[i]=0;
		strahler[i]=0;
		visited[i]=false;
	}
	while(!Q.empty()) Q.pop();
	
}

void Input(){
	cin>>K>>M>>P;
	int a,b;
	for(int i=0; i<P; i++){
		cin>>a>>b;
		map[a].push_back(b);
		inputLineCnt[b]++;
	}
	
	for(int i=1; i<=M; i++){
		if(inputLineCnt[i]==0){
			 inputLineValue[i].push_back(1);
			 Q.push(i);
		}
	}
}

void Solve(){
	while(!Q.empty()){
		int now = Q.front();
		Q.pop();
		
		//strahler계산
		int maxStr=0;
		int maxStrCnt=0;
		for(int i=0; i<inputLineValue[now].size(); i++){
			if(maxStr<inputLineValue[now][i]){
				maxStr=inputLineValue[now][i];
				maxStrCnt=1;
			}
			else if(maxStr==inputLineValue[now][i]){
				maxStrCnt++;
			}
		} 
		if(maxStrCnt>=2)strahler[now]=maxStr+1;
		else if(maxStrCnt==1) strahler[now]=maxStr;
		
		if(now==M) break;
		
		for(int i=0; i<map[now].size(); i++){
			
			inputLineCnt[map[now][i]]--;
			
			inputLineValue[map[now][i]].push_back(strahler[now]);
			
			if(inputLineCnt[map[now][i]]==0){
				Q.push(map[now][i]);
			}
		}
	}
	
	cout<<K<<" "<<strahler[M]<<'\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	//freopen("input.txt", "rt", stdin);
	
	InputTC();
	for(int t=0; t<T; t++){
		Init();
		Input();
		Solve();
	}
	
	return 0;
} 
