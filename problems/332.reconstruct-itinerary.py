#
# @lc app=leetcode id=332 lang=python
#
# [332] Reconstruct Itinerary
#

# @lc code=start
from collections import OrderedDict

def search(self, key):
    print(key)
    print(self.map)
    if key in self.map:
        destinations = self.map[key]
        while len(destinations) > 0:
            value = destinations[0]
            destinations.pop(0)
            search(self, value)
    self.result.append(key)
            
class Solution(object):
    def findItinerary(self, tickets):
        """
        :type tickets: List[List[str]]
        :rtype: List[str]
        """
        self.map = {}
        for ticket in tickets:
            key = str(ticket[0])
            if key not in self.map:
                self.map[key] = []
            self.map[key].append(str(ticket[1]))
        for key, value in self.map.items():
            self.map[key] = sorted(value)
        self.map = OrderedDict(sorted(self.map.items()))

        self.result = []
        initialKey = "JFK"
        search(self, initialKey)
        self.result.reverse()
        return self.result
        
        
# @lc code=end