#include <stdio.h>
#include <algorithm>
#include <queue>
#include <iostream>
#include <vector>

using namespace std;

//����_1275_Ŀ�Ǽ�2 

#define MAXK 18

int N,Q,B; 
long long IDT[1<<MAXK];

void initIDT(){
	for(int i=B-1; i>0; i--){
		IDT[i] = IDT[i<<1] + IDT[(i<<1)|1];
	}
} 

long long lgSum(int l, int r){
	l+=(B-1); r+=(B-1);
	
	long long sum=0;
	while(l<=r){
		if((l&1)==1) sum+=IDT[l];
		if((r&1)==0) sum+=IDT[r];
		
		l=(l+1)>>1;
		r=(r-1)>>1;
	}
	
	return sum;
}

void update(int p, int v){
	p+=(B-1);
	IDT[p]=v;
	
	while(p>>=1){
		IDT[p] = IDT[p<<1] + IDT[(p<<1)|1];
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	//freopen("input.txt", "rt", stdin);
	cin>>N>>Q;
	
	//ù ������� �ε��� ã�� 
	for(B=1; B<N; B<<=1);
	
	//������忡 ������ �ֱ� 
	for(int i=B; i<N+B; i++){
		long long tmp;
		cin>>tmp;
		IDT[i]=tmp;
	} 
	
	//��� 
	initIDT();
	
	int x=0,y=0,a=0,b=0;
	for(int i=0; i<Q; i++){
        cin>>x>>y>>a>>b;
        //long long tmp = lgSum(min(x,y), max(x,y));
        //cout<<tmp<<endl;  -> cin ó�� ��, �ð��ʰ�!
        printf("%lld\n", lgSum(min(x,y), max(x,y)));
		update(a,b);
	}
	
	return 0; 
}
