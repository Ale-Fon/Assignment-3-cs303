#pragma once
#include <iostream>
#include <stack>
#include <string>
#include <queue>

using namespace std;

//Functions for post operations.
bool theOperator(char c);
bool theOpeningBracket(char c);
bool theClosingBracket(char c);
bool theMatchingBracket(char open, char close);
bool theBalancedParentheses(const string &expression);
string theinfixToPostfix(const string &infixExpression);


//This will be the class used to determine the node that the code will use.
class Node {
public:
    int data;
    Node* next;

    Node(int val) : data(val), next(nullptr) {}
};

//This will be the class for each function of queue in the code, most code have been solved in this class.
class Queue {
private:
    Node* front;
    Node* rear;
    int size;

public:
    Queue() : front(nullptr), rear(nullptr), size(0) {}
//Code for the enqueue.
    void enqueue(int element) {
        Node* newNode = new Node(element);
        if (isEmpty()) {
            front = newNode;
            rear = newNode;
        } 
        else {
            rear->next = newNode;
            rear = newNode;
        }
        size++;
    }

//Code for the dequeue.
    int dequeue() {
        if (isEmpty()) {
            return -1;
        }
        Node* temp = front;
        int frontElement = front->data;
        front = front->next;
        delete temp;
        size--;
        return frontElement;
    }
//Code to get the front index of the queue.
    int getFront() {
        if (isEmpty()) {
            return -1;
        }
        return front->data;
    }
//Code to see if the queue is empty.
    bool isEmpty() {
        return size == 0;
    }
//Code to get the size of the queue.
    int getSize() {
        return size;
    }
};

