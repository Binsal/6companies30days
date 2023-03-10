class Solution {
public:
    int mod=1e9+7;
    
    int peopleAwareOfSecret(int n, int delay, int forget) {
        vector<int>v(2005,0);
        v[1]=1;
        
        for(int i=1;i<=n;i++){
            for(int j=i+delay;j<i+forget;j++){
                v[j]=(v[i]+v[j])%mod;
            }
        }
        
        
        int count=0;
        
        for(int i=max(1,n-forget+1);i<=n;i++){
            count=(count+v[i])%mod;
        }
        
        return count;
    }
}; 