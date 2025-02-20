#ifndef Node_H
#define Node_H

class Node {
public:
    Node();

    Node(char value, int f);

    Node(Node* one, Node* two);

    Node(const Node& ref);

    void addFreq();

    //геттеры
    Node* getLeft() const;

    Node* getRight() const;

    char getData() const;

    int getFreq() const;

    //сеттеры
    void setLeft(Node* l);
    void setRight(Node* r);
    void setData(char d);
    void setFreq(int f);

private:
    char data;
    Node* left;
    Node* right;
    int freq;
};


#endif //Node_H