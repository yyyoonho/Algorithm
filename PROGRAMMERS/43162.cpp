
2
3
4
5
6
7
8
9
10
11
12
13
14
15
16
17
18
19
20
21
22
23
24
25
26
27
28
29
30
31
32
33
34
35
36
37
38
39
40
41
42
43
44
45
46
47
48
49
50
51
52
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int unf[201];

void init(){
    for(int i=0; i<201; i++){
        unf[i]=i;
    } 
}

int find(int a){
    if(a==unf[a]) return a;
    else return unf[a]=find(unf[a]);
}

void unionFunc(int a, int b){
    a=find(a);
    b=find(b);
    if(a!=b){
        unf[b]=a;
    }
}

int solution(int n, vector<vector<int>> computers) {
    init();

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(i>=j) continue;
            if(computers[i][j]==1){
                unionFunc(i,j);
            }
        }
    }

    for(int i=0; i<n; i++){
        find(i);
    }

    sort(unf,unf+n);
    int ans=1;
    for(int i=1; i<n; i++){
        if(unf[i]!=unf[i-1]) ans++;
    }

    return ans;
}
