#
# @lc app=leetcode id=332 lang=python
#
# [332] Reconstruct Itinerary
#

# @lc code=start
from collections import OrderedDict

def nextLocation(self, FULL_TICKET):
    key = FULL_TICKET[0:3]
    for ticket in self.map:
        if key == ticket[0:3]:
            key = ticket
            break
    if self.map[key] == 1:
        self.map.pop(key)
    else:
        self.map[key] -= 1
    return key[3:6]
            
class Solution(object):
    def findItinerary(self, tickets):
        """
        :type tickets: List[List[str]]
        :rtype: List[str]
        """
        self.map = {}
        for ticket in tickets:
            FULL_TICKET = str(ticket[0] + ticket[1])
            self.map[FULL_TICKET] = 1 if FULL_TICKET not in self.map else self.map[FULL_TICKET] + 1

        self.map = OrderedDict(sorted(self.map.items()))

        print(self.map)

        resultList = []
        key = "JFK"
        resultList.append(key)
        while len(self.map) > 0:
            nextKey = nextLocation(self, key)
            resultList.append(nextKey)
            key = nextKey
        return resultList
        
        
# @lc code=end