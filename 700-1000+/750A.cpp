
#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n,k;
	cin>>n>>k;
	int time_left = 240 - k;
	int sum=0;
	int i=1;
	for(i=1; i<=n; i++)
	{
		sum += 5*i;
		if (sum>time_left)
		{
			break;
		}
	}
	cout<<i-1<<"\n";
}

// #include <iostream>
// using namespace std;

// int main()
// {    
//     int number;

//     cout << "Enter an integer: ";
//     cin >> number;

//     cout << "You entered " << number;    
//     return 0;
// }