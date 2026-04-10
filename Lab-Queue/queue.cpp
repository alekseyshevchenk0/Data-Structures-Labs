#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
};

void pushBack(Node** head, Node** tail, int value) {
    Node* temp = new Node;
    temp->data = value;
    temp->next = nullptr;
    temp->prev = *tail;

    if (*tail != nullptr) {
        (*tail)->next = temp;
    }
    *tail = temp;

    if (*head == nullptr) {
        *head = temp;
    }
}

void pushFront(Node** head, Node** tail, int value) {
    Node* temp = new Node;
    temp->data = value;
    temp->prev = nullptr;
    temp->next = *head;

    if (*head != nullptr) {
        (*head)->prev = temp;
    }
    *head = temp;

    if (*tail == nullptr) {
        *tail = temp;
    }
}

void createQueue(Node** head, Node** tail) {
    int n, value;
    cout << "How many elements to enter? ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        cout << "Value " << i + 1 << ": ";
        cin >> value;
        pushBack(head, tail, value);
    }
}

void printForward(Node* head) {
    if (!head) { cout << "List is empty" << endl; return; }
    Node* curr = head;
    cout << "Forward view: ";
    while (curr) {
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << endl;
}

void printBackward(Node* tail) {
    if (!tail) { cout << "List is empty" << endl; return; }
    Node* curr = tail;
    cout << "Backward view: ";
    while (curr) {
        cout << curr->data << " ";
        curr = curr->prev;
    }
    cout << endl;
}

void deleteMax(Node** head, Node** tail) {
    if (*head == nullptr) return;

    Node* maxNode = *head;
    Node* curr = (*head)->next;
    while (curr) {
        if (curr->data > maxNode->data) maxNode = curr;
        curr = curr->next;
    }

    cout << "Removing maximum: " << maxNode->data << endl;

    if (*head == maxNode) *head = maxNode->next;
    if (*tail == maxNode) *tail = maxNode->prev;

    if (maxNode->prev) maxNode->prev->next = maxNode->next;
    if (maxNode->next) maxNode->next->prev = maxNode->prev;

    delete maxNode;
}

void avToHead(Node* head) {
    if (head == nullptr) {
        cout << "List is empty, nothing to calculate." << endl;
        return;
    }
    long sum = 0;
    int count = 0;
    Node* curr = head;
    while (curr) {
        sum += curr->data;
        count++;
        curr = curr->next;
    }
    double avg = (double)sum / count;
    head->data = (int)avg;
    cout << "Average value (" << (int)avg << ") assigned to head." << endl;
}

int main() {
    Node *begin = nullptr, *end = nullptr;
    int choice, val;

    while (true) {
        cout << "\n1. Create list";
        cout << "\n2. Add to front";
        cout << "\n3. Add to back";
        cout << "\n4. Print forward";
        cout << "\n5. Print backward";
        cout << "\n6. Delete maximum";
        cout << "\n7. Set Average to Head";
        cout << "\n0. Exit";
        cout << "\n>> ";
        cin >> choice;

        if (choice == 0) break;
        switch (choice) {
            case 1: createQueue(&begin, &end); break;
            case 2: cout << "Enter value: "; cin >> val; pushFront(&begin, &end, val); break;
            case 3: cout << "Enter value: "; cin >> val; pushBack(&begin, &end, val); break;
            case 4: printForward(begin); break;
            case 5: printBackward(end); break;
            case 6: deleteMax(&begin, &end); break;
            case 7: avToHead(begin); break;
            default: cout << "Invalid choice. Try again." << endl;
        }
    }
    return 0;
}