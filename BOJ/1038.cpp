#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
 
//boj_1038
//백트래킹
//브루트포스 

int N;
vector<long long> ansTable;

void Input(){
	cin>>N;
}

void DFS(long long num, int cnt){
	if(cnt>10){
		return;
	}
	else{
		ansTable.push_back(num);
		for(int i=0; i<10; i++){
			if(num%10>i){
				DFS(num*10+i,cnt+1);
			}
		}
		return;
	}
	
}

void Solve(){
	for(int i=0; i<10; i++){
		DFS(i,1);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	//freopen("input.txt", "rt", stdin);
	
	Input();
	Solve();
	if(N>1022){
		cout<<-1;
		return 0;
	}
	sort(ansTable.begin(),ansTable.end());
	cout<<ansTable[N];
	
	return 0;
} 
