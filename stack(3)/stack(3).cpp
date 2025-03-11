#include <iostream>
#include <vector>
template<typename T>class Stack {
    std::vector<T> arr;
    size_t stackSize;
public:
    Stack(const size_t& value) : stackSize(value) {}
    void displayStack() const {
        if (arr.empty()) {
            std::cout << "Stack is empty!";
            return;
        }
        for (T num : arr) {
            std::cout << num << ' ';
        }
        std::cout << '\n';
    }
    void addElement(const T& value) {
        if (arr.size() == stackSize){
            std::cout << "Stack Overflow!";
            return;
        }
        arr.push_back(value);
    }
    void removeElement() {
        if (arr.empty()) {
            std::cout << "Stack is empty!";
            return;
        }
        arr.pop_back();
    }

    void top() const {
        if (arr.empty()) {
            std::cout << "Stack is empty!";
            return;
        }
        std::cout << arr[arr.size()-1] << '\n';
    }
    void setTop(const T& value) {
        if (arr.empty()) {
            std::cout << "Stack is empty!";
            return;
        }
        arr.pop_back();
        arr.push_back(value);
    }
};

int main()
{
    Stack<int> s(100);
    s.addElement(52);
    s.addElement(42);
    s.addElement(11);
    s.addElement(8008);
    s.displayStack();
    s.removeElement();
    s.displayStack();
    s.top();
    s.setTop(34);
    s.displayStack();

    return 0;
}
