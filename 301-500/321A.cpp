#include <bits/stdc++.h>
#include <string>

using namespace std;

struct par{
	long long first;
	long long second;
};

int main()
{
	long long a,b;

	cin>>a>>b;

	string str; 
  	cin.ignore(1000,'\n');
    // Taking string input using getline() 
    // "geeksforgeek" in givin output 
    getline(cin,str); 
  

	long long len = str.length();

	// Create a pair for storing the cumulative dist after traversing
	// first->x and second->y
	// cout<<"S"<<str;
	par dp[len];
	dp[0].first = 0;
	dp[0].second= 0;
	long long i;
	for(i=1;i<len;i++)
	{
		if(dp[i].first == a && dp[i].second == b)
		{
			cout<<"YES";
		}
		if(str[i]=='U')
		{
			dp[i].second = dp[i-1].second + 1;
			dp[i].first = dp[i-1].first;
		}
		else if(str[i]=='D')
		{
			dp[i].second = dp[i-1].second - 1;
			dp[i].first = dp[i-1].first;
		}
		else if(str[i]=='L')
		{
			dp[i].first = dp[i-1].first - 1;
			dp[i].second = dp[i-1].second;
		}
		else if(str[i]=='R')
		{
			dp[i].first = dp[i-1].first + 1;
			dp[i].second = dp[i-1].second;
		}
	}

	par full;
	full.first = dp[len-1].first;
	full.second = dp[len-1].second;

	// Trying to find a k which results in the same initial point
	// pair <long long, long long> k(0,0);
	par k;
	k.first = k.second = -1 ;
	for(i=0;i<len;i++)
	{
		if(full.first)
		{
			k.first = (a - dp[i].second)/full.first;
		}
		else if(!full.first)
		{
			k.first = 0;
		}
		if(full.second)
		{
			k.second = (b - dp[i].second)/full.second;
		}
		else if(!full.second)
		{
			k.second = 0;
		}
		if(k.first==k.second!=0)
		{
			cout<<"YES";
		}
	}
	cout<<"KF"<<k.first<<"KS"<<k.second;
	if(k.first>0 && k.second>0)
	{
		if(k.first==k.second!=0)
		{
			cout<<"YES";
		}
	}
	// if(k.first<0 || k.second<0)
	// 	{
	// 		cout<<"NO";
	// 	}
	
	else
	{
		cout<<"NO";
	}


}