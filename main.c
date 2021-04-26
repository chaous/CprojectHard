#include <stdio.h>

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size){

    int i = 0, j = 0;
    int mergeArray[(nums1Size + nums2Size) / 2 + 1];
    if(nums1Size == 0) {
        while ((i + j) < (nums1Size + nums2Size) / 2 + 1) {
            mergeArray[i + j] = *(nums2 + j);
            ++j;
        }
    }
    else if(nums2Size == 0) {
        while ((i + j) < (nums1Size + nums2Size) / 2 + 1) {
            mergeArray[i + j] = *(nums1 + i);
            ++i;
        }
    }
    else {
        while ((i + j) < (nums1Size + nums2Size) / 2 + 1) {
            if (*(nums1 + i) < *(nums2 + j)) {
                mergeArray[i + j] = *(nums1 + i);
                ++i;
                if (i == nums1Size) {
                    while ((i + j) < (nums1Size + nums2Size) / 2 + 1) {
                        mergeArray[i + j] = *(nums2 + j);
                        ++j;
                    }
                    break;
                }

            } else {
                mergeArray[i + j] = *(nums2 + j);
                ++j;
                if (j == nums2Size) {
                    while ((i + j) < (nums1Size + nums2Size) / 2 + 1) {
                        mergeArray[i + j] = *(nums1 + i);
                        ++i;
                    }
                    break;
                }
            }
        }
    }

    if((nums2Size + nums1Size) % 2 == 1)
        return mergeArray[(nums1Size + nums2Size) / 2 ];
    double a = mergeArray[(nums1Size + nums2Size) / 2 ];
    double b = mergeArray[(nums1Size + nums2Size) / 2 - 1];
    return (a + b) /2;


}

int main() {
    //printf("Hello, World!\n");
    int array1[2] = {1, 2};
    int array2[1] = {3, 4};
    printf("%lf",findMedianSortedArrays(array1, 2, array2, 2));
    return 0;
}
