#include "BinarySearchTree.hpp"

int main() {
    ft::pair<int, int> p0 = ft::make_pair<int, int>(1, 1);
    ft::pair<int, int> p1 = ft::make_pair<int, int>(2, 2);
    ft::pair<int, int> p2 = ft::make_pair<int, int>(3, 3);
    ft::pair<int, int> p3 = ft::make_pair<int, int>(4, 4);
    ft::pair<int, int> p4 = ft::make_pair<int, int>(5, 5);
    ft::pair<int, int> p5 = ft::make_pair<int, int>(6, 6);
    ft::BinarySearchTree<int, int> t;
    t.insert(p0);
    t.insert(p1);
    t.insert(p2);
    t.insert(p3);
    t.insert(p4);
    t.insert(p5);

    for (size_t i = 1; i < t.size() + 1; i++)
        std::cout << t[i] << std::endl;
}