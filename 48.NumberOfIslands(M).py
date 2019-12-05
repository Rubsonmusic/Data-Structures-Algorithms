class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        if not grid:
            return 0
        
        width = len(grid[0])
        height = len(grid)
        visited = [[False]*width for _ in range(height)]
        count = 0
        
        def dfs(j,i):
            if (j<0) or (j>=height) or (i<0) or (i>=width) or (visited[j][i]==True):
                return
            elif grid[j][i]=='1':
                visited[j][i] = True
                dfs(j,i+1)
                dfs(j+1,i)
                dfs(j,i-1)
                dfs(j-1,i)
            
            visited[j][i] = True
        
        for y in range(height):
            for x in range(width):
                
                if (not visited[y][x]) and (grid[y][x]=='1'):
                    count += 1
                    dfs(y,x)
                
                if grid[y][x]=='0':
                    visited[y][x] = True
        
        
        return count
