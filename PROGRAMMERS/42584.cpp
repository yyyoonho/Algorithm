#include <string>
#include <vector>
#include <stack>

//프로그래머스_주식가격_#42584

using namespace std;

vector<int> solution(vector<int> prices) {
    int size = prices.size();
    vector<int> answer(size);
    stack<int> st;
    
    for(int i=0; i<size; i++){
        //가격이 떨어진 경우
        while(!st.empty() && (prices[st.top()]>prices[i])){
            answer[st.top()]=i-st.top();
            st.pop();
        }
        st.push(i);
    }
    
    while(!st.empty()){
        answer[st.top()]=size-st.top()-1;
        st.pop();
    }
    
    return answer;
}
