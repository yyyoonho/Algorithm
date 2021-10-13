#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(string numbers) {
    int cnt=0;
    vector<int> v;
	for(int i=0; i<numbers.size(); i++){
		v.push_back(numbers[i]-'0');
	}
	sort(v.begin(),v.end());
	
	vector<int> ans;
	
	do{
		for(int i=0; i<=v.size(); i++){
			int tmp=0;
			for(int j=0; j<i; j++){
				tmp=(tmp*10)+v[j];
				ans.push_back(tmp);
			}
		}
	}while(next_permutation(v.begin(),v.end()));
	
    sort(ans.begin(),ans.end());
	ans.erase(unique(ans.begin(),ans.end()),ans.end());
	
	for(int i=0; i<ans.size(); i++){
		bool flag=false;
		if(ans[i]<2) continue;
		for(int j=2; j*j<=ans[i]; j++){
			if(ans[i]%j==0){
				flag=true;
				break;
			}
		}
		if(flag==false) cnt++;
	}
    return cnt;
}
