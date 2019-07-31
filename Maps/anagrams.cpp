//sort all strings, then map them!

vector<vector<int> > Solution::anagrams(const vector<string> &A) {
    vector<vector<int> > ans;
    
    map<string, vector<int>> cMap;
    for(int i=0; i<A.size(); i++){
        string s = A[i];
        sort(s.begin(), s.end());
        if(cMap.find(s)!=cMap.end()){
            cMap[s].push_back(i+1);
            continue;
        }else{
            vector<int> v; v.push_back(i+1);
            cMap[s] = v;
        }
    }
    
    for(auto x: cMap){
        ans.push_back(x.second);
    }
    
    return ans;
}
