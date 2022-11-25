#include <algorithm>
#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

//1202
// priority_queue에서 less -> 내림차순, greater -> 오름차순
// sort 에서 less-> 오름차순, greater -> 내림차순

#define MAXK 300001

struct Jewerly
{
	Jewerly(int w, int p):weight(w),price(p){}

	int weight;
	int price;

	bool operator<(const Jewerly& other)const
	{
		return weight < other.weight;
	}
	bool operator>(const Jewerly& other)const
	{
		return weight > other.weight;
	}
};

vector<Jewerly> v;
int bag[MAXK];
priority_queue<int,vector<int>,less<int> > pq;
int N, K;

void Input()
{
	cin >> N >> K;
	
	v.reserve(N+1);
	int w, p;
	for (int i = 0; i < N; i++)
	{
		cin >> w >> p;
		v.push_back(Jewerly(w, p));
	}
	
	for (int i = 0; i < K; i++)
	{
		cin >> bag[i];
	}
	
}

void Solve()
{
	sort(v.begin(), v.end());
	sort(bag, bag + K);

	int idx = 0;
	long long sum = 0;
	for (int i = 0; i < K; i++)
	{
		while (idx < N && bag[i] >= v[idx].weight) 
		{
			pq.push(v[idx].price);
			idx++;
		}
		if (!pq.empty())
		{
			//cout << pq.top() << endl;
			sum += pq.top();
			pq.pop();
		}
	}

	cout << sum;

}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	Input();
	Solve();

	return 0;
}
