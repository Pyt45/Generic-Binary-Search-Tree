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
        return x.first < y.first;
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
    template < class K, class V, class Compare = less< pair<K, V> >, class Keycomp = std::less<K> >
    class BinarySearchTree {
        public:
            using key_type = K;
            using value_type = V;
            using pair_compare = Compare;
            using key_compare = Keycomp;
            using pair_type = pair<const key_type, value_type>;
            using pointer = Tree<pair_type>*;
            using size_type = std::size_t;
        private:
            pair_compare cmp;
            key_compare kcmp;
            pointer __root;
            pointer __begin;
            pointer __end;
            size_type __size;
            pointer __find(const key_type& key, pointer root) const {
                if (root == nullptr)
                    return nullptr;
                if (root->__pair.first == key)
                    return root;
                if (kcmp(key, root->__pair.first))
                    return __find(key, root->__left);
                else
                    return __find(key, root->__right);
            }
            void __insert(pointer node, pointer root) {
                if (cmp(node->__pair, root->__pair)) {
                    if (root->__left == nullptr) {
                        root->__left = node;
                        node->__parent = root;
                    }
                    else
                        __insert(node, root->__left);
                } else {
                    if (root->__right == nullptr) {
                        root->__right = node;
                        node->__parent = root;
                    }
                    else
                        __insert(node, root->__right);
                }
            }
            void __remove(const pair_type& p);
        public:
            class NotFound: public std::exception {
                public:
                    virtual const char* what() const throw() override {
                        return "not found";
                    }
            };
            BinarySearchTree() {
                __root = nullptr;
                // __begin = nullptr;
                // __end = nullptr;
                __size = 0;
            }
            value_type& operator[](const key_type& key) const {
                pointer found = __find(key, __root);
                if (found)
                    return found->__pair.second;
                throw NotFound();
            }
            ~BinarySearchTree() {
                // delete all pointers
            }
            pointer find(const key_type& key) const {
                return __find(key, __root);
            }
            void insert(const pair_type& p) {
                pointer node = new Tree<pair_type>(p);
                if (__root == nullptr)
                    __root = node;
                else
                    __insert(node, __root);
                __size++;
            }
            void remove(const pair_type& p);
            size_type size() const {
                return __size;
            }
    };
}
