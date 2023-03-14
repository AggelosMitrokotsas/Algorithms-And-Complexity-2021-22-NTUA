#include <iostream>
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    for(int t=0; t<34; t++) {
        auto start = high_resolution_clock::now();
    freopen("input.txt", "r",stdin);
    string s = "input";
    string s2 = "output"; 
    s += std::to_string(t) + ".txt";
    s2 += std::to_string(t) + ".txt";
    FILE *f = freopen(s.c_str() , "r", stdin);
      
      long N, M;
     cin >> N >> M;
     int a,b,c;
     for(int i=0; i<N; i++) {
         cin >> a;
     }
     for(int i =0; i<M; i++){
         cin >> a >> b >> c;
     }
auto stop = high_resolution_clock::now();
auto duration = duration_cast<microseconds>(stop - start);
cout << duration.count() << " " << t <<endl;
    }
    return 0;

}