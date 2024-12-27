#include "lib.hpp"
#include <gtest/gtest.h>

// Тестирование подсчёта компонент связности
TEST(GraphTest, CountConnectedComponents) {
    Graph g1(5);
    g1.addEdge(1, 2);
    g1.addEdge(2, 3);
    g1.addEdge(4, 5);
    EXPECT_EQ(g1.countConnectedComponents(), 2);

    Graph g2(4);
    g2.addEdge(1, 2);
    g2.addEdge(2, 3);
    g2.addEdge(3, 4);
    EXPECT_EQ(g2.countConnectedComponents(), 1);
}

// Тестирование обнаружения цикла
TEST(GraphTest, HasCycle) {
    Graph g1(4);
    g1.addEdge(1, 2);
    g1.addEdge(2, 3);
    g1.addEdge(3, 4);
    EXPECT_FALSE(g1.hasCycle());

    Graph g2(4);
    g2.addEdge(1, 2);
    g2.addEdge(2, 3);
    g2.addEdge(3, 4);
    g2.addEdge(4, 2);
    EXPECT_TRUE(g2.hasCycle());

    Graph g3(3);
    g3.addEdge(1, 2);
    g3.addEdge(2, 3);
    g3.addEdge(3, 1);
    EXPECT_TRUE(g3.hasCycle());
}

// Тестирование проверки на дерево
TEST(GraphTest, IsTree) {
    Graph g1(5);
    g1.addEdge(1, 2);
    g1.addEdge(1, 3);
    g1.addEdge(3, 4);
    g1.addEdge(3, 5);
    EXPECT_TRUE(g1.isTree());

    Graph g2(4);
    g2.addEdge(1, 2);
    g2.addEdge(2, 3);
    g2.addEdge(3, 4);
    g2.addEdge(4, 2);
    EXPECT_FALSE(g2.isTree());

    Graph g3(4);
    g3.addEdge(1, 2);
    g3.addEdge(3, 4);
    EXPECT_FALSE(g3.isTree()); // Несвязный граф
}

// Тестирование проверки на двудольность
TEST(GraphTest, IsBipartite) {
    // Двудольный граф
    Graph g1(4);
    g1.addEdge(1, 2);
    g1.addEdge(1, 3);
    g1.addEdge(2, 4);
    g1.addEdge(3, 4);
    EXPECT_TRUE(g1.isBipartite());

    // Не двудольный граф (с нечётным циклом)
    Graph g2(3);
    g2.addEdge(1, 2);
    g2.addEdge(2, 3);
    g2.addEdge(3, 1);
    EXPECT_FALSE(g2.isBipartite());

    // Дерево (является двудольным)
    Graph g3(5);
    g3.addEdge(1, 2);
    g3.addEdge(1, 3);
    g3.addEdge(3, 4);
    g3.addEdge(3, 5);
    EXPECT_TRUE(g3.isBipartite());

    // Несвязный двудольный граф
    Graph g4(6);
    g4.addEdge(1, 2);
    g4.addEdge(3, 4);
    g4.addEdge(5, 6);
    EXPECT_TRUE(g4.isBipartite());

    // Несвязный граф с нечётным циклом
    Graph g5(6);
    g5.addEdge(1, 2);
    g5.addEdge(2, 3);
    g5.addEdge(3, 1);
    g5.addEdge(4, 5);
    EXPECT_FALSE(g5.isBipartite());
}

// Главная функция для запуска всех тестов
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}