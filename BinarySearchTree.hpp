#pragma once
#include <iostream>

namespace ft {
    template <class K, class T>
    class pair {
        public:
            using first_type = K;
            using second_type = T;
        public:
            first_type 	first;
            second_type second;
            pair(): first(), second() {}
            pair(const first_type& a, const second_type& b): first(a), second(b) {}
            template<class U, class V>
                pair (const pair<U, V>& pr): first(pr.first), second(pr.second) {
                    // first = (T1)pr.first;
                    // second = (T2)pr.second;
                    // *this = pr;
                }
            pair& operator=(const pair& pr) {
                if (this != &pr) {
                    this->first = pr.first;
                    this->second = pr.second;
                }
                return (*this);
            }
    };
    template<class K, class V>
    bool operator<(const pair<K, V>& x, const pair<K, V>& y) {
        return x.first < y.fisrt;
    }
    template <class T1,class T2>
        pair<T1,T2> make_pair (T1 x, T2 y)
        {
            return ( pair<T1,T2>(x,y) );
        }

    template<class pair>
    class Tree {
        public:
            using value_type = pair;
            using pointer = Tree<value_type>*;
        public:
            pointer __left;
            pointer __right;
            pointer __parent;
            value_type __pair;
        public:
            Tree(): __pair() {
                __left = __right = __parent = nullptr;
            }
            Tree(const value_type& val): __pair(val) {
                __left = __right = __parent = nullptr;
            }
            ~Tree() {}
    };
    template <class T>
    struct less {
        bool operator() (const T& x, const T& y) const {
            return x < y;
        }
    };
    template <class K, class V, class Compare = less< pair<K, V> > >
    class BinarySearchTree {
        public:
            using key_type = K;
            using value_type = V;
            using key_compare = Compare;
            using pair_type = pair<const key_type, value_type>;
            using pointer = Tree<pair_type>*;
            using size_type = std::size_t;
        private:
            key_compare cmp;
            pointer __root;
            pointer __begin;
            pointer __end;
            size_type __size;
            pointer __find(const key_type& key);
            void __insert(pointer node) {
                if (cmp(node->_data, __root->_data)) {
                    //
                }
            }
            void __remove(const pair_type& p);
        public:
            BinarySearchTree() {
                __root = nullptr;
                // __begin = nullptr;
                // __end = nullptr;
                __size = 0;
            }
            value_type& operator[](const key_type& key) {
                return __root->__pair.second;
            }
            ~BinarySearchTree() {
                // delete all pointers
            }
            pointer find(const key_type& key);
            void insert(const pair_type& p) {
                pointer node = new Tree<pair_type>(p);
                if (__root == nullptr)
                    __root = node;
                else
                    __insert(node);
            }
            void remove(const pair_type& p);
    };
}
