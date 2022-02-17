#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//백준 1920_수 찾기 

int N,M;
vector<int> v;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	freopen("input.txt", "rt", stdin);
	
	cin>>N;
	int a;
	for(int i=0; i<N; i++){
		cin>>a;
		v.push_back(a);
	}
	
	sort(v.begin(),v.end());
	
	cin>>M;
	for(int i=0; i<M; i++){
		int ans,l,r,mid;
		r=N-1;
		l=0;
		cin>>ans;
		
		while(l<=r){
			mid=(r-l)/2+l;
			
			if(v[mid]==ans){
				 cout<<"1"<<"\n";
				 break;
			}
			else if(v[mid]>ans){
				r=mid-1;
			}
			else{
				l=mid+1;
			}
		}
		
		if(l>r) cout<<"0"<<"\n";
	}

	return 0; 
}
