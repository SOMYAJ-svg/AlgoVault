#include "graph.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <fstream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <chrono>
using namespace std;
using pii = pair<int,int>;
using ms = chrono::duration<double, milli>;

void BFS(const vector<vector<pair<int,int>>>& adj, int start) {
    int n = adj.size();
    vector<bool> visited(n, false);
    queue<int> q;
    q.push(start);
    visited[start] = true;

    cout << "BFS Order: ";
    while(!q.empty()) {
        int u = q.front(); q.pop();
        cout << u << " ";
        for(auto &p : adj[u]) {
            int v = p.first;
            if(!visited[v]) {
                visited[v] = true;
                q.push(v);
            }
        }
    }
    cout << endl;
}

// DFS
void DFSUtil(const vector<vector<pair<int,int>>>& adj, int u, vector<bool>& visited) {
    visited[u] = true;
    cout << u << " ";
    for(auto &p : adj[u]) {
        int v = p.first;
        if(!visited[v]) DFSUtil(adj, v, visited);
    }
}

void DFS(const vector<vector<pair<int,int>>>& adj, int start) {
    int n = adj.size();
    vector<bool> visited(n, false);
    cout << "DFS Order: ";
    DFSUtil(adj, start, visited);
    cout << endl;
}

// Dijkstra
void Dijkstra(const vector<vector<pair<int,int>>>& adj, int src) {
    int n = adj.size();
    vector<int> dist(n, numeric_limits<int>::max());
    dist[src] = 0;

    using pii = pair<int,int>;
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, src});

    while(!pq.empty()) {
        int d = pq.top().first;
        int u = pq.top().second;
        pq.pop();
        if(d > dist[u]) continue;

        for(auto &p : adj[u]) {
            int v = p.first;
            int w = p.second;
            if(dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }

    cout << "Shortest distances from vertex " << src << ":\n";
    for(int i=0;i<n;i++) {
        cout << i << ": ";
        if(dist[i]==numeric_limits<int>::max()) cout << "INF";
        else cout << dist[i];
        cout << endl;
    }
}

// Graph Menu
void graphMenu() {
    int n, m;
    cout << "Enter number of vertices: ";
    cin >> n;
    cout << "Enter number of edges: ";
    cin >> m;

    vector<vector<pair<int,int>>> adj(n);

    cout << "Now enter each edge as: u v [weight]. For unweighted put weight=1.\n";
    for(int i=0;i<m;i++) {
        int u, v, w=1;
        cin >> u >> v;
        // Safety check
        if(u<0 || u>=n || v<0 || v>=n) {
            cout << "❌ Invalid edge! Skipping.\n";
            continue;
        }
        if(!(cin >> w)) w = 1; // optional weight
        adj[u].push_back({v,w});
        // adj[v].push_back({u,w}); // uncomment if undirected
    }

    while(true) {
        cout << "\nChoose operation:\n1. BFS\n2. DFS\n3. Dijkstra\n4. Exit\nChoice: ";
        int choice;
        cin >> choice;
        if(choice == 4) break;

        int src;
        cout << "Enter source vertex (0-based): ";
        cin >> src;
        if(src<0 || src>=n) {
            cout << "❌ Invalid source vertex!\n";
            continue;
        }

        if(choice==1) BFS(adj, src);
        else if(choice==2) DFS(adj, src);
        else if(choice==3) Dijkstra(adj, src);
        else cout << "❌ Invalid choice!\n";
    }
}