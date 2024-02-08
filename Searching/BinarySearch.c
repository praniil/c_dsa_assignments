#include <stdio.h>

void BinarySearch(int array[], int length, int search)
{
    int firstIndex = 0;
    int lastIndex = length - 1;
    int middleIndex;
    while (firstIndex <= lastIndex)
    {
        middleIndex = (firstIndex + lastIndex) / 2;
        if (array[middleIndex] == search)
        {
            printf("item found: %d", array[middleIndex]);
            return;
        }
        else if (array[middleIndex] < search)
        {
            firstIndex = middleIndex + 1;
        }
        else
        {
            lastIndex = middleIndex - 1;
        }
    }
    printf("Number not found");
}

int main()
{
    int array[] = {1, 2, 3, 4, 5, 6, 7};
    array[1000] = 25;

    int length = sizeof(array) / sizeof(array[0]);
    int search = 7;
    BinarySearch(array, length, search);
}