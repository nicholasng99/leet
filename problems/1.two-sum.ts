/*
 * @lc app=leetcode id=1 lang=typescript
 *
 * [1] Two Sum
 */

// @lc code=start
function twoSum(nums: number[], target: number): number[] {
  let map = new Map<number, number>();
  for (let i = 0; i < nums.length; ++i) map.set(nums[i], i);
  for (let i = 0; i < nums.length; ++i) {
    const complement = target - nums[i];
    if (map.has(complement) && map.get(complement) != i)
      return [i, map.get(complement) as number];
  }
  return [];
}
// @lc code=end
