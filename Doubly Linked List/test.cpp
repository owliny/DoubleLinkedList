#include <iostream>
#include "C:\Users\lucky\source\repos\Doubly Linked List\Doubly Linked List\Doubly Linked List.h"

using namespace std;

int main(void) {
	int i = 0;
	int count = 0;
	Node* List = NULL;
	Node* current = NULL;
	Node* NewNode = NULL;

	for (i = 0; i < 5; i++) {
		NewNode = CreateNode(i);
		AppendNode(&List, NewNode);
	}
	/* 리스트 출력 */
	count = GetNodeCount(List);
	for (i = 0; i < count; i++)
	{
		current = GetNodeAt(List, i);
		cout << "List" << i << ":" << current->data << endl;
	}

	/* 리스트에서 세 번째 칸 뒤에 노드 삽입 */
	cout << "\n Inserting 3000 After [2]... \n" << endl;
	current = GetNodeAt(List, 2);
	NewNode = CreateNode(3000);
	InsertAfter(current, NewNode);

	/* 리스트 출력 */
	count = GetNodeCount(List);
	for (i = 0; i < count; i++) {
		current = GetNodeAt(List, i);
		cout << "List" << i << ":" << current->data << endl;
	}

	/* 모든 노드를 메모리에서 제거 */
	cout << "\n Destroying List...\n" << endl;
	count = GetNodeCount(List);

	for (i = 0; i < count; i++) {
		current = GetNodeAt(List, 0);
		if (current != NULL) {
			RemoveNode(&List, current);
			DestroyNode(current);
		}
	}

	return 0;
}
