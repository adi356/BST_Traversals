#ifndef NODE_H
#define NODE_H

#include <set>
#include <string>
#include <stdio.h>

using namespace std;

struct node {
    int key_value;
    set<string> words;
    node *left;
    node *right;
};

#endif /*NODE_H*/