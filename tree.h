#ifndef TREE_H
#define TREE_H

#include <string.h>
#include "node.h"

class tree {
    public:
        tree();
        void buildTree(int key, string word);
        node *search(int key);
        void destroy_tree();
        void printInorder(struct node* node, FILE *outFile);
        void printPreorder(struct node* node, FILE *outFile);
        void printPostorder(struct node* node, FILE *outFile);
        node * getRoot(tree myTree);
        int getLevelUtil(struct node * node, int key_value, int level);
        int getLevel(struct node *node, int key_value);

    private:
        void destroy_tree(node *leaf);
        void insert(int key, node *leaf, string word);
        void *search(int key, node *leaf);

        node *root;
};

#endif /*TREE_H*/