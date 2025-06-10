#include <bits/stdc++.h>
#define ll long long
#define hi ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define pb push_back
#define in(j,n,v) for(int i=j; i<n; i++) cin>> v[i];
#define out(j,n,v) for(int i=j; i<n; i++) cout<< v[i]<<" ";
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
#define mod 1000000007
#define mod2 998244353
using namespace std;
int main()
{
   int n;
   cin>> n;
   vector< int > v(n);
   for(int i=0; i<n; i++) cin>> v[i];
   srt(v);
   ll sum1=0, sum2=0;
   for(int i=0; i<n; i++)
   {
       sum1+= (v[i]*v[i]);
       sum2+=v[i];
   }
   ll ans= n*sum1 - (sum2*sum2);
   cout<< ans<< endl;
}
