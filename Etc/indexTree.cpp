#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;

// IndexTree (구간합) 

#define MAXN 21
int N,M,K,B,T;

long long IDT[1<<MAXN];

void swap(int b, long long c){
	int idx=b+B-1;
	IDT[idx]=c;
	
	while(idx>>=1){
		IDT[idx] = IDT[idx<<1] + IDT[(idx<<1)|1];
	}
}

long long rgSum(int b, int c){
	int lp=b+B-1;
	int rp=c+B-1;
	
	long long sum=0;
	while(lp<=rp){
		if((lp&1)==1) sum+=IDT[lp];
		if((rp&1)==0) sum+=IDT[rp];
		
		lp=(lp+1)>>1;
		rp=(rp-1)>>1;
	}
	
	return sum;
}

void initTree(){
	for(int i=B-1; i>0; i--){
		IDT[i] = IDT[i*2]+IDT[i*2+1];
	}
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	freopen("input.txt", "rt", stdin);
	cin>>N>>M>>K;
	cout<<"1"<<endl;
	//리프노드 인덱스 찾기 
	for(B=1; B<=N; B<<=1);

	//리프노드에 데이터 입력 
	for(int i=B; i<N+B; i++){
		cin>>IDT[i];
	}

	//인덱스트리 채우기
	initTree(); 

	//총 몇번의 수행? (update+rgSum) 
	T=M+K;
	
	int a,b;
	long long c;
	for(int i=0; i<T; i++){
		cin>>a>>b>>c;
		
		//swap
		if(a==1){
			swap(b,c);
		}
		
		//rgSum 
		else{
			cout<<rgSum(b,c)<<"\n";
		}
	}
	
	return 0; 
}
