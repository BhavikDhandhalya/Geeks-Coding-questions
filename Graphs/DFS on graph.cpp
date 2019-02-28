/*
Given N edges of a graph. The task is to do depth first traversal of the graph.
Note: Please use recursive approach.

Input:
First line of input contains number of testcases T. For each testcase, first line contains number of edges and next line contains N pairs of integers (X and Y each) where X Y means an edge from X to Y.

Output:
For each testcase, print the nodes while doing DFS starting from node 1.

Your task:
The task is to complete the function dfs() which should do the depth first traversal of given graph and prints the node in DFS order.

Constraints:
1 <= T <= 100
1 <= N <= 500

Example:
Input:
1
4
1 2 1 3 1 4 3 5

Output:
1 2 3 5 4    // dfs from node 1

Explanation:
Testcase 1: There is  one test cases.  First line of each test case represent an integer N denoting number of edges and then in the next line N pairs of values a and b are fed which denotes there is an edge from a to b.
*/

void dfs(int s, vector<int> g[], bool vis[])
{
    cout << s << " ";
    // Your code here
    vis[s] = true;
    for (int i = 0; i < g[s].size(); i++) {
        if (vis[g[s][i]] == false)
            dfs(g[s][i], g, vis);
    }
}
