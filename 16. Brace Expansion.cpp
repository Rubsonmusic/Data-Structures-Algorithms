class Solution(object):
    def braceExpansionII(self, expression):
        """
        :type expression: str
        :rtype: List[str]
        """
        def balanced_index(string , start):
            factor = 1
            while(1):
                start += 1
                if(string[start] == '{'):
                    factor += 1
                elif(string[start] == '}'):
                    factor -= 1
                if factor==0:
                    return start
        
        def parse(s):
            #strip enclosing brackets
            if (s[0]=='{' and (balanced_index(s, 0)==len(s)-1)):
                s = s[1:-1]
                
            if len(s)==1 or ((s.find(',') == -1) and (s.find('{') == -1)):
                return set([s])
            if(s.find(',')!=-1 and s.find('{') == -1):
                return set(s.split(','))

            opb = s.find('{')
            clb = balanced_index(s, opb)
            if opb==0:
                if (s[clb+1] == ','):  # R(x), R(y)
                    return parse(s[:clb+1]).union(parse(s[clb+2:]))
                else: # R(x) a
                    return set([e1+e2 for e1 in parse(s[:clb+1]) for e2 in parse(s[clb+1:])])
            else: # a R(x)
                if(s[opb-1]==','):
                    return parse(s[:opb-1]).union(parse(s[opb:]))
                else:
                    sub = s[0:opb]
                    return set([sub+e for e in parse(s[opb:])])
            
        rl = list(parse(expression))
        rl.sort()
        return rl
