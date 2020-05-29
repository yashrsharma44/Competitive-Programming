#include <bits/stdc++.h>

using namespace std;

int main(){


	int a,b;

	cin>>a>>b;

	int i;
	int a_count =0,b_count=0,tie=0;

	for(i=1;i<7;i++)
	{
		if(abs(a-i)>abs(b-i))
		{
			b_count+=1;
		}
		else if(abs(a-i)<abs(b-i))
		{
			a_count+=1;
		}
		else if(abs(a-i)==abs(b-i))
		{
			tie+=1;
		}
	}

	cout<<a_count<<" "<<tie<<" "<<b_count;
}