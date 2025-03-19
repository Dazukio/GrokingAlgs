#include <iostream>
using namespace std;


template <typename T> class Node {
public:
    int data;
    Node<T>* next;
    Node<T>* previous;

    Node(int value) {
        next = previous = nullptr;
        data = value;
    }
    Node() {
        next = previous = nullptr;
        data = 0;
    }
};

template <typename T> class DoublyCircularLinkedList {
    Node<T>* head;
    Node<T>* last;

public:

    DoublyCircularLinkedList() {
        head = last = nullptr;
    }


    ~DoublyCircularLinkedList() {
        if (head) {
            Node<T>* current = head->next;
            while (current != head) {
                Node<T>* next = current->next;
                delete current;
                current = next;
            }
            delete head;
            head = last = nullptr;
        }
    }

    void displayList() {
        if (!head) {
            cout << "List is empty!\n";
            return;
        }

        Node<T>* current = head;
        cout << "last" << " <-> ";
        do {
            cout << current->data << " <-> ";
            current = current->next;
        } while (current != head);
        cout << "head" << '\n';
    }


    void insertAtBeginning(int value) {
        Node<T>* newNode = new Node(value);
        if (!newNode) {
            cout << "Allocation error!\n";
            return;
        }
        if (!head) {
            head = last = newNode;
            newNode->next = newNode->previous = newNode;
        }
        newNode->next = head;
        head->previous = newNode;
        head = newNode;
        last->next = head;

    }

    void deleteFromBeginning() {
        if (!head) {
            cout << "List is empty!\n";
            return;
        }

        Node<T>* tmp = head;
        if (head == last) {
            delete head;
            head = last = nullptr;
            return;
        }
        head = head->next;
        last->next = head;
        head->previous = last;
        delete tmp;
    }

    void insertAtEnd(int value) {
        Node<T>* newNode = new Node(value);
        if (!newNode) {
            cout << "Allocation error!\n";
            return;
        }


        if (!head) {
            insertAtBeginning(value);
            return;
        }

        last->next = head->previous = newNode;
        newNode->next = head;
        newNode->previous = last;
        last = newNode;
    }


    void deleteFromEnd() {
        if (!head) {
            cout << "List is empty!\n";
            return;
        }

        if (head == last) {
            delete head;
            head = last = nullptr;
            return;
        }
        Node<T>* temp = last;
        last = last->previous;
        head->previous = last;
        last->next = head;
        delete temp;

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
        Node<T>* tmp = head;

        if (!tmp) {
            cout << "List is empty. \n";
            return;
        }

        Node<T>* newNode = new Node(value);
        if (!newNode) {
            cout << "Allocation error!\n";
            return;
        }

        int i = 1;

        while (i < position - 1 && tmp->next != head) {  
            tmp = tmp->next;
            i++;
        }


        if (i < position - 1) { 
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

        Node<T>* tmp = head;

        int i = 1;

        while (i < position - 1 && tmp->next != head) {
            tmp = tmp->next;
            i++;
        }


        if (i < position - 1) {
            cout << "Error: Position out of range\n";
            return;
        }


        Node<T>* tmp2 = tmp->next;
        if (tmp2 == head) {
            tmp->next = head;
            head->previous = tmp;
            delete tmp2;
            last = tmp;

        }
        else {
            tmp2->next->previous = tmp;
            tmp->next = tmp2->next;
            delete tmp2;
        }
    }
};





int main()
{
    DoublyCircularLinkedList<int> l;

    l.insertAtBeginning(12);
    l.insertAtBeginning(121);
    l.insertAtBeginning(2312);
    l.displayList();
    l.insertAtPosition(2, 37);
    l.displayList();

}