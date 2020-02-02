    #include <cstdio>
    #include <algorithm>
    #include <limits>
    #include <tuple>
    #include <queue>
    #include <vector>
    using std::get;
    using std::numeric_limits;
    using std::pair;
    using std::priority_queue;
    using std::vector;




    pair<int, int> find_min_range(const vector<vector<int>>& arrays) {

      // The result.
      pair<int, int> min_range{
        numeric_limits<int>::min(),
        numeric_limits<int>::max()
      };

      // Sweeping index on each row.
      vector<int> indices(arrays.size());

      // M.
      std::priority_queue< pair<int, int>, std::vector<pair<int, int>>, std::greater<pair<int, int>> > minimums;
      // max(M).
      auto max = arrays[0][0];
      for (auto i = 0; i < arrays.size(); i++) {
        auto v = arrays[i][0];
        minimums.push({v, i});
        if (max < v) {
          max = v;
        }
      }


      while (true) {
        auto min = minimums.top();
        auto min_val = min.first;
        auto min_row = min.second;
        minimums.pop();
        if (long(min_range.second) - long(min_range.first) >
            long(max) - long(min_val)) {
          min_range = {min_val, max};
        }
        indices[min_row]++;
        if (indices[min_row] == arrays[min_row].size()) {
          return min_range;
        }
        auto v = arrays[min_row][indices[min_row]];
        if (max < v) {
          max = v;
        }
        minimums.push({v, min_row});
      }


      return min_range;
    }



    int main() {
      vector<vector<int>> a {
        {1, 1000, 2000},
        {20, 1001, 5000},
        {55, 1002, 222222}
      };
      auto res = find_min_range(a);
      printf("Minimum range is (%d, %d)\n", res.first, res.second);
      return 0;
    }
