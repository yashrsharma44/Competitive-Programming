#include <bits/stdc++.h>

using namespace std;

int main(){
	int n;

	cin>>n;

	if(n>=0)
	{
		cout<<n;
	}
	else
	{
		int max=n;

		if(n/10 > n){
			max=n/10;
		}
		if(n%10 + (n/100)*10 > max)
		{
			max = n%10 + (n/100)*10;
		}
		cout<<max;
	}
}