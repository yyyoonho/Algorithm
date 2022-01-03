#include <stdio.h>
#include <algorithm>
#include <queue>
#include <iostream>
#include <set>

using namespace std;

//백준_1039_교환 

int main(){
	//ios_base::sync_with_stdio(false);
	//freopen("input.txt", "rt", stdin);
	
	char S[10],t;
	int k;
	string str, ans="0";
	queue<string> Q;
	
	scanf("%s %d", S, &k);
	str=S;
	
	Q.push(str);
	
	for(int i=0; i<k; i++){
		set<string> s;
		int qSize=Q.size();
		
		for(int j=0; j<qSize; j++){
			str=Q.front();
			Q.pop();
			
			if(s.count(str)==1) continue;
			s.insert(str);
			
			for(int k=0; k<str.size()-1; k++){
				for(int l=k+1; l<str.size();l++){
					if(k==0 && str[l]=='0') continue;
					
                    t = str[k];
                    str[k] = str[l];
                    str[l] = t;

                    Q.push(str);

                    t = str[k];
                    str[k] = str[l];
                    str[l] = t;
				}
			}
		}
	}
	
	while(!Q.empty()){
        ans = max(ans, Q.front());
        Q.pop();
    }
    
	if(ans[0]=='0') printf("-1");
    else printf("%s", ans.c_str());    

	return 0;
}
