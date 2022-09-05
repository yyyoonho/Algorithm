#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
 
//boj_2023
//백트래킹
//소수판별 

int N;

bool CheckPrimeNum(int a){
	if(a==1){
		return false;
	}
	for(int i=2; i*i<=a; i++){
		if(a%i==0){
			return false;
		}
	}
	return true;
}

void DFS(int cnt, int num){
	if(cnt==N){
		if(CheckPrimeNum(num)){
			cout<<num<<"\n";
		}
		return;
	}
	
	for(int i=1; i<10; i++){
		if(CheckPrimeNum(num)){
			DFS(cnt+1, num*10+i);
		}
	}
}

void Input(){
	cin>>N;
}

void Solve(){
	DFS(0,0);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	//freopen("input.txt", "rt", stdin);
	
	Input();
	Solve();
	
	return 0;
} 
