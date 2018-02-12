#include <functional>
#include <iostream>

#include "stack.hpp"
#include "utils/test.hpp"

int main() {
    test("Stack function", []() {
        Stack<int> stack(3);
        try {
            stack.push(1);
            stack.push(2);
            stack.push(3);
        } catch (std::out_of_range) {
            return false;
        }
        if (stack.pop() != 3) {
            return false;
        }
        if (stack.pop() != 2) {
            return false;
        }
        if (stack.pop() != 1) {
            return false;
        }
        return true;
    });

    test("Push to full stack", []() {
        Stack<int> stack(3);
        try {
            stack.push(0);
            stack.push(0);
            stack.push(0);
        } catch (std::out_of_range) {
            return false;
        }
        try {
            stack.push(0);
        } catch (std::out_of_range) {
            return true;
        }
        return false;
    });

    test("Pop from empty stack", []() {
        Stack<int> stack(3);
        try {
            stack.push(0);
            stack.push(0);
            stack.pop();
            stack.pop();
        } catch (std::out_of_range) {
            return false;
        }
        try {
            stack.pop();
        } catch (std::out_of_range) {
            return true;
        }
        return false;
    });

    test("Push to stack with 0 capacity", []() {
        Stack<int> stack(0);
        try {
            stack.push(0);
        } catch (std::out_of_range) {
            return true;
        }
        return false;
    });

    test("Pop from stack with 0 capacity", []() {
        Stack<int> stack(0);
        try {
            stack.pop();
        } catch (std::out_of_range) {
            return true;
        }
        return false;
    });

    return 0;
}