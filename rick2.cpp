#include <iostream>
#include<bits/stdc++.h>
#include <algorithm>
using namespace std;

#define MAXN 100000000;

void mysort(int arr[][3], int len){
    int buff;
    for(int i=0; i<len; i++){
        for(int j=0; j<len-1-i; j++){
            if(arr[j][2]> arr[j+1][2]){
                for(int k=0; k<3; k++){
                    buff= arr[j+1][k];
                    arr[j+1][k]= arr[j][k];
                    arr[j][k]= buff;
                }
            }
        }
    }  
}
int parent[MAXN], rank[MAXN];

void make_set(int v) {
    parent[v] = v;
    rank[v] = 0;
}

int find_set(int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}

void union_sets(int a, int b, int w) {
    a = find_set(a);
    b = find_set(b);
    int width= w;
    if (a != b) {
        if (rank[a] < rank[b])
            swap(a, b);
        parent[b] = a;
        if (rank[a] == rank[b])
            rank[a]++;
    }
    return width;
}

bool check(int c[], int size) {  
    for(int i=0; i<size; i++) {  
        if(find_set(i+1) != find_set(c[i])) return false;  
    }  
    return true;  
}

int main(int argc, char** argv){
    int N= atoi(argv[1]), M= atoi(argv[2]);
    int positions[N];
    for(int i=0; i<N; i++)
        cin>> positions[i]; 
    
    int a[M], b[M], w[M];
    int arr[M][3];
    for(int i=0; i<M; i++){
        cin>> a[i] >> b[i] >> w[i];
        arr[i][0]= a[i];
        arr[i][1]= b[i];
        arr[i][2]= w[i];
    }
    mysort(arr, M);
    int result=100000000;

    for(int i=0; i<M; i++){
        result= min(union_sets(arr[i][0],arr[i][1], arr[i][2]), result);
        check(positions, i);
    }
    cout<< result << "\n";

    return 0;
}