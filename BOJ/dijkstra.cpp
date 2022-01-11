#include <iostream>
#include <vector>
#include <queue>

using namespace std;

//���ͽ�Ʈ�� ���� 

/* ����
6 9
1 2 2
1 3 6
1 5 3
1 6 5 
2 3 2
2 4 1
2 5 4
4 5 1
5 6 1 
*/

struct Node{
	int vertex;
	int w;
	Node(int v1, int w1){
		vertex=v1;
		w=w1;
	};
	bool operator<(const Node &b)const{
		return w>b.w;
	}
}; 

#define MAXN 50
#define INF 2147483647

vector<Node> v[MAXN];
bool visit[MAXN];
int cost[MAXN]; 
priority_queue<Node> pQ;
int N,M;

void init(){
	for(int i=0; i<MAXN; i++){
		cost[i]=INF;
	}
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	freopen("input.txt", "rt", stdin);
	cin>>N>>M;
	
	init();
	//������ ���� 
	int x,y,w;
	for(int i=1; i<=M; i++){	
		cin>>x>>y>>w;
		v[x].push_back(Node(y,w));
		v[y].push_back(Node(x,w));
	}
	
	//���۳�� 1������ ����
	cost[1]=0;
	pQ.push(Node(1,0));
	
	while(!pQ.empty()){
		Node nowNode=pQ.top();
		pQ.pop();
				
		int x=nowNode.vertex;
		int w=nowNode.w;
		
		//�湮üũ 
		if(visit[x]==true) continue;
		visit[x]=true;
		
		// x -> ����vertex �ּҰ� ����
		for(int i=0; i<v[x].size(); i++){
			Node nextNode = v[x].at(i);
			if(visit[nextNode.vertex]) continue;
			if(cost[nextNode.vertex]>cost[x]+nextNode.w){
				cost[nextNode.vertex] = cost[x]+nextNode.w;
				pQ.push(Node(nextNode.vertex, cost[nextNode.vertex]));
			}
		} 
	}
	
	//������ 
	for(int i=1; i<=N; i++){
		cout<<cost[i]<<endl;
	}
	
	return 0; 
}
