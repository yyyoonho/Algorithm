#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'minimumBribes' function below.
 *
 * The function accepts INTEGER_ARRAY q as parameter.
 */

void minimumBribes(vector<int> q) {
    int cnt=0;
    int size=q.size();
    
    for(int i=0; i<size; i++){
        //case 1.
        if(q[i]>i+3){
            cout<<"Too chaotic"<<endl;
            return;
        }
        
        //case 2.
        for(int j=max(q[i]-2,0); j<i; j++){
            if(q[j]>q[i]) cnt++;
        }
        
    }
    cout<<cnt<<endl;
    return;
}
