// Author: Kartikey Tewari
// E-mail: kartikeya30@gmail.com

// Time Complexity: 
// Space Complexity: 

#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define endl "\n"
#define mod 997
using namespace std;
vector<vector<int>> dp;

void generate_dp (int a)
{
    dp.resize(a+1,vector<int> (a+1));
    for (int i=1;i<=a;i++)
    {
        dp[i][0]=1;
        dp[0][i]=0;
    }
    dp[0][0]=1;

    for (int i=1;i<=a;i++)
    {
        for (int j=1;j<=a;j++)
        {
            dp[i][j]=(dp[i-1][j-1]+dp[i-1][j])%mod;
        }
    }
}

int ncr_lucas (int n, int r)
{
    if ((r==0)||(r==n))
    {
        return 1;
    }
    else
    {
        int a=n%mod;
        int b=r%mod;
        
        return (ncr_lucas(n/mod,r/mod)*dp[a][b])%mod;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(10);

    int tt;
    cin >> tt;
    generate_dp(mod);
    for (int yy=0;yy<=tt-1;yy++)
    {
        int n,r;
        cin >> n >> r;
        cout << ncr_lucas(n,r) << endl;
    }

    return 0;
}