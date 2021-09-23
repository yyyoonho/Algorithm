#include <string>
#include <vector>
#include <queue>

//PROGRAMMERS_기능개발 #42586

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    queue<int> Q;
    int size=progresses.size();
    for(int i=0; i<size; i++){
        int tmp=(100-progresses[i])%speeds[i];
        if(tmp==0)
            Q.push((100-progresses[i])/speeds[i]);
        else
            Q.push((100-progresses[i])/speeds[i]+1);
    }
    
    while(!Q.empty()){
        int cnt=1;
        int cur=Q.front();
        Q.pop();
        while(cur>=Q.front() && !Q.empty()){
            cnt++;
            Q.pop();
        }
        answer.push_back(cnt);
    }
    
    return answer;
}
