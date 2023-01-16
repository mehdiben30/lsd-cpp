#include <iostream>
using namespace std;

class Node {
public :
    int m_value;
    Node* m_next;

    Node(int value) : m_value(value), m_next(nullptr) {}

    
};

class Stack {
private :
    Node* m_head;
public :
    Stack() : m_head(nullptr) {}

    void push(int value) {
        Node* new_node = new Node(value);
        new_node->m_next = m_head;
        m_head= new_node;
    }

    void pop() {
        if(m_head == NULL) cout << "stack is empty" << endl;
        Node* temp = m_head;
        m_head = m_head->m_next;
        delete temp;
    }

    int peek() {
        if(m_head == NULL) {
        cout << "stack is empty" << endl;
        return -1; 
        }
        return m_head->m_value;
    }
};

int main() {
  Stack s;
  s.push(1);
  s.push(2);
  s.push(3);
  cout << "Top element: " << s.peek() << endl;  // Outputs 3
  s.pop();
  cout << "Top element: " << s.peek() << endl;  // Outputs 2
  s.pop();
  cout << "Top element: " << s.peek() << endl;  // Outputs 1
  s.pop();
  
}

