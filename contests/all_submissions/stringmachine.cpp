#include <vector>
#include <queue>
#include <utility>

using namespace std;

class Solution {
public:
    pair<int, int> bfs(int start, const vector<vector<int>>& adj) {
        int n = adj.size();
        vector<int> dist(n, -1);
        queue<int> q;
        q.push(start);
        dist[start] = 0;
        
        int farthestNode = start;
        int maxDist = 0;
        
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            
            for (int neighbor : adj[node]) {
                if (dist[neighbor] == -1) {
                    dist[neighbor] = dist[node] + 1;
                    q.push(neighbor);
                    
                    if (dist[neighbor] > maxDist) {
                        maxDist = dist[neighbor];
                        farthestNode = neighbor;
                    }
                }
            }
        }
        
        return {farthestNode, maxDist};
    }
    
    int findDiameter(const vector<vector<int>>& adj) {
        pair<int, int> p1 = bfs(0, adj);
        pair<int, int> p2 = bfs(p1.first, adj);
        return p2.second;
    }
    
    vector<int> getLinkage(int n, vector<vector<int>>& tree1, vector<vector<int>>& tree2) {
        vector<int> result;
        
        for (int i = 0; i < n; ++i) {
            vector<vector<int>> combinedTree(n * 2);
            
            for (int u = 0; u < n; ++u) {
                for (int v : tree1[u]) {
                    combinedTree[u].push_back(v);
                    combinedTree[v].push_back(u);
                }
            }
            
            for (int u = 0; u < n; ++u) {
                for (int v : tree2[u]) {
                    combinedTree[u + n].push_back(v + n);
                    combinedTree[v + n].push_back(u + n);
                }
            }
            
            combinedTree[i].push_back(i + n);
            combinedTree[i + n].push_back(i);
            
            int diameter = findDiameter(combinedTree);
            result.push_back(diameter);
        }
        
        return result;
    }
};

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<vector<int>> tree1(n);
        vector<vector<int>> tree2(n);
        for(int i=0;i<n-1;i++){
            int u,v;
            cin>>u>>v;
            tree1[u].push_back(v);
            tree1[v].push_back(u);
        }
        for(int i=0;i<n-1;i++){
            int u,v;
            cin>>u>>v;
            tree2[u].push_back(v);
            tree2[v].push_back(u);
        }
        Solution ob;
        vector<int> ans = ob.getLinkage(n,tree1,tree2);
        for(auto i: ans){
            cout<<i<<" ";
        }
        cout<<endl;
    }
}