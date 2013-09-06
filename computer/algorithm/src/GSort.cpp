#include "GSort.h"
#include <stdio.h>
#include <stdlib.h>
#include <QDebug>

GSort::GSort()
{
}

void GSort::print(int a[], int count)
{
    qDebug()<<"\n--------begin--------\n";
    for(int i = 0; i < count; ++i)
    {
        qDebug()<<i<<"---->"<<a[i];
    }
    qDebug()<<"\n--------end--------\n";
}


//--bad o(n^2)
//--good o(n)
void GSort::insert_sort(int a[], int r)
{
    for(int i = 1; i < r; ++i)
    {
        int key = a[i];
        int insertPos = i;
 //这里要从i到0,才能保证在 已排好序的情况下o(n)内完成,因为是从小到大排序
 //如果要从大到小排序,则要从0到i才能保证已排序下情况系下o(n)内完成
        while(insertPos > 0)
        {
            if(key < a[insertPos - 1])
            {
                insertPos--;
            }
            else
            {
                break;
            }
        }

        int j = i;
        while(j > insertPos)
        {
            a[j] = a[j-1];
            j--;
        }

        a[insertPos] = key;

        this->print(a, r);
    }
}

void GSort::binary_insert_sort(int a[], int r)
{
    for(int i = 1; i < r; ++i)
    {
        int key = a[i];
        int insertPos = this->binary_insert(a, 0, i, key);

        int j = i;
        while(j > insertPos)
        {
            a[j] = a[j-1];
            j--;
        }

        a[insertPos] = key;

        this->print(a, r);
    }
}

//--对已经排好序的两段数据合并
//a[p..q-1], a[q..r-1]
void GSort::merge(int a[], int p, int q, int r)
{
    int* b = (int*)malloc(sizeof(int)*(r - p));
    int index1 = p;
    int index2 = q;

    int index3 = 0;
    while(1)
    {
        if( a[index1] < a[index2] )
        {
            b[index3++] = a[index1++];
        }
        else
        {
            b[index3++] = a[index2++];
        }

        if (index1 == q)
        {
            while(index2 < r)
            {
                b[index3++] = a[index2++];
            }
            break;
        }

        if (index2 == r)
        {
            while(index1 < q)
            {
                b[index3++] = a[index1++];
            }
            break;
        }
    }

    for(int i = 0; i < index3; ++i)
    {
        a[p + i] = b[i];
    }

    print(b, index3);
    free(b);
}

void GSort::merge_sort(int a[], int p, int r)
{
    if (p + 1 < r)
    {
        int q = (p+r)/2;
        this->merge_sort(a, p, q);
        this->merge_sort(a, q, r);
        this->merge(a, p, q, r);
    }
}

int GSort::binary_search(int a[], int p, int r, int value)
{
    int left = p;
    int right = r;

    while(left < right)
    {
        int middle = left + ((right - left)>>1);

        if(value < a[middle])
        {
            right = middle;
        }
        else if(value > a[middle])
        {
            left = middle + 1;
        }
        else
        {
            return middle;
        }
    }

    return -1;
}

int GSort::binary_insert(int a[], int p, int r, int value)
{
    int left = p;
    int right = r;

    while(left < right)
    {
        int middle = left + ((right - left)>>1);

        if(value < a[middle])
        {
            right = middle;
        }
        else if(value > a[middle])
        {
            left = middle + 1;
        }
        else
        {
            return middle;
        }
    }

    if( value > a[left] )
    {
        return left + 1;
    }

    return left;
}

//o(logn)
int GSort::reverse_pair_count(int a[], int r)
{
    int count = 0;
    for(int i = 1; i < r; ++i)
    {
        int key = a[i];
        int insertPos = this->binary_insert(a, 0, i, key);
        count += i - insertPos;
        int j = i;
        while(j > insertPos)
        {
            a[j] = a[j-1];
            j--;
        }

        a[insertPos] = key;

        this->print(a, r);
    }

    return count;
}

bool GSort::is_contain_two_value_sum(int a[], int r, int sum)
{
    for(int i = 1; i < r; ++i)
    {
        int key = a[i];
//question ?
        if( this->binary_search(a, 0, i, sum - key) != -1)
        {
            return true;
        }

        int insertPos = this->binary_insert(a, 0, i, key);

        int j = i;
        while(j > insertPos)
        {
            a[j] = a[j-1];
            j--;
        }

        a[insertPos] = key;

        this->print(a, r);
    }

    return false;
}

//parent = (i-1)/2
//left = i*2 + 1;
//right = i*2 + 2;

void GSort::heap_heapify(int a[], int p, int r)
{
    int largest = p;
    int left = 2*p + 1;
    int right = 2*p + 2;

    if(left < r && a[left] > a[largest])
    {
        largest = left;
    }

    if(right < r && a[right] > a[largest])
    {
        largest = right;
    }

    if(largest != p)
    {
        int temp = a[p];
        a[p] = a[largest];
        a[largest] = temp;
        this->heap_heapify(a, largest, r);
    }
}

void GSort::heap_build(int a[], int r)
{
    for(int i = (r-1)/2; i >= 0; i--)
    {
        this->heap_heapify(a, i, r);
    }
}

void GSort::heap_sort(int a[], int r)
{
    this->heap_build(a, r);

    for(int i = r-1; i >= 0; --i)
    {
        int temp = a[i];
        a[i] = a[0];
        a[0] = temp;
        this->heap_heapify(a, 0, i);
    }
}

void GSort::heap_delete(int a[],int p, int r)
{
    if(p != r-1)
    {
        int temp = a[p];
        a[p] = a[r-1];
        a[r-1] = temp;
        int parent = (p-1)/2;

        if(p > 0 && a[parent] < a[p])
        {
            while(1)
            {
                temp = a[p];
                a[p] = a[parent];
                a[parent] = temp;
                p = parent;

                if(p == 0 || a[parent] >= a[p])
                {
                    break;
                }
            }
        }
        else
        {
            this->heap_heapify(a, p, r-1);
        }
    }
}

int GSort::partition(int a[], int p, int r)
{
    int key = a[p];//一个随机化版本是取其中的数，而不是第一个，保证平均值为nlgn
    int i = 0;
    int j = r - 1;

    while(1)
    {
        while(a[j] > key)
        {
            j--;
        }

        while(a[i] < key)
        {
            i++;
        }

        if(i < j)
        {
            int temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
        else
        {
            break;
        }
    }

    return j;
}

void GSort::quick_sort(int a[], int p, int r)
{
    if(p < r)
    {
        int q = this->partition(a,p,r);
        this->quick_sort(a,p,q);
        this->quick_sort(a,q+1,r);
    }
}

//a<--in
//b-->out
void GSort::count_sort(int a[], int b[], int r, int k)
{
    int* c = (int*)malloc(sizeof(int)*(k));
    for(int i = 0; i < k; ++i)
    {
        c[i] = 0;
    }

    //记录等于i的元素的个数
    for(int i = 0; i < r; ++i)
    {
        c[ a[i] ]++;
    }

    //记录小于等于i的元素个数
    for(int i = 1; i < k; ++i)
    {
        c[i] += c[i-1];
    }

    for(int i = r-1; i >= 0; --i)
    {
        b[ c[ a[i] ] - 1 ] = a[i];
        c[ a[i] ]--;
    }

    free(c);
}
