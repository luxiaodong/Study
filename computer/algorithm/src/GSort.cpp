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
        qDebug()<<a[i];
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

