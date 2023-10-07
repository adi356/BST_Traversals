#include "tree.h"
#include "node.h"
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;

tree::tree() {
    root = NULL;
}

void tree::insert(int key, node *leaf, string word) {
    if (key < leaf -> key_value) {
        if (leaf->left != NULL)
            insert(key, leaf->left, word);
    else {
        leaf->left = new node;
        leaf->left->key_value=key;
        leaf->left->words.insert(word);
        leaf->left->left = NULL;
        leaf->left->right = NULL;
    }
    } else if (key > leaf->key_value) {
        if(leaf->right != NULL)
            insert(key, leaf->right, word);
        else {
            leaf->right = new node;
            leaf->right->key_value = key;
            leaf->right->words.insert(word);
            leaf->right->left = NULL;
            leaf->right->right = NULL;
        }
    } else {
        leaf->words.insert(word);
    }
}

void tree::buildTree(int key, string word) {
    if (root != NULL)
        insert(key, root, word);
    else {
        root = new node;
        root->key_value = key;
        root->words.insert(word);
        root->left = NULL;
        root->right = NULL;
    }
}

void tree::printInorder(struct node* node, FILE *outFile) {
    if (node == NULL)
        return;
    
    printInorder(node->left, outFile);
    for (set<string>::const_iterator it=node->words.begin(); it != node->words.end(); ++it) {
        int depth = getLevel(root, int(node->key_value));
        string word = *it;
        int wordLength = int(word.length());

        if (word == *node->words.begin()) {
            fprintf(outFile, "%*c%d: %s ", depth*2, ' ', wordLength, word.c_str());
        } else {
            fprintf(outFile, "%s ", word.c_str());
        }
    }
    fprintf(outFile, "\n");

    printInorder(node->right, outFile);
}

void tree::printPreorder(struct node* node, FILE *outFile) {
    if (node == NULL)
        return;
    
    for (set<string>::const_iterator it=node->words.begin(); it != node->words.end(); ++it) {
        int depth = getLevel(root, int(node->key_value));
        string word = *it;
        int wordLength = int(word.length());

        if (word == *node->words.begin()) {
            fprintf(outFile, "%*c%d: %s ", depth*2, ' ', wordLength, word.c_str());
        } else {
            fprintf(outFile, "%s", word.c_str());
        }
    }
    fprintf(outFile, "\n");
    printPreorder(node->left, outFile);
    printPreorder(node->right, outFile);
}

void tree::printPostorder(struct node* node, FILE *outFile) {
    if (node == NULL)
        return;
    printPostorder(node->left, outFile);
    printPostorder(node->right, outFile);


    for (set<string>::const_iterator it=node->words.begin(); it != node->words.end(); ++it) {
        int depth = getLevel(root, int(node->key_value));

        string word = *it;
        int wordLength = int(word.length());

        if (word == *node->words.begin()) {
            fprintf(outFile, "%*c%d: %s ", depth*2, ' ', wordLength, word.c_str());
        } else {
            fprintf(outFile, "%s ", word.c_str());
        }
    }
    fprintf(outFile, "\n");
}

node * tree::getRoot(tree bstTree) {
    return bstTree.root;
}

int tree::getLevelUtil(struct node * node, int key_value, int level) {
    if (node == NULL)
        return 0;
    if (node->key_value == key_value)
        return level;
    int downlevel = getLevelUtil(node->left, key_value, level + 1);
    if (downlevel != 0)
        return downlevel;
    downlevel = getLevelUtil(node->right, key_value, level + 1);
    return downlevel;
}

int tree::getLevel(struct node *node, int key_value){
    return getLevelUtil(node, key_value, 0);
}