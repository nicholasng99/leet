/*
 * @lc app=leetcode id=217 lang=typescript
 *
 * [217] Contains Duplicate
 */

// @lc code=start
function containsDuplicate(nums: number[]): boolean {
  let exists = new Set<number>();
  for (let num of nums) {
    if (exists.has(num)) return true;
    exists.add(num);
  }
  return false;
}
// @lc code=end
