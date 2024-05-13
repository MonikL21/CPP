//number of provinces
class Solution {
  private:
   void dfs(int node,vector<int>adj[],vector<bool>&vis)
    {
        vis[node]=true;
        for(auto it:adj[node])
        {
            if(!vis[it])
            {
                dfs(it,adj,vis);
            }
        }
    }
  public:
    int numProvinces(vector<vector<int>>A, int V) 
    {
        int n=A.size();
        vector<int>adj[n+1];
        for(int i=0;i<A.size();i++)
        {
            for(int j=0;j<A[0].size();j++)
            {
                if(A[i][j] == 1 && i!=j)
                {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                   
                }
            }
        }
        vector<bool>vis(n,false);
        int count=0;
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
                dfs(i,adj,vis);
                count++;
            }
        }
        return count;
    }
};
class Solution {
public:
    void DFS(vector<vector<char>>& grid, int i, int j, int m, int n) {
    if (i < 0 || j < 0 || i >= m || j >= n || grid[i][j] == '0') {
        return;
    }

    grid[i][j] = '0';  // Mark the current cell as visited

    // Visit adjacent cells in all four directions
    DFS(grid, i + 1, j, m, n);
    DFS(grid, i - 1, j, m, n);
    DFS(grid, i, j + 1, m, n);
    DFS(grid, i, j - 1, m, n);

    // dfs(grid,i+1,j-1,m,n);
    // dfs(grid,i-1,j+1,m,n);
    // dfs(grid,i-1,j-1,m,n);
    // dfs(grid,i+1,j+1,m,n); //all 8 directions
}

int numIslands(vector<vector<char>>& grid) 
{
    int m = grid.size();
    if (m == 0) return 0;  // Handle the case when the grid is empty
    int n = grid[0].size();

    int numIslands = 0;

    for (int i = 0; i < m; ++i) 
    {
        for (int j = 0; j < n; ++j) 
        {
            if (grid[i][j] == '1') 
            {
                numIslands++;
                DFS(grid, i, j, m, n);
            }
        }
    }

    return numIslands;
}
};
class Solution {
public:
    void floodFillDFS(vector<vector<int>>& image, int sr, int sc, int newColor, int oldColor) 
    {
    if (sr < 0 || sr >= image.size() || sc < 0 || sc >= image[0].size() || image[sr][sc] != oldColor) {
        return;
    }

    image[sr][sc] = newColor; // Change the color of the current pixel

    // Recursively visit adjacent pixels
    floodFillDFS(image, sr - 1, sc, newColor, oldColor);
    floodFillDFS(image, sr + 1, sc, newColor, oldColor);
    floodFillDFS(image, sr, sc - 1, newColor, oldColor);
    floodFillDFS(image, sr, sc + 1, newColor, oldColor);
}

vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) 
{
    int oldColor = image[sr][sc];

    if (oldColor == newColor) {
        return image; // No need to make any changes if the new color is the same as the old color.
    }

    floodFillDFS(image, sr, sc, newColor, oldColor);

    return image;
}
};
class Solution 
{
    public:
    //Function to find distance of nearest 1 in the grid for each cell.
	vector<vector<int>>nearest(vector<vector<int>>mat)
	{
	    // Code here
	    int n=mat.size();
        int m=mat[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        vector<vector<int>>dist(n,vector<int>(m,0));
        queue<pair<pair<int,int>,int>>q;
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(mat[i][j] == 1)
                {
                    q.push({{i,j},0});
                    vis[i][j]=1;
                }
            }
        }
        int delrow[]={-1,0,1,0};
        int delcol[]={0,1,0,-1};
        
        while(!q.empty())
        {
            int row=q.front().first.first;
            int col=q.front().first.second;
            int steps=q.front().second;
            q.pop();
            dist[row][col]=steps;
            
            for(int i=0;i<4;i++)
            {
                int nrow=row+delrow[i];
                int ncol=col+delcol[i];
                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && mat[nrow][ncol] == 0)
                {
                    vis[nrow][ncol]=1;
                    q.push({{nrow,ncol},steps+1});
                }
            }
        }
        return dist;
	}
};