/**
 * @file
 * @brief K Weekest Row Header
 * @author Richard Vodden
 */


#include <vector>
#include <limits>

/**
 * @brief All the leetcode solutions live in this namespace.
 * 
 */
namespace Solution {

/**
 * @brief The standard LeetCode Solution class.
 * 
 */
class Solution {
public:
    /**
     * @brief 1337. The K Weakest Rows in a Matrix.
     * 
     * You are given an m x n binary matrix mat of 1's (representing soldiers) and 0's (representing civilians). 
     * The soldiers are positioned in front of the civilians. That is, all the 1's will appear to the left of all the 0's in each row.
     * 
     * A row i is weaker than a row j if one of the following is true:
     * 
     *  - The number of soldiers in row i is less than the number of soldiers in row j.
     *  - Both rows have the same number of soldiers and i < j.
     * 
     * @param mat A vector of Rows of soliders and civilians.
     * @param k The number of indices to return.
     * @return vector<int> the indices of the k weakest rows in the matrix ordered from weakest to strongest.
     */
    static std::vector<int> kWeakestRows(std::vector<std::vector<int>> const&, int const&);

  /**
   * @brief Calculates the number of 1s at the start of the vector
   * 
   * @param row the vector<int> to process
   * @return int the number of consecutive '1's at the start of `row`
   */
  static int rank(std::vector<int> const& row);
};


} // namespace Solution