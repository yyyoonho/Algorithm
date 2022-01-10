#include <bits/stdc++.h>

using namespace std;

//백준_1922_네트워크연결 

struct Edge{
	int a;
	int b;
	int w;
	Edge(int a1, int b1, int w1){
		a=a1;
		b=b1;
		w=w1;
	}
	bool operator<(const Edge &b) const{
		return w>b.w;
	}
};

int N,M;
int unf[1001];
priority_queue<Edge> pQ;

int find(int v){
	if(unf[v]==v) return v;
	else return unf[v]=find(unf[v]);
}

void unfFunc(int x, int y){
	x=find(x);
	y=find(y);
	if(x!=y) unf[x]=y;
} 

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	//freopen("input.txt", "rt", stdin);
	cin>>N>>M;
	
	for(int i=0; i<=N; i++){
		unf[i]=i;
	}
	
	int a,b,w;
	for(int i=0; i<M; i++){
		cin>>a>>b>>w;
		pQ.push(Edge(a,b,w));
	}
	
	int cnt=0;
	int wSum=0;
	while(true){
		if(cnt==N-1) break;
		
		Edge tmp = pQ.top();
		pQ.pop();
		
		int tmpX=tmp.a;
		int tmpY=tmp.b;
		int tmpW=tmp.w;
		
		if(find(tmpX)!=find(tmpY)){
			unfFunc(tmpX,tmpY);
			wSum+=tmpW;
			cnt++;
		}
	}
	
	cout<<wSum;
	
	return 0; 
}
