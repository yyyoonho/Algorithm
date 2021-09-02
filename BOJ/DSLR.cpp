#include <stdio.h>
#include <algorithm>
#include <queue>
#include <iostream>
#include <cstring>
using namespace std;

//BOJ_DSLR_#9019

int T;
int a,b;
queue<pair<int, string> > Q;
bool visited[10000]; //true -> 방문했다. 

int main(){
	ios_base::sync_with_stdio(false);
	freopen("input.txt", "rt", stdin);
	cin>>T;
	for(int i=0; i<T; i++){
		memset(visited, false, sizeof(visited));
		cin>>a>>b;
		while(!Q.empty()) Q.pop();
		Q.push(make_pair(a,""));
		visited[a]=true;
		
		while(!Q.empty()){
			int num=Q.front().first;
			string com=Q.front().second;
			Q.pop();
			
			//A==B인 경우
			if(num==b){
				cout<<com<<endl;
				break;
			} 
			
			//D
			int nextNum=(2*num)%10000;
			if(!visited[nextNum]){
				visited[nextNum]=true;
				Q.push(make_pair(nextNum,com+"D"));
			}
			
			//S
			nextNum=(num-1)<0?9999:(num-1);
			if(!visited[nextNum]){
				visited[nextNum]=true;
				Q.push(make_pair(nextNum,com+"S"));
			}
			
			//L
			nextNum=(num%1000)*10+num/1000;
			if(!visited[nextNum]){
				visited[nextNum]=true;
				Q.push(make_pair(nextNum,com+"L"));
			}
			
			//R
			nextNum=(num%10)*1000+num/10;
			if(!visited[nextNum]){
				visited[nextNum]=true;
				Q.push(make_pair(nextNum,com+"R"));
			}
		}
	}
	
	return 0;
}
