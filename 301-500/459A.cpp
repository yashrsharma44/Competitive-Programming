#include <bits/stdc++.h>

using namespace std;

int main()
{
	int x1,x2,y1,y2;

	cin>>x1>>y1>>x2>>y2;

	// 

	// Case1 two points have either same x or y

	if(x1==x2 || y1==y2)
	{
		if(x1==x2)
		{
			int dx = abs(y2-y1);
			cout<<x1+dx<<" "<<y1<<" "<<x1+dx<<" "<<y2;
		}
		else
		{
			int dy = abs(x2-x1);
			cout<<x2<<" "<<y1+dy<<" "<<x1<<" "<<y1+dy;
		}
	}

	// Case2 two points have diff x and y

	if(x1!=x2 && y1!=y2)
	{
		if(abs(x2-x1)==abs(y2-y1))
	{
		cout<<x1<<" "<<y2<<" "<<x2<<" "<<y1;
	}
	else
	{
		cout<<-1;
	}
	}

}