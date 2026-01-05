#include <bits/stdc++.h>
#define Will_of_D ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
#define yes cout << "Yes" << '\n';
#define no cout << "No" << '\n';
#define F first
#define S second
using namespace std;

const int N = 1e6 + 10;
vector<int> g[N];
int vis[N] ;

void solve(int test){
    
    int n , r , m; // n = number of city , r = number of roads , m = number of soldiers
    cin >> n >> r >> m;

    //clearing the graph and visited array
    for(int i = 0; i <= n; i++){
        vis[i] = 0;
        g[i].clear();
    } 

    for(int i = 1; i <= r; i++){
        int x , y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    vector<pair<int , int >> v;
    for(int i = 1; i <= m; i++){
        int x , y;
        cin >> x >> y;
        v.push_back({x , y});
    }

    for(int i = 0; i < m; i++){
        int x = v[i].F;
        int y = v[i].S;
        queue<pair<int , int>> q; // pair a prothom ta hoche node , r porer ta holo etar level , initial level 0 , karon 0 strenght a ekta city
        set <int> s; // visited array ++ kore dile WA ashbe for some cases , thats why kon kon node visit hoche eita set a push korte hobe
      
        if(vis[x]){
            no // agei jodi visited thake tahole bad
            return;
        }else {
            q.push({x , 0});
            s.insert(x);
        }

        while(!q.empty()){
            int a = q.front().F;
            int b = q.front().S;
            q.pop();
            if(b == y)continue; // level cover hoye gele r niche jabo na

            for(auto val : g[a]){
                if(val != a){
                    s.insert(val);
                    q.push({val , b + 1});
                }
            }
        }

        for(auto xx : s){
            if(vis[xx]){
                no
                return;
            }else vis[xx] =  1;
        }
        s.clear();
    }
    // konota visit chara ache kina check
    for(int i = 1; i <= n; i++){
        if(vis[i] == 0){
            no
            return;
        }
    }
    yes
}

int main()
{
    Will_of_D
    int test = 1;
    cin >> test;
    for(int i = 1; i <= test; i++)
        solve(i);
}
//https://www.spoj.com/problems/AKBAR/
