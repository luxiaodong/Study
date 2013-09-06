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

    //已经排好序了
    int binary_search(int a[], int p, int r, int value);
    int binary_insert(int a[], int p, int r, int value);
    int reverse_pair_count(int a[], int r);

    bool is_contain_two_value_sum(int a[], int r, int sum);

    //heap
    void heap_heapify(int a[], int p, int r);
    void heap_build(int a[], int r);
    void heap_sort(int a[], int r);
    void heap_delete(int a[],int p, int r);

    //quick
    int partition(int a[], int p, int r);
    int random_partition(int a[], int p, int r);
    void quick_sort(int a[], int p, int r);

    //count 计数, 适合0 ~ k -1内的排序
    void count_sort(int a[], int b[], int r, int k);

    //基排序和桶排序不写了
    //基排序是基于数字从个位，十位，百位依次排序
    //桶排序是讲数字映射到0-1内按0.1-0.2，0.2-0.3排序

    //返回数组a[p .. r) 中第 i小的元素
    int random_select(int a[], int p, int r, int i);
    int mid_number_in_two_order_array(int a[], int ap, int ar, int b[], int bp, int br);

    void print(int a[], int count);
};

#endif // GSORT_H
