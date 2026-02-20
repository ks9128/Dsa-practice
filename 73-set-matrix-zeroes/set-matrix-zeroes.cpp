// class Solution {
// public:
//     void setZeroes(vector<vector<int>>& matrix) {
//         //take two array i and j to store row and col of zero;
//         int n = matrix.size();
//         int m = matrix[0].size();
//         vector<int> row(n), col(m);
//         for(int i=0; i<n;i++){
//             for(int j=0; j<m; j++){
//                 if(matrix[i][j]==0){
//                     row[i]=1;
//                     col[j]=1;
//                     // cout<<i<<"&"<<j<<endl;
//                 }
//             }
//         }
    
//         for(int i=0; i<n;i++){
//             if(row[i]==1){
//                 for(int j=0; j<m; j++){
//                     matrix[i][j] = 0;
//                     // cout<<i<<" "<<j;
//                 }
//             }
//         }
//         cout<<endl;
//         for(int i=0; i<m;i++){
//             if(col[i]==1){
//                 for(int j=0; j<n; j++){
//                     matrix[j][i] = 0;
//                     // cout<<j<<" "<<i;
//                 }
//             }
//         }
//     }
// };

//approach 2 to use O(1) space
// ->intresting approach
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        bool firstRowZero = false;
        bool firstColZero = false;

        // Check if first row or first column originally have any zeros
        for (int i = 0; i < n; i++) if (matrix[i][0] == 0) firstColZero = true;
        for (int j = 0; j < m; j++) if (matrix[0][j] == 0) firstRowZero = true;

        for (int i = 1; i < n; i++) {
            for (int j = 1; j < m; j++) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }

        // Set matrix cells to zero (excluding first row/col)
        for (int i = 1; i < n; i++) {
            for (int j = 1; j < m; j++) {
                if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }

        // handle the first row and first column
        if (firstColZero) {
            for (int i = 0; i < n; i++) matrix[i][0] = 0;
        }
        if (firstRowZero) {
            for (int j = 0; j < m; j++) matrix[0][j] = 0;
        }
    }
};