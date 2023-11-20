/*
MIT License

Copyright (c) 2023 Inha-Open-Source-Team-BBBig

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.

Created by 박준영 on 11/18/23.
 */

#include "AVLTree.h"
#include "iostream"

using namespace std;

int height(Node *N) {
    if (N == NULL) {
        return 0;
    }
    return N->height;
}

int getBalanceFactor(Node *N) {
    if (N == NULL) {
        return 0;
    }
    return height(N->left) - height(N->right);
}

Node *newNode(int key) {
    Node *node = new Node();
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;
    return node;
}

Node *rightRotate(Node *y) {
    Node *x = y->left;
    Node *T2 = x->right;
    x->right = y;
    y->left = T2;
    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;
    return x;
}

Node *leftRotate(Node *x) {
    Node *y = x->right;
    Node *T2 = y->left;
    y->left = x;
    x->right = T2;
    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;
    return y;
}

int getDepth(Node *node, int key, int depth) {
    if (node == NULL) {
        return -1;
    }

    if (node->key == key) {
        return depth;
    }

    int downlevel = getDepth(node->left, key, depth + 1);
    if (downlevel != -1) {
        return downlevel;
    }

    downlevel = getDepth(node->right, key, depth + 1);
    return downlevel;
}

Node *insertNode(Node *node, int key) {
    if (node == NULL) {
        return (newNode(key));
    }
    if (key < node->key) {
        node->left = insertNode(node->left, key);
    } else if (key > node->key) {
        node->right = insertNode(node->right, key);
    } else {
        return node;
    }

    node->height = 1 + max(height(node->left), height(node->right));

    int balanceFactor = getBalanceFactor(node);

    if (balanceFactor > 1) {
        if (key < node->left->key) {
            return rightRotate(node);
        } else if (key > node->left->key) {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }
    }

    if (balanceFactor < -1) {
        if (key > node->right->key) {
            return leftRotate(node);
        } else if (key < node->right->key) {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }
    }

    return node;
}

Node *AVLTree::insert(int key) {
    root = insertNode(root, key);
    int depth = getDepth(root, key, 1);
    cout << depth << '\n';
    return root;
}

void printTree(Node *root, string indent, bool last) {
    if (root != nullptr) {
        cout << indent;
        if (last) {
            cout << "R----";
            indent += "   ";
        } else {
            cout << "L----";
            indent += "|  ";
        }
        cout << root->key << endl;
        printTree(root->left, indent, false);
        printTree(root->right, indent, true);
    }
}

int main() {
    AVLTree avlTree;
    avlTree.insert(50);
    printTree(avlTree.root, "", true);
    avlTree.insert(30);
    printTree(avlTree.root, "", true);
    avlTree.insert(20);
    printTree(avlTree.root, "", true);
    avlTree.insert(40);
    printTree(avlTree.root, "", true);
    avlTree.insert(70);
    printTree(avlTree.root, "", true);
    avlTree.insert(60);
    printTree(avlTree.root, "", true);
    avlTree.insert(80);
    printTree(avlTree.root, "", true);

    return 0;
}
