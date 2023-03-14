#include <bits/stdc++.h>  
#include<iostream>  
#include<vector>  
using namespace std;  
// DSU data structure  
//  path compression + rank by union  
  
void addEdge(vector<pair<int,int> > v[],int x,int y,int z){  
    v[x].push_back({y,z});  
    v[y].push_back({x,z});  
}  
  
void addEdges(vector<int> v[],int x,int y){  
    v[x].push_back(y);  
    v[y].push_back(x);  
}  
vector<int> global_path;  
  
void printPath(vector<int> stack){  
    int i;  
    for (i = 0; i < (int)stack.size() - 1; i++) {  
        //cout << stack[i] << " -> ";  
        global_path.push_back(stack[i]);  
    }  
    //cout << stack[i] << endl;  
    global_path.push_back(stack[i]);  
}  
   
// An utility function to do  
// DFS of graph recursively  
// from a given vertex x.  
void DFS(vector<int> v[],bool vis[],int x,int y,vector<int> stack)  
{  
    stack.push_back(x);  
    if (x == y) {  
        // print the path and return on  
        // reaching the destination node  
        printPath(stack);  
        return;  
    }  
    vis[x] = true;  
   
    // if backtracking is taking place  
    if (!v[x].empty()) {  
        for (int j = 0; j < v[x].size(); j++) {  
            // if the node is not visited  
            if (vis[v[x][j]] == false)  
                DFS(v, vis, v[x][j], y, stack);  
        }  
    }  
   
    stack.pop_back();  
}  
   
// A utility function to initialise  
// visited for the node and call  
// DFS function for a given vertex x.  
void DFSCall(int x,int y,vector<int> v[],int n,vector<int> stack)  
{  
    // visited array  
    bool vis[n + 1];  
   
    memset(vis, false, sizeof(vis));  
   
    // DFS function call  
    DFS(v, vis, x, y, stack);  
}  
  
class DSU {  
    int* parent;  
    int* rank;  
   
public:  
    DSU(int n)  
    {  
        parent = new int[n];  
        rank = new int[n];  
   
        for (int i = 0; i < n; i++) {  
            parent[i] = -1;  
            rank[i] = 1;  
        }  
    }  
   
    // Find function  
    int find(int i)  
    {  
        if (parent[i] == -1)  
            return i;  
   
        return parent[i] = find(parent[i]);  
    }  
    // union function  
    void unite(int x, int y)  
    {  
        int s1 = find(x);  
        int s2 = find(y);  
   
        if (s1 != s2) {  
            if (rank[s1] < rank[s2]) {  
                parent[s1] = s2;  
                rank[s2] += rank[s1];  
            }  
            else {  
                parent[s2] = s1;  
                rank[s1] += rank[s2];  
            }  
        }  
    }  
};  
   
vector<vector<int> > akmes_telikes;  
  
int metavasi_apo_pros(int thesi,vector<pair<int,int> > v[],vector<int> path){  
    /* 
    if(starting == ending){return 0;} 
    if(akmes_telikes[starting-1].size() == 0){return 0;} 
    if(akmes_telikes[starting-1].size() == 1){return metavasi_apo_pros(akmes_telikes[starting-1][0].first,ending,akmes_telikes);} 
    int megisto; 
    for(int j = 0; j < akmes_telikes[starting-1].size(); j++){ 
         
        if(akmes_telikes[starting-1][j].first == ending){ 
            //cout << "Edw eisai yeap : " << endl; 
            return akmes_telikes[starting-1][j].second; 
        } 
        else{ 
            return max(akmes_telikes[starting-1][j].second,metavasi_apo_pros(akmes_telikes[starting-1][j].first,ending,akmes_telikes));//,metavasi_apo_pros(starting,akmes_telikes[ending-1][j],akmes_telikes))); 
        } 
        //if(akmes_telikes[0][0] > starting){break;} 
    } 
    //cout << "Man anazytise allou" << endl; 
    return -1; 
    */  
    int u;  
    if(thesi == path.size()-1){return -1;}  
    for(int k = 0; k < v[path[thesi]].size(); k++){  
        if(v[path[thesi]][k].first == path[thesi+1]){  
            u = k;  
            break;  
        }  
    }  
    //cout << "destination is " << katanomi[path[thesi]-1][u].first << endl;  
    return(max(v[path[thesi]][u].second,metavasi_apo_pros(thesi+1,v,path)));  
}  
  
bool sortedwith(const vector<int> &a, const vector<int> &b){  
    return (a[2] < b[2]);  
}  
  
class Graph {  
    vector<vector<int> > edgelist;  
    int V;  
   
public:  
    Graph(int V) { this->V = V; }  
   
    void ADDEdge(int x, int y, int w)  
    {  
        edgelist.push_back({ w, x, y });  
    }  
   
    void kruskals_mst(){  
        // 1. Sort all edges  
        sort(edgelist.begin(), edgelist.end());  
   
        // Initialize the DSU  
        DSU s(V);  
        int ans = 0;  
        //cout << "Following are the edges in the "  
        //       "constructed MST"  
        //     << endl;  
        for (auto edge : edgelist) {  
            int w = edge[0];  
            int x = edge[1];  
            int y = edge[2];  
   
            // take that edge in MST if it does form a cycle  
            if (s.find(x) != s.find(y)) {  
                s.unite(x, y);  
                ans += w;  
                //cout << x << " - " << y << " == " << w  
                //     << endl;  
                vector<int> zeygos1;  
                zeygos1 = {x,y,w};  
                akmes_telikes.push_back(zeygos1);  
            }  
        }  
        //cout << "Minimum Cost Spanning Tree: " << ans;  
    }  
};  
int main(){  
    int N,M,kostos;  
    cin >> N >> M;  
    int x,y;  
    Graph g(N);  
    /* 
    for(int i = 0; i < N; i++){ 
        for (int j = 0; j < cost[i].size(); j++){ 
            cout << cost[i][j] << endl; 
        } 
    }*/  
    //cout<<"Enter the vertices for a graph with 6 vetices";  
    for (int i = 0; i < M; i++){  
            //vector<int> endiameso;  
            cin >> x >> y ;  
            cin >> kostos;  
            g.ADDEdge(x,y,kostos);  
    }  
      
    // int n, m;  
    // cin >> n >> m;  
   
    // Graph g(n);  
    // for (int i = 0; i < m; i++)  
    // {  
    //     int x, y, w;  
    //     cin >> x >> y >> w;  
    //     g.addEdge(x, y, w);  
    // }  
  
    g.kruskals_mst();  
    vector<vector<pair<int,int> > > katanemimeno;  
    for(int k = 0; k < N; k++){  
        vector<pair<int,int> > eswteriko;  
        eswteriko.push_back({});  
        katanemimeno.push_back(eswteriko);  
    }  
      
    for(int j = 0; j < akmes_telikes.size(); j++){  
        pair<int,int> zeygos1;  
        zeygos1 = {akmes_telikes[j][1],akmes_telikes[j][2]};  
        katanemimeno[akmes_telikes[j][0]-1].push_back(zeygos1);  
    }  
    //cout << katanemimeno.size() << endl;  
    for(int j = 0; j < katanemimeno.size(); j++){  
        katanemimeno[j].erase(katanemimeno[j].begin());  
    }  
    //OLA TELEIA EDW   
    int Q;  
    int starting,ending;  
    vector<pair<int,int> > v[N+1];  
    vector<int> k[N+1],stack;  
    for(int j = 0; j < akmes_telikes.size(); j++){  
        //vec.erase(vec.begin());  
        addEdge(v,akmes_telikes[j][0],akmes_telikes[j][1],akmes_telikes[j][2]);  
        addEdges(k,akmes_telikes[j][0],akmes_telikes[j][1]);  
    }  
      
    cin >> Q;  
    for(int h = 0; h < Q; h++){  
        //vector<int> path;  
        cin >> starting >> ending;  
        global_path.clear();  
        DFSCall(starting, ending, k, N+1, stack);  
        //for(int i = 0; i < global_path.size(); i++){  
        //    cout << global_path[i] << " ";  
        //}  
        //cout << endl;  
        cout << metavasi_apo_pros(0,v,global_path) << endl;  
    }  
    return 0;    
}  