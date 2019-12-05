# https://leetcode.com/problems/check-if-it-is-a-straight-line/submissions/

class Solution:
    def checkStraightLine(self, coordinates: List[List[int]]) -> bool:
        if (coordinates[0][0] == coordinates[1][0]):
            for i in range(1,len(coordinates)):
                if coordinates[i][0] != coordinates[i-1][0]:
                    return False
            return True
        
        p1, p2 = coordinates[0], coordinates[1]
        
        m = (p2[1] - p1[1]) / (p2[0] - p1[0])
        c = p2[1] - m*p2[0]
        
        for p in coordinates:
            if p[1] != m*p[0] + c:
                return False
            
        return True
