#include "unity.h"
#include "integer_toolkit.h"

void test_range() {
  TEST_ASSERT_EQUAL(1, intk_range(1, 2, 1));
  TEST_ASSERT_EQUAL(1, intk_range(1, 2, 1));
}

void test_number_from_to() {
  TEST_ASSERT_EQUAL(1, intk_number_from_to(1234567890, 0, 1));
  TEST_ASSERT_EQUAL(12, intk_number_from_to(1234567890, 0, 2));
  TEST_ASSERT_EQUAL(123, intk_number_from_to(1234567890, 0, 3));
  TEST_ASSERT_EQUAL(1234, intk_number_from_to(1234567890, 0, 4));
  TEST_ASSERT_EQUAL(12345, intk_number_from_to(1234567890, 0, 5));
  TEST_ASSERT_EQUAL(123456, intk_number_from_to(1234567890, 0, 6));
  TEST_ASSERT_EQUAL(1234567, intk_number_from_to(1234567890, 0, 7));
  TEST_ASSERT_EQUAL(12345678, intk_number_from_to(1234567890, 0, 8));
  TEST_ASSERT_EQUAL(123456789, intk_number_from_to(1234567890, 0, 9));
  TEST_ASSERT_EQUAL(1234567890, intk_number_from_to(1234567890, 0, 10));
  TEST_ASSERT_EQUAL(234567890, intk_number_from_to(1234567890, 1, 10));
  TEST_ASSERT_EQUAL(34567890, intk_number_from_to(1234567890, 2, 10));
  TEST_ASSERT_EQUAL(4567890, intk_number_from_to(1234567890, 3, 10));
  TEST_ASSERT_EQUAL(567890, intk_number_from_to(1234567890, 4, 10));
  TEST_ASSERT_EQUAL(67890, intk_number_from_to(1234567890, 5, 10));
  TEST_ASSERT_EQUAL(7890, intk_number_from_to(1234567890, 6, 10));
  TEST_ASSERT_EQUAL(890, intk_number_from_to(1234567890, 7, 10));
  TEST_ASSERT_EQUAL(90, intk_number_from_to(1234567890, 8, 10));
  TEST_ASSERT_EQUAL(0, intk_number_from_to(1234567890, 9, 10));
}