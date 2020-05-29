#include <bits/stdc++.h>

using namespace std;

int main(){

	int n,k,l,c,d,p,nl,np;

	cin>>n>>k>>l>>c>>d>>p>>nl>>np;

	int tot_drink = k*l;

	int tot_lime = c*d;

	int tot_salt = p;

	cout<<min(min(tot_drink/nl,tot_lime), (tot_salt/np))/n;
}