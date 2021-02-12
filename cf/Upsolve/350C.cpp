#include <bits/stdc++.h>
#define int long long 
#define MOD 100000000
using namespace std;



void solve(){

    int n; cin>>n;
    vector<vector<int>> arr;
    int nn = n;
    while(nn--){
        int u,v; cin>>u>>v;
        arr.push_back({abs(u) + abs(v), u, v});
    }

    sort(arr.begin(), arr.end());
    int ans = 0;

    for(auto el : arr){
        int cnt = 3;
        if(el[1] == 0) cnt--;
        if(el[2] == 0) cnt--;
        ans += (cnt * 2);
    }
    printf("%lld\n",ans);
    // vector<string> aa;
    for(auto el : arr){
        if(el[1] > 0){
            printf("1 %lld R\n", el[1]);
        } else if(el[1] < 0){
            printf("1 %lld L\n",abs(el[1]));
        }

        if(el[2] > 0){
            printf("1 %lld U\n", abs(el[2]));
        } else if(el[2] < 0){
            printf("1 %lld D\n", abs(el[2]));
        }

        printf("2\n");
        if(el[1] > 0){
            printf("1 %lld L\n", el[1]);
        } else if(el[1] < 0){
            printf("1 %lld R\n", abs(el[1]));
        }

        if(el[2] > 0){
            printf("1 %lld D\n", abs(el[2]));
        } else if(el[2] < 0){
            printf("1 %lld U\n", abs(el[2]));
        }

        printf("3\n");
    }

    // ans = aa.size();
    // cout<<ans<<endl;
    // for(auto el : aa) cout<<el<<endl;


}

int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	// cin>>t;
	t = 1;

	while(t--){
		solve();
	}
}