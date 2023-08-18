#include <iostream>

using namespace std;

class Node {
public:
	int Value;
	Node* Next;
	Node* Prev;

};
void DeleteNode(Node*& Head, Node* ToDelete) {
	if (Head == NULL || ToDelete == NULL) return;
	if (ToDelete == Head)
		Head = ToDelete->Next;
	if (ToDelete->Prev != NULL)
		ToDelete->Prev->Next = ToDelete->Next;
	if (ToDelete->Next != NULL)
		ToDelete->Next->Prev = ToDelete->Prev;
	delete ToDelete;
}
void DeleteFirstNode(Node*& Head) {
	if (Head == NULL) return;
	Node* First = Head;
	Head = First->Next;
	if (Head != NULL)
		Head->Prev = NULL;
	delete First;
}
void DeleteLastNode(Node*& Head) {
	if (Head == NULL) return;
	if (Head->Next == NULL) {
		delete Head;
		Head = NULL;
		return;
	}
	Node* Last = Head;
	while (Last->Next != NULL) {
		Last = Last->Next;
	}
	if (Last->Prev != NULL)
		Last->Prev->Next = NULL;
	delete Last;
}
void InsertAtFirst(Node*& Head, int Value) {
	Node* New_Node = new Node();
	New_Node->Next = Head;
	New_Node->Prev = NULL;
	New_Node->Value = Value;
	if (Head != NULL)
		Head->Prev = New_Node;
	Head = New_Node;
}
void InsertAfter(Node*& PrevNode, int Value) {
	if (PrevNode == NULL) {
		return;
	}
	Node* New_Node = new Node();
	New_Node->Value = Value;
	New_Node->Next = PrevNode->Next;
	if (PrevNode->Next != NULL)
		PrevNode->Next->Prev = New_Node;
	New_Node->Prev = PrevNode;
	PrevNode->Next = New_Node;
}
void InsertAtEnd(Node*& Head, int Value) {
	Node* New_Node = new Node();
	New_Node->Value = Value;
	New_Node->Next = NULL;
	if (Head == NULL) {
		New_Node->Prev = NULL;
		Head = New_Node;
	}
	else {
		Node* LastNode = Head;
		while (LastNode->Next != NULL) {
			LastNode = LastNode->Next;
		}
		New_Node->Prev = LastNode;
		LastNode->Next = New_Node;
	}
}
Node* Find(Node* Head, int Value) {
	while (Head != NULL) {
		if (Head->Value == Value)
		{
			return Head;
		}
		Head = Head->Next;
	}
	return NULL;
}
void PrintNodeDetails(Node* Head)
{

	if (Head->Prev != NULL)
		cout << Head->Prev->Value;
	else
		cout << "NULL";

	cout << " <--> " << Head->Value << " <--> ";

	if (Head->Next != NULL)
		cout << Head->Next->Value << "\n";
	else
		cout << "NULL";

}
void PrintListDetails(Node* Head)
{
	cout << "\n\n";
	while (Head != NULL) {
		PrintNodeDetails(Head);
		Head = Head->Next;
	}
}
void PrintList(Node* Head) {
	cout << "NULL <--> ";
	while (Head != NULL) {
		cout << Head->Value << " <--> ";
		Head = Head->Next;
	}
	cout << " NULL";
}

int   main() {
	Node* Head = NULL;
	InsertAtFirst(Head, 400);
	InsertAtFirst(Head, 300);
	InsertAtFirst(Head, 200);
	PrintList(Head);

	Node* Prev_Node = Find(Head, 400);
	InsertAfter(Prev_Node, 500);
	cout << "\n____________________________\n";
	PrintList(Head);

	InsertAtEnd(Head, 500000);
	cout << "\n____________________________\n";
	PrintList(Head);

	Node* Del = Find(Head, 300);
	DeleteNode(Head, Del);
	cout << "\n____________________________\n";
	PrintList(Head);

	DeleteFirstNode(Head);
	cout << "\n____________________________\n";
	PrintList(Head);

	DeleteLastNode(Head);
	cout << "\n____________________________\n";
	PrintList(Head);	
	
	DeleteLastNode(Head);
	cout << "\n____________________________\n";
	PrintList(Head);
	
	DeleteLastNode(Head);
	cout << "\n____________________________\n";
	PrintList(Head);


	system("pause>0");
	return 0;
};
