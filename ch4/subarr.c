// Find max sum of subarray with recursion
// Find MaxSubArr on the left and on the right
// Find MaxSubArr crosing the mid

#include <stdio.h>
#define LOW -1000000

typedef struct MaxSub { int left, right, sum; } MaxSub;

MaxSub FindMaxCrossingSubArr(int *A, int low, int mid, int high) {
    MaxSub temp;
    int left_sum = LOW;
    int sum = 0;
    for (int i = mid; i >= low; i--) {
        sum += A[i];
        if (sum > left_sum) {
            left_sum = sum;
            temp.left = i;
        }
    }
    int right_sum = LOW;
    sum = 0;
    for (int i = mid + 1; i <= high; i++) {
        sum += A[i];
        if (sum > right_sum) {
            right_sum = sum;
            temp.right = i;
        }
    }
    temp.sum = left_sum + right_sum;
    return temp;
}

MaxSub FindMaximumSubArr(int *A, int low, int high) {
    if (low == high)  // base case: only 1 element
    {
        MaxSub temp;
        temp.left = low;
        temp.right = high;
        temp.sum = A[low];
        return temp;
    } else {
        int mid = (low + high) / 2;
        MaxSub LeftSub = FindMaximumSubArr(A, low, mid);
        MaxSub RightSub = FindMaximumSubArr(A, mid + 1, high);
        MaxSub CrossSub = FindMaxCrossingSubArr(A, low, mid, high);
        if (LeftSub.sum > RightSub.sum && LeftSub.sum > CrossSub.sum)
            return LeftSub;
        else if (RightSub.sum > LeftSub.sum && RightSub.sum > CrossSub.sum)
            return RightSub;
        return CrossSub;
    }
}

// Brute force
int SumArr(int *A, int low, int high) {
    int sum = 0;
    for (int i = low; i, i <= high; i++) {
        sum += A[i];
    }
    return sum;
}

MaxSub FindMaximumSubArrBrute(int *A, int low, int high) {
    MaxSub temp;
    temp.sum = LOW;
    for (int i = low; i <= high; i++) {
        for (int j = low; j <= high; j++) {
            int sum = SumArr(A, i, j);
            if (sum > temp.sum) {
                temp.sum = sum;
                temp.left = i;
                temp.right = j;
            }
        }
    }
    return temp;
}

// 4.1-5  nonrecursive linear-time

MaxSub FindMaximumSubArrLinear(int *A, int low, int high) {
    MaxSub temp;
    for (int i = low; i <= high; i++) {
        for (int j = low; j <= high; j++) {
            int k = 0;
        }
    }
    return temp;
}

int main() {
    int A[] = {13, -3, -25, 20, -3,  -16, -23, 18,
               20, -7, 12,  -5, -22, 15,  -4,  7};
    int size = sizeof(A) / sizeof(A[0]);
    MaxSub temp = FindMaximumSubArr(A, 0, size - 1);
    MaxSub temp2 = FindMaximumSubArrBrute(A, 0, size - 1);
    printf("%d %d %d\n", temp.left, temp.right, temp.sum);
    printf("%d %d %d\n", temp2.left, temp2.right, temp2.sum);
    return 0;
}
