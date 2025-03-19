#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* previous;

    Node(int value) {
        next = previous = nullptr;
        data = value;
    }
    Node() {
        next = previous = nullptr;
        data = 0;
    }
};

class DoublyLinkedList {
    Node* head;

public:

    DoublyLinkedList() {
        head = nullptr;
    }


    ~DoublyLinkedList() {
        Node* current = head;
        Node* next = nullptr;
        while (current != nullptr) {
            next = current->next;
            delete current;
            current = next;
        }
        head = nullptr;
    }

    void displayList() {
        Node* current = head;
        if (!head) {
            cout << "List is empty\n";
            return;
        }
        cout << "nullptr <- ";
        while (current->next != nullptr) {
            cout << current->data << " <-> ";
            current = current->next;
        }
        cout << current->data << " -> nullptr\n";
    }


    void insertAtBeginning(int value) {
        Node* newNode = new Node(value);
        newNode->next = head;
        if (head) {
            head->previous = newNode;
        }
        head = newNode;
    }

    void deleteFromBeginning() {
        if (!head) {
            cout << "List is empty!\n";
            return;
        }

        Node* tmp = head;
        head = head->next;
        head->previous = nullptr;
        delete tmp;
    }

    void insertAtEnd(int value) {
        Node* newNode = new Node(value);
        if (!newNode) {
            cout << "Allocation error!\n";
            return;
        }


        if (!head) {
            head = newNode;
            return;
        }


        Node* tmp = head;
        while (tmp->next) {
            tmp = tmp->next;
        }


        tmp->next = newNode;
        newNode->previous = tmp;

    }


    void deleteFromEnd() {
        if (!head) {
            cout << "List is empty!\n";
            return;
        }

        if (!head->next) {
            delete head;
            head = nullptr;
            return;
        }


        Node* tmp = head;

        while (tmp->next->next) {
            tmp = tmp->next;
        }
        delete tmp->next;
        tmp->next = nullptr;
    }


    void insertAtPosition(int position, int value) {
        if (position < 1) {
            cout << "Position must be >= 1\n";
            return;
        }

        if (position == 1) {
            insertAtBeginning(value);
            return;
        }
        Node* tmp = head;

        if (!tmp) {
            cout << "List is empty. \n";
            return;
        }

        Node* newNode = new Node(value);
        if (!newNode) {
            cout << "Allocation error!\n";
            return;
        }
        //newNode->data = value;

        for (int i = 1; i < position - 1 && tmp; i++) {
            tmp = tmp->next;
        }

        if (!tmp) {
            cout << "Error: Position out of range\n";
            delete newNode;
            return;
        }

        newNode->next = tmp->next;
        newNode->previous = tmp;
        newNode->next->previous = newNode;
        tmp->next = newNode;
    }

    void deleteAtPosition(int position) {
        if (position < 1) {
            cout << "Position must be >= 1\n";
            return;
        }

        if (!head) {
            cout << "List is empty. \n";
            return;
        }

        if (position == 1) {
            deleteFromBeginning();
            return;
        }

        Node* tmp = head;

        for (int i = 1; i < position - 1 && tmp; i++) {
            tmp = tmp->next;
        }


        if (!tmp) {
            cout << "Error: Position out of range\n";
            return;
        }

        if (!tmp->next) {
            deleteFromEnd();
            return;
        }

        Node* tmp2 = tmp->next;
        tmp2->next->previous = tmp;
        tmp->next = tmp2->next;
        delete tmp2;
    }
};





int main()
{
    DoublyLinkedList l;

    l.insertAtBeginning(12);
    l.insertAtBeginning(121);
    l.insertAtBeginning(2312);
    l.displayList();
    l.insertAtPosition(2, 37);
    l.displayList();

}