#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
 
//boj_16916
//KMP 

#define MAXPATT 1000005
string patt;
string text;
int pi[MAXPATT];

void Input(){
	cin>>patt;
	cin>>text;
}

void Solve(){
	int j=0;
	for(int i=1; i<patt.size(); i++){
		while(j>0 && patt[i]!=patt[j]){
			j=pi[j-1];
		}
		if(patt[i]==patt[j]){
			pi[i]=j+1;
			j++;
		}
	}
	
	int ans=0;
	j=0;
	for(int i=0; i<patt.size(); i++){
		while(j>0 && patt[i]!=text[j]){
			j=pi[j-1];
		}
		if(patt[i] == text[j]){
			if(j==text.size()-1){
				ans=1;
				break;
			}
			else
				j++;
		}
	}
	
	cout<<ans;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	//freopen("input.txt", "rt", stdin);
	
	Input();
	Solve();
	
	return 0;
} 
