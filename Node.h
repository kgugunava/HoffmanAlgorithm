#ifndef Node_H
#define Node_H

class Node {
public:
    Node();

    Node(int freq, unsigned char value);

    void add_number(unsigned char value);

    int number_of_freq() const;

    char number_of_value() const;

    void setParent(Node *node);

    void setLeft(Node *node);

    void setRight(Node *node);

    void setFreq(int value);

    Node *getLeft() const;

    Node *getRight() const;

private:
    Node *right;
    Node *left;
    Node *parent;
    int freq;
    unsigned char symb;
};


#endif Node_H
