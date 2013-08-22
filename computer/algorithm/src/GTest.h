#ifndef GTEST_H
#define GTEST_H

#include "GSort.h"

class GTest
{
public:
    GTest();

public:
    void test();

private:
    void insert_sort();
    void binary_insert_sort();
    void merge();
    void merge_sort();
    void binary_insert();
    void binary_search();
};

#endif // GTEST_H
