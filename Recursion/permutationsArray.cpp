vector<vector<int> > Solution::permute(vector<int> &A) {
    vector<vector<int>> ans;
    
    if(A.size()==1){
        ans.push_back(A);
        return ans;
    }
    
    for(int i=0; i<A.size(); i++){
        vector<int> v;
        for(int j=0; j<A.size(); j++){
            if(i!=j) v.push_back(A[j]);
        }
        vector<vector<int>> tans = permute(v);
        
        for(vector<int> a: tans){
            a.push_back(A[i]);
            ans.push_back(a);
        }
    }
    
    return ans;
}