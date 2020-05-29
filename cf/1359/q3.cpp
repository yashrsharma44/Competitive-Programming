#include <bits/stdc++.h>
#define ll long long int

using namespace std;

double sm(ll h, ll c, ll k){

	ll z = k / 2;
	double sum = (z*h) + (k - z)*c;
	double avg = sum / k;

	return avg;

}

void solve(){
	
	double h,c,t;
	cin>>h>>c>>t;

	if(2*t == (h+c)){
		cout<<2<<endl;
		return;
	}

	double a1 = (h+c+h) / 3;
	double a2 = h;

	if(t >= a1){

		if(abs(a2 - t) < abs(a1 - t)){
			cout<<1<<endl;
		} else {
			cout<<3<<endl;
		}
		return;
	}

	double sum = 0;
	ll k = 1;
	ll r = 0;
	if((ll)(h-c)%2!=0){
		r = (h - c) / 2;
	} else {
		r = (h - c)/2 + 1;
	}
	ll l = 1;
	while(l<=r){

		ll k = l + (r - l) / 2;

		if(k % 2 == 0){
			k+=1;
		}

		double d1 = t - sm(h,c,k-1);
		double d2 =  t - sm(h,c,k);
		double d3 =  t - sm(h,c,k+1);

		if((d1 - d2) == (d2 - d3)){

			if(d1 - d2 >  0){
				r = k - 1;
			} else {
				l = k + 1;
			}

		} else {
			cout<<k<<endl;
			return;
		}
	}

}


int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	ll t;
	cin>>t;
	// t = 1;

	while(t--){
		solve();
	}
}
