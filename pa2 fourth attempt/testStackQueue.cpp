#include <iostream>

#include "cs221util/catch.hpp"
#include "queue.h"
#include "stack.h"
using namespace std;

// TEST_CASE("quack::basic functions", "[weight=1][part=quack]") {
//     // cout << "Testing Quack..." << endl;
//     Quack<int> intQuack;
//     vector<int> result;
//     vector<int> expected;

//     // for (int i = 10; i > 0; i--) {
//     //     expected.push_back(i);
//     // }

//     for (int i = 0; i < 10; i++) {
//         intQuack.pushR(i);                      // quack_size = 10
//     }

//     for (int i = 0; i < 4; i++) {
//         intQuack.popL();
//     }

//     for (int i = 0; i < 10; i++) {
//         expected.push_back(i);                    
//     }
// }

TEST_CASE("stack::basic functions", "[weight=1][part=stack]") {
    // cout << "Testing Stack..." << endl;
    Stack<int> intStack;
    vector<int> result;
    vector<int> expected;
    for (int i = 10; i > 0; i--) {
        expected.push_back(i);
    }
    for (int i = 1; i <= 10; i++) {
        intStack.push(i);
    }
    while (!intStack.isEmpty()) {
        result.push_back(intStack.pop());
    }
    REQUIRE(result == expected);
}

TEST_CASE("stack::resize", "[weight=1][part=stack]") {
    Stack<int> resizeStack;

    for (int i = 0; i < 4; i++) {
        resizeStack.push(i);
    }
    for (int i = 1; i <= 2; i++) {
        resizeStack.pop();
    }

    int size = 0;
    while (!resizeStack.isEmpty()) {
        resizeStack.pop();
        size++;
    }
    REQUIRE(size == 2);
}

TEST_CASE("queue::basic functions", "[weight=1][part=queue]") {
    Queue<int> intQueue;
    vector<int> result;
    vector<int> expected;
    for (int i = 1; i <= 10; i++) {
        expected.push_back(i);
    }
    for (int i = 1; i <= 10; i++) {
        intQueue.enqueue(i);
    }
    while (!intQueue.isEmpty()) {
        result.push_back(intQueue.dequeue());
    }
    REQUIRE(result == expected);
}

TEST_CASE("queue::resize", "[weight=1][part=queue]") {
    Queue<int> resizeQueue;

    for (int i = 0; i < 4; i++) {
        resizeQueue.enqueue(i);
    }
    for (int i = 1; i <= 2; i++) {
        resizeQueue.dequeue();
    }

    int size = 0;
    while (!resizeQueue.isEmpty()) {
        resizeQueue.dequeue();
        size++;
    }
    REQUIRE(size == 2);
}

