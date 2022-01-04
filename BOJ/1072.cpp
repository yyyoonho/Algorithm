#include <stdio.h>
#include <algorithm>
#include <queue>
#include <iostream>
#include <vector>

using namespace std;

//백준_1072_게임 

long long X,Y; 
long long Z;

bool check(int mid){
	long long tmpX=X+mid;
	long long tmpY=Y+mid;
	long long tmpZ=(tmpY*100/tmpX);
	
	if(Z!=tmpZ) return true;
	else return false;
}

int main(){
	ios_base::sync_with_stdio(false);
	freopen("input.txt", "rt", stdin);
	cin>>X>>Y;
	
	Z=(Y*100/X);
	
	if(Z>=99){
		cout<<-1;
		return 0;
	}
	
	int lb=0;
	int rb=X;
	int mid=0;
	
	
	while(lb+1<rb){
		mid=lb+(rb-lb)/2;
		if(check(mid)) rb=mid;
		else lb=mid;
	}
	
	cout<<rb<<endl;
	
	return 0; 
}
