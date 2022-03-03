#include <string>
#include <vector>
#include <iostream>

using namespace std;

//BOJ_1976 

#define MAXN 201
int N,M;
int map[MAXN][MAXN];
bool visited[MAXN];
int unf[MAXN];

int find(int a){
	if(unf[a]==a) return a;
	else return unf[a]=find(unf[a]);
}

void unionFunc(int a, int b){
	a=find(a);
	b=find(b);
	if(a!=b) unf[a]=b;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	freopen("input.txt", "rt", stdin);
	
	cin>>N>>M;
	
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			cin>>map[i][j];
		}
	}
	
	for(int i=0; i<MAXN; i++) unf[i]=i;
	
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			if(i>j) continue;
			else if(map[i][j]==1) unionFunc(i,j);
		}
	}
	
	for(int i=0; i<N; i++) find(i);
	
	int firstCity;
	int rootCity;
	cin>>firstCity;
	rootCity=find(firstCity-1);
	
	//cout<<"루트시티: "<<rootCity<<endl; 
	
	int city;
	for(int i=0; i<M-1; i++){
		cin>>city;
		city=find(city-1);
		//cout<<"시티: "<<city<<endl; 
		
		if(rootCity!=city){
			cout<<"NO"<<endl;
			return 0;
		}
	}
	
	cout<<"YES"<<endl;
	
	return 0;
}
