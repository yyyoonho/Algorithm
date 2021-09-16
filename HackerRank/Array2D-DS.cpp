#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

// HackerRank 2D Array - DS

/*
 * Complete the 'hourglassSum' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts 2D_INTEGER_ARRAY arr as parameter.
 */

int hourglassSum(vector<vector<int>> arr) {
    int sum=0;
    int max1=-2147483647;
    
    for(int i=0; i<4; i++){
        for(int j=0; j<4; j++){
            sum=0;
            
            for(int k=i; k<i+3; k++){
                for(int q=j; q<j+3; q++){
                    if(k==i+1){
                        if(q!=j+1) continue;
                    }
                    sum+=arr[k][q];
                }
            }
            
            max1=max(max1,sum);
        }
    }
    
    return max1;
}
