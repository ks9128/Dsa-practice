#include <vector>
#include <iostream>
using namespace std;


class Solution {
    public:
      bool isSafe(int row, int col,vector<vector<int>> &board, int val ){
          for(int i = 0;i <9;i++){
          //check row and col :
              if(board[row][i]==val || board[i][col]==val){
                  return false;
              }
              //check 3x3 matrix
              if(board[3*(row/3) + i/3][3*(col/3)+i%3]== val)
                  return false;
          }
          return true;
          
      }
      bool solve(vector<vector<int>> &board){
          // traverse each cell
          for(int row=0 ;row< 9 ;row++){
              for(int col=0; col<9;col++){
                  if(board[row][col]==0){
                      // check each elemet
                      for(int val = 1; val <=9 ; val++){
                          //put value
                          if(isSafe(row,col,board,val))
                          {
                              board[row][col] = val;
                          
                          //recursive call
                          bool isnextanswerpossible = solve(board);
                              if(isnextanswerpossible){
                                  return true;
                              }
                              else{
                                  //backtrack
                                  board[row][col] = 0;
                              }
                          }
                      }
                      return false;
                  }
              }
          }
          return true;
      }
    
      // Function to find a solved Sudoku.
      void solveSudoku(vector<vector<int>> &mat) {
          solve(mat);
      }
  };