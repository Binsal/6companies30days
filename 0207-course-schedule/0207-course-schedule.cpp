class Solution {
public:
   
    bool canFinish(int numCourses, vector<vector<int>>& pre) {
      
	   vector<int>adj[numCourses];
       
        for(auto it:pre){
            adj[it[1]].push_back(it[0]);
        }
        
        vector<int>indegree(numCourses,0);
        
        for(int i=0;i<numCourses;i++){
            for(auto it:adj[i]){
                indegree[it]++;
            }
        }
        
        queue<int>q;
        
        for(int i=0;i<numCourses;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        vector<int>topo;
        
        while(!q.empty()){
            int val=q.front();
            topo.push_back(val);
            q.pop();
            
            for(auto it:adj[val]){
                indegree[it]--;
                if(indegree[it]==0){
                    q.push(it);
                }
            }
        }
        
        
        if(topo.size()==numCourses){
            return true;
        }
        
        return false;
    }
};