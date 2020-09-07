//
//  SortTestCases.cpp
//  CSE_565
//
//  Created by samai on 9/6/20.
//  Copyright © 2020 samai. All rights reserved.
//

#define CATCH_CONFIG_MAIN //provides a main() for test cases

#include <stdio.h>
#include "catch.h"
#include "myQuickSort.h"


bool isSorted(int array[])
{
    bool sorted = true;
    int size = sizeof(array)/sizeof(array[0]);
    int prev = array[0];
    
    for(int i = 0; i < size; i++)
    {
        if(i > 0)
        {
            if(prev > array[i])
            {
                sorted = false;
            }
        }
        prev = array[i];
    }
    return sorted;
}

TEST_CASE("1", "[isSorted]")
{
    int vec[] = {5, 10, 4, 3, 15, 14, 7, 9, 10, 12};
    int size = sizeof(vec)/sizeof(vec[0]);
    mySort(vec, 0, size-1);

    REQUIRE(isSorted(vec) == true);
}



