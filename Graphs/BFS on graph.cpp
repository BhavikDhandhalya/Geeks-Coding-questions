/*
Given N, number of edges for a graph. The task is to do Breadth First Search of this graph.

Input:
First line of input contains number of testcases T. For each testcase, first line of input contains N, for which 2*N numbers (N pairs as X Y) are given in the next line which represents an edge from X to Y.

Output:
For each testcase, print the BFS of the graph starting from 1.

Note : The expected output button always produces BFS starting from node 1.

User Task:
Since, this is a functional problem, your task is to complete the function bfs() which do BFS of the given graph starting from node 1 and prints the nodes in BFS order.

Constraints:
1 <= T <= 100
1 <= N <= 100

Example:
Input:
1
4
1 2 1 3 1 4 3 5

Output:
1 2 3 4 5    // BFS from node 1

Explanation:
Testcase 1: There is  one test cases.  First line of each test case represent an integer N denoting no of edges and then in the next line N pairs of values a and b are fed which denotes there is a unidirectional edge from a to b 
*/

void bfs(int s,vector<int> adj[],bool vis[])
{
    // Your code here
    queue < int > Q;
    Q.push(s);
    vis[s] = true;
    
    while (not Q.empty()) {
        auto x = Q.front();
        Q.pop();
        cout << x << " ";
        
        for (int i = 0; i < adj[x].size(); i++) {
            if (vis[adj[x][i]] == false) {
                vis[adj[x][i]] = true;
                Q.push(adj[x][i]);
            }
        }
    }
}
