#include "stdafx.h"
#pragma once
#ifndef  BSTNODE_H
#define BSTNODE_H

#include <iostream>
using namespace std;

template<typename T>
class bstNode
{
public:
	bstNode();
	bstNode(const T & newVal, bstNode<T> * leftVal = nullptr, bstNode<T> * rightVal = nullptr);
	~bstNode();

public:
	T elementVal;
	bstNode<T> * left;
	bstNode<T> * right;
};

template<typename T>
inline bstNode<T>::bstNode()
{
	left = nullptr;
	right = nullptr;
}

template<typename T>
inline bstNode<T>::bstNode(const T & newVal, bstNode<T>* leftVal, bstNode<T>* rightVal)
{
	elementVal = newVal;
	left = leftVal;
	right = rightVal;
}

template<typename T>
inline bstNode<T>::~bstNode()
{
	left = nullptr;
	right = nullptr;
}

#endif 
