#include <iostream>
#include "C:\Users\lucky\source\repos\Doubly Linked List\Doubly Linked List\Doubly Linked List.h"


	Node* CreateNode(int data) {
		Node* NewNode = new Node;
		NewNode->data = data; //데이터를 저장한다.
		NewNode->NextNode = NULL; //다음 노드에 대한 포인터는 NULL로 초기화한다.
		return NewNode; //노드 주소 반환.
	}



	void DestroyNode(Node* Node)
	{
		free(Node);
	}

	void AppendNode(Node** Head, Node* NewNode)
	{
		if ((*Head) == NULL) //헤드 노드가 NULL이라면 새로운 노드가 Head이다.
		{
			*Head = NewNode;
		}
		else
		{
			Node* Tail = (*Head); //테일을 찾아 NewNode 연결하기.
			while (Tail->NextNode != NULL)
			{
				Tail = Tail->NextNode;
			}
			Tail->NextNode = NewNode;
			NewNode->PrevNode = Tail;
		}
	}

	void InsertAfter(Node* current, Node* NewNode)
	{
		NewNode->NextNode = current->NextNode;
		NewNode->PrevNode = current;
		if (current->NextNode != NULL)
		{
			current->NextNode->PrevNode = NewNode;
		}
		current->NextNode = NewNode;
	}

	void InsertNewHead(Node** Head, Node* NewHead)
	{
		if (*Head == NULL) {
			*Head = NewHead;
		}
		else {
			NewHead->NextNode = *Head;
			*Head = NewHead;
		}
	}

	void RemoveNode(Node** Head, Node* Remove)
	{
		if (*Head == Remove) {
			*Head = Remove->NextNode;
			if ((*Head) != NULL)
				(*Head)->PrevNode = NULL;

			Remove->PrevNode = NULL;
			Remove->NextNode = NULL;
		}
		else
		{
			Node* Temp = Remove;
			
			if (Remove->PrevNode != NULL)
				Remove->PrevNode->NextNode = Temp->NextNode;
			if (Remove->NextNode != NULL)
				Remove->NextNode->PrevNode = Temp->PrevNode;
			Remove->PrevNode = NULL;
			Remove->NextNode = NULL;
		}
	}

	Node* GetNodeAt(Node* Head, int Location)
	{
		Node* current = Head;

		while (current != NULL && (--Location) >= 0)
		{
			current = current->NextNode;
		}
		return current;
	}

	int GetNodeCount(Node* Head)
	{
		unsigned int count = 0;
		Node* current = Head;

		while (current != NULL)
		{
			current = current->NextNode;
			count++;
		}

		return count;
	}
