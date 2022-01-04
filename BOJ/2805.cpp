#include <stdio.h>
#include <algorithm>
#include <queue>
#include <iostream>
#include <vector>

using namespace std;

//백준_2805_나무자르기 

int N,M;
vector<int> tree;
 

bool check(int mid){
	long long sum=0;
	for(int i=0; i<tree.size(); i++){
		if(tree[i]>=mid) sum+=(tree[i]-mid);
	}
	
	if(sum>=M) return true;
	else return false;
}

int main(){
	ios_base::sync_with_stdio(false);
	//freopen("input.txt", "rt", stdin);
	cin>>N>>M;
	
	int lb=0,rb,mid=0;
	
	for(int i=0; i<N; i++){
		int tmp;
		cin>>tmp;
		tree.push_back(tmp);
		rb=max(rb,tmp);
	}
	
	while(lb+1<rb){
		mid=lb+(rb-lb)/2;
		if(check(mid)) lb=mid;
		else rb=mid;
	}
	
	cout<<lb;
	
	return 0; 
}
