#include <bits/stdc++.h>
using namespace std;

// Implement Stack using Queues

class MyStack {
private:
    std::queue<int> q;

public:
    MyStack() {}

    void push(int x) {
        q.push(x);
        for (int i = 0; i < q.size() - 1; ++i) {
            q.push(q.front());
            q.pop();
        }
    }

    int pop() {
        int val = q.front();
        q.pop();
        return val;
    }

    int top() {
        return q.front();
    }

    bool empty() {
        return q.empty();
    }
};

// Implement Queue using Stacks

struct Queue {
  stack < int > input, output;
  
  // Push elements in queue
  void Push(int data) {
    // Pop out all elements from the stack input
    while (!input.empty()) {
      output.push(input.top());
      input.pop();
    }
    // Insert the desired element in the stack input
    cout << "The element pushed is " << data << endl;
    input.push(data);
    // Pop out elements from the stack output and push them into the stack input
    while (!output.empty()) {
      input.push(output.top());
      output.pop();
    }
  }
  // Pop the element from the Queue
  int Pop() {
    if (input.empty()) {
      cout << "Stack is empty";
      exit(0);
    }
    int val = input.top();
    input.pop();
    return val;
  }
  // Return the Topmost element from the Queue
  int Top() {
    if (input.empty()) {
      cout << "Stack is empty";
      exit(0);
    }
    return input.top();
  }
  // Return the size of the Queue
  int size() {
    return input.size();
  }
};

// Check for Balanced Parentheses

bool isValid(string s) {
    stack<char>st; 
    for(auto it: s) {
        if(it=='(' || it=='{' || it == '[') st.push(it); 
        else {
            if(st.size() == 0) return false; 
            char ch = st.top(); 
            st.pop(); 
            if((it == ')' and ch == '(') or  (it == ']' and ch == '[') or (it == '}' and ch == '{')) continue;
            else return false;
        }
    }
    return st.empty(); 
}


// Next Greater Element Using Stack

vector < int > nextGreaterElements(vector < int > & nums) {
    int n = nums.size();
    vector < int > nge(n, -1);
    stack < int > st;
    for (int i = 2 * n - 1; i >= 0; i--) {
    while (!st.empty() && st.top() <= nums[i % n]) {
        st.pop();
    }

    if (i < n) {
        if (!st.empty()) nge[i] = st.top();
    }
    st.push(nums[i % n]);
    }
    return nge;
}