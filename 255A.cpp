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

	int biceps=0;
	int chest=0;
	int back=0;

	for(i=0;i<n;i++)
	{
		if(i%3==0)
		{
			chest+=list[i];
		}
		if(i%3==1)
		{
			biceps+=list[i];
		}
		if(i%3==2)
		{
			back+=list[i];
		}
	}

	int max=-1;

	max = std::max(std::max(biceps,chest), back);

	if(biceps==max)
	{
		cout<<"biceps";
	}
	if(chest==max)
	{
		cout<<"chest";
	}
	if(back==max)
	{
		cout<<"back";
	}



}