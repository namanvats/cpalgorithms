// Author: Kartikey Tewari
// E-mail: kartikeya30@gmail.com

// Time Complexity: O(n + k*log(p)(base=2))
// Space Complexity: O(n)
// where p is the mod under consideration
// viable method od calculating ncr_mod_p when p is large

#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define endl "\n"
#define mod 1000000007
#define max_val 1000 // maximum possible expected value of n
using namespace std;
vector<ll> fact;

void generate_factorial (ll a)
{   
    fact.resize(a+1);
    fact[0]=1;
    for (ll i=1;i<=a;i++)
    {
        fact[i]=(fact[i-1]*i)%mod;
    }
}

ll power (ll a, ll b)
{
    ll ans=1;
    while (b>=1)
    {
        if (b%2==1)
        {
            ans=(ans*a)%mod;
            b--;
        }
        else
        {
            a=(a*a)%mod;
            b/=2;
        }
    }

    return ans;
}

ll ncr_fermat (ll n, ll r)
{
    ll a=fact[n];
    ll b=power(fact[r],mod-2);
    ll c=power(fact[n-r],mod-2);

    return (((a*b)%mod)*c)%mod;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(10);

    generate_factorial(max_val);
    ll tt;
    cin >> tt;
    for (ll yy=0;yy<=tt-1;yy++)
    {
        ll n,r;
        cin >> n >> r;
        cout << ncr_fermat(n,r) << endl;
    }

    return 0;
}