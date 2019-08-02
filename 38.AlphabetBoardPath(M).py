# https://leetcode.com/problems/alphabet-board-path/

class Solution:
    def alphabetBoardPath(self, target: str) -> str:
        d = {'a': (0, 0), 'b': (0, 1), 'c': (0, 2), 'd': (0, 3), 'e': (0, 4), 'f': (1, 0), 'g': (1, 1), 'h': (1, 2), 'i': (1, 3), 'j': (1, 4), 'k': (2, 0), 'l': (2, 1), 'm': (2, 2), 'n': (2, 3), 'o': (2, 4), 'p': (3, 0), 'q': (3, 1), 'r': (3, 2), 's': (3, 3), 't': (3, 4), 'u': (4, 0), 'v': (4, 1), 'w': (4, 2), 'x': (4, 3), 'y': (4, 4), 'z': (5, 0)}
        
        rv = ""
        current = 'a'
        
        for letter in target:
            v = d[current][0] - d[letter][0]
            h = d[current][1] - d[letter][1]
            
            if(current == "z"):
                if(v>0):
                    rv += "U"*abs(v)
                elif(v<0):
                    rv += "D"*abs(v)
            
            if(h>0):
                rv += "L"*abs(h)
            elif (h<0):
                rv += "R"*abs(h)
                
            if(current != "z"):
                if(v>0):
                    rv += "U"*abs(v)
                elif(v<0):
                    rv += "D"*abs(v)
                
            rv += "!"
            current = letter
        
        return rv
