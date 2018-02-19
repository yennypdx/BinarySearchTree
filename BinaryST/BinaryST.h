#include "stdafx.h"
#pragma once
#ifndef  BINARYST_H
#define BINARYST_H

#include <queue>
#include <stack>
#include <iostream>
#include "Exception.h"
#include "bstNode.h"
using namespace std;

template<typename T>
class Stack : public stack<T>
{};

template<typename T>
class Queue : public queue<T>
{
public:
	T dequeue()
	{
		T tempQueue = queue<T>::front();
		queue<T>::pop();

		return tempQueue;
	}

	void enqueue(const T & inVal)
	{
		queue<T>::push(inVal);
	}
};

template<typename T>
class binaryST
{
public:
	binaryST() { root = nullptr; }
	~binaryST();
public:
	void preorder() { preorder(root); printPreorder(root); }
	void inorder() { inorder(root); printInorder(root); }
	void postorder() { postorder(root); printPostorder(root); }
	void breadthfirst();
public:
	bstNode<T> * getRoot() { return root; }
	bool isEmpty() const;
	T * search(bstNode<T> * inNode, const T & inElm) const;
public:
	int treeHeight(bstNode<T> * inNode);
	void purgeTree(bstNode<T> * inNode);
	void insert(const T & inElm);
	void insertRecursively(bstNode<T>* inNode, T inElm);
	void deleteNode(bstNode<T> * &inNode);
	bool findAndDeleteNode(const T & inElm);
public:
	void printPreorder(bstNode<T> const * const inNode);
	void printInorder(bstNode<T> const * const inNode);
	void printPostorder(bstNode<T> const * const inNode);
	
protected:
	bstNode<T> * root;
	void preorder(bstNode<T> * inNode);
	void inorder(bstNode<T> * inNode);
	void postorder(bstNode<T> * inNode);
	virtual void visit(bstNode<T> * inNode) { inNode->elementVal; }
};

template<typename T>
inline binaryST<T>::~binaryST()
{
	purgeTree(root);
}

template<typename T>
inline void binaryST<T>::breadthfirst()
{
	Queue<bstNode<T> *>  queue; //temporary container
	bstNode<T> * traverse = root;

	if (traverse != nullptr) {
		queue.enqueue(traverse);

		while (!queue.empty())
		{
			traverse = queue.dequeue();
			cout << traverse->elementVal << ", ";

			if (traverse->left != nullptr) {
				queue.enqueue(traverse->left);
			}
			if (traverse->right != nullptr) {
				queue.enqueue(traverse->right);
			}
		}
	}
}
template<typename T>
inline bool binaryST<T>::isEmpty() const
{
	 return root == nullptr;
}

template<typename T>
inline T * binaryST<T>::search(bstNode<T>* inNode, const T & inElm) const
{
	while (inNode != nullptr)
	{
		if (inElm == inNode->elementVal) {
			return &inNode->elementVal;
		}
		else if (inElm < inNode->elementVal) {
			inNode = inNode->left;
		}
		else {
			inNode = inNode->right;
		}
	}
	return nullptr;
}

template<typename T>
inline int binaryST<T>::treeHeight(bstNode<T>* inNode)
{
	if (!inNode) {
		return -1;
	}

	int leftHeight = treeHeight(inNode->left);
	int rightHeight = treeHeight(inNode->right);
	int totalHeight = 1 + max(leftHeight, rightHeight);

	return totalHeight;
}

template<typename T>
inline void binaryST<T>::purgeTree(bstNode<T>* inNode)
{
	root = inNode;
	while (inNode != nullptr)
	{
		if (inNode->left != nullptr) {
			purgeTree(inNode->left);
		}
		if (inNode->right != nullptr) {
			purgeTree(inNode->right);
		}
				
		delete inNode;
		inNode = nullptr;
		root = inNode;
	}
}

template<typename T>
inline void binaryST<T>::insert(const T & inElm)
{
	bstNode<T> * currNode = root;
	bstNode<T> * prevNode = nullptr;
	bstNode<T> * newNode = new bstNode<T>(inElm);

	//find a place to insert the node
	while (currNode != nullptr)
	{
		prevNode = currNode;
		if (newNode->elementVal < currNode->elementVal) {
			currNode = currNode->left;
		}
		else {
			currNode = currNode->right;
		}
	}

	//if tree is empty do this
	if (root == nullptr) {
		root = newNode;
	}
	else if (newNode->elementVal < prevNode->elementVal) {
		prevNode->left = newNode;
	}
	else {
		prevNode->right = newNode;
	}
}

template<typename T>
inline void binaryST<T>::insertRecursively(bstNode<T>* inNode, T inElm)
{
	if (inNode == nullptr) {
		binaryST<T>* newNode;
		newNode->elementVal = inElm;
		newNode = inNode;
	}
	else {
		if (inElm < inNode->elementVal) {
			insertRecursively(inNode->left, inElm);
		}
		else {
			insertRecursively(inNode->right, inElm);
		}
	}
}

template<typename T>
inline void binaryST<T>::deleteNode(bstNode<T> * &inNode)
{
	bstNode<T> * tempNode = inNode;

	if (inNode != 0) {
		if (!inNode->right) {
			inNode = inNode->left;
		}
		else if (inNode->left = 0) {
			inNode = inNode->right;
		}
		else {
			tempNode = inNode->left;
			while (tempNode->right != 0) {
				tempNode = tempNode->right;
			}

			tempNode->right = inNode->right;
			tempNode = inNode;
			inNode = inNode->left;
		}
		delete tempNode;
	}
}

template<typename T>
inline bool binaryST<T>::findAndDeleteNode(const T & inElm)
{
	bstNode<T> * currNode;
	bstNode<T> * prevNode;
	bool found = false;

	if (root == nullptr)	{
		throw Exception("Exception caught: Tree is empty.");
	}
	else 	{
		prevNode = root;
		currNode = root;

		while (currNode != nullptr && currNode->elementVal != inElm)
		{
			if (currNode->elementVal == inElm) {
				found = true;
			}
			else {
				prevNode = currNode;

				if (currNode->elementVal > inElm) {
					currNode = currNode->left;
				}
				else {
					currNode = currNode->right;
				}
			}
		}

		if (currNode == nullptr) {
			throw Exception("Exception caught: The node has no data");
		}
		else if (currNode->elementVal == inElm) {
			if (root == currNode) {
				deleteNode(root);
			}
			else if (prevNode->elementVal > inElm) {
				deleteNode(prevNode->left);
			}
			else {
				deleteNode(prevNode->right);
			}
		}
		return found;
	}
}

template<typename T>
inline void binaryST<T>::printPreorder(bstNode<T> const * const inNode)
{
	if (inNode != nullptr) {
		cout << inNode->elementVal;
	
		if (inNode->left || inNode->right)
			cout << ", ";	
		printPreorder(inNode->left);
		
		if (inNode->left && inNode->right)
			cout << ", ";
		printPreorder(inNode->right);
	}
}

template<typename T>
inline void binaryST<T>::printInorder(bstNode<T> const * const inNode)
{
	if (inNode != nullptr) {
		printInorder(inNode->left);

		if (inNode->left || inNode->right)
			cout << ", ";
		cout << inNode->elementVal;
	
		if (inNode->left && inNode->right)
			cout << ", ";
		printInorder(inNode->right);
	}
}

template<typename T>
inline void binaryST<T>::printPostorder(bstNode<T> const * const inNode)
{
	if (inNode != nullptr) {
		printPostorder(inNode->left);
	
		if (inNode->left && inNode->right)
			cout << ", ";
		printPostorder(inNode->right);

		if (inNode->left || inNode->right)
			cout << ", ";
		cout << inNode->elementVal;
	}
}

template<typename T>
inline void binaryST<T>::preorder(bstNode<T>* inNode)
{
	if (inNode != nullptr) {
		visit(inNode);
		preorder(inNode->left);
		preorder(inNode->right);
	}
}

template<typename T>
inline void binaryST<T>::inorder(bstNode<T>* inNode)
{
	if (inNode != nullptr) {
		inorder(inNode->left);
		visit(inNode);
		inorder(inNode->right);
	}
}

template<typename T>
inline void binaryST<T>::postorder(bstNode<T>* inNode)
{
	if (inNode != nullptr) {
		postorder(inNode->left);
		postorder(inNode->right);
		visit(inNode);
	}
}

#endif