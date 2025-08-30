#include <bits/stdc++.h>
#define ll long long
#define hi ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

const int N= 1e6+9, mod= 1e9+7;

int fac[N], inv[N], facinv[N];

void pre_calculate()// pre calculate the factorial and the invrse factorial
{
    fac[0] = 1;
    for (int i = 1; i < N; i++) fac[i] = 1LL * i * fac[i - 1] % mod;
    inv[1] = 1;
    for (int i = 2; i < N; i++ )
    {
        inv[i] = (-(1LL * mod / i) * inv[mod % i] ) % mod;
        inv[i] = (inv[i] + mod) % mod;
    }
    facinv[0] = 1;
    for (int i = 1; i < N; i++) facinv[i] = 1LL * inv[i] * facinv[i - 1] % mod;
}

int nCr( int n, int k)// just simple formula return
{
    if (n < k || n < 0 || k < 0) return 0;
    return 1LL * fac[n] * facinv[n - k] % mod * facinv[k] % mod;
}


void solve()
{
   
   pre_calculate();

   int a, b, n;
   cin>> a>> b>> n;
   ll ans=0;

   for(int i=0; i<=n; i++)
   {
      int sum= i*a + (n-i)*b;

      int x=1;

      while(sum>0)
      {
         if(sum%10 != a && sum%10 !=b)
         {
            x=0;
            break;
         }

         sum/=10;
      }

      if(x)
      {
         ans+= nCr(n,i);
         ans%=mod;
      }
   }

   cout<< ans<< endl;
}

int main()
{
    hi

   // test
        solve();
    
}
//https://codeforces.com/contest/300/problem/C
