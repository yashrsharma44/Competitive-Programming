#include<bits/stdc++.h>
using namespace std;

int n, a[200002];
map<long long, int> mp;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    mp[0] = -1;
    cin >> n;
    long long sm = 0;
    long long ans = 0;
    int mx = 0;
    cout<<"Sum: "<<sm<<" Max: "<<mx<<" Ans: "<<ans<<endl;
    for(int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        sm += a[i];
        if(mp.find(sm) != mp.end())
        {
            if(sm == 0 && mp[0] == -1)
                mx = max(mx, 1);
            else
                mx = max(mx, mp[sm] + 1);
        }
        mp[sm] = i;
        cout<<"---------------------"<<endl;
        cout<<"ANS + I - MX ("<<ans<<"+"<<i<<"-"<<mx<<"="<<(ans+i-mx)<<")"<<endl;
        
        ans = ans + i - mx;
        cout<<"Sum: "<<sm<<" Max: "<<mx<<" Ans: "<<ans<<endl;
    
    }
    cout << ans;
    return 0;
}