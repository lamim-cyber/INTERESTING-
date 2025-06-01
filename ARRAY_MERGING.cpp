#include <bits/stdc++.h>
#define ll long long 
using namespace std;
//here i learned how to count and reset...its easy to count in reverse instead of (a[i]==a[i+1])
// you cannot compare two thing different parameter or data type
int main()
{
       int n;
       cin>> n;
       vector< ll > a(n), b(n);
       in(0,n,a);
       in(0,n,b);
       vector< ll > long_a(2*n+1, 0), long_b(2*n+1, 0);//the two must be containg only 2*n numbers at most
        //intializing with zero, so the counting would easy
        ll cnt_a=1, cnt_b=1;
        for(int i=1; i<n; i++)
        {
            if(a[i]==a[i-1])
                cnt_a++;
            else
            {
                long_a[a[i-1]]= max(long_a[a[i-1]], cnt_a);
                cnt_a=1;
            }
            if(b[i]==b[i-1])
                cnt_b++;
            else
            {
                long_b[b[i-1]]= max(long_b[b[i-1]], cnt_b);
                cnt_b=1;
            }
        }
       //if any count remain after the loop finished
        long_b[b[n-1]]= max(long_b[b[n-1]], cnt_b);
        long_a[a[n-1]]= max(long_a[a[n-1]], cnt_a);
 
        ll ans=-1;//ans is initialized with -1 because value can be 0
        for(int i=0; i<=2*n; i++)
        {
            ans=max(ans, long_b[i]+long_a[i]);
        }
 
        cout<< ans<< nl;
}
