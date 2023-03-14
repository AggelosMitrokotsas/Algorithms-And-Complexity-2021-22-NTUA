#include<iostream>
#include<bits/stdc++.h>
#include <vector>
#include <bits/stdc++.h>
#include <functional>
#include <queue>
using namespace std;

#define MIN -100000001

    int N,Q;
    vector <long> d, s;
    priority_queue<int, vector<int>, greater<int>> q; // my priority queue
    unordered_set<int> visited;
    unordered_set<int>::iterator it;
    void mySearch(int c[], int min_d) {
         while(!q.empty()) {
        int head = q.top();
        q.pop();
        if(c[head%min_d] == head) visited.insert(head);
        for(it = visited.begin(); it != visited.end(); it++) {
            int sum = (*it + head);
            int pivot = sum % min_d;
            if(c[pivot] > (sum) or c[pivot] == MIN) {
                c[pivot] = sum;
                q.push(sum);
            }
        }
    }

    for(int i=0; i<Q; i++) {
        if(c[s[i]%min_d]<= s[i]) cout << "YES\n";
        else cout << "NO\n";
    }

}

int main() {    
    scanf("%d", &N);
    scanf("%d", &Q);
    d.resize(N);
    s.resize(Q);
    int min_d=MIN;

    for(int i=0; i<N; i++) {
        scanf("%ld", &d[i]);
        if(min_d > d[i] or min_d==MIN)
            min_d = d[i];
    }
    int c[min_d];
    for(int i=0; i<Q; i++) {
        scanf("%ld", &s[i]);
        
        if(i<min_d) c[i]=MIN;
    }

    for(int i=0; i<N; i++) {
        int pivot = d[i]%min_d;
        if(c[pivot] > d[i] or c[pivot] == MIN) {
            c[pivot] = d[i];
            visited.insert(d[i]);
            q.push(d[i]);
        }
    }
    mySearch(c, min_d);

    return 0;
}
