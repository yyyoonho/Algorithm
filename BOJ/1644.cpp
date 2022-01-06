#include <stdio.h>
#include <algorithm>
#include <queue>
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

//백준_1644_소수의연속합

#define MAXK 4000001

bool visit[MAXK]; // false->소수, true-> 소수아님 
int N;
int primeNum[MAXK];
 
int main(){
	ios_base::sync_with_stdio(false);
	//freopen("input.txt", "rt", stdin);
	cin>>N;
	int primeNumCnt=0;
	
	//에라토스테네스의 체 구현
	visit[0]=true; visit[1]=true;
	for(int i=2; i<=sqrt(N); i++){
		if(visit[i]==true) continue;
		primeNum[primeNumCnt++]=i;
		for(long long j=(long long)i*i; j<=N; j+=i){
			visit[j]=true;
		}
	}
	
	int l=0, r=0, cnt=0, sum=0;
	
	while(true){
		if(sum>=N) sum-=primeNum[l++];
		else if(r==primeNumCnt) break;
		else sum+=primeNum[r++];
		
		if(sum==N) cnt++;
	}
	
	cout<<cnt<<endl;
	return 0; 
}
