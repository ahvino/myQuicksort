//
//  SortTestCases.cpp
//  CSE_565
//
//  Created by samai on 9/6/20.
//  Copyright © 2020 samai. All rights reserved.
//

#define CATCH_CONFIG_MAIN //provides a main() for test cases

#include <stdio.h>
#include <vector>
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

TEST_CASE("2", "[empty array]")
{
    int arr[] = {};
    int size = sizeof(arr)/sizeof(arr[0]);
    mySort(arr, 0, size-1);

    std::vector<int> vec;
    
    for(int i = 0; i < size; i++)
    {
        vec.push_back(arr[i]);
    }
    REQUIRE(vec.size() == 0);
}


TEST_CASE("3", "[long array]")
{
    int vec[] = {10, 4, 3, 15, 14, 7, 9, 12, 23, 500, 67, 0, 90, 4, 3, 3, 7, 9, 90, 13, 50, 200, 201, 204,199, 54, 3, 2};
    int size = sizeof(vec)/sizeof(vec[0]);
    mySort(vec, 0, size-1);

    REQUIRE(isSorted(vec) == true);
}

TEST_CASE("4", "[negative values]")
{
    int vec[] = {-10, 147, -19, -12, -23, -500, -67, -0, -90, -4, -9, -54, -3, -2};
    int size = sizeof(vec)/sizeof(vec[0]);
    mySort(vec, 0, size-1);

    REQUIRE(isSorted(vec) == true);
}


TEST_CASE("5", "[duplicate values]")
{
    int vec[] = {10, 10, 19, 12, 23, 500, 10, 0, 90, 4, 10, 54, 3, 10};
    int size = sizeof(vec)/sizeof(vec[0]);
    mySort(vec, 0, size-1);

    REQUIRE(isSorted(vec) == true);
}


TEST_CASE("6", "[negative and positive values]")
{
    int vec[] = {10, -10, 19, 12, 23, -500, 10, 0, 90, 4, -10, 54, -3, 10};
    int size = sizeof(vec)/sizeof(vec[0]);
    mySort(vec, 0, size-1);

    REQUIRE(isSorted(vec) == true);
}


TEST_CASE("7", "[best case sorted]")
{
    int vec[] = {10, 11, 19, 22, 23, 25, 40, 50, 90, 401, 1000};
    int size = sizeof(vec)/sizeof(vec[0]);
    mySort(vec, 0, size-1);

    REQUIRE(isSorted(vec) == true);
}


TEST_CASE("8", "[worst case all unsorted]")
{
    int vec[] = {100, 500, 191, 121, 23, 10, 10, 0, -4, -10};
    int size = sizeof(vec)/sizeof(vec[0]);
    mySort(vec, 0, size-1);

    REQUIRE(isSorted(vec) == true);
}
