#include "k_weakest_rows.h"

#include <limits>
#include <iostream>

namespace Solution {

using std::vector;
using std::pair;
using std::array;

int Solution::rank(vector<int> const& row) {
    int rank_count = 0;
    for (int soldier : row) {
        if (soldier == 0) break;
        rank_count++;
    }
    return rank_count;
}   

using row_t = vector<pair<bool, int>>;

vector<int> Solution::kWeakestRows(vector<vector<int>> const& mat, int const& k) {
    row_t rows(mat.size()); // boolean indicates if the row has already been used.
    vector<int> retval;

    row_t::iterator row = rows.begin();
    for(vector<int> const& line : mat) {
        row->second = rank(line);
        row++;
    }

    for(int i = 0; i < k; i++) {
        vector<pair<bool, int>>::const_iterator min = rows.cbegin();
        row = rows.begin();
        
        while(row->first) { // wind forward to the first unused value;
            row++;
            min++;
        }
        
        do {
            if(!(row->first) and (row->second < min->second)) min = row;
            row++;
        } while (row != rows.end());

        int idx = std::distance(rows.cbegin(), min);
        rows[idx].first = true;
        retval.push_back(idx);
    }

    return retval;
}

} // namespace Solution