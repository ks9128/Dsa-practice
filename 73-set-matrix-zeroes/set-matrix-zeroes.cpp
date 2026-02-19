class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        //take two array i and j to store row and col of zero;
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> row(n), col(m);
        for(int i=0; i<n;i++){
            for(int j=0; j<m; j++){
                if(matrix[i][j]==0){
                    row[i]=1;
                    col[j]=1;
                    // cout<<i<<"&"<<j<<endl;
                }
            }
        }
    
        for(int i=0; i<n;i++){
            if(row[i]==1){
                for(int j=0; j<m; j++){
                    matrix[i][j] = 0;
                    // cout<<i<<" "<<j;
                }
            }
        }
        cout<<endl;
        for(int i=0; i<m;i++){
            if(col[i]==1){
                for(int j=0; j<n; j++){
                    matrix[j][i] = 0;
                    // cout<<j<<" "<<i;
                }
            }
        }
    }
};