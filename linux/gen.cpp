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

ll int rand(ll int a,ll int b) {
    return a + rand() % (b - a + 1);
}   


int main(int argc, char* argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    srand(atoi(argv[1])); // atoi(s) converts an array of chars to int
    int TESTS=rand(1,1);
//  cin>>TESTS;
    while(TESTS--)
    {
        ll int x=rand(0,hell-1);
        ll int k=0;
        ll int m=rand(1,200);
        ll int n=rand(1,1e9)*rand(1,1e9);
        cout<<x<<" "<<k<<" "<<m<<" "<<n<<endl;
        ll int s1=rand(2,n);
        ll int s2=rand(1,s1);
        cout<<endl;
        // cout<<s1<<" "<<s2<<endl;
        for(ll int i=1;i<=m;i++) cout<<rand(0,hell-1)<<" ";
    }
    return 0;
}