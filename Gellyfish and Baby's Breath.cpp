#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define in(j,n,v) for(int i=j; i<n; i++) cin>> v[i];
#define out(j,n,v) for(int i=j; i<n; i++) cout<< v[i]<<" ";
#define mp(x, y) make_pair(x, y)
#define test int t; cin >> t; while (t--)
#define F first
#define S second
#define nl '\n'
#define mod2 998244353
//i learned about position array in this problem
//if i should calculate larger value then calculate it before mod, 
using namespace std;
//the funtion to efficiently calculate pow(2,x)
ll modul(ll exp) {
    ll result = 1;
    ll base = 2;
    while (exp > 0) {
        if (exp % 2 == 1)
        result = (result * base) % mod2;
 
        base = (base * base) % mod2;
        exp /= 2;
    }
    return result%mod2;
}
int main()
{
   test
   {
       ll n;
       cin>> n;
       vector< ll > a(n), b(n);
       in(0,n,a);
       in(0,n,b);
       //position array
       vector< ll > posa(n), posb(n);
       for(int i=0; i<n; i++)
       {
         posa[a[i]]=i;
         posb[b[i]]=i;
       }
       ll p1=a[0], p2=b[0];
       vector< ll> v;
    // now we check the larger pair
       for(int i=0; i<n; i++)
       {
            p1=max(p1, a[i]);
            p2=max(p2, b[i]);
 
            pair< ll,ll> x={p1, b[i-posa[p1]]};
            pair< ll,ll> y={p2, a[i-posb[p2]]};
            pair< ll,ll> z=max(x,y);
 
            ll o=(modul(z.F)+modul(z.S))%mod2;
 
            v.pb(o);
       }
       out(0,n,v);
       cout<< nl;
   }
}
