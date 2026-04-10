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
    cout << "Сколько элементов ввести сейчас? ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        cout << "Значение " << i + 1 << ": ";
        cin >> value;
        pushBack(head, tail, value);
    }
}

void printForward(Node* head) {
    if (!head) { cout << "Пусто" << endl; return; }
    Node* curr = head;
    cout << "От начала: ";
    while (curr) {
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << endl;
}

void printBackward(Node* tail) {
    if (!tail) { cout << "Пусто" << endl; return; }
    Node* curr = tail;
    cout << "От конца: ";
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

    cout << "Удаляем: " << maxNode->data << endl;

    if (*head == maxNode) *head = maxNode->next;
    if (*tail == maxNode) *tail = maxNode->prev;

    if (maxNode->prev) maxNode->prev->next = maxNode->next;
    if (maxNode->next) maxNode->next->prev = maxNode->prev;

    delete maxNode;
}

void avToHead(Node* head) {
    if (head == nullptr) {
        cout << "Список пуст, вычислять нечего." << endl;
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
}

int main() {
    setlocale(LC_ALL, "ru");
    Node *begin = nullptr, *end = nullptr;
    int choice, val;

    while (true) {
        cout << "\n1. Создать\n2. Добавить в начало\n3. Добавить в конец";
        cout << "\n4. Просмотр с начала\n5. Просмотр с конца\n6. Удалить максимум\n7. Поменять\n0. Выход\n>> ";
        cin >> choice;

        if (choice == 0) break;
        switch (choice) {
            case 1: createQueue(&begin, &end); break;
            case 2: cout << "Число: "; cin >> val; pushFront(&begin, &end, val); break;
            case 3: cout << "Число: "; cin >> val; pushBack(&begin, &end, val); break;
            case 4: printForward(begin); break;
            case 5: printBackward(end); break;
            case 6: deleteMax(&begin, &end); break;
            case 7: avToHead(begin); break;
        }
    }
    return 0;
}