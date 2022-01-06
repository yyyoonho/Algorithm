#include <stdio.h>
#include <algorithm>
#include <queue>
#include <iostream>
#include <vector>

using namespace std;

//백준_1837_암호제작

string P;
int K; 
bool visit[1000002]; // false->소수, true->소수아님 

bool check(int num){
	int sum=0;
	
	//주어진 수P를 각 자리수별로(큰 자리수부터) 나누어본다.
	for(int i=0; P[i]; i++)
		sum=(sum*10+(P[i]-'0'))%num;
		
	if(sum==0) return true;
	return false; 
}

int main(){
	ios_base::sync_with_stdio(false);
	//freopen("input.txt", "rt", stdin);
	cin>>P>>K;
	
	bool state = true;
	int minPrime=0;
	
	for(int i=2; i<K; i++){
		if(visit[i]==true) continue; //에라토스테네스 의 체 확인 
		
		if(check(i)){ // k보다 밑인 수로 나누어 진다면 -> Bad 비밀번호. 
			state=false;
			minPrime=i;
			break;
		}
		
		for(long long j=(long long)i*i; j<K; j+=i) // 에라토스테네스의 체 -> 배수인것들 true 
			visit[j]=true; 
	}
	
	if(state) cout<<"GOOD";
	else cout<<"BAD"<<" "<<minPrime; 

	
	return 0; 
}
