#include "lib.hpp"
#include <queue>

Graph::Graph(int n) : numVertices(n), numEdges(0), adj(n + 1, std::vector<int>()) {}

// Метод для добавления ребра
void Graph::addEdge(int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
    numEdges++;
}

// Вспомогательный метод DFS для подсчёта компонент связности
void Graph::dfs(int v, std::vector<bool>& visited) const {
    visited[v] = true;
    for (const int& neighbor : adj[v]) {
        if (!visited[neighbor]) {
            dfs(neighbor, visited);
        }
    }
}

// Метод для подсчёта количества компонент связности
int Graph::countConnectedComponents() const {
    std::vector<bool> visited(numVertices + 1, false);
    int components = 0;
    for (int v = 1; v <= numVertices; ++v) {
        if (!visited[v]) {
            dfs(v, visited);
            components++;
        }
    }
    return components;
}

// Вспомогательный метод DFS для проверки цикла
void Graph::dfsCycle(int v, int parent, std::vector<bool>& visited, bool& cycleFound) const {
    visited[v] = true;
    for (const int& neighbor : adj[v]) {
        if (!visited[neighbor]) {
            dfsCycle(neighbor, v, visited, cycleFound);
        } else if (neighbor != parent) {
            cycleFound = true;
        }
        if (cycleFound) {
            return;
        }
    }
}

// Метод для проверки наличия цикла
bool Graph::hasCycle() const {
    std::vector<bool> visited(numVertices + 1, false);
    bool cycleFound = false;
    for (int v = 1; v <= numVertices; ++v) {
        if (!visited[v]) {
            dfsCycle(v, -1, visited, cycleFound);
            if (cycleFound) {
                break;
            }
        }
    }
    return cycleFound;
}

// Метод для проверки, является ли граф деревом
bool Graph::isTree() const {
    return (countConnectedComponents() == 1) && (!hasCycle()) && (numEdges == numVertices - 1);
}

// Метод для проверки, является ли граф двудольным (бипаритным)
bool Graph::isBipartite() const {
    std::vector<int> color(numVertices + 1, -1);
    for (int start = 1; start <= numVertices; ++start) {
        if (color[start] == -1) {
            if (!bfsCheckBipartite(start, color)) {
                return false;
            }
        }
    }
    return true;
}

// Вспомогательный метод BFS для проверки двудольности
bool Graph::bfsCheckBipartite(int start, std::vector<int>& color) const {
    std::queue<int> q;
    q.push(start);
    color[start] = 0; // Начальный цвет

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (const int& v : adj[u]) {
            if (color[v] == -1) {
                color[v] = 1 - color[u];
                q.push(v);
            } else if (color[v] == color[u]) {
                return false; // Конфликт цветов
            }
        }
    }
    return true;
}