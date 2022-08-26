#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
 
//boj_1062
//완전탐색
//조합 

int N,K;
bool alpha[27];
vector<string> word;
int maxAns;

void DFS(int idx, int cnt){
	if(cnt==K){
		//단어를 읽을 수 있는지 확인 
		int tmpAns=0;
		for(int i=0; i<N; i++){
			bool canRead=true;
			for(int j=4; j<word[i].size()-4; j++){
				if(alpha[word[i].at(j)-'a']==false){
					canRead=false;
					break;
				}
			}
			if(canRead) tmpAns++;
		}
		maxAns=max(maxAns, tmpAns);
	}
	else{
		for(int j=idx; j<26; j++){
			if(alpha[j]==true) continue;
			
			alpha[j]=true;
			DFS(j,cnt+1);
			alpha[j]=false;
		}
	}
}

void Input(){
	cin>>N>>K;
	
	if(K<5){
		cout<<"0";
		exit(0);
	}
	
	string tmp;
	for(int i=0; i<N; i++){
		cin>>tmp;
		word.push_back(tmp);
	}
}

void Solve(){
	alpha['a'-'a']=true;
	alpha['c'-'a']=true;
	alpha['i'-'a']=true;
	alpha['n'-'a']=true;
	alpha['t'-'a']=true;
	
	//combination DFS
	K=K-5;
	DFS(0,0); 
	cout<<maxAns;
}
 

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	//freopen("input.txt", "rt", stdin);
	
	Input();
	Solve();
	
	return 0;
} 
