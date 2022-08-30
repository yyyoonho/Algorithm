#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
 
//boj_1931
//그리디
//우선순위 큐 

int N;

struct Meeting{
	int startTime;
	int endTime;
	Meeting(int st, int et){
		startTime=st;
		endTime=et;
	}
	bool operator<(const Meeting &b) const{
		if(endTime==b.endTime){
			return startTime>b.startTime;
		}
		else return endTime>b.endTime;
	}
};

priority_queue<Meeting> pQ;

void Input(){
	cin>>N;
	int st,et;
	for(int i=0; i<N; i++){
		cin>>st>>et;
		pQ.push(Meeting(st,et));
	}
}

void Solve(){
	int nowTime=0;
	int cnt=0;
	
	while(!pQ.empty()){
		if(nowTime>pQ.top().startTime){
			pQ.pop();
			continue;
		}
		
		nowTime=pQ.top().endTime;
		pQ.pop();
		cnt++;
	}
	
	cout<<cnt;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	//freopen("input.txt", "rt", stdin);
	
	Input();
	Solve();
	
	return 0;
} 
