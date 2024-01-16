#include <bits/stdc++.h>
using namespace std;

vector<int> shortestPath( vector<pair<int,int>> edges, int s , int t){
	
    // Create Adjacency List
	unordered_map<int, list<int>> adj;

	for(int i=0;i<edges.size();i++){
		int u = edges[i].first;
		int v = edges[i].second;

		adj[u].push_back(v);
		adj[v].push_back(u);
	}


    // Do bfs and store nearest parent of each node
	unordered_map<int, bool>visited;
	unordered_map<int,int>parent;

	queue<int>q;
	q.push(s);
	visited[s] = true;
	parent[s] = -1;

	while(!q.empty()){
		int front = q.front();
		q.pop();

		for(auto it: adj[front]){
			if(!visited[it]){
				visited[it] = true;
				parent[it] = front;
				q.push(it);
			}
		}
	}


    // find the shortest path by bcktracking
	vector<int>shortestpath;
	int currentNode = t;
	shortestpath.push_back(currentNode);

	while(currentNode != s){
		currentNode = parent[currentNode];
		shortestpath.push_back(currentNode);
	}

	reverse(shortestpath.begin(), shortestpath.end());
	return shortestpath;
}


int main(){
    vector<pair<int,int>> edges = {{1, 2},{1, 3},{1, 4},{2, 5},{3, 8},{4, 6},{6, 7},{7, 8}};
    vector<int>shortestpath  = shortestPath(edges, 1, 8);

    cout << "Shortest Path of Node-8 from Node-1 is : " ;
    for(auto it:shortestpath){
        cout << it << " ";
    }cout << endl;

}