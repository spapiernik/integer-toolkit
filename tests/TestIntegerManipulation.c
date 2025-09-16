#include "unity.h"
#include "integer_toolkit.h"

void test_push_front() {
  int number = 0;

  intk_push_front(&number, 0);
  TEST_ASSERT_EQUAL(0, number);
  intk_push_front(&number, 90);
  TEST_ASSERT_EQUAL(90, number);
  intk_push_front(&number, 8);
  TEST_ASSERT_EQUAL(890, number);
  intk_push_front(&number, 7);
  TEST_ASSERT_EQUAL(7890, number);
  intk_push_front(&number, 6);
  TEST_ASSERT_EQUAL(67890, number);
  intk_push_front(&number, 5);
  TEST_ASSERT_EQUAL(567890, number);
  intk_push_front(&number, 4);
  TEST_ASSERT_EQUAL(4567890, number);
  intk_push_front(&number, 23);
  TEST_ASSERT_EQUAL(234567890, number);
  intk_push_front(&number, 1);
  TEST_ASSERT_EQUAL(1234567890, number);
}

void test_push_back() {
  int number = 0;

  intk_push_back(&number, 0);
  TEST_ASSERT_EQUAL(0, number);
  intk_push_back(&number, 12);
  TEST_ASSERT_EQUAL(12, number);
  intk_push_back(&number, 3);
  TEST_ASSERT_EQUAL(123, number);
  intk_push_back(&number, 4);
  TEST_ASSERT_EQUAL(1234, number);
  intk_push_back(&number, 5);
  TEST_ASSERT_EQUAL(12345, number);
  intk_push_back(&number, 6);
  TEST_ASSERT_EQUAL(123456, number);
  intk_push_back(&number, 7);
  TEST_ASSERT_EQUAL(1234567, number);
  intk_push_back(&number, 89);
  TEST_ASSERT_EQUAL(123456789, number);
  intk_push_back(&number, 0);
  TEST_ASSERT_EQUAL(1234567890, number);
}

void test_pop_front_n() {
  int number = 1234567890;

  int popped_value = intk_pop_front_n(&number, 1);
  TEST_ASSERT_EQUAL(234567890, number);
  TEST_ASSERT_EQUAL(1, popped_value);
  popped_value = intk_pop_front_n(&number, 2);
  TEST_ASSERT_EQUAL(4567890, number);
  TEST_ASSERT_EQUAL(23, popped_value);
  popped_value = intk_pop_front_n(&number, 1);
  TEST_ASSERT_EQUAL(567890, number);
  TEST_ASSERT_EQUAL(4, popped_value);
  popped_value = intk_pop_front_n(&number, 1);
  TEST_ASSERT_EQUAL(67890, number);
  TEST_ASSERT_EQUAL(5, popped_value);
  popped_value = intk_pop_front_n(&number, 1);
  TEST_ASSERT_EQUAL(7890, number);
  TEST_ASSERT_EQUAL(6, popped_value);
  popped_value = intk_pop_front_n(&number, 1);
  TEST_ASSERT_EQUAL(890, number);
  TEST_ASSERT_EQUAL(7, popped_value);
  popped_value = intk_pop_front_n(&number, 2);
  TEST_ASSERT_EQUAL(0, number);
  TEST_ASSERT_EQUAL(89, popped_value);
}

void test_pop_back_n() {
  int number = 1234567890;

  int popped_value = intk_pop_back_n(&number, 1);
  TEST_ASSERT_EQUAL(123456789, number);
  TEST_ASSERT_EQUAL(0, popped_value);
  popped_value = intk_pop_back_n(&number, 2);
  TEST_ASSERT_EQUAL(1234567, number);
  TEST_ASSERT_EQUAL(89, popped_value);
  popped_value = intk_pop_back_n(&number, 1);
  TEST_ASSERT_EQUAL(123456, number);
  TEST_ASSERT_EQUAL(7, popped_value);
  popped_value = intk_pop_back_n(&number, 1);
  TEST_ASSERT_EQUAL(12345, number);
  TEST_ASSERT_EQUAL(6, popped_value);
  popped_value = intk_pop_back_n(&number, 1);
  TEST_ASSERT_EQUAL(1234, number);
  TEST_ASSERT_EQUAL(5, popped_value);
  popped_value = intk_pop_back_n(&number, 1);
  TEST_ASSERT_EQUAL(123, number);
  TEST_ASSERT_EQUAL(4, popped_value);
  popped_value = intk_pop_back_n(&number, 2);
  TEST_ASSERT_EQUAL(1, number);
  TEST_ASSERT_EQUAL(23, popped_value);
  popped_value = intk_pop_back_n(&number, 1);
  TEST_ASSERT_EQUAL(0, number);
  TEST_ASSERT_EQUAL(1, popped_value);
}

void test_pop_front() {
  int number = 1234567890;

  int popped_value = intk_pop_front(&number);
  TEST_ASSERT_EQUAL(234567890, number);
  TEST_ASSERT_EQUAL(1, popped_value);
  popped_value = intk_pop_front(&number);
  TEST_ASSERT_EQUAL(34567890, number);
  TEST_ASSERT_EQUAL(2, popped_value);
  popped_value = intk_pop_front(&number);
  TEST_ASSERT_EQUAL(4567890, number);
  TEST_ASSERT_EQUAL(3, popped_value);
  popped_value = intk_pop_front(&number);
  TEST_ASSERT_EQUAL(567890, number);
  TEST_ASSERT_EQUAL(4, popped_value);
  popped_value = intk_pop_front(&number);
  TEST_ASSERT_EQUAL(67890, number);
  TEST_ASSERT_EQUAL(5, popped_value);
  popped_value = intk_pop_front(&number);
  TEST_ASSERT_EQUAL(7890, number);
  TEST_ASSERT_EQUAL(6, popped_value);
  popped_value = intk_pop_front(&number);
  TEST_ASSERT_EQUAL(890, number);
  TEST_ASSERT_EQUAL(7, popped_value);
  popped_value = intk_pop_front(&number);
  TEST_ASSERT_EQUAL(90, number);
  TEST_ASSERT_EQUAL(8, popped_value);
  popped_value = intk_pop_front(&number);
  TEST_ASSERT_EQUAL(0, number);
  TEST_ASSERT_EQUAL(9, popped_value);
  popped_value = intk_pop_front(&number);
  TEST_ASSERT_EQUAL(0, number);
  TEST_ASSERT_EQUAL(0, popped_value);
}

void test_pop_back() {
  int number = 1234567890;

  int popped_value = intk_pop_back(&number);
  TEST_ASSERT_EQUAL(123456789, number);
  TEST_ASSERT_EQUAL(0, popped_value);
  popped_value = intk_pop_back(&number);
  TEST_ASSERT_EQUAL(12345678, number);
  TEST_ASSERT_EQUAL(9, popped_value);
  popped_value = intk_pop_back(&number);
  TEST_ASSERT_EQUAL(1234567, number);
  TEST_ASSERT_EQUAL(8, popped_value);
  popped_value = intk_pop_back(&number);
  TEST_ASSERT_EQUAL(123456, number);
  TEST_ASSERT_EQUAL(7, popped_value);
  popped_value = intk_pop_back(&number);
  TEST_ASSERT_EQUAL(12345, number);
  TEST_ASSERT_EQUAL(6, popped_value);
  popped_value = intk_pop_back(&number);
  TEST_ASSERT_EQUAL(1234, number);
  TEST_ASSERT_EQUAL(5, popped_value);
  popped_value = intk_pop_back(&number);
  TEST_ASSERT_EQUAL(123, number);
  TEST_ASSERT_EQUAL(4, popped_value);
  popped_value = intk_pop_back(&number);
  TEST_ASSERT_EQUAL(12, number);
  TEST_ASSERT_EQUAL(3, popped_value);
  popped_value = intk_pop_back(&number);
  TEST_ASSERT_EQUAL(1, number);
  TEST_ASSERT_EQUAL(2, popped_value);
  popped_value = intk_pop_back(&number);
  TEST_ASSERT_EQUAL(0, number);
  TEST_ASSERT_EQUAL(1, popped_value);
}

void test_insert() {
  int number = 0;

  intk_insert(&number, -10, 123);
  TEST_ASSERT_EQUAL(123, number);
  intk_insert(&number, 10, 890);
  TEST_ASSERT_EQUAL(123890, number);
  intk_insert(&number, 3, 4);
  TEST_ASSERT_EQUAL(1234890, number);
  intk_insert(&number, 4, 567);
  TEST_ASSERT_EQUAL(1234567890, number);
}