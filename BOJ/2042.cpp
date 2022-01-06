#include <stdio.h>
#include <algorithm>
#include <queue>
#include <iostream>
#include <vector>

using namespace std;

//백준_2042_구간합구하기 

#define MAXK 21

int N,M,K,B,T;
long long IDT[1<<MAXK];

void update(int p, long long v){
	p+=(B-1);
	IDT[p]=v;
	while(p>>=1){
		IDT[p] = IDT[p<<1] + IDT[(p<<1)|1];
	}
}

long long lgsum(int l, int r){
	l+=(B-1); r+=(B-1);
	long long sum=0;
	while(l<=r){
		if((l&1)==1) sum+= IDT[l];
		if((r&1)==0) sum+= IDT[r];
		
		l=(l+1)>>1;
		r=(r-1)>>1;
	}
	
	return sum;
}

void initIDT(){
	for(int i=B-1; i>0; i--){
		IDT[i]=IDT[i<<1]+IDT[(i<<1)|1];
	}
} 

int main(){
	ios_base::sync_with_stdio(false);
	freopen("input.txt", "rt", stdin);
	
	cin>>N>>M>>K;
	
	//인덱스찾기 
	for(B=1; B<N; B<<=1);
	
	//리프노드에 데이터 입력
	for(int i=B; i<N+B; i++){
		cin>>IDT[i];
	}
	
	// Bottom-up 계산 
	initIDT();
	
	T=M+K;
	
	int a,b;
	long long c;
	while(T--){
		cin>>a>>b>>c;
		
		if(a==1) update(b,c);
		else cout<<lgsum(b,c)<<endl; 
	}
	
	return 0; 
}
