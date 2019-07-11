#include <bits/stdc++.h>

using namespace std;

int main()
{
	int a,b,c;

	cin>>a>>b>>c;
	int list[8];
	list[0]=(a+b+c);
	list[1]=((a*b)+c);
	list[2]=((a+b)*c);
	list[3]=(a+(b*c));
	list[4]=(a*(b+c));
	list[5]=(a*b*c);

	int i=0,max=list[0];
	for(i=1;i<6;i++)
	{
		if(max<list[i])
		{
			max=list[i];
		}
	}

	cout<<max;
}