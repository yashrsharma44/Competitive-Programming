#include <bits/stdc++.h>
#define ll long long int

using namespace std;

void solve(){

	unsigned long long n;
	cin>>n;

	unsigned long long ans=0ULL;

	for(unsigned long long i=1ULL;i<=(n-1ULL)/(2ULL);i++){
		ans+=(i*(1ULL << (i-1ULL)));
	}
	unsigned long long e = 8ULL;
	// ans = ans * ()
	cout<<(unsigned long long)(ans*e)<<endl;

}

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	unsigned long long t;
	cin>>t;
	// t = 1;

	while(t--){
		solve();
	}
}
