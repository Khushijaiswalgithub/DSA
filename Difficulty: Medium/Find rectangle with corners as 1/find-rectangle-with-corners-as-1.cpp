class Solution {
  public:
    bool ValidCorner(vector<vector<int> >& mat) {
        // code here
        int r=mat.size();
        int c=mat[0].size();
        
        unordered_set<string>st;
        for(int i=0;i<r;i++){
            vector<int>col;
            for(int j=0;j<c;j++){
                if(mat[i][j]==1){
                    col.push_back(j);
                }
            }
            for(int x=0;x<col.size();x++){
                for(int y=x+1;y<col.size();y++){
                    string res=to_string(col[x])+"_"+to_string(col[y]);
                    if(st.count(res)){
                        return true;
                    }
                    st.insert(res);
                }
            }
        }
        return false;
    }
};