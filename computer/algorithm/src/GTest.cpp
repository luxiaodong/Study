#include "GTest.h"
#include "GSort.h"
#include <stdio.h>
#include <QDebug>

GTest::GTest()
{
}

void GTest::test()
{
    this->binary_insert_sort();
}

void GTest::insert_sort()
{
    int a[] = {5,2,4,6,1,3,0,4,2,7,2,8,9,2,-1};
    //int a[] = {2,4,5,6,1,3};
    GSort sort;
    sort.insert_sort(a, 13);
}

void GTest::binary_insert_sort()
{
    int a[] = {5,2,4,6,1,3,0,4,2,7,2,8,9,2,-1};
    //int a[] = {2,4,5,6,1,3};
    GSort sort;
    sort.insert_sort(a, 13);
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

void GTest::binary_search()
{
    int a[] = {1,2,3,4,6,7,8,9,13,16,19,21,23};
    GSort sort;
    int p = sort.binary_search(a, 0, 13, 0);
    qDebug()<<p;
}

void GTest::binary_insert()
{
    int a[] = {1,2,3,4,6,7,8,9,13,16,19,21,23};
    GSort sort;
    int p = sort.binary_insert(a, 0, 13, 21);
    qDebug()<<p;
}
