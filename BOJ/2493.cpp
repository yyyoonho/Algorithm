#include <iostream>
#include <cstring>
#include <algorithm>
#include <stack>
#include <queue>

using namespace std;

//น้มุ 2493_ลพ 

#define MAXN 500001
int N; 
vector<int> tower;
stack<int> st;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	//freopen("input.txt", "rt", stdin);
	cin>>N;
		
	int inputNum;
	tower.push_back(0);
	for(int i=0; i<N; i++){
		cin>>inputNum;
		tower.push_back(inputNum);
	}
	
	st.push(1);
	cout<<0<<" ";
	
	for(int i=2; i<tower.size(); i++){
		while(true){
			int tmp=tower[st.top()];
			if(tmp<tower[i]){
				st.pop();
				if(st.empty()){
					cout<<0<<" ";
					st.push(i);
					break;
				}
			}	
			else{
				cout<<st.top()<<" ";
				st.push(i);
				break;
			}
		}
	}

	return 0; 
}
