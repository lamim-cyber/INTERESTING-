#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp(x, y) make_pair(x, y)
#define yes cout << "YES" << '\n';
#define no cout << "NO" << '\n';
#define test int t; cin >> t; while (t--)
#define srt(v) sort(v.begin(), v.end());
#define rsrt(v) sort(v.rbegin(), v.rend());
#define rvs(v) reverse(v.begin(), v.end());
#define F first
#define S second
#define ld long double
#define nl '\n'
#define iint 1000000000
using namespace std;

bool cmp(pair< ll, ll > a, pair< ll, ll > b)
{
    if(a.F == b.F)
        return a.S>b.S;
}

ll gcd(ll a, ll b) {
    while (b != 0) {
        ll temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

void seive (ll n)
{
    vector< ll > v(n+1);
    for(int i=0; i<=n; i++) v[i]=0;
    for(int i=2; i<=n; i++)
    {
        if(v[i])continue;

        for(int j= 2*i; j<=n; j+=i)
        {
            v[j]=1;
        }
    }

    vector< ll > prime;

    for(int i=2; i<=n; i++)
    {
        if(v[i]==0)
        {
            prime.pb(i);
        }
    }

    for(int i=0; i<prime.size(); i++)cout<<prime[i]<< " ";
}

void factors(ll a)
{
    vector< ll > v;
    for(int i=2 ; i*i <= a; i++)
    {
        while(a%i==0)
        {
            v.pb(i);
            a/=i;
        }
    }

    if(a>1) v.pb(a);

    for(int i=0; i<v.size(); i++)
        cout<< v[i]<< " ";
}

int main()
{
   vector< pair< int , int >  > v;
   int n;
   cin>> n;
   for(int i=0; i<n; i++)
   {
       int x, y;
       cin>> x>> y;
       v.pb({x,y});
   }

   sort(v.begin(), v.end(), cmp);
   rvs(v);

   for(int i=0; i<n; i++)
   {
       cout<< v[i].F<< " "<< v[i].S<< endl;
   }

}


