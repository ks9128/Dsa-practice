class Solution {
public:

bool check(vector <int> baseBox , vector<int> newBox ){
    if(newBox[0] <= baseBox[0] && newBox[1] <= baseBox[1] && newBox[2] <= baseBox[2]){
        return true;
    }else return false;
}
 int solveSC(int n, vector<vector<int>>& a){
      vector<int> currRow(n+1,0);
      vector<int> prevRow(n+1,0);
     for(int curr = n-1; curr>=0; curr--){
         for(int prev = curr-1; prev>=-1; prev--){
             //include
              int take = 0;
              if(prev == -1 || check(a[curr] ,a[prev])){
                  take  = a[curr][2] + prevRow[curr+1];
              }
              int nottake = 0+ prevRow[prev+1];
              
              currRow[prev+1]=  max(take,nottake);
         }
         prevRow = currRow;
     }
     return prevRow[0];
  }
  
    int maxHeight(vector<vector<int>>& cuboids) {
        //step 1: sort all dimentions of every cuboid
        for(auto &a: cuboids){
            sort(a.begin(),a.end());
        }
        //stpe 2 sort all cuboid or w or 1
        sort(cuboids.begin(),cuboids.end());

        // step 3 use lcs logic
        return solveSC(cuboids.size(),cuboids);
    }
};