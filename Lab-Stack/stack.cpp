#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
};

void push(Node*& top, int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = top;
    top = newNode;
    cout << "Successfully pushed: " << value << endl;
}

void pop(Node*& top) {
    if (top == nullptr) {
        cout << "Error: Stack is empty!" << endl;
        return;
    }
    Node* temp = top;
    top = top->next;
    cout << "Popped element: " << temp->data << endl;
    delete temp;
}

void display(Node* top) {
    if (top == nullptr) {
        cout << "Stack is empty." << endl;
        return;
    }
    Node* current = top;
    cout << "Stack (Top to Bottom): ";
    while (current != nullptr) {
        cout << current->data << " -> ";
        current = current->next;
    }
    cout << "NULL" << endl;
}

void deleteMax(Node*& top) {
    if (top == nullptr) {
        cout << "Stack is empty." << endl;
        return;
    }

    Node* current = top;
    int maxVal = top->data;
    while (current != nullptr) {
        if (current->data > maxVal) maxVal = current->data;
        current = current->next;
    }

    cout << "Deleting maximum value: " << maxVal << endl;

    while (top != nullptr && top->data == maxVal) {
        Node* temp = top;
        top = top->next;
        delete temp;
    }

    if (top == nullptr) return;
    
    Node* prev = top;
    current = top->next;
    while (current != nullptr) {
        if (current->data == maxVal) {
            prev->next = current->next;
            delete current;
            current = prev->next;
        } else {
            prev = current;
            current = current->next;
        }
    }
}

int main() {
    Node* stack = nullptr;
    int choice, value;

    do {
        cout << "1. Push" << endl;
        cout << "2. Pop" << endl;
        cout << "3. Delete maximum" << endl;
        cout << "4. Display" << endl;
        cout << "0. Exit" << endl;
        cout << "Option: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Value: "; cin >> value;
                push(stack, value);
                break;
            case 2:
                pop(stack);
                break;
            case 3:
                deleteMax(stack);
                break;
            case 4:
                display(stack);
                break;
            case 0:
                break;
            default:
                cout << "Invalid choice!" << endl;
        }
    } while (choice != 0);

    return 0;
}