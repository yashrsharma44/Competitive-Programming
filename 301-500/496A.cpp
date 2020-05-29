#include <bits/stdc++.h>

using namespace std;

int main(){

	int n;
	cin>>n;
	vector <int> list(n);

	int i;

	for(i=0;i<n;i++)
	{
		cin>>list[i];
	}

	vector <int> diff(n-1);
	int max = -1;
	for(i=0;i<n-1;i++)
	{
		if(max<list[i+1] - list[i])
		{
			max = list[i+1] - list[i];
		}
	}

	int min = 9999999;

	for(i=1;i<n-1;i++)
	{
		// if(list[i+1] - list[i-1] < min && list[i+1] - list[i-1] >= max){
			min = std::max(max, std::min(min,list[i+1] - list[i-1])); 
		// }
	}

	cout<<min;



}