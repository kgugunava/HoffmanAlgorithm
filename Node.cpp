#include "Node.h"
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>


Node::Node() {
	freq = 0;
	symb = '\0';
	right = nullptr;
	left = nullptr;
	parent = nullptr;
}

void Node::add_number(unsigned char value) { // find necessary Node and its frequency += 1
	this->freq++;
	if (!this->symb)
		this->symb = value;
}

int Node::number_of_freq() const {
	return this->freq;
}

char Node::number_of_value() const {
	return this->symb;
}

void Node::setParent(Node *node) {
	this->parent = node;
}

void Node::setLeft(Node *node) {
	this->left = node;
}

void Node::setRight(Node *node) {
	this->right = node;
}

void Node::setFreq(int value) {
	this->freq = value;
}

Node* Node::getLeft() const
{
	return this->left;
}

Node* Node::getRight() const
{
	return this->right;
}

Node::Node(int freq, unsigned char value) {
	this->freq = freq;
	symb = value;
}
