#include "BinarySearchTree.hpp"

int main() {
    ft::pair<int, int> p = ft::make_pair<int, int>(1, 2);
    ft::BinarySearchTree<int, int> t;
    t.insert(p);

    std::cout << t[1] << std::endl;
}