#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>

//Sorting algorithm function utilizing bubble sort
//Function will interact with array elements through pointers
void bubbleSort(int* a, int n) {
    int sorted = 0;
    int k = n;

    //Loop will continue until the array is appropiately sorted
    while (!sorted) {
        sorted = -1;

        for (int i = 0; i < k - 1; i++) {      //Since we're interacting with array elements through pointers, we'll use *(a + i) to access an element.
            if (*(a + i) > * (a + i + 1)) {     //If the array element before the next element is larger, swap elements.
                sorted = 0;                    //The sorted list will also be in ascending order. 
                int temp = *(a + i);            //Temp stores the value at the current array index.
                *(a + i) = *(a + i + 1);        //The current array index stores the smaller number from the next array index element.
                *(a + i + 1) = temp;            //The next array index element stores the larger element stored in temp
            }
        }
        k--;
    }
}

//Sorting algorithm function utilizing selection sort
//Function will interact with array elements through pointers
void selectionSort(int* a, int n) {
    for (int i = 0; i < n - 1; i++) {
        int minPosition = i;            //minPosition will be set to the first unsorted element

        for (int j = i + 1; j < n; j++)
            if (*(a + j) < *(a + minPosition)) {           //The minimum element will be set by determining if the next element is less than                                                           
                minPosition = j;                           //the previous unsorted element.
            }

        int temp = *(a + minPosition);      //temp will store the minimum position element
        *(a + minPosition) = *(a + i);      //The minPosition will be swapped with the first unsorted position
        *(a + i) = temp;                    //The first unsorted position will now hold the value in the minimum position
    }
}

//Function to calculate the mean of values in an array.
//Function will also interact with array elements through pointers
double mean(int* a, int n) {
    double valueSum = 0;

    for (int i = 0; i < n; i++) {
        valueSum += *(a + i) * 1.0;   //valueSum stores the sum of values by adding each value at each index in the array. Cast elements to type double.
    }

    return(valueSum / n);   //return mean value
}

//Function to calculate the median of values in an array.
//Function will also interact with array elements through pointers
double median(int* a, int n) {
    //When an even number of elements is present in the list, the two middle values in the array will be added and then divided by 2
    //n will be divided by two to reach the middle element. The next middle element will be found by subtracting 1 from n.
    //A double typecast to the first middle element will be made to prevent potential overflow.
    if (n % 2 == 0) {
        return(((double)*(a + (n / 2)) + *(a + (n / 2) - 1)) / 2.0);
    }

    //Otherwise return the middle element. n will be divided by two to reach the middle element. 
    else {
        return *(a + (n / 2));
    }
}

//Function to calculate the mode of values in an array.
//Function will also interact with array elements through pointers
int mode(int* a, int n) {
    int maxValueCount = 0;
    int maxValue = 0;

    //Iterates through the entire array
    for (int i = 0; i < n; i++) {
        int valueCount = 0;

        //Inner loop used to compare elements in array
        for (int j = 0; j < n; j++) {
            if (*(a + j) == *(a + i)) {     //If an element is equal to another element at least once,
                valueCount++;               //The count for the appearances of that element is updated.
            }
        }

        //If the number of appearances of an element is more than the previous high of appearances,
        //then the new max value of appearances is updated alongside the new value that holds the most appearances in a list.
        if (valueCount > maxValueCount) {
            maxValueCount = valueCount;
            maxValue = *(a + i);
        }
    }

    return maxValue; //return value with most appearances in a list.
}

//Function to print elements in an array as well as the mean, median, and mode values for the array values.
//Function will also interact with array elements through pointers
void printData(int* a, int n) {

    //Iterates through each element in an array and prints them.
    for (int i = 0; i < n; i++) {
        printf("%d ", *(a + i));
    }

    //Information regarding the mean, median, and mode values of a particular array is also printed by using their corresponding functions.
    printf("\n");
    printf("Mean: ");
    printf("%.2f", mean(a, n));
    printf("\n");
    printf("Median: ");
    printf("%.2f", median(a, n));
    printf("\n");
    printf("Mode: ");
    printf("%d", mode(a, n));
    printf("\n\n");
}

int main() {
    int array1[] = { 99, 98, 97, 96, 95, 94, 93, 81, 79, 78, 98, 76, 75, 98, 73, 72, 95, 69, 68, 67, 92, 91,89, 88, 87, 86,98, 84, 83, 82 };
    int array2[] = { 99, 98, 97, 96, 95, 94, 93, 81, 79, 78, 98, 76, 75, 98, 73, 72, 95, 69, 68, 67, 92, 91,89, 88, 87, 86,98, 84, 83, 82 };
    int n = 30;

    //Sort array values using bubble sort then print the sorted list with the mean, median, and mode values.
    bubbleSort(array1, n);
    printf("Bubble sort: ");
    printData(array1, n);

    //Sort array values using selection sort then print the sorted list with the mean, median, and mode values.
    selectionSort(array2, n);
    printf("Selection sort: ");
    printData(array2, n);

    scanf("%d", &n);
}

