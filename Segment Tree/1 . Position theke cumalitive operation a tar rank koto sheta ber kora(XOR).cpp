#include <bits/stdc++.h>
#define ll long long
#define Will_of_D ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
#define yes cout << "Yes" << '\n';
#define no cout << "No" << '\n';
#define all(v) v.begin(),v.end()
#define F first
#define S second
#define nl '\n'
#define gap ' '
using namespace std;

const int N = 3e5 + 10;
ll a[N] , nn , q , n;
ll t[4 * N];

void build(int node , int b , int e){
    if(b == e){
        t[node] = a[b];
        return;
    }
    int left = node * 2;
    int right = node * 2 + 1;
    int mid = (b + e) / 2;
    build(left , b , mid);
    build(right , mid + 1 , e);
    t[node] = t[left] ^ t[right];
}

ll query(int node , int b , int e , int i , int j){
    if(b > j or i > e){
        return 0;
    }

    if(b >= i and e <= j){
        return t[node];
    }

    int left = node * 2;
    int right = node * 2 + 1;
    int mid = (b + e) / 2;
    return query(left , b , mid , i , j) ^ query(right , mid + 1 , e , i , j);
}

void update(int node , int b , int e , int pos , int val){
    if(b == e and b == pos){
        t[node] = val;
        return;
    }

    if(pos < b or pos > e){
        return;
    }

    int left = node * 2;
    int right = node * 2 + 1;
    int mid = (b + e) / 2;
    update(left , b , mid , pos , val);
    update(right , mid + 1 , e , pos , val);
    t[node] = t[left] ^ t[right];
}

void solve(int test) {
    cin >> nn >> q;
    int n =  1 << nn;
    for(int i = 1; i <= n; i++)cin >> a[i];
    build(1 , 1 , n);

    for(int i = 1; i <= q; i++){
        int b , c;
        cin >> b >> c;
        update(1 , 1 , n , b , c);

        int l = 1 , r = n;
        int ans = 0;
        while(l < r){
            int mid = (l + r) / 2;

            if(b <= mid){
                ll x = query(1 , 1 , n , l , mid);
                ll y = query(1 , 1 , n , mid + 1 , r);

                if(y > x){
                    ans += (r - mid);
                }
                r = mid;
            }else {
                ll x = query(1 , 1 , n , l , mid);
                ll y = query(1 , 1 , n , mid + 1 , r);

                if(y <= x){
                    ans += (mid - l + 1);
                }
                l = mid + 1;
            }
        }
        cout << ans << nl;
        update(1 , 1 , n , b , a[b]);
    }    
}

int main()
{
    Will_of_D
    int test = 1;
    cin >> test;
    for(int i = 1; i <= test; i++)
        solve(i);
}
//https://codeforces.com/contest/2185/problem/F
