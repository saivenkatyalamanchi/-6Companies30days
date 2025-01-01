class Solution {
public:
    void shortPath(int src,vector<vector<int>> &dist,vector<pair<int,int>> adj[]){
            priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> hp;
            dist[src][src] = 0;
            hp.push({0,src});

            while(!hp.empty()){
                int dis = hp.top().first;
                int u = hp.top().second;

                hp.pop();
                for(auto it : adj[u]){
                    int v = it.first;
                    int wt = it.second;
                    if(dist[src][v] > dist[src][u] + wt){
                        dist[src][v] = dist[src][u] + wt;
                        hp.push({dist[src][v],v});
                    }
                }
            }
    }
    int findTheCity(int n, vector<vector<int>>& edges, int k) {
        vector<pair<int,int>> adj[n];
        for(auto const &it : edges){
            int u = it[0];
            int v = it[1];
            int wt = it[2];

            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt});
        }

        vector<vector<int>> dist(n, vector<int>(n,INT_MAX));
        int mini = INT_MAX;
        int city = -1;
        

        for(int i=0;i<n;i++){
            int count = 0;
            shortPath(i,dist,adj);

            for(auto it : dist[i]){
                if(it <= k){
                    count++;
                }
            }

            if(count <= mini){
                mini = count;
                city = i;
            }

        }

        return city;


    }
};