#include <bits/stdc++.h>
using namespace std;

int bin_ser(int *A, int l, int r, int sum)
	{
		if(r>=l)
		{
			// cout<<"L"<<l<<"R"<<r<<"\n";
			int mid = (r+l)/2;
			if (A[r] - A[l] > sum)
				{
					
					bin_ser(A, l, mid-1, sum);
				}
				else
				{	

					// cout<<"RET"<<(r-l+1);
					return (r-l+1);
				}
		}
		else
		{
			return 0;
		}
	}

int main()
{
	int n, t;

	cin>>n>>t;
	int books[n];
	int i, j;
	int sum[n];
	for(i=0;i<n;i++)
	{
		cin>>books[i];
		if(i==0)
		{
			sum[i] = books[i];
		}
		else
		{
			sum[i] = sum[i-1]+books[i];
		}
	}

	
	// Use two pointer technique

	int comsum =0;
	

	int max=-1;
	// Store the max
	for(i=0;i<n;i++)
	{
		// We should find the value of j, condition being the
		// diff of values shoould be <= time. We can choose j
		// in O(n) time, but using binary search we can get the 
		// value of j in O(lgn)
		int val = bin_ser(sum, i, n-1, t+sum[i]-books[i]);
		max = val - i + 1;
		if (max < val)
		{
			max = val;
		}

	}

	cout<<max;

}