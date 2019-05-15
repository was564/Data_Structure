#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cmath>
using namespace std;

struct BTreeNode{
	BTreeNode *left;
	int data;
	BTreeNode *right;
} *root, *temp, *p;

BTreeNode* createNode(int data);
void order(BTreeNode *node, int n, int i);
void preorder(BTreeNode *root);

int main(){
	int arr[11] = { 0, };
	root = createNode(10);
	arr[1] = 10;
	temp = root;
	for (int i = 2; i <= 10; i++){
		order(root, 0, i);
	}

	preorder(root);

	return 0;
}

BTreeNode* createNode(int data){
	p = (BTreeNode*)malloc(sizeof(BTreeNode));
	p->left = nullptr;
	p->right = nullptr;
	p->data = data;
	return p;
}

void order(BTreeNode *node, int n, int i){
	if (n * 2 == i){
		node->left = createNode(i * 10);
		return;
	}
	else if (n * 2 + 1 == i){
		node->right = createNode(i * 10);
		return;
	}
	else if (n * 2 + 1 < i){
		return;
	}
	order(node->left, n * 2, i);
	order(node->right, n * 2 + 1, i);
}

void preorder(BTreeNode *root) {
	printf("%d", root->data);
	if (root->left != nullptr){
		preorder(root->left);
	}
	else if (root->right != nullptr){
		preorder(root->right);
	}
}