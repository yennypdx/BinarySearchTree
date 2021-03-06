#include "stdafx.h"
#pragma once

#define _CRTDBG_MAP_ALLOC
#include <iostream>
#include <crtdbg.h>
#include <cassert>
#include <queue>
#include <stack>
#include "BinaryST.h"
#include "Exception.h"
using namespace std;

void PrintTestHeader(const char *testName)
{
	cout << "\n************* " << testName << " ************" << endl;
}

void PrintTestPass(const char * test)
{
	cout << "\t" << test << ": TEST PASS" << endl;
}

void PrintTestPassForGoodMeasure(const char * test)
{
	cout << "\t" << test << ": TEST FAIL" << endl;
}

void PrintTestFail(const char * test, const char * message)
{
	cerr << message << endl;
	cerr << "\t" << test << ": TEST FAIL" << endl;;
}

void PrintTestFailForGoodMeasure(const char * test, const char * message)
{
	cerr << message << endl;
	cerr << "\t" << test << ": TEST PASS" << endl;;
}

void testingGenericInsertion()
{
	const char * test = "Testing Generic Value Insertion";
	PrintTestHeader(test);
	try
	{
		binaryST<int> * atree = new binaryST<int>();
		cout << "Case: Inserting values { 5, 4, 3, 2, 1 }" << endl;
		for (int i = 5; i > 0; i--) {
				atree->insert(i);		
		}

		cout << "Test tool: isEmpty()" << endl << endl;
		assert(atree->isEmpty() != true);
		PrintTestPass(test);
		delete atree;
	}
	catch (Exception e) {
		PrintTestFail(test, e.getMessage());
	}
}

void testingPreorder()
{
	const char * test = "Testing Preorder Method";
	PrintTestHeader(test);

	binaryST<int> * atree = new binaryST<int>();
	cout << "Case: Inserting values of 20, 12, 25, 11, 18, 22, consecutively." << endl;
	atree->insert(20);
	atree->insert(12);
	atree->insert(25);
	atree->insert(11);
	atree->insert(18);
	atree->insert(22);
		
	cout << "Test tool: isEmpty() and preorder()" << endl << endl;
	cout << "Printing elements preorder: " << endl;
	atree->preorder();
	assert(atree->isEmpty() != true);
	cout << endl << endl;
	PrintTestPass(test);
	delete atree;
}

void testingInorder()
{
	const char * test = "Testing Inorder Method";
	PrintTestHeader(test);
	
	binaryST<int> * atree = new binaryST<int>();
	cout << "Case: Inserting values of 20, 12, 25, 11, 18, 22, consecutively." << endl;
	atree->insert(20);
	atree->insert(12);
	atree->insert(25);
	atree->insert(11);
	atree->insert(18);
	atree->insert(22);

	cout << "Test tool: isEmpty() and inorder()" << endl << endl;
	cout << "Printing elements inorder: " << endl;
	atree->inorder();
	assert(atree->isEmpty() != true);
	cout << endl << endl;
	PrintTestPass(test);
	delete atree;
}

void testingPostorder()
{
	const char * test = "Testing Postorder Method";
	PrintTestHeader(test);
		
	binaryST<int> * atree = new binaryST<int>();
	cout << "Case: Inserting values of 20, 12, 25, 11, 18, 22, consecutively." << endl;
	atree->insert(20);
	atree->insert(12);
	atree->insert(25);
	atree->insert(11);
	atree->insert(18);
	atree->insert(22);

	cout << "Test tool: isEmpty() and postorder()" << endl << endl;
	cout << "Printing elements postorder: " << endl;
	atree->postorder();
	assert(atree->isEmpty() != true);
	cout << endl << endl;
	PrintTestPass(test);
	delete atree;
}

void testingBreadthfirst()
{
	const char * test = "Testing Breadth-First Method";
	PrintTestHeader(test);

	binaryST<int> * atree = new binaryST<int>();
	cout << "Case: Inserting values of 20, 12, 25, 11, 18, 22, consecutively." << endl;
	atree->insert(20);
	atree->insert(12);
	atree->insert(25);
	atree->insert(11);
	atree->insert(18);
	atree->insert(22);

	cout << "Test tool: isEmpty() and breadthfirst()" << endl << endl;
	cout << "Printing elements breadthfirst: " << endl;
	atree->breadthfirst();
	assert(atree->isEmpty() != true);
	cout << endl << endl;
	PrintTestPass(test);
	delete atree;
}

void testingDeletion()
{
	const char * test = "Testing Deletion Method";
	PrintTestHeader(test);

	binaryST<int> * atree = new binaryST<int>();
	cout << "Case: Inserting values of 20, 12, 25, 11, 18, 22, consecutively." << endl;
	atree->insert(20);
	atree->insert(12);
	atree->insert(25);
	atree->insert(11);
	atree->insert(18);
	atree->insert(22);
	
	cout << "Test tool: isEmpty(), findAndDeleteNode() and inorder()" << endl << endl;
	cout << "Deleting 18 from the tree..." << endl;
	cout << "Printing elements inorder: " << endl;
	atree->findAndDeleteNode(18);
	atree->inorder();
	assert(atree->isEmpty() != true);
	cout << endl << endl;
	PrintTestPass(test);
	delete atree;
}

void testingPurgeTree()
{
	const char * test = "Testing Tree Purging Method";
	PrintTestHeader(test);

	binaryST<int> * atree = new binaryST<int>();
	cout << "Case: Inserting values of 20, 12, 25, 11, 18, 22, consecutively." << endl;
	atree->insert(20);
	atree->insert(12);
	atree->insert(25);
	atree->insert(11);
	atree->insert(18);
	atree->insert(22);

	cout << "Test tool: purgeTree() and isEmpty()" << endl << endl;
	atree->purgeTree(atree->getRoot());
	assert(atree->isEmpty() == true);
	cout << "Tree is emptied." << endl << endl;
	PrintTestPass(test);
	delete atree;
}
//Rainy day test
void testingEmptyTreeDeletion()
{
	const char * test = "Testing Empty Tree Deletion";
	PrintTestHeader(test);
	
	binaryST<int> * atree = new binaryST<int>();
	cout << "Case: Creating a tree with no values." << endl;
	cout << "Test tool: findAndDeleteNode()" << endl << endl;

	try
	{
		cout << "Deleting 11 from the tree..." << endl;
		atree->findAndDeleteNode(11);
	
		assert(atree->isEmpty() == true);
		PrintTestPassForGoodMeasure(test);
	}
	catch (Exception e)
	{
		PrintTestFailForGoodMeasure(test, e.getMessage());
	}
	delete atree;
}

void RunTest()
{
	testingGenericInsertion();
	testingPreorder();
	testingInorder();
	testingPostorder();
	testingBreadthfirst();
	testingDeletion();
	testingPurgeTree();
	testingEmptyTreeDeletion();
}

int main() {

	RunTest();

	_CrtSetReportMode(_CRT_WARN, _CRTDBG_MODE_FILE);
	_CrtSetReportFile(_CRT_WARN, _CRTDBG_FILE_STDOUT);
	_CrtDumpMemoryLeaks();

	system("pause");
	return 0;
}