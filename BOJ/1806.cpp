#include <stdio.h>
#include <algorithm>
#include <queue>
#include <iostream>
#include <vector>

using namespace std;

//백준_1806_부분합  

int N,S; 
vector<int> arr;

int main(){
	ios_base::sync_with_stdio(false);
	//freopen("input.txt", "rt", stdin);
	cin>>N>>S;
	
	for(int i=0; i<N; i++){
		int tmp;
		cin>>tmp;
		arr.push_back(tmp);
	}
	
	int l=0,r=0,sum=0;
	int ans=N+1;
	
	while(true){
		if(sum>=S){
			ans=min(ans,r-l);
			sum-=arr[l++];
		}
		else if(r>=N) break;
		else{
			sum+=arr[r++];
		}
	}
	
	if(ans==N+1) ans=0;
	
	cout<<ans;	
	
	return 0; 
}
