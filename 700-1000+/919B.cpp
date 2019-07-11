#include <bits/stdc++.h>
using namespace std;

int sum(int num){
	int val = 0;
	while(num!=0){
		val += num %10;
		num /= 10;
	}
	return val;
}

int main(){

	int k;
	cin>>k;
	long long MAX=1e9;
	int count=0;
	long long ans=0;
	for(long long i=1;i<=MAX, count<k;i++)
	{
		if(sum(i)==10)
		{
			count++;
			ans = i;
		}
	}
	cout<<ans;
}