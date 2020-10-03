// Author: Kartikey Tewari
// E-mail: kartikeya30@gmail.com

// Time Complexity: O(pow(p,2) + log(n)(base=p))
// Space Complexity: O(pow(p,2))
// where p is the mod under consideration
// viable method od calculating ncr_mod_p when p is small

#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define endl "\n"
#define mod 997
using namespace std;
vector<vector<ll>> dp;

void generate_dp (ll a)
{
    dp.resize(a+1,vector<ll> (a+1));
    for (ll i=1;i<=a;i++)
    {
        dp[i][0]=1;
        dp[0][i]=0;
    }
    dp[0][0]=1;

    for (ll i=1;i<=a;i++)
    {
        for (ll j=1;j<=a;j++)
        {
            dp[i][j]=(dp[i-1][j-1]+dp[i-1][j])%mod;
        }
    }
}

ll ncr_lucas (ll n, ll r)
{
    if ((r==0)||(r==n))
    {
        return 1;
    }
    else
    {
        ll a=n%mod;
        ll b=r%mod;

        return (ncr_lucas(n/mod,r/mod)*dp[a][b])%mod;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(10);

    ll tt;
    cin >> tt;
    generate_dp(mod);
    for (ll yy=0;yy<=tt-1;yy++)
    {
        ll n,r;
        cin >> n >> r;
        cout << ncr_lucas(n,r) << endl;
    }

    return 0;
}