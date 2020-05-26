#include <bits/stdc++.h>
#define ll long long int
using namespace std;

bool comp(pair<ll,ll> &p1, pair<ll,ll> &p2){
	return p1.second < p2.second;
}

void solve(){

	ll n;
	cin>>n;
	ll num = n;
	map<ll,ll> prime;

	while(n % 2 == 0){
		prime[2] += 1;
		n = n / 2;
	}

	for(ll i=3;i*i<=n;i+=2){

		while(n % i==0){
			prime[i] += 1;
			n = n / i;
		}

	}

	if(n > 2){
		prime[n] += 1;
	}

	ll size = prime.size();
	
	vector<pair<ll,ll> > prime_num;

	for(pair<ll,ll> el : prime){
		// cout<<el.first<<" "<<el.second<<endl;
		prime_num.push_back(el);
	}

	if(size >= 3){

		ll new_num = num / (pow(prime_num[0].first, prime_num[0].second));
		new_num /= pow(prime_num[1].first, prime_num[1].second);
		cout<<"YES"<<endl;

		ll num1 = pow(prime_num[0].first, prime_num[0].second);
		ll num2 = pow(prime_num[1].first, prime_num[1].second);
		ll num3 = num / (num1 * num2);
		cout<<num1<<" "<<num2<<" "<<num3<<endl;
	
	} else if(size == 2){
		
		ll sum_pow = prime_num[0].second + prime_num[1].second;
		if(sum_pow < 4){
			cout<<"NO"<<endl;
		} else {

			cout<<"YES"<<endl;
			ll num3 = (num / (prime_num[0].first * prime_num[1].first));
			cout<<prime_num[0].first<<" "<<prime_num[1].first<<" "<<num3<<endl;
		}

	} else {

		ll poww = prime_num[0].second;
		if(poww < 6){
			cout<<"NO"<<endl;
			return;
		} else {
			ll num1 = pow(prime_num[0].first, 1);
			ll num2 = pow(prime_num[0].first, 2);
			ll num3 = pow(prime_num[0].first, prime_num[0].second - 3);
			cout<<"YES"<<endl;
			cout<<num1<<" "<<num2<<" "<<num3<<endl;
		}
	}

}

int main(){

	ll t;
	cin>>t;

	while(t--){
		solve();
	}
}