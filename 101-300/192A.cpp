#include <bits/stdc++.h>
using namespace std;

int main(){

	long long n;
	cin>>n;

	long long max_value = sqrt(2*n);
	int i;
	long long funky_value[max_value+1];
	for(i=0;i<=max_value;i++){funky_value[i]=(i)*(i+1)/2;}

	int low=1,high=max_value;
	bool found(0);
	while(low<=high)
	{
		int mid = (low+high)/2;
		if(funky_value[low]+funky_value[high] == n){found=1;break;}
		else if(funky_value[low]+funky_value[high]<n){low=mid+1;}
		else{high=mid-1;}
	}

	if (!found)
	{cout<<"NO";}
else
	{cout<<"YES";}


}