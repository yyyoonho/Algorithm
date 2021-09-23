#include <string>
#include <vector>

//PROGRAMMERS_��ɰ��� #42586

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {

    vector<int> answer;
    int cnt=0;
    int pIndex=0;
    bool flag=false;
    int size=progresses.size();
    vector<bool> check(size,false);
    while(true){
        //���� flag
        flag=true;

        //�۾����� 
        for(int i=0; i<size; i++){
            if(progresses[i]<100){
                flag=false;
                progresses[i]+=speeds[i];
                if(progresses[i]>=100) check[i]=true;
            }
        } 

        //��������
        if(flag==true) break; 

        //���� 
        for(int i=pIndex; i<size; i++){
            if(check[i]==true) cnt++;
            else{
                pIndex=i;
                break;
            }
        }

        //��� 
        if(cnt>0){
            answer.push_back(cnt);
            cnt=0;
        }

    }


    return answer;
}
