/*
 * LeetCode 1109 Corporate Flight Bookings
 * Medium
 * Jiawei Wang
 * 2022.5.15
 */


#include <vector>

using namespace::std;

class Solution {
public:
  vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
    vector<int> reserved(n+2, 0);

    for (auto booking : bookings) {
      reserved[booking[0]] += booking[2];
      reserved[booking[1] + 1] -= booking[2];
    }

    vector<int> ret;
    int total = 0;
    // n is given and small
    // we can use this way to replace sorting
    for (int i = 1; i <= n; i++) {
      total += reserved[i];
      ret.push_back(total);
    }

    return ret;
  }
};
