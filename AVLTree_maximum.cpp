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

Created by 주시현 on 11/20/21.
 */



#include "AVLTree.h"
#include <iostream>

int AVLTree::maximum() {
    int depth;
    return maximum(root, depth);
}

// AVLTree에서 최댓값을 출력 및 리턴하는 함수
// 최댓값이 존재하는 오른쪽 노드까지 파고들게 구현 진행
int AVLTree::maximum(NodePointer curNode, int &depth) {
    depth = 0;

    while (curNode->right != nullptr) {
        curNode = curNode->right;
        depth++;
    }

    std::cout << curNode->key << " " << depth << std::endl;
    return curNode->key;
}
