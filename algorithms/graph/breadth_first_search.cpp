#include <vector>
#include <iostream>
#include <bitset>
#include <deque>

using namespace std;

struct Graph {
public:
    Graph(int num_nodes) : node_map(vector<vector<int>>(num_nodes)) { }
    void add_edge(int s, int d) {
        node_map[s-1].push_back(d-1);
        node_map[d-1].push_back(s-1);
    }
    void print() {
        for (int ii = 0; ii < node_map.size(); ++ii) {
            cout << ii+1 << ": ";
            for (int jj : node_map[ii]) {
                cout << jj+1 << " ";
            }
            cout << endl;
        }
    }
    void bfs(int S);
private:
    vector<vector<int>> node_map;
};

void Graph::bfs(int S) {
    --S;
    vector<char> marked(node_map.size(), 0);
    vector<int> dist(node_map.size(), -1);
    marked[S] = 1;
    dist[S] = 0;
    deque<int> visited(1, S);
    while (!visited.empty()) {
        int curr = visited.front();
        visited.pop_front();
        for (const int &next : node_map[curr]) {
            if (false == marked[next]) {
                marked[next] = 1;
                dist[next] = dist[curr] + 6;
                visited.push_back(next);
            }
        }
    }
    for (int ii = 0; ii < node_map.size(); ++ii) {
        if (ii == S) {
            continue;
        }
        cout << dist[ii] << " ";
    }
    cout << endl;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, E;
        cin >> N >> E;
        Graph g(N);
        for (int ii = 0; ii < E; ++ii) {
            int s, d;
            cin >> s >> d;
            g.add_edge(s, d);
        }
        int S;
        cin >> S;
//        g.print();
        g.bfs(S);
    }
    return 0;
}