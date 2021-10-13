#include <string>
#include <vector>

using namespace std;

//programmers_모의고사_42840 

int s1[]={1,2,3,4,5};
int s2[]={2,1,2,3,2,4,2,5};
int s3[]={3,3,1,1,2,2,4,4,5,5};
int cnt[4];
int max1=-1;

vector<int> solution(vector<int> answers) {

    int answer_size=answers.size();
    int s1_size=sizeof(s1)/sizeof(s1[0]);
    int s2_size=sizeof(s2)/sizeof(s2[0]);
    int s3_size=sizeof(s3)/sizeof(s3[0]);

    for(int j=0; j<answer_size; j++){
        if(s1[j%s1_size]==answers[j]) cnt[1]++;
        if(s2[j%s2_size]==answers[j]) cnt[2]++;
        if(s3[j%s3_size]==answers[j]) cnt[3]++;
    }

    vector<int> answer;

    for(int i=1; i<4; i++){
        max1=max(max1,cnt[i]);
    }

    for(int i=1; i<4; i++){
        if(max1==cnt[i]) answer.push_back(i);
    }

    return answer;
}
