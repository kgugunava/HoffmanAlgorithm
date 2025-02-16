

#ifndef Node_H
#define Node_H

class Node {
public:
	Node() {
		char data = 0;
		Node* left = nullptr;
		Node* right = nullptr;
		int freq = 0;
	}

	Node(char value, int f) {
		data = value;
		freq = f;
		Node* left = nullptr;
		Node* right = nullptr;
	}

	//геттеры
	Node* getLeft()const{return left;}
	Node* getRight()const{return right;}
	int getData()const {return data;}
	int getFreq()const{return freq;}

	//сеттеры
	void setLeft(Node* l){left = l;}
	void setRight(Node* r){right = r;}
	void setData(int d){data = d;}
	void setFreq(int f){freq = f;}

private:
	char data = 0;
	Node* left = nullptr;
	Node* right = nullptr;
	int freq = 0;
};


#endif //Node_H
