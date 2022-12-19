#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include<iostream>

struct Node
{
	int data;
	struct Node* PrevNode;
	struct Node* NextNode;
};

Node* CreateNode(int data);
void DestroyNode(Node* Node);
void AppendNode(Node** Head, Node* Newnode);
void InsertAfter(Node* Current, Node* NewNode);
void InsertNewHead(Node** Head, Node* NewHead);
void RemoveNode(Node** Head, Node* Remove);
Node* GetNodeAt(Node* Head, int Location);
int GetNodeCount(Node* Head);
#endif
