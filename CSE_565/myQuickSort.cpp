//
//  myQuickSort.cpp
//  CSE_565
//
//  Created by samai on 8/24/20.
//  Copyright © 2020 samai. All rights reserved.
//

#include "myQuickSort.h"


int middle;

void mySort(int mArray[], int lt, int rt)
{
        
    if(lt < rt)
    {
        middle = partition(mArray, lt, rt);

        mySort(mArray, lt, middle-1);
        mySort(mArray, middle + 1, rt);
    }
}

void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int array[], int left, int right)
{
    int pivot = array[right];
    int i = left - 1;
    
    for(int j = left; j <= right - 1; j++)
    {
        if(array[j] < pivot)
        {
            i++;
            swap(&array[i], &array[j]);
        }
    }
    swap(&array[i+1], &array[right]);

    return (i + 1);
}

