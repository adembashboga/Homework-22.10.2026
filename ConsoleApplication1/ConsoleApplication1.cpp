#include <iostream>
using namespace std;

template <typename T>
class Stack 
{
private:
    struct Node 
    {
        T data;
        Node* next;
        Node(T val) : data(val), next(nullptr) {}
    };

    Node* topNode;
    size_t count;

public:
    Stack() : topNode(nullptr), count(0) {}

    ~Stack()
    {
        while (!isEmpty()) {
            pop();
        }
    }

    void push(T value) 
    {
        Node* newNode = new Node(value);
        newNode->next = topNode;
        topNode = newNode;
        count++;
    }

    void pop() 
    {
        if (isEmpty()) 
        {
            return;
        }
        Node* temp = topNode;
        topNode = topNode->next;
        delete temp;
        count--;
    }

    T peek() const
    {
        if (isEmpty()) {
            throw std::runtime_error("Stack is empty");
        }
        return topNode->data;
    }

    bool isEmpty() const 
    {
        return topNode == nullptr;
    }

    size_t size() const 
    {
        return count;
    }
};

int main()
{
    Stack<int> s;
    s.push(10);
    s.push(20);
    s.push(30);

    while (!s.isEmpty()) {
        std::cout << s.peek() << " ";
        s.pop();
    }
    std::cout << std::endl;

    return 0;
}