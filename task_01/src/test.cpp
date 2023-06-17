
#include <gtest/gtest.h>

#include "stack.hpp"

TEST(StackTest, ComplexInt) {
  Stack<int> stack;
  ASSERT_ANY_THROW(stack.Pop());
  ASSERT_EQ(stack.Size(), 0);
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
  stack.Push(1);              // Stack [1]
  stack.Push(2);              // Stack [1, 2]
  stack.Push(3);              // Stack [1, 2, 3]
  stack.Push(4);              // Stack [1, 2, 3, 4]
  ASSERT_EQ(stack.Size(), 4);
  ASSERT_EQ(stack.Back(), 4);
  ASSERT_EQ(stack.Size(), 4);
  stack.Clear();
  ASSERT_EQ(stack.Size(), 0);
}

TEST(StackTest, ComplexFloat) {
  Stack<double> stack;
  ASSERT_ANY_THROW(stack.Pop());
  ASSERT_EQ(stack.Size(), 0);
  stack.Push(1.3);              // Stack [1.3]
  ASSERT_EQ(stack.Pop(), 1.3);  // Stack []
  stack.Push(1.5);              // Stack [1.5]
  stack.Push(2.1);              // Stack [1.5, 2.1]
  ASSERT_EQ(stack.Pop(), 2.1);  // Stack [1.5]
  ASSERT_EQ(stack.Pop(), 1.5);  // Stack []
  stack.Push(1.5);              // Stack [1.5]
  stack.Push(2.1);              // Stack [1.5, 2.1]
  ASSERT_EQ(stack.Pop(), 2.1);  // Stack [1.5]
  stack.Push(3.3);              // Stack [1.5, 3.3]
  ASSERT_EQ(stack.Pop(), 3.3);  // Stack [1.5]
  ASSERT_EQ(stack.Pop(), 1.5);  // Stack []
  stack.Push(4.);               // Stack [1.]
  stack.Push(2.);               // Stack [1., 2.]
  stack.Push(3.);               // Stack [1., 2., 3.]
  stack.Push(4.);               // Stack [1., 2., 3., 4.]
  ASSERT_EQ(stack.Size(), 4);
  ASSERT_EQ(stack.Back(), 4.);
  ASSERT_EQ(stack.Size(), 4);
  stack.Clear();
  ASSERT_EQ(stack.Size(), 0);
}

TEST(StackTest, SimpleChar) {
  Stack<char> stack;
  ASSERT_ANY_THROW(stack.Pop());
  stack.Push('h');  // Stack ['b']
  stack.Push('l');  // Stack ['b', 'l']
  stack.Push('a');  // Stack ['b', 'l', 'a']
  ASSERT_EQ(stack.Size(), 3);
  ASSERT_EQ(stack.Pop(), 'a');  // Stack ['b', 'l']
  stack.Clear();                // Stack [ ]
  ASSERT_EQ(stack.Size(), 0);
}

TEST(MinStackTest, ComplexInt) {
  MinStack<int> stack;
  ASSERT_ANY_THROW(stack.Pop());
  stack.Push(1);  // Stack [1]
  ASSERT_EQ(stack.GetMin(), 1);
  ASSERT_EQ(stack.Pop(), 1);  // Stack []
  stack.Push(1);              // Stack [1]
  stack.Push(2);              // Stack [1, 2]
  ASSERT_EQ(stack.GetMin(), 1);
  ASSERT_EQ(stack.Pop(), 2);  // Stack [1]
  ASSERT_EQ(stack.Pop(), 1);  // Stack []
  stack.Push(2);              // Stack [2]
  stack.Push(1);              // Stack [2, 1]
  ASSERT_EQ(stack.GetMin(), 1);
  ASSERT_EQ(stack.Pop(), 1);  // Stack [2]
  stack.Push(3);              // Stack [2, 3]
  ASSERT_EQ(stack.GetMin(), 2);
  ASSERT_EQ(stack.Pop(), 3);  // Stack [1]
  ASSERT_EQ(stack.Pop(), 2);  // Stack []
  stack.Push(1);              // Stack [1]
  stack.Push(2);              // Stack [1, 2]
  stack.Push(3);              // Stack [1, 2, 3]
  stack.Push(4);              // Stack [1, 2, 3, 4]
  ASSERT_EQ(stack.Size(), 4);
  ASSERT_EQ(stack.Back(), 4);
  ASSERT_EQ(stack.Size(), 4);
  stack.Clear();
  ASSERT_EQ(stack.Size(), 0);
  stack.Push(5);              // Stack [5]
  stack.Push(4);              // Stack [5, 4]
  stack.Push(4);              // Stack [5, 4, 4]
  ASSERT_EQ(stack.Pop(), 4);  // Stack [5, 4]
  ASSERT_EQ(stack.GetMin(), 4);
}

TEST(MinStackTest, ComplexFloat) {
  MinStack<double> stack;
  ASSERT_ANY_THROW(stack.Pop());
  stack.Push(1.2);  // Stack [1.2]
  ASSERT_EQ(stack.GetMin(), 1.2);
  ASSERT_EQ(stack.Pop(), 1.2);  // Stack []
  stack.Push(1.2);              // Stack [1.2]
  stack.Push(2.2);              // Stack [1.2, 2.2]
  ASSERT_EQ(stack.GetMin(), 1.2);
  ASSERT_EQ(stack.Pop(), 2.2);  // Stack [1.2]
  ASSERT_EQ(stack.Pop(), 1.2);  // Stack []
  stack.Push(1.3);              // Stack [1.3]
  stack.Push(2.3);              // Stack [1.3, 2.3]
  ASSERT_EQ(stack.GetMin(), 1.3);
  ASSERT_EQ(stack.Pop(), 2.3);  // Stack [1.3]
  stack.Push(3.3);              // Stack [1.3, 3.3]
  ASSERT_EQ(stack.GetMin(), 1.3);
  ASSERT_EQ(stack.Pop(), 3.3);  // Stack [1.3]
  ASSERT_EQ(stack.Pop(), 1.3);  // Stack []
  stack.Push(1.);               // Stack [1.]
  stack.Push(2.);               // Stack [1., 2.]
  stack.Push(3.);               // Stack [1., 2., 3.]
  stack.Push(4.);               // Stack [1., 2., 3., 4.]
  ASSERT_EQ(stack.Size(), 4);
  ASSERT_EQ(stack.Back(), 4.);
  ASSERT_EQ(stack.Size(), 4);
  stack.Clear();
  ASSERT_EQ(stack.Size(), 0);
}

TEST(MinStackTest, SimpleChar) {
  MinStack<char> stack;
  ASSERT_ANY_THROW(stack.Pop());
  stack.Push('h');  // Stack ['b']
  stack.Push('l');  // Stack ['b', 'l']
  stack.Push('a');  // Stack ['b', 'l', 'a']
  stack.Push('k');  // Stack ['b', 'l', 'a', 'k']
  ASSERT_EQ(stack.GetMin(), 'a');
  ASSERT_EQ(stack.Size(), 4);
  ASSERT_EQ(stack.Pop(), 'k');  // Stack ['b', 'l', 'a']
  stack.Clear();                // Stack [ ]
  ASSERT_EQ(stack.Size(), 0);
}