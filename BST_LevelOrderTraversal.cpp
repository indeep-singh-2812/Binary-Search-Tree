//Example program to provide source code for Level Order Traversal for Binary Search Tree. 
//We have used queue to store the current BST node and its child nodes. Once the current node is traversed, we will pop the current node. 

//Author - Indeep Singh
//Date - 07/06/2017
#include<iostream>
#include<queue>
#include<stdio.h>

using namespace std;

//structure of a Binary Search Tree.
struct BST{
	int data;
	BST* left;
	BST* right;
};

//method to create a new Node of BST using the value provided by user.
BST* GetNewNode(int value){
	BST* newNode = new BST();
	newNode->data = value;
	newNode->right = NULL;
	newNode->left = NULL;
	
	return newNode;
}

//method to insert the newly created node at its relevant position according to the value it has.
BST* InsertValue(int value, BST* root){
	if(root == NULL){
		root = GetNewNode(value);
	} else if(value <= root->data){
		root->left = InsertValue(value, root->left);
	} else {
		root->right = InsertValue(value, root->right);
	}	
	return root;
}

//method to implement Level Order Traversal for a Binary Search Tree.
void LevelOrderTraversal(BST* root){
	if(root == NULL){
		return;
	} 
	queue<BST*> Queue;
	Queue.push(root);

	while(!Queue.empty()){ // we will traverse the BST untill queue is empty.
		BST* current = Queue.front();
	
	//for pushing the child nodes of the current node into the queue.
		if(current->left!=NULL) { 
				Queue.push(current->left);
		}
		if(current->right!=NULL) {
				Queue.push(current->right);
		}

	// do operation on the current node i.e. display and pop it from the queue as its traversed for now.
		cout<<current->data<<"\t";
		Queue.pop();
	}	
}

int main(){
	BST* root = NULL;
	root = InsertValue(10,root);
	root = InsertValue(15,root);
	root = InsertValue(13,root);
	root = InsertValue(20,root);
	root = InsertValue(25,root);
	root = InsertValue(8,root);
	
	LevelOrderTraversal(root); // 10	8	15	13	20	25 	
	return 0;
}


