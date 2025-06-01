#include <bits/stdc++.h>
int main()
{
   int n, q;
   string s;
   cin>> n>> q>> s;
   int c=0;// the changing idx count 
   while(q--)
   {
       int t, x;
       cin>> t>> x;
       if(t==2)
       {
           cout<< s[(x-c-1+n)%n]<< endl;// simulate the rotation and find the idx
       }
       if(t==1)
       {
          c= (c+x)%n;
       }
   }
}
