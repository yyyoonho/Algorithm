#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

//BOJ_��ŸƮ��ũ_#5014

int F,S,G,U,D;
bool check[1000001];

int main(){
	ios_base::sync_with_stdio(false);
	//freopen("input.txt", "rt", stdin);
	cin>>F>>S>>G>>U>>D;
	
	queue<pair<int,int> > Q;
	check[S]=true;
	Q.push(make_pair(S,0));
	while(!Q.empty()){
		int nowStair=Q.front().first;
		int nowCnt=Q.front().second;
		Q.pop();
		
		//G���� ������ ���
		if(nowStair==G){
			cout<<nowCnt;
			exit(0);
		} 
		
		//U��ư�� ���� ���
		if(nowStair+U<=F && check[nowStair+U]==false){
			Q.push(make_pair(nowStair+U,nowCnt+1));
			check[nowStair+U]=true;
		}
		
		//D��ư�� ���� ��� 
		if(nowStair-D>0 && check[nowStair-D]==false){
			Q.push(make_pair(nowStair-D,nowCnt+1));
			check[nowStair-D]=true;
		}
	}
	cout<<"use the stairs";
	
	return 0;
}
