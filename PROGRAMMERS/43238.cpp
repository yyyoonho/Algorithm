#include <string>
#include <vector>
#include <algorithm>

//PROGRAMMERS_입국심사 #43238

using namespace std;

long long solution(int n, vector<int> times) {
    long long answer = 0;
    long long tmp=0;
    sort(times.begin(), times.end());
    long long start=1;
    long long end=(long long)times[times.size()-1]*n;
    long long mid;
    while(start<=end){
        mid=(start+end)/2;
        for(int i=0; i<times.size(); i++){
            tmp+=mid/times[i];
        }
        if(tmp>=n){
            answer=mid;
            end=mid-1;
        }
        else if(tmp<n){
            start=mid+1;
        }
        tmp=0;
    }

    return answer;
}
