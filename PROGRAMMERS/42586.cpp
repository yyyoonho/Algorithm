#include <string>
#include <vector>

//PROGRAMMERS_기능개발 #42586

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {

    vector<int> answer;
    int cnt=0;
    int pIndex=0;
    bool flag=false;
    int size=progresses.size();
    vector<bool> check(size,false);
    while(true){
        //종료 flag
        flag=true;

        //작업진행 
        for(int i=0; i<size; i++){
            if(progresses[i]<100){
                flag=false;
                progresses[i]+=speeds[i];
                if(progresses[i]>=100) check[i]=true;
            }
        } 

        //종료조건
        if(flag==true) break; 

        //배포 
        for(int i=pIndex; i<size; i++){
            if(check[i]==true) cnt++;
            else{
                pIndex=i;
                break;
            }
        }

        //출력 
        if(cnt>0){
            answer.push_back(cnt);
            cnt=0;
        }

    }


    return answer;
}
