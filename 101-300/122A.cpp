#include <bits/stdc++.h>

using namespace std;

bool check_lucky(int n)
{
	while(n!=0)
	{
		int r=n%10;
		if(r==4 || r==7)
		{
			n=n/10;
			continue;
		}
		else
		{
			return false;
		}

	}
	return true;
}

bool almost_lucky(int n)
{
	if((n%4==0)||(n%7==0)||(n%47==0)||(n%74==0)||(n%474==0)||(n%444==0)||(n%447==0)||(n%477==0)||(n%744==0)||(n%747==0)||(n%777==0))
	{
		return true;
	}
	else
	{
		return false;
	}

}

int main()
{
	int n;
	cin>>n;

	// If lucky
	if(check_lucky(n))
	{
		cout<<"YES";
	}
	else if(almost_lucky(n))
	{
		cout<<"YES";
	}
	else
	{
		cout<<"NO";
	}

}