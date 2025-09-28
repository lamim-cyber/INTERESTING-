#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define Code_Delete_Koren_Shomossha_hobe ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);
#define in(j,n,v) for(int i=j; i<n; i++) cin>> v[i];
#define out(j,n,v) for(int i=j; i<n; i++) cout<< v[i]<<" ";
#define mp(x, y) make_pair(x, y)
#define yes cout << "YES" << '\n';
#define no cout << "NO" << '\n';
#define test int t; cin >> t; while (t--)
#define srt(v) sort(v.begin(), v.end());
#define rsrt(v) sort(v.rbegin(), v.rend());
#define gcd __gcd
#define rvs(v) reverse(v.begin(), v.end());
#define lcm(a, b) ((a) * (b) / gcd(a, b))
#define F first
#define S second
#define ld long double
#define nl '\n'
#define iint 1000000000
#define mod 1000000007
#define mod2 998244353
using namespace std;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count()); // generating random numbers 
const int N=2e5+100;
int a[N], rv[N]; // rv holds the reverse mapping 
map< int , int > m; // array compression mapping 
vector< int > v[N];

int binary_cnt(int n, int l, int r)
{
    int lo=0, hi=v[n].size()-1;

    int res1=-1, res2=-1;

    while(lo<=hi)
    {
        int mid= (lo+hi)/2;

        if(v[n][mid]>= l)
        {
            res1= mid;
            hi=mid-1;
        }else{
            lo= mid+1;
        }
    }

    lo=0, hi=v[n].size()-1;

    while(lo<=hi)
    {
        int mid= (lo+hi)/2;

        if(v[n][mid]<=r)
        {
            res2= mid;
            lo=mid+1;
        }else
        {
            hi=mid-1;
        }
    }

    if(res1!=-1 && res2!=-1)
    {
        return res2-res1+1;
    }else
        return 0;

}

void solve()
{
    int n, q, l, r;
    cin>> n>> q;
    for(int i=1; i<=n; i++)cin>>a[i];

    for(int i=1; i<=n; i++)
    {
        if(!m.count(a[i]))
        {
            m[a[i]]=m.size(); // array compression
            rv[m[a[i]]]=a[i]; // reverse array compression 
        }

        a[i]=m[a[i]]; 

    }

    for(int i=1; i<=n; i++)
    {
       v[a[i]].pb(i); // hold the positions like adj lists 
    }

    while(q--)
    {
        cin>> l>> r;
        int seg= (r-l+1)/3;
        vector< int > b;
        for(int i=1; i<=60; i++)
        {
            int x= rng() % (r-l+1) + l; // choose a random number from l to r
            int y= a[x];

            if(binary_cnt(y, l, r)> seg) // count how many times it occurs in the segment from [ l, r]
            {
               if(b.size()==0 || b.front()!=rv[y] && b.back()!=rv[y])
                    b.pb(rv[y]);
            }
        }

        if(b.size()==0)
        {
            cout<< -1<< endl;
            continue;
        }

        srt(b);

        for(int i=0; i<b.size(); i++)
            cout<< b[i]<< " ";

        cout<< endl;
    }

    m.clear(); // clearing everything 
    for(int i=0; i<=n; i++)
    {
        v[i].clear();
    }

}

int main()
{
    Code_Delete_Koren_Shomossha_hobe

    test
    solve();

}
// counted how many times a number occured in an array in a range by array compression , reverse mapping , counting by binary search ... SHERRRAAA
//https://codeforces.com/contest/2149/problem/G
