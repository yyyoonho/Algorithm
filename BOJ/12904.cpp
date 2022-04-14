#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

string S,T;

bool check(){
	if(S==T) return true;
	else return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	//freopen("input.txt", "rt", stdin);
	
	cin>>S;
	cin>>T;
	
	while(T.size()>S.size()){
		if(T[T.size()-1]=='A') T.pop_back();
		else{
			T.pop_back();
			reverse(T.begin(),T.end());
		}
	}
	
	bool flag=check();
	if(flag) cout<<"1";
	else cout<<"0";
	
	return 0;
}
