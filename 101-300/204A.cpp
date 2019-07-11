#include <bits/stdc++.h>

using namespace std;


int get_len(int r)
{
	int count=0;
	for(;r!=0;)
	{
		count+=1;
		r=r/10;
	}
	return count;
}

int first_dig(int m, double len)
{
	return m%(int)(pow(10,len-1));
}
int main()
{
	int l,r;

	cin>>l>>r;

	int min_len = get_len(l);
	int max_len = get_len(r);


	if (max_len<3)
	{
		if(max_len==1)
		{
		
			cout<<(r - l+1);
			
		}
		else if(max_len==2)
		{
			if(min_len==1)
			{
				cout<<(9-l+1)+(r/11);
			}
			else if(min_len==2)
			{
				cout<<(r/11)-(l/11);
			}
		}
	}
	else
	{
		if(min_len==1)
		{
			cout<<(9-l+1) + (9) +(first_dig(r, max_len)*pow(10,max_len-2));
		}
		else if(min_len==2)
		{
			cout<<(9-first_dig(l,min_len)+1)+(first_dig(r, max_len)*pow(10,max_len-2));
		}
		else 
		{
			cout<<(first_dig(r, max_len)*pow(10,max_len-2))-(first_dig(l, min_len)*pow(10,min_len-2));
		}
	}
}