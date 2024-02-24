#include <iostream>
using namespace std;

template <typename T>
struct Node {
	T value;
	Node<T>* parent = nullptr;
	Node<T>* left = nullptr;
	Node<T>* right = nullptr;
};

template <typename T>
class BinaryTree {
	Node<T>* root = nullptr;
	int count = 0;

	void showAll(Node<T>* el) {
		cout << el->value << " ";
		if (el->left != nullptr) showAll(el->left);
		if (el->right != nullptr) showAll(el->right);
	}
public:
	void push(T value) {
		Node<T>* newNode = new Node<T>{ value };
		if (root == nullptr) {
			root = newNode;
			count++;
			return;
		}
		Node<T>* buf = root;
		while (true) {
			if (value > buf->value) {
				if (buf->right == nullptr) {
					buf->right = newNode;
					newNode->parent = buf;
					break;
				}
				buf = buf->right;
			}
			else {
				if (buf->left == nullptr) {
					buf->left = newNode;
					newNode->parent = buf;
					break;
				}
				buf = buf->left;
			}
		}
		count++;
	}
	Node<T>* search(T value) {
		Node<T>* buf = root;
		while (true)
		{
			if (value < buf->value) {
				if (buf->left != nullptr)
					buf = buf->left;
				else
					return buf;
			}
			else if (value > buf->value) {
				if (buf->right != nullptr)
					buf = buf->right;
				else
					return buf;
			}
			else if (value == buf->value)
				return buf;
			else if (value != buf->value)
				return NULL;
		}
	}
	void del(T value) {
		if (root == nullptr) return;
		Node<T>* it = search(value);
		Node<T>* buf = nullptr;

		if (it == nullptr) return;
		//удаление листового узла
		if (it->right == nullptr && it->left == nullptr) {
			if(it->parent->left == it)
				it->parent->left = nullptr;
			else if(it->parent->right == it)
				it->parent->right = nullptr;
			delete it;
		}
		//удаление узла с одним потомком (правым или левым)
		else if (it->left != nullptr && it->right == nullptr ||
				 it->left == nullptr && it->right != nullptr) {

			if (it == root) {
				if (it->left == nullptr && it->right != nullptr) {
					it = it->right;
					delete it;
				}
				else if (it->left != nullptr && it->right == nullptr) {
					it->parent->left = it->left;
					delete it;
				}
			}

			else if (it->value < root->value) {
				if (it->left == nullptr && it->right != nullptr) {
					it->parent->left = it->right;
					delete it;
				}
				else if (it->left != nullptr && it->right == nullptr) {
					it->parent->left = it->left;
					delete it;
				}
			}
			else if (it->value > root->value) {
				if (it->left == nullptr && it->right != nullptr) {
					it->parent->right = it->right;
					delete it;
				}
				else if (it->left != nullptr && it->right == nullptr) {
					it->parent->right = it->left;
					delete it;
				}
			}
		}
		//удаление узла с двумя потомками
		else if (it->left != nullptr && it->right != nullptr) {

			if (it->value < root->value) {
				buf = it->right;
				while (buf->left != nullptr)
					buf = buf->left;
				it->value = buf->value;
				buf->parent->left = buf->right;
				delete buf;
			}
			else if (it->value >= root->value) {
				buf = it->left;
				while (buf->right!= nullptr)
					buf = buf->right;
				it->value = buf->value;
				buf->parent->right = buf->left;
				delete buf;
			}
		}
		count--;
	}

	void show() {
		if (root != nullptr) showAll(root);
	}
};

int main() {

	BinaryTree<int> tree;

	int arr[]{35, 88, 97, 54, 23, 96, 34, 78, 56};
	for (int k = 0; k < size(arr); k++)
		tree.push(arr[k]);
	tree.show();
	cout << endl;
	tree.del(56);
	tree.show();
	cout << endl;
	tree.del(88);
	tree.show();
	cout << endl;
	tree.del(97);
	tree.show();
	cout << endl;
	tree.del(35);
	tree.show();
	cout << endl;
	system("pause");
	return 0;
}