#include <bits/stdc++.h>
#define ll long long int

using namespace std;

int main(){

	ll n,m,a;
	cin>>n>>m>>a;

	ll l= 0, b = 0;

	if((m % a) ==0){
		l=m/a;
	} else {
		l = m/a + 1;
	}

	if((n%a)==0){
		b=n/a;
	} else {
		b = n / a + 1;
	}

	cout<<(l*b)<<endl;
}