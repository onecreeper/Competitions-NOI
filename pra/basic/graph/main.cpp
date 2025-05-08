#include <vector>
#include <iostream>
#include <queue>
#include <unordered_set>
#include <stack>

using namespace std;


// 定义 BFS 函数
vector<int> bfsTraversal(const vector<vector<int>>& graph, int startNode) {
    unordered_set<int> visited;  // 记录已访问的节点
    queue<int> que;              // BFS 使用的队列
    vector<int> res;             // 存储遍历顺序

    visited.insert(startNode);
    que.push(startNode);

    while (!que.empty()) {
        int t = que.front();
        que.pop();
        res.push_back(t);

        // 遍历当前节点的所有邻居
        for (int x = 0; x < graph[t].size(); ++x) {
            if (graph[t][x] != 0 && visited.insert(x).second) {
                que.push(x);
            }
        }
    }

    return res;
}



void DFS(int Node, vector<int>& res, const vector<vector<int>>& graph, unordered_set<int>& visited) {
    res.push_back(Node);
    // 遍历当前节点的所有邻接点
    for (int i = 0; i < graph[Node].size(); ++i) {
        if (graph[Node][i] != 0 && visited.insert(i).second) {
            DFS(i, res, graph, visited);
        }
    }
}

vector<int> dfsTraversal(const vector<vector<int>>& graph, int startNode) {
    unordered_set<int> visited;
    vector<int> res;
    // 标记起始节点为已访问并开始DFS
    visited.insert(startNode);
    DFS(startNode, res, graph, visited);
    return res;
}

int main() {
    // 图的邻接矩阵表示（6个节点）
    vector<vector<int>> graph = {
        {0, 4, 2, 0, 0, 0},  // a (0)
        {4, 0, 5, 0, 0, 9},  // b (1)
        {2, 5, 0, 4, 0, 0},  // c (2)
        {0, 0, 4, 0, 4, 0},  // d (3)
        {0, 0, 0, 4, 0, 0},  // e (4)
        {0, 9, 0, 0, 0, 0}   // f (5)
    };

// a --4-- b
// |       |
// 2       5
// |       |
// c --4-- d
// |
// 4
// |
// e

// b --9-- f

    // 从节点 0 开始进行 BFS 遍历
    int startNode = 0;
    vector<int> result = dfsTraversal(graph, startNode);

    // 输出结果
    cout << "traversal order: ";
    for (int node : result) {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}