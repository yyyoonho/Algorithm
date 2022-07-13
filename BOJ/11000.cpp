#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

//boj_11000
//그리디
//우선순위 큐 

int N;
int ans=0;
vector<pair<int,int> > lecture;
priority_queue<int, vector<int>, greater<int> > endQ;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	//freopen("input.txt", "rt", stdin);
	
	cin>>N;
	
	int a,b;
	for(int i=0;i<N; i++){
		cin>>a>>b;
		lecture.push_back(make_pair(a,b));
	} 
	
	sort(lecture.begin(),lecture.end());
	
	endQ.push(lecture[0].second);
	
	for(int i=1; i<N; i++){
		if(endQ.top() <= lecture[i].first){
			endQ.pop();
			endQ.push(lecture[i].second);
		}
		else{
			endQ.push(lecture[i].second);
		}
	}
	
	cout<<endQ.size()<<endl;
	

	return 0;
} 
