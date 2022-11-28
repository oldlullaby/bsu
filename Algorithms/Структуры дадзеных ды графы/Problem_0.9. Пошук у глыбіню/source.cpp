#include <fstream>
#include <iostream>
#include <queue>

void dfs(const int &x, int &z, std::vector <bool> &v, std::vector <int> &ind, const std::vector <std::vector<int>>& graph) {
    v[x] = true;
    z++;
    ind[x] = z;
    for(int i =0; i < graph.size(); i++){
        if(graph[x][i] == 1) {
            if (!v[i])
                dfs(i,z,v,ind,graph);
        }
    }
}

int main() {

    std::ifstream in("input.txt"); std::ofstream out("output.txt");

    int vx = 0, n;
    in >> n;

    std::vector <int> ind(n);
    std::vector<bool> v(n);

    std::vector<std::vector <int> > graph(n);
    for (auto &i:graph) i = std::vector<int>(n);

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            in >> graph[i][j];

    for (int i = 0; i < n; ++i) if (!v[i]) dfs(i, vx, v, ind, graph);
    for (const auto &i:ind) out << i << " ";

    in.close(); out.close();
    return 0;
}
