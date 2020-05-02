#include "stack.hpp"

/*
 * Pre:   None
 * Post:  The Stack exists and it intialied to be empty
 */
Stack::Stack() : count {}
{
}

/*
 * Pre:   None
 * Post:  If the Stack is not empty, the top of the Stack is removed. If the
 *        Stack is empty, an Error_code of underflow is returned and the
 *        Stack is left unchanged.
 */
Error_code Stack::pop()
{
  Error_code outcome = Error_code::SUCCESS;
  if (count == 0) {
    outcome = Error_code::UNDERFLOW;
  } else {
    --count;
  }
  return outcome;
}

/*
 * Pre:   None
 * Post:  If the Stack is not full, item is added to the top of the Stack.
 *        If the Stack is full, an Error_code of overflow is returned and
 *        the Stack is left unchanged.
 */
Error_code Stack::push(const Stack_entry &item)
{
  Error_code outcome = Error_code::SUCCESS;
  if (count >= MAX_STACK) {
    outcome = Error_code::OVERFLOW;
  } else {
    entry[count++] = item;
  }
  return outcome;
}

/*
 * Pre:   None
 * Post:  The top of a nonempty Stack is copied to item. An Error_code of
 *        underflow returned if the Stack is empty.
 */
Error_code Stack::top(Stack_entry &item) const
{
  Error_code outcome = Error_code::SUCCESS;
  if (count == 0) {
    outcome = Error_code::UNDERFLOW;
  } else {
    item = entry[count - 1];
  }
  return outcome;
}

/*
 * Pre:   None
 * Post:  A result of true is returned if the Stack is empty, otherwise
 *        false is returned.
 */
bool Stack::empty() const
{
  return count == 0;;
}
