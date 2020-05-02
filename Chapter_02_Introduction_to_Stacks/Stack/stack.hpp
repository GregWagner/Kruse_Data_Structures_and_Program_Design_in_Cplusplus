#ifndef STACK_H
#define STACK_H

using Stack_entry = char;

enum class Error_code {SUCCESS, OVERFLOW, UNDERFLOW};

class Stack {
  public:
    Stack();

    Error_code pop();
    Error_code push(const Stack_entry &item);
    Error_code top(Stack_entry &item) const;
    bool empty() const;

  private:
    static int const MAX_STACK {10}; 
    int count {};
    Stack_entry entry[MAX_STACK];
};

#endif
