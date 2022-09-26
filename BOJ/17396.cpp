#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
 
//boj_17396
//���ͽ�Ʈ��
//���� ������ INT������ �ʰ��Ѵ�! �׻� üũ����! 

#define MAXN 100001
#define INF 10000000001

int N,M; 
bool vision[MAXN]; //false -> ������ �þ߰� ������ �ִ�. true-> ������ �þ߿� �ɸ���. 
bool visited[MAXN];
long long dist[MAXN];

struct Node{
	int b;
	int w;
	Node(int b1, int w1){
		b=b1;
		w=w1;
	}
	bool operator<(const Node& n)const{
		return w>n.w;
	}
};

vector<Node> map[MAXN];
priority_queue<Node> pQ;

void Input(){
	cin>>N>>M;
	int checkVision;
	for(int i=0; i<N; i++){
		cin>>checkVision;
		if(i!=N-1 && checkVision==1) vision[i]=true;
	}
	
	int a,b,w;
	for(int i=0; i<M; i++){
		cin>>a>>b>>w;
		map[a].push_back(Node(b,w));
		map[b].push_back(Node(a,w));
	}
	
	for(int i=0; i<N; i++){
		dist[i]=INF;
	}
}

void Djk(int start){
	while(!pQ.empty()){
		Node now = pQ.top();
		pQ.pop();
		
		if(visited[now.b]) continue;
		visited[now.b]=true;
		
		for(int i=0; i<map[now.b].size(); i++){
			Node next = map[now.b][i];
			if(visited[next.b]) continue;
			if(vision[next.b]) continue;
			
			if(dist[next.b]>=dist[now.b]+next.w){
				dist[next.b]=dist[now.b]+next.w;
				pQ.push(Node(next.b,dist[next.b]));
			}
		}
	}
}

void Solve(){
	pQ.push(Node(0,0));
	dist[0]=0;
	Djk(0);
	if(dist[N-1]>=INF){
		cout<<-1;
	}
	else cout<<dist[N-1];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	//freopen("input.txt", "rt", stdin);
	
	Input();
	Solve();
	
	return 0;
} 
