#include <iostream>
#include <queue>
using namespace std;

//BOJ_¼û¹Ù²ÀÁú4 #13913
 
int N,K;
int cnt;
bool check[100001];
int visited[100001];
vector<int> path;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "rt", stdin);
	cin>>N>>K;
	queue<pair<int,int> > Q;
	
	Q.push(make_pair(N,0));
	
	while(!Q.empty()){
		int now=Q.front().first;
		int cnt=Q.front().second;
		Q.pop();
		
		if(now==K){
			cout<<cnt<<endl;
			int idx=now;
			while(idx!=N){
				path.push_back(idx);
				idx=visited[idx];
			}
			path.push_back(N);
			
			for(int i=path.size()-1; i>=0; i--){
				cout<<path[i]<<" ";
			}
			break;	
		}
		
		if(now-1>=0 && check[now-1]==false){
			Q.push(make_pair(now-1, cnt+1));
			check[now-1]=true;
			visited[now-1]=now;
		}
		if(now+1<=100000 && check[now+1]==false){
			Q.push(make_pair(now+1, cnt+1));
			check[now+1]=true;
			visited[now+1]=now;
		}
		if(now*2<=100000 && check[now*2]==false){
			Q.push(make_pair(now*2, cnt+1));
			check[now*2]=true;
			visited[now*2]=now;
		}
	}
	
	return 0;
}
