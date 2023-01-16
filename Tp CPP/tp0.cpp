#include <iostream>

struct Node {
    int data;
    Node* next;
};

class Stack {
private:
    Node* top;

public:
    Stack() {
        top = nullptr;
    }

    void push(int data) {
        Node* newNode = new Node();
        newNode->data = data;
        newNode->next = top;
        top = newNode;
    }

    int pop() {
        if (top == nullptr) {
            std::cout << "Stack is empty." << std::endl;
            return -1;
        }

        int data = top->data;
        Node* temp = top;
        top = top->next;
        delete temp;
        return data;
    }

    int peek() {
        if (top == nullptr) {
            std::cout << "Stack is empty." << std::endl;
            return -1;
        }
        return top->data;
    }

    bool isEmpty() {
        return top == nullptr;
    }
};

Node* reverseInGroups(Node* head, int k) {
    Node* current = head;
    Node* previous = nullptr;
    Node* next = nullptr;
    int count = 0;

    while (current != nullptr && count < k) {
        next = current->next;
        current->next = previous;
        previous = current;
        current = next;
        count++;
    }

    if (next != nullptr) {
        head->next = reverseInGroups(next, k);
    }
    return previous;
}

void eliminateDuplicates(Node* head) {
    Node* current = head;
    while (current != nullptr && current->next != nullptr) {
        if (current->data == current->next->data) {
            Node* temp = current->next;
            current->next = temp->next;
            delete temp;
        } else {
            current = current->next;
        }
    }
}

int main() {
    Node* head = new Node();
    head->data = 1;
    head->next = new Node();
    head->next->data = 2;
    head->next->next = new Node();
    head->next->next->data = 2;
    head->next->next->next = new Node();
    head->next->next->next->data = 3;
    head->next->next->next->next = new Node();
    head->next->next->next->next->data = 3;
    head->next->next->next->next->next = nullptr;

    std::cout << "Original list: ";
    Node* current = head;
    while (current != nullptr) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;


    eliminateDuplicates(head);

    std::cout << "Updated list: ";
    current = head;
    while (current != nullptr) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;

    Node* duplicate = reverseInGroups(head,2);
    std::cout << "2 reversed list: ";
    current = duplicate;
    while (current != nullptr) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
    return 0;
}
