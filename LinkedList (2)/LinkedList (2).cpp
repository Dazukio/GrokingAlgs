#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next = nullptr;
    Node(int value) {
        data = value;
    }
    Node() {
        data = 0;
    }
};

class LinkedList {
    Node* head;

public:

    LinkedList() {
        head = NULL;
    }


    ~LinkedList() {
        Node* current = head;
        Node* next = nullptr;
        while (current != nullptr) {
            next = current->next;
            delete current;
            current = next;
        }
        head = nullptr;
    }

    void diplayList() {
        Node* current = head;
        if (!head) {
            cout << "List is empty";
            return;
        }
        while (current != nullptr) {
            cout << current->data << " -> ";
            current = current->next;
        }
        cout << "nullptr\n";
    }


    void insertAtBeginning(int value) {
        Node* newNode = new Node(value);
        //newNode->data = value;
        newNode->next = head;
        head = newNode;
    }

    void deleteFromBeginning() {
        if (!head) {
            cout << "List is empty!";
            return;
        }

        Node* tmp = head;
        head = head->next;
        delete tmp;
    }

    void insertAtEnd(int value) {
        Node* newNode = new Node(value);
        if (!newNode) {
            cout << "Allocation error!\n";
            return;
        }
        //newNode->data = value;


        if (!head) {
            head = newNode;
            return;
        }


        Node* tmp = head;
        while (tmp->next) {
            tmp = tmp->next;
        }


        tmp->next = newNode;

    }


    void deleteFromEnd() {
        if (!head) {
            cout << "List is empty!";
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
        tmp->next = tmp2->next;
        delete tmp2;
    }
};





int main()
{
    // 15.02.2025, 23:14. создал, завтра начну написание реализации связного список, гит очень увлекательный
    // 16.02.2025, 17:59, завершил создание связного списка
    // ^
    // |
    // 19:04 долго пытался удалить коммит, где были билды, но не получилось, снёс весь репозиторий :(
}