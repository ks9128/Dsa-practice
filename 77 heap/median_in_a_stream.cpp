//{ Driver Code Starts
#include <iostream>
#include <vector>
#include <queue>
#include <sstream>
#include <iomanip>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    
int signum(int a, int b) {
    if (a == b) return 0;
    else if (a > b) return 1;
    else return -1;
}

void callMedian(int element, priority_queue<int> &maxi,
                priority_queue<int, vector<int>, greater<int>> &mini,
                double &median) {
    switch (signum(maxi.size(), mini.size())) {
        case 0:
            if (element > median) {
                mini.push(element);
                median = mini.top();
            } else {
                maxi.push(element);
                median = maxi.top();
            }
            break;
        case 1:
            if (element > median) {
                mini.push(element);
                median = (mini.top() + maxi.top()) / 2.0;
            } else {
                mini.push(maxi.top());
                maxi.pop();
                maxi.push(element);
                median = (mini.top() + maxi.top()) / 2.0;
            }
            break;
        case -1:
            if (element > median) {
                maxi.push(mini.top());
                mini.pop();
                mini.push(element);
                median = (mini.top() + maxi.top()) / 2.0;
            } else {
                maxi.push(element);
                median = (mini.top() + maxi.top()) / 2.0;
            }
            break;
    }
}
    vector<double> getMedian(vector<int> &arr) {
        vector<double> ans;
        priority_queue<int> maxheap;
        priority_queue<int, vector<int>, greater<int>> minheap;
        double median = 0;

        for (int i = 0; i < arr.size(); i++) {
            callMedian(arr[i], maxheap, minheap, median);
            ans.push_back(median);
        }
        return ans;
    }
};



//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {

        string s;
        getline(cin, s);
        stringstream ss(s);
        vector<int> nums;
        int num;
        while (ss >> num) {
            nums.push_back(num);
        }
        Solution ob;
        vector<double> ans = ob.getMedian(nums);
        cout << fixed << setprecision(1);
        for (auto &i : ans)
            cout << i << " ";
        cout << "\n";
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends