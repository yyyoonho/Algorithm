#include <string>
#include <vector>

using namespace std;

//프로그래머스_타겟넘버_#43165 

int answer = 0;

void DFS(vector<int> &numbers, int& target, int sum, int cnt){
	if(cnt==numbers.size()){
		if(sum==target){
			answer++;
		}
		return;
	}
	DFS(numbers,target,sum+numbers[cnt],cnt+1);
	DFS(numbers,target,sum-numbers[cnt],cnt+1);
}

int solution(vector<int> numbers, int target) {
    DFS(numbers, target,0,0);
    return answer;
}
