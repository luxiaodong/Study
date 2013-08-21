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
    void merge();
    void merge_sort();
};

#endif // GTEST_H
