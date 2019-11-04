/*
 _     _                             
| |__ | |__   __ _  __ _ _   _  __ _ 
| '_ \| '_ \ / _` |/ _` | | | |/ _` |
| |_) | | | | (_| | (_| | |_| | (_| |
|_.__/|_| |_|\__,_|\__, |\__, |\__,_|
                   |___/ |___/       
*/
#include<bits/stdc++.h>

#define ll          long long
#define pb          push_back
#define ppb         pop_back
#define endl        '\n'
#define mii         map<ll int,ll int>
#define msi         map<string,ll int>
#define mis         map<ll int, string>
#define mpi         map<pair<ll int,ll int>,ll int>
#define pii         pair<ll int,ll int>
#define vi          vector<ll int>
#define vs          vector<string>
#define all(a)      (a).begin(),(a).end()
#define F           first
#define S           second
#define sz(x)       (ll int)x.size()
#define hell        1000000007
#define lbnd        lower_bound
#define ubnd        upper_bound
#define bs          binary_search
#define mp          make_pair
#define what_is(x)  cerr << #x << " is " << x << endl;
using namespace std;

#define N  100005

ll int n,k;

ll int c[3*N];

bool check(ll int mid)
{
    if(!mid) return true;
    ll int num=0;
    ll int prev=0;
    for(ll int i=1;i<=n;i++)
    {
        ll int sm=prev+c[i];
        num+=sm/mid;
        if(sm>=mid) prev=sm%mid;
        else prev=c[i];
    }
    return num>=k;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int TESTS=1;
    cin>>TESTS;
    while(TESTS--)
    {
        cin>>n>>k;
        ll int sm=0;
        for(ll int i=1;i<=n;i++) {cin>>c[i];sm+=c[i];}
        ll int low=0,high=sm/k;
        ll int ans=-1;
        while(low<=high)
        {
            ll int mid=(low+high)/2;
            if(check(mid))
            {
                low=mid+1;
                ans=mid;
            }
            else
            {
                high=mid-1;
            }
        }
        cout<<k*ans<<endl;
    }
    return 0;
}