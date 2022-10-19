#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;

//17140
//구현
//각각 모듈을 잘게 쪼개기
//섣부른 판단으로 조건만들지않기 

#define MAXR 101
#define MAXC 101

struct Node{
	int num;
	int cnt;
	Node(int num1, int cnt1){
		num=num1;
		cnt=cnt1;
	}
	bool operator<(const Node& b)const{
		if(cnt==b.cnt){
			return num>b.num;
		}
		else return cnt>b.cnt;
	}
};

int r,c,k;
int A[MAXR][MAXC];
int countNum[101];
int maxRLength;
int maxCLength;
priority_queue<Node> pQ;

void Input(){
	cin>>r>>c>>k;
	for(int i=1; i<=3; i++){
		for(int j=1; j<=3; j++){
			cin>>A[i][j];
		}
	}
}

void RFunc(){
	//cout<<"RFunc"<<endl;
	
	for(int i=1; i<MAXR; i++){
		memset(countNum,0,sizeof(countNum));
		
		for(int j=1; j<MAXC; j++){
			countNum[A[i][j]]++;
		}
		
		for(int j=1; j<=100; j++){
			if(countNum[j]==0) continue;
			pQ.push(Node(j,countNum[j])); 
		}
		
		int idx=1;
		while(!pQ.empty()){
			if(idx>100){
				break;	
			}
			
			Node now=pQ.top();
			pQ.pop();
			
			A[i][idx]=now.num;
			idx++;
			A[i][idx]=now.cnt;
			idx++;
		}
		
		while(!pQ.empty()) pQ.pop();
		
		for(; idx<MAXC; idx++){
			A[i][idx]=0;
		}
	}
}

void CFunc(){
	//cout<<"CFunc"<<endl;
	
	for(int i=1; i<MAXC; i++){
		memset(countNum,0,sizeof(countNum));
		
		for(int j=1; j<MAXR; j++){
			countNum[A[j][i]]++;
		}
		
		for(int j=1; j<=100; j++){
			if(countNum[j]==0) continue;
			pQ.push(Node(j,countNum[j])); 
		}
		
		int idx=1;
		while(!pQ.empty()){
			if(idx>100){
				break;	
			}
			
			Node now=pQ.top();
			pQ.pop();
			
			A[idx][i]=now.num;
			idx++;
			A[idx][i]=now.cnt;
			idx++;
		}

		while(!pQ.empty()) pQ.pop();

		for(; idx<MAXC; idx++){
			A[idx][i]=0;
		}
	}
}

void GetMaxLength(){
	maxCLength=0;
	maxRLength=0;
	
	for(int i=1; i<101; i++){
		for(int j=1; j<101; j++){
			if(A[i][j]==0){
				maxRLength=max(maxRLength,j-1);
				break;
			}
		}
	}
	
	for(int i=1; i<101; i++){
		for(int j=1; j<101; j++){
			if(A[j][i]==0){
				maxCLength=max(maxCLength,j-1);
				break;
			}
		}
	}
}

void Solve(){
	int sec=0;
	
	if(A[r][c]==k){
		cout<<sec;
		return;
	}
	
	while(true){
		if(sec>100) break;
		sec++;
		
		GetMaxLength();
		
		//Test 
		//cout<<"maxRLength:"<<maxRLength<<"  maxCLength:"<<maxCLength<<endl; 
		
		if(maxCLength>=maxRLength){
			RFunc();
		}
		else if(maxCLength<maxRLength){
			CFunc();
		}
		
		if(A[r][c]==k){
			cout<<sec;
			break;
		}
	}
	
	if(sec>100) cout<<-1;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	//freopen("input.txt", "rt", stdin);
	
	Input();
	Solve();
	
	return 0;
} 
