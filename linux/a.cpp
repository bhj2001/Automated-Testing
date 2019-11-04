/*
 _     _                             
| |__ | |__   __ _  __ _ _   _  __ _ 
| '_ \| '_ \ / _` |/ _` | | | |/ _` |
| |_) | | | | (_| | (_| | |_| | (_| |
|_.__/|_| |_|\__,_|\__, |\__, |\__,_|
                   |___/ |___/       
*/
#include<bits/stdc++.h>

#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse2")

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
 
ll int x,n;

ll int k,m;

ll int matrix[62][201][201];

vi s;

ll int a[201];

ll int fuck;

void init()
{
    memset(matrix,0,sizeof(matrix));
    for(int i=1;i<m;i++) matrix[0][1][i]=a[i];
    matrix[0][1][m]=(a[m]+1)%hell;
    for(int i=2;i<=m;i++) matrix[0][i][i-1]=1;
    for(int num=1;num<62;num++)
    {
        for(int i=1;i<=m;i++)
        {
            for(int j=1;j<=m;j++)
            {
                fuck=0;
                for(int k=1;k<=m;k++)
                {
                    fuck=(fuck+(1ll*matrix[num-1][i][k]*matrix[num-1][k][j])%hell);
                }
                matrix[num][i][j]=fuck%hell;
            }
        }
    }
} 

ll int f[201];

ll int newf[201];

void move(ll int value)
{
    for(int it=0;it<62;it++)
    {
        if((value>>it)&1ll)
        {
            memset(newf,0,sizeof(newf));
            for(int i=1;i<=m;i++)
            {
                fuck=0;
                for(int j=1;j<=m;j++)
                {
                    fuck=(fuck+(1ll*matrix[it][m-i+1][j]*f[m-j+1])%hell);
                }
                newf[i]=fuck%hell;
            }
            for(int i=1;i<=m;i++) f[i]=newf[i];
        }
    }
}

// void print(ll int idx)
// {
//  cout<<endl;
//  for(ll int i=1;i<=m;i++)
//  {
//      for(ll int j=1;j<=m;j++)
//      {
//          cout<<matrix[i][j][idx]<<" ";
//      }
//      cout<<endl;
//  }
//  cout<<endl;
// }

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int TESTS=1;
    // cin>>TESTS;
    while(TESTS--)
    {
        cin>>x>>k>>m>>n;
        s.resize(k);
        for(int i=0;i<k;i++) cin>>s[i];
        for(int i=1;i<=m;i++) cin>>a[i];
        init();
        f[0]=x;
        for(int i=1;i<=m;i++)
        {
            ll int tmp=0;
            for(int j=1;j<=i;j++)
            {
                tmp=(tmp+(1ll*f[i-j]*a[j])%hell)%hell;
            }
            f[i]=tmp;
            bool fnd=0;
            for(auto it:s) if(it==i) fnd=1;
            if(fnd) f[i]=0;
        }
        // for(ll int i=0;i<=m;i++) cout<<f[i]<<" ";cout<<endl;
        mii ma;
        for(auto i:s)
        {
            if(i<=m)
            {   
                f[i]=0;
            }
            else
            {
                ma[i]=1;
            }
        }
        s.clear();
        for(auto i:ma) s.pb(i.F);
        k=s.size();
        if(n<=m)
        {
            cout<<f[n]<<endl;
            return 0;
        }
        ll int cur=m;
        for(auto i:s)
        {
            move(i-cur);
            f[m]=0;
            cur=i;
        }
        move(n-cur);
        cout<<f[m]<<endl;
    }
    // cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
    return 0;
}