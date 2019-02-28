/*
A group of connected 1's forms an island. The task is to complete the method findIslands() which returns the number of islands present. The function takes three arguments the first is the boolean matrix A and then the next two arguments are N and M denoting the size(N*M) of the matrix A .

Input:
The first line of input will be the number of testcases T, then T test cases follow. The first line of each testcase contains two space separated integers N and M. Then in the next line are the NxM inputs of the matrix A separated by space .

Output:
For each testcase in a new line, print the number of islands present.

User Task:
Since this is a functional problem you don't have to worry about input, you just have to complete the function findIslands().

Constraints:
1 <= T <= 100
1 <= N, M <= 50
0 <= A[i][j] <= 1

Example(To be used only for expected output) :
Input
1
3 3
1 1 0 0 0 1 1 0 1

Output
2

Explanation:
Testcase 1: The graph will look like
1 1 0
0 0 1
1 0 1
Here, two islands will be formed
First island will be formed by elements {A[0][0] ,  A[0][1], A[1][2], A[2][2]}
Second island will be formed by {A[2][0]}.

*/

int findIslands(int A[MAX][MAX], int N, int M) {
    bool visited[MAX][MAX];
    memset (visited, 0, sizeof(visited));
    
    int result = 0;
    queue < pair < int, int > > Q;
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (A[i][j] == 1 && visited[i][j] == false) {
                result++;
                
                Q.push(make_pair(i, j));
                visited[i][j] = true;
                
                while (!Q.empty()) {
                    auto cur = Q.front();
                    Q.pop();
                    
                    for (int X = -1; X <= 1; X++) {
                        for (int Y = -1; Y <= 1; Y++) {
                            int aa = cur.first + X;
                            int bb = cur.second + Y;
                            
                            /*checking borders*/
                            if (aa >= 0 && bb >= 0 && aa < N && bb < M) {
                                if (A[aa][bb] == 1 && visited[aa][bb] == false) {
                                    visited[aa][bb] = true;
                                    Q.push(make_pair(aa, bb));
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    
    return result;
}
