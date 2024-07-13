class Solution {
public:
    int numberOfSets(int n, int maxDistance, vector<vector<int>>& roads) {
        int ans =0;
        // we are considering all subsets using bitmanipulation
        for(int bit= 0;bit<(1<<n);bit++){ //if n = 3 then total number of subsets are 2^3 (111)
            vector<vector<int>>dirgraph(n,vector<int>(n,1e9)); // we are initializing undirected graph every time for a subset
            for(auto it:roads){
                int start = it[0]; //starting node
                int end = it[1];  //ending node
                int weight = it[2]; //weight between the nodes
                if((bit>>start &1) && (bit>>end & 1)){ // we are checking whether the node exists or not in the current subset
                    dirgraph[start][end] = min(dirgraph[start][end],weight);
                    dirgraph[end][start] = min(dirgraph[end][start],weight);
                }
            }

            // we are keeping the distance between the smae node as zero 
            for(int i=0;i<n;i++) dirgraph[i][i] = 0;

            // we are using floyd warshall for shortest distance
            for(int via = 0;via<n;via++){ // via node
                for(int i=0;i<n;i++){     // start node
                    for(int j=0;j<n;j++){ // end node
                        dirgraph[i][j] = min(dirgraph[i][j],dirgraph[i][via]+dirgraph[via][j]);
                    }
                }
            }

            //finding whether all the distances between the nodes are less than the max distance
            // if it is not the case we are breaking the loop
            bool flag = true;
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    // here also we need to find whether the node is currently is in the subset
                    // because we initialized infinity for all the nodes except the included nodes
                    if((bit>>i & 1) && (bit>>j & 1)){
                        if(dirgraph[i][j]>maxDistance){
                            flag = false;
                            break;
                        }
                    }
                }
            }
            // if all the distances are less than the maxDistance we are appending answer
            if(flag) ans++;

        }
        return ans;
    }
};
