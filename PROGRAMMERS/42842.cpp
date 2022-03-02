#include <string>
#include <vector>

using namespace std;
int sum=0;

vector<int> solution(int brown, int yellow) {
    sum=brown+yellow;
	vector<int> answer;
    
	for(int i=3; i*i<=sum; i++){
		int row=sum/i;
		int col=i;
		if((row-2)*(col-2)==yellow){
			answer.push_back(row);
            answer.push_back(col);
            break;
		}
	}
    
    return answer;
}
