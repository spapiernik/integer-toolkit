#include "unity.h"
#include "integer_toolkit.h"

void test_contains() {
  TEST_ASSERT_TRUE(intk_contains(34120, 1));
  TEST_ASSERT_FALSE(intk_contains(34120, 9));
}

void test_startswith() {
  TEST_ASSERT_TRUE(intk_startswith(34120, 3));
  TEST_ASSERT_FALSE(intk_startswith(34120, 4));
}

void test_endswith() {
  TEST_ASSERT_TRUE(intk_endswith(34120, 0));
  TEST_ASSERT_FALSE(intk_endswith(34120, 2));
}

void test_reversed() {
  TEST_ASSERT_EQUAL(235711, intk_reversed(117532));
  TEST_ASSERT_EQUAL(1985, intk_reversed(5891));
}