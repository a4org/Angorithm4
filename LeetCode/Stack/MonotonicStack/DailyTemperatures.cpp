/*
 * LeetCode 739 Daily Temeratures
 * Medium
 * Jiawei Wang
 * 2021.10.19
 */

/* Revision
 * $1 2021.11.13 Jiawei Wang
 */

#include <vector>
#include <stack>

using namespace::std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        // Monotonic Stack
        int n = temperatures.size();
        stack<int> Stack;
        vector<int> ret(n, 0);
        
        for (int i = 0; i < n; i++) {
            if (Stack.empty()) Stack.push(i);
	    // decreasing
            else if (temperatures[Stack.top()] >= temperatures[i]) Stack.push(i);
            else {
                // deal with it
		// find a greater
                while (!Stack.empty() && temperatures[Stack.top()] < temperatures[i]) {
                    // Indexes
                    ret[Stack.top()] = i - Stack.top();
                    Stack.pop();
                }
                Stack.push(i);
            }
        }
        return ret;
    }
};

