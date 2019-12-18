#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main()
{
    ll n,arr[5010];
    cin>>n;
    for(ll i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    ll dp[5010];
    for(ll i=0;i<n;i++)
    {
        dp[i]=1;
    }
        for(ll i=0;i<n-1;i++)
        {
            for(ll j=i+1;j<n;j++)
            {
                if(abs(arr[i])<abs(arr[j]) && (arr[i]^arr[j])<0)
                {
                    dp[j]=max(dp[j],dp[i]+1);
                }
            }
        }
        ll ans=0;
        for(ll i=0;i<n;i++)
        {
            ans=max(ans,dp[i]);
        }
        cout<<ans<<'\n';
        return 0;
    }
