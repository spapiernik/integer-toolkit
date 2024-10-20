#include "unity.h"
#include "integer_toolkit.h"

void test_length() {
  TEST_ASSERT_EQUAL(1, intk_length(0));

  for (int i = 0; i < 6; ++i) {
    for (int j = 1; j < 10; ++j) {
      TEST_ASSERT_EQUAL(i + 1, intk_length(intk_with_zeros(j, i)));
    }
  }
}

void test_is_empty() {
  TEST_ASSERT_TRUE(intk_is_empty(0));
  TEST_ASSERT_FALSE(intk_is_empty(1));
}

void test_in_range() {
  for (int i = 2; i < 13; ++i) {
    TEST_ASSERT_TRUE(intk_in_range(i, i - 1, i + 1));
    TEST_ASSERT_FALSE(intk_in_range(i, i + 1, i + 2));
    TEST_ASSERT_FALSE(intk_in_range(i, i - 1, i - 2));
  }
}

void test_index_ok() {
  int number = 1234567890;
  int number_length = intk_length(number);

  for (int index = 0; index < number_length; ++index) {
    TEST_ASSERT_TRUE(intk_index_ok(number, index));
    TEST_ASSERT_FALSE(intk_index_ok(number, index + number_length));
  }
}