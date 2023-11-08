#include <iostream>
#include <stack>
#include <string>
#include <queue>
#include "function.h"

using namespace std;

int main() {
  int choice1;
  char choice2;
  bool again = true;
  bool agains = true;
  cout << "Welcome to this program!" << endl << endl;
  while (again){
    cout << "Please choice between these options: "<< endl;
    cout << "1) Inflix Expression" << endl;
    cout << "2) Queues" << endl << endl;
    cout << "Choice: ";
    cin >> choice1;
    if (choice1 == 1){
      string infixExpression;
      cout << "Enter an infix expression: ";
      cin >> infixExpression;

      if (theBalancedParentheses(infixExpression)) {
          string postfixExpression = theinfixToPostfix(infixExpression);
          cout << "Postfix expression: " << postfixExpression << endl << endl;
      } 
      else {
        cout << "The expression is invalid due to unbalanced parentheses." << endl;
      }
    }
    else if (choice1 == 2){
      Queue myQueue;

      while (1) {
        while(agains){
          cout << "Queue Operations menu:" << endl << endl;
          cout << "Here are the choices: " << endl;
          cout << "E. Enqueue" << endl;
          cout << "D. Dequeue" << endl;
          cout << "F. Get Front of queue"<< endl;
          cout << "C. Check if queue is empty"<< endl;
          cout << "G. Get queue size"<< endl;
          cout << "Q. Quit"<< endl << endl;
          cout << "Please enter your choice: ";
          cin >> choice2;
          
          switch (choice2) {
            case 'e':
            case 'E':
              int element;
              cout << "Enter the index to enqueue: ";
              cin >> element;
              myQueue.enqueue(element);
              break;
            case 'd':
            case 'D':
              int dequeued;
              dequeued = myQueue.dequeue();
              if (dequeued == -1) {
                cout << "Sorry! the queue is empty, couldnt dequeue." << endl;
              } 
              else {
                cout << "The dequeued: " << dequeued << endl;
              }
              break;
            case 'f':
            case 'F':
              int front;
              front = myQueue.getFront();
              if (front == -1) {
                cout << "The queue is empty, we were not able to retrieve front element." << endl;
              } 
              else {
                cout << "Front of queue: " << front << endl;
              }
              break;
            case 'c':
            case 'C':
              cout << "The queue is empty: " << myQueue.isEmpty() << endl;
              break;
            case 'g':
            case 'G':
              cout << "Size of queue: " << myQueue.getSize() << endl;
              break;
            case 'q':
            case 'Q':
              cout << "Thank you for using my program, have a great day!";
              agains = false;
              return 0;
              break;
            default:
              cout <<"Oops, wrong input, please try again!" << endl << endl;
          }
        }
      }
    }
  }
}
