#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(), people.end(), [](const vector<int>& a, const vector<int>& b) {
            if (a[0] != b[0]) {
                return a[0] > b[0];
            } else {
                return a[1] < b[1];
            }
        });

        vector<vector<int>> result;
       
        for (const auto& p : people) {
            result.insert(result.begin() + p[1], p);
        }
        
        return result;
    }
};

int main() {
    Solution sol;
    
    cout << "Test Case 1:" << endl;
    vector<vector<int>> people1 = {{7,0},{4,4},{7,1},{5,0},{6,1},{5,2}};
    cout << "Input: [[7,0],[4,4],[7,1],[5,0],[6,1],[5,2]]" << endl;
    vector<vector<int>> result1 = sol.reconstructQueue(people1);
    cout << "Output: [";
    for (size_t i = 0; i < result1.size(); i++) {
        cout << "[" << result1[i][0] << "," << result1[i][1] << "]";
        if (i < result1.size() - 1) cout << ",";
    }
    cout << "]" << endl;
    
    cout << "\nTest Case 2:" << endl;
    vector<vector<int>> people2 = {{6,0},{5,0},{4,0},{3,2},{2,2},{1,4}};
    cout << "Input: [[6,0],[5,0],[4,0],[3,2],[2,2],[1,4]]" << endl;
    vector<vector<int>> result2 = sol.reconstructQueue(people2);
    cout << "Output: [";
    for (size_t i = 0; i < result2.size(); i++) {
        cout << "[" << result2[i][0] << "," << result2[i][1] << "]";
        if (i < result2.size() - 1) cout << ",";
    }
    cout << "]" << endl;
    
    return 0;
}