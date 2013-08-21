#ifndef GSORT_H
#define GSORT_H

//以数字为例, 从小到大排列
class GSort
{
public:
    GSort();

public:
    void insertion_sort(int a[], int count);
    void merge(int a[], int p, int q, int r);
    void merge_sort(int a[], int p, int r);

private:
    void print(int a[], int count);
};

#endif // GSORT_H
