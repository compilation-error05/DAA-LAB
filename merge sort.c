#include<stdio.h>
void partition(int arr[], int h, int l, int m) {
    int an = m - l + 1;
    int bn = h - m;
    int a[an];
    int b[bn];
    int i, j, k;
    
    for (i = 0; i < an; i++) {
        a[i] = arr[l + i];
    }
    for (j = 0; j < bn; j++) {
        b[j] = arr[m + 1 + j];
    }
    
    i = 0;j = 0;k = l;
    while (i < an && j < bn) {
        if (b[j] > a[i]) {
            arr[k++] = a[i++];
        } else {
            arr[k++] = b[j++];
        }
    }
    while (i < an) {
        arr[k++] = a[i++];
    }
    while (j < bn) {
        arr[k++] = b[j++];
    }
}

void merge(int arr[], int l, int h) {
    if (l >= h) {
        return;
    }
    int m = (l + h) / 2;
    merge(arr, l, m);
    merge(arr, m + 1, h);
    partition(arr, h, l, m);
}

int main() {
    int arr[7] = {90, 4, 12, 11, 3333, 0, 1111};
    merge(arr, 0, 7 - 1);
    for (int i = 0; i < 7; i++) {
        printf("%d\n", arr[i]);
    }
    return 0;
}
