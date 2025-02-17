

#ifndef Node_H
#define Node_H

class Node {
public:
	Node() {
		data = '\0';
		left = nullptr;
		right = nullptr;
		freq = 0;
	}

	Node(char value, int f) {
		data = value;
		freq = f;
		left = nullptr;
		right = nullptr;
	}

	Node(Node* one, Node* two) {
		freq = one->getFreq() + two->getFreq();
		data = '\0';
		left = one;
		right = two;
	}

	Node(const Node& ref) {
		this->data = ref.getData();
		this->freq = ref.getFreq();
		this->left = ref.left;
		this->right = ref.right;
	}

	void addFreq(){freq++;};

	//геттеры
	Node* getLeft()const{return left;}
	Node* getRight()const{return right;}
	char getData()const {return data;}
	int getFreq()const{return freq;}

	//сеттеры
	void setLeft(Node* l){left = l;}
	void setRight(Node* r){right = r;}
	void setData(char d){data = d;}
	void setFreq(int f){freq = f;}

private:
	char data;
	Node* left;
	Node* right;
	int freq;
};


#endif //Node_H
