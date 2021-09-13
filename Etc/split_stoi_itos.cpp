#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

//C++ 문자열 split, string-> int, int-> string

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);	
	string test="123 456 789 Ryan"; 
	
	//문자열 자르기
	string buf;
	istringstream ss(test);
	vector<string> v;
	while(getline(ss, buf, ' ')){
		v.push_back(buf);
	}
	
	for(int i=0; i<v.size(); i++)
		cout<<v[i]<<endl;
	cout<<"===="<<endl;	
	
	
	//string -> int
	int tmp = stoi(v[0]);
	cout<<tmp+1<<endl;
	cout<<tmp+1<<endl;
	cout<<"===="<<endl;
	
	//int -> string
	string s = to_string(tmp);
	s=s+"Hello"; 
	cout<<s<<endl;
	
	return 0;
}
