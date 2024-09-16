#include <iostream>

class Stack
{
private:
    int *arr;
    int top;
    int capacity;

public:
    Stack(int size = 5)
    {
        capacity = size;
        arr = new int[capacity];
        top = -1;
    }

    ~Stack()
    {
        delete[] arr;
    }

    void push(int value)
    {
        if (isFull())
        {
            std::cout << "Stack is full. Cannot push " << value << std::endl;
            return;
        }
        arr[++top] = value;
    }

    void pop()
    {
        if (isEmpty())
        {
            std::cout << "Stack is empty. Cannot pop." << std::endl;
            return;
        }
        --top;
    }

    int peek() const
    {
        if (isEmpty())
        {
            std::cout << "Stack is empty. Nothing to peek." << std::endl;
            return -1;
        }
        return arr[top];
    }

    bool isEmpty() const
    {
        return top == -1;
    }

    bool isFull() const
    {
        return top == capacity - 1;
    }

    void print() const
    {
        if (isEmpty())
        {
            std::cout << "Stack is empty." << std::endl;
            return;
        }
        std::cout << "Stack elements are: ";
        for (int i = 0; i <= top; ++i)
        {
            std::cout << arr[i] << " ";
        }
        std::cout << std::endl;
    }
};

int main()
{
    Stack s;

    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);

    s.print();

    std::cout << "Top element is: " << s.peek() << std::endl;

    s.pop();
    s.print();

    std::cout << "Is stack empty? " << (s.isEmpty() ? "Yes" : "No") << std::endl;
    std::cout << "Is stack full? " << (s.isFull() ? "Yes" : "No") << std::endl;

    return 0;
}
