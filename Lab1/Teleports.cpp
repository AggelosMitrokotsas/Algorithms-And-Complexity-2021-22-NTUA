#include <iostream>
#include <stdio.h>
#include <bits/stdc++.h>
#include <fstream>
#define MAXN 1000001
using namespace std;


int c[MAXN], parents[MAXN], ranks[MAXN];


void fastscan(int &number)
{
    //variable to indicate sign of input number
    bool negative = false;
    register int c;
 
    number = 0;
 
    // extract current character from buffer
    c = getchar();
    if (c=='-')
    {
        // number is negative
        negative = true;
 
        // extract the next character from the buffer
        c = getchar();
    }
 
    // Keep on extracting characters if they are integers
    // i.e ASCII Value lies from '0'(48) to '9' (57)
    for (; (c>47 && c<58); c=getchar())
        number = number *10 + c - 48;
 
    // if scanned input has a negative sign, negate the
    // value of the input number
    if (negative)
        number *= -1;
}

struct WeightedPermutation{ // δεν εχει σημασια ποια θα ειναι τα from και ποια τα to αφου εχουμε undirected graph
    int from,to,w;
};

WeightedPermutation A[MAXN];

bool sortbyw(WeightedPermutation a, WeightedPermutation b) {
    return (a.w > b.w);
}

int Find(int node) { //find absolute parent
    if(parents[node] == -1){    
        return node;    
    }    
    int x = Find(parents[node]);    
    parents[node] = x;
    return x; 
    // vector<int> V;
    // while(parents[a]>0) { // an einai -1 8a deixnei ston eayto tou are einai absolute parent
    //     V.push_back(a);
    //     a=parents[a];
    // }
    // for(int i=0; i<V.size(); i++) {
    //     parents[V[i]] = a;
    // } // βαζω ως πατερα ολων των κομβων που βρηκα να ειναι προγονοι του a τον τελικο absolute parent // κανει και path compression
    // return a;
}

int myUnion(WeightedPermutation a){
    int start=a.from;
    int destination=a.to;
    int weight=a.w; // χρειαζεται να κανω αναθεση γιατι παιρνω ολο το item, για να μη μου αλλαξει τα στοιχεια του permutation
    start = Find(start);
    destination = Find(destination);

    if(start==destination) return 1000000002; //max weight 10^9

    if(ranks[start] > ranks[destination]) {
        parents[destination] = start;
        ranks[start] += ranks[destination]; // δεν χρειαζεται να ενημερωσω το rank των παιδιων γιατι στις συναρτησεις μου ελεγχω μονο τους γονεις
    }
    else{
        parents[start] = destination;
        ranks[destination] += ranks[start];
    }
    return weight;
}

int check(int N,int counter) {
   while((counter<N) && (Find(counter+1) == Find(c[counter]))){
       counter++;
   }
   // for(int i=0; i<size; i++) {  
     //   if(Find(i+1,parents) != Find(c[i],parents)) return false;  
    //} 
    return counter;
}


int main() {
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    int N, M;
     fastscan(N);
     fastscan(M);
    //ifstream infile(argv[1]);
    //infile >> N;
    //infile >> M;
    //scanf("%d", &N);
    //scanf("%d", &M);
    // cin >> N >> M;
    //N = readLong();
    //M = readLong();
    // c = (int*) malloc(N * sizeof(int));
    // parents = (int*) malloc((N+1) * sizeof(int));
    //ranks = (int*) malloc((N+1) * sizeof(int)); // οι rank και parent εχουν Ν κελια και ξεκινανε απο το 1, αρα βαζω ενα εξτρα κελι για να μη βγαζει segfault. Μπορουσα απλα να βαζω παντα -1 στα indexes των πινακων
    //int c[N];
    //int parents[N+1];
    //int rank[N+1]; 
    //WeightedPermutation A[M]; // skefthka na kanw 2*M gia na phgainw apo x se y kai apo y se x alla den xreiazetai epeidh einai undirected graph
   
    for(int i = 0; i<N; i++) {
        fastscan(c[i]);
        //infile >> c[i];
       // scanf("%d", &c[i]); //universes
        //cin >> c[i];
    } 

    for(int i=0; i<M; i++) {//node i στο A[i-1]
        fastscan(A[i].from);
        fastscan(A[i].to);
        fastscan(A[i].w);
       // infile >> A[i].from;
        //infile >> A[i].to;
        //infile >> A[i].w;   
        //scanf("%d", &A[i].from);
        //scanf("%d", &A[i].to);
        //scanf("%d", &A[i].w);
        //cin >> A[i].from >> A[i].to >> A[i].w;
    }
    // if (N<100000 && M<100000) 
    if(!is_sorted(A,A+M,sortbyw)){
        sort(A, A+M, sortbyw);
    }  

    for(int i=0; i<N+1; i++) {
        parents[i] = -1;
    }
    for(int i=0; i<N+1; i++){
        ranks[i] = 1;
    }
    int x = 1000000001;
    int counter =0;
    for(int i=0; i<M; i++){
        x = min(x, myUnion(A[i]));
        counter = check(N,counter); 
        if(counter == N) break;
    }

    printf("%d\n", x);
   // cout << x << endl;
 
    return 0;
    
}