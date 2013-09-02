#ifndef GSORT_H
#define GSORT_H

//以数字为例, 从小到大排列
class GSort
{
public:
    GSort();

public:
    void insert_sort(int a[], int r);
    void binary_insert_sort(int a[], int r);
    void merge(int a[], int p, int q, int r);
    void merge_sort(int a[], int p, int r);

    int binary_search(int a[], int p, int r, int value);
    int binary_insert(int a[], int p, int r, int value);
    int reverse_pair_count(int a[], int r);

    bool is_contain_two_value_sum(int a[], int r, int sum);

    //heap
    heap_heapify(int a[], int p, int r);
    heap_build(int a[], int r);
    heap_sort(int a[], int r);
    heap_extract_max(int a[], int r);
    heap_insert(int a[], key, int r);
    heap_delete(int a[], int p, int r);

private:
    void print(int a[], int count);
};

#endif // GSORT_H
