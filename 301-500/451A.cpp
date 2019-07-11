#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n,m;
	cin>>n>>m;

	int mul = n*m;
	int i=0;
	while(mul!=0)
	{
		
		mul = (n-1)*(m-1);
		n=n-1;
		m=m-1;
		i+=1;
	}

	if(i%2==0)
	{
		cout<<"Malvika";
		
	}
	else
	{
		cout<<"Akshat";
	}
}