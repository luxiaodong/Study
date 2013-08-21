#include "GTest.h"
#include "GSort.h"

GTest::GTest()
{
}

void GTest::test()
{
    this->merge_sort();
}

void GTest::insert_sort()
{
    int a[] = {5,2,4,6,1,3,0,4,2,7,2,8,9,2,-1};
    //int a[] = {2,4,5,6,1,3};
    GSort sort;
    sort.insertion_sort(a, 13);
}

void GTest::merge()
{
    int a[] = {1,3,5,7,9,2,4,6,8};
    GSort sort;
    sort.merge(a,0,5,9);
}

void GTest::merge_sort()
{
    int a[] = {5,2,4,6,1,3,0,4,2,7,2,8,9,2,-1};
    GSort sort;
    sort.merge_sort(a,0,14);
}
