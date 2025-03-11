#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;  // Add missing namespace

pair < int , int > findSimilarity(vector < int > arr1, vector < int > arr2, int n, int m) 
{
	// Write Your Code here.      
	unordered_map<int,int> count;

	for(auto i: arr1){
		count[i]++;
	}  
	for(auto i: arr2){
		count[i]++; 
	}
	int common = 0;
	int distinct = 0;
	for(auto i: count){
		if(i.second == 2){
			common++;
		}
			distinct++;
	}
	return {common,distinct};
}

int main() {
    // Test case
    vector<int> arr1 = {1, 2, 3, 4, 5};
    vector<int> arr2 = {2, 3, 4, 6, 7};
    
    int n = arr1.size();
    int m = arr2.size();
    
    pair<int, int> result = findSimilarity(arr1, arr2, n, m);
    
    cout << "Common elements: " << result.first << endl;
    cout << "Distinct elements: " << result.second << endl;
    
    return 0;
}