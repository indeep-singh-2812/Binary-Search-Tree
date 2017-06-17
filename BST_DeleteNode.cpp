#include<stdio.h>
#include<iostream>

using namespace std;

//structure of a BST
struct BST{
	int data;
	BST* right;
	BST* left;
};

//method to create a new node.
BST* GetNewNode(int value){
	BST* newNode = new BST();
	newNode->data = value;
	newNode->left = newNode->right = NULL;
	
	return newNode;
}

//method to insert the newly created node.
BST* InsertNode(int value, BST* root){
	if(root == NULL){
		root = GetNewNode(value);
	} else if(value <= root->data){
		root->left = InsertNode(value,root->left);
	} else {
		root->right = InsertNode(value,root->right);
	}
	
	return root;
}

BST* FindMin(BST* root){
	int minValue = -1;
	if(root == NULL){
		cout<<"Tree is empty. ";
	} else{
			while(root->left != NULL){
				root = root->left;
			}
			minValue = root->data;
	}
	return root;
}

BST* DeleteNode(BST* root, int value){
	if(root == NULL) return root;
	else if(value < root->data) DeleteNode(root->left, value);
	else if(value > root->data) DeleteNode(root->right, value);
	else{
		if(root->left == NULL && root->right == NULL){
			delete root;
			root = NULL;
		} else if(root->left == NULL){
			BST* temp = root;
			root= root->right;
			delete temp;
		} else if(root->right == NULL){
			BST* temp = root->left;
			root = root->left;
			delete temp;  
		} else{
			BST* temp = FindMin(root->right);
			root->data = temp->data;
			root->right = DeleteNode(root->right,temp->data);
		}
	}
	
	return root;	
}

int main(){
	BST* root = NULL;
	root = InsertNode(10, root);	
	root = InsertNode(15, root);
	root = InsertNode(20,root);
	root = InsertNode(25,root);
	root = InsertNode(35,root);
	root = InsertNode(8,root);
	
	return 0;
}
