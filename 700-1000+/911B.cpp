#include <bits/stdc++.h>
using namespace std;

int main(){
	long long n, a, b;
	cin>>n>>a>>b;
	if(a>b)
        swap(a,b);
	
	long long min1 = a/(n/2); 
	long long min2 = b/(n-(n/2));

	long long min = (min1 < min2) ? min1 : min2;
	cout<<min;
}