#include <iostream>
#include <queue>
using namespace std;

//BOJ_¼û¹Ù²ÀÁú2 #12851
 
int N,K;
int cnt;
bool check[100001];
int mini;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "rt", stdin);
	cin>>N>>K;
	queue<pair<int,int> > Q;
	Q.push(make_pair(N,0));
	
	while(!Q.empty()){
		int now=Q.front().first;
		int moveCnt=Q.front().second;
		Q.pop();
		check[now]=true;
		
		if(mini!=0 && mini<moveCnt){
			while(!Q.empty()) Q.pop();
			break;
		}
		
		if(mini==moveCnt && now==K){
			cnt++;
			continue;
		}
		
		if(mini==0 && now==K){
			mini=moveCnt;
			cnt++;
			continue;
		}
		
		if((now-1)>=0 && check[now-1]==false){
			Q.push(make_pair(now-1, moveCnt+1));	
		}
		if((now+1)<=100000 && check[now+1]==false){
			Q.push(make_pair(now+1, moveCnt+1));
		}
		if((now*2)<=100000 && check[now*2]==false){
			Q.push(make_pair(now*2, moveCnt+1));
		}
	}
	
	cout<<mini<<endl;
	cout<<cnt<<endl;
	
	return 0;
}
