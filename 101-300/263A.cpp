#include <bits/stdc++.h>

using namespace std;

int main()
{
	// vector< vector <int> > mat(5);
	int i,j;
	
	int x, y;
	for(i=0;i<5;i++)
	{
		for(j=0;j<5;j++)
		{
			int value;
			cin>>value;
			// mat[i][j] = value;
			if(value)
			{
				x = i;
				y = j;
			}
		}
	}

	cout<<(abs(x-2)+abs(y-2));



	
}