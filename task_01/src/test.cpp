
#include <gtest/gtest.h>

#include <stack>

#include "stack.hpp"

TEST(StackTest, SimpleInt) {
  Stack<int> stack;
  stack.Push(1);              // Stack [1]
  ASSERT_EQ(stack.Pop(), 1);  // Stack []
  stack.Push(1);              // Stack [1]
  stack.Push(2);              // Stack [1, 2]
  ASSERT_EQ(stack.Pop(), 2);  // Stack [1]
  ASSERT_EQ(stack.Pop(), 1);  // Stack []
  stack.Push(1);              // Stack [1]
  stack.Push(2);              // Stack [1, 2]
  ASSERT_EQ(stack.Pop(), 2);  // Stack [1]
  stack.Push(3);              // Stack [1, 3]
  ASSERT_EQ(stack.Pop(), 3);  // Stack [1]
  ASSERT_EQ(stack.Pop(), 1);  // Stack []
}

TEST(StackTest, SimpleChar) {
  Stack<char> stack;
  stack.Push('a');              // Stack [a]
  ASSERT_EQ(stack.Pop(), 'a');  // Stack []
  stack.Push('a');              // Stack [a]
  stack.Push('b');              // Stack [a, b]
  ASSERT_EQ(stack.Pop(), 'b');  // Stack [a]
  ASSERT_EQ(stack.Pop(), 'a');  // Stack []
  stack.Push('b');              // Stack [b]
  stack.Push('a');              // Stack [b, a]
  ASSERT_EQ(stack.Pop(), 'a');  // Stack [b]
  stack.Push('c');              // Stack [b, c]
  ASSERT_EQ(stack.Pop(), 'c');  // Stack [b]
  ASSERT_EQ(stack.Pop(), 'b');  // Stack []
}

TEST(StackTest, Empty) {
  Stack<char> stack;
  ASSERT_ANY_THROW(stack.Pop());
  stack.Push(1);
  ASSERT_EQ(stack.Pop(), 1);  // [(1), 2, 3]
  ASSERT_ANY_THROW(stack.Pop());
}

TEST(MinStackTest, SimpleInt) {
  MinStack<int> stack;
  stack.Push(1);  // Stack [1]
  ASSERT_EQ(stack.GetMin(), 1);
  ASSERT_EQ(stack.Pop(), 1);  // Stack []
  stack.Push(1);              // Stack [1]
  stack.Push(2);              // Stack [1, 2]
  ASSERT_EQ(stack.GetMin(), 1);
  ASSERT_EQ(stack.Pop(), 2);  // Stack [1]
  ASSERT_EQ(stack.Pop(), 1);  // Stack []
  stack.Push(1);              // Stack [1]
  stack.Push(2);              // Stack [1, 2]
  ASSERT_EQ(stack.GetMin(), 1);
  ASSERT_EQ(stack.Pop(), 2);  // Stack [1]
  stack.Push(3);              // Stack [1, 3]
  ASSERT_EQ(stack.GetMin(), 1);
  ASSERT_EQ(stack.Pop(), 3);  // Stack [1]
  ASSERT_EQ(stack.Pop(), 1);  // Stack []
}


TEST(MinStackTest, SimpleChar) {
  MinStack<char> stack;
  stack.Push('a');  // Stack [a]
  ASSERT_EQ(stack.GetMin(), 'a');
  ASSERT_EQ(stack.Pop(), 'a');  // Stack []
  stack.Push('a');              // Stack [a]
  stack.Push('b');              // Stack [a, b]
  ASSERT_EQ(stack.GetMin(), 'a');
  ASSERT_EQ(stack.Pop(), 'b');  // Stack [a]
  ASSERT_EQ(stack.Pop(), 'a');  // Stack []
  stack.Push('a');              // Stack [a]
  stack.Push('b');              // Stack [a, b]
  ASSERT_EQ(stack.GetMin(), 'a');
  ASSERT_EQ(stack.Pop(), 'b');  // Stack [a]
  stack.Push('c');              // Stack [a, c]
  ASSERT_EQ(stack.GetMin(), 'a');
  ASSERT_EQ(stack.Pop(), 'c');  // Stack [a]
  ASSERT_EQ(stack.Pop(), 'a');  // Stack []
}
