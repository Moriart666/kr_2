#pragma once

#include <vector>

class Graph {
public:
    // Конструктор: n — количество вершин
    Graph(int n);

    // Метод для добавления ребра
    void addEdge(int u, int v);

    // Метод для подсчёта количества компонент связности
    int countConnectedComponents() const;

    // Метод для проверки наличия цикла
    bool hasCycle() const;

    // Метод для проверки, является ли граф деревом
    bool isTree() const;

    // Метод для проверки, является ли граф двудольным
    bool isBipartite() const;

private:
    int numVertices;
    int numEdges;
    std::vector<std::vector<int>> adj;

    // Вспомогательные методы для DFS
    void dfs(int v, std::vector<bool>& visited) const;
    void dfsCycle(int v, int parent, std::vector<bool>& visited, bool& cycleFound) const;

    // Вспомогательный метод для проверки двудольности с использованием BFS
    bool bfsCheckBipartite(int start, std::vector<int>& color) const;
};
