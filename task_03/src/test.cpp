
#include <gtest/gtest.h>

#include "sort.hpp"

TEST(SortTest, Simple) {
  ASSERT_EQ(QuickSort<int>({}), std::vector<int>{});
  ASSERT_EQ(QuickSort<int>({1}), std::vector<int>{1});
  ASSERT_EQ(QuickSort<int>({1, 2, 3}), (std::vector<int>{1, 2, 3}));
  ASSERT_EQ(QuickSort<int>({3, 2, 1}), (std::vector<int>{1, 2, 3}));
  ASSERT_EQ(QuickSort<int>({3, 2, -1}), (std::vector<int>{-1, 2, 3}));
}

TEST(SortTest, SimpleChar) {
  ASSERT_EQ(QuickSort<char>({}), std::vector<char>{});
  ASSERT_EQ(QuickSort<char>({'a'}), std::vector<char>{'a'});
  ASSERT_EQ(QuickSort<char>({'a', 'b', 'c'}),
            (std::vector<char>{'a', 'b', 'c'}));
  ASSERT_EQ(QuickSort<char>({'c', 'b', 'a'}),
            (std::vector<char>{'a', 'b', 'c'}));
}

TEST(SortTest, Even) {
  ASSERT_EQ(QuickSort<int>({1, 2}), (std::vector<int>{1, 2}));
  ASSERT_EQ(QuickSort<int>({1, 1, 2, 3}), (std::vector<int>{1, 1, 2, 3}));
  ASSERT_EQ(QuickSort<int>({1, 2, 1, 3}), (std::vector<int>{1, 1, 2, 3}));
  ASSERT_EQ(QuickSort<int>({1, 1, 2, 3, 2}), (std::vector<int>{1, 1, 2, 2, 3}));
  ASSERT_EQ(QuickSort<int>({1, 2, 1, 3, 2}), (std::vector<int>{1, 1, 2, 2, 3}));
}

TEST(SortTest, EvenChar) {
  ASSERT_EQ(QuickSort<char>({'a', 'b'}), (std::vector<char>{'a', 'b'}));
  ASSERT_EQ(QuickSort<char>({'a', 'a', 'b', 'c'}),
            (std::vector<char>{'a', 'a', 'b', 'c'}));
  ASSERT_EQ(QuickSort<char>({'a', 'b', 'a', 'c'}),
            (std::vector<char>{'a', 'a', 'b', 'c'}));
  ASSERT_EQ(QuickSort<char>({'a', 'a', 'b', 'c', 'b'}),
            (std::vector<char>{'a', 'a', 'b', 'b', 'c'}));
  ASSERT_EQ(QuickSort<char>({'a', 'b', 'a', 'c', 'b'}),
            (std::vector<char>{'a', 'a', 'b', 'b', 'c'}));
}

TEST(SortTest, BigData) {
  std::vector<int> data{};
  std::vector<int> answer{};
  for (int i = 1000000; i >= 0; --i) data.push_back(i);
  for (int i = 0; i < 1000001; ++i) answer.push_back(i);
  ASSERT_EQ(QuickSort<int>(data), answer);
}
