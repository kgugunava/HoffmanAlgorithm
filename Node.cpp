#include "Node.h"

Node::Node() {
    data = '\0';
    left = nullptr;
    right = nullptr;
    freq = 0;
}

Node::Node(char value, int f) {
    data = value;
    freq = f;
    left = nullptr;
    right = nullptr;
}

Node::Node(Node* one, Node* two) {
    freq = one->getFreq() + two->getFreq();
    data = '\0';
    left = one;
    right = two;
}

Node::Node(const Node& ref) {
    this->data = ref.getData();
    this->freq = ref.getFreq();
    this->left = ref.left;
    this->right = ref.right;
}

void Node::addFreq() {
    freq++;
}

Node* Node::getLeft() const {
    return left;
}

Node* Node::getRight() const {
    return right;
}

char Node::getData() const {
    return data;
}

int Node::getFreq() const {
    return freq;
}

void Node::setLeft(Node* l) {
    left = l;
}

void Node::setRight(Node* r) {
    right = r;
}

void Node::setData(char d) {
    data = d;
}

void Node::setFreq(int f) {
    freq = f;
}