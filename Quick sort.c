#include<stdio.h>//19121
int part(int arr[], int l, int h) {
    int pivot = arr[h];
    int i = l - 1;

    for (int j = l; j < h; j++) {
        if (arr[j] < pivot) {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    int temp = arr[i + 1];
    arr[i + 1] = arr[h];
    arr[h] = temp;

    return i + 1;
}

void quick(int arr[], int l, int h) {
    if (l >= h){
        return;
    }
    
        int pi = part(arr, l, h);
        quick(arr, l, pi - 1);
        quick(arr, pi + 1, h);
    
}

int main() {
    int n;
    printf("Enter the no. elemts want to enter::\n");
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++){
        printf("Enter the %d element:",i+1);
        scanf("%d",&arr[i]);
    }
    int no = sizeof(arr) / sizeof(arr[0]);

    quick(arr, 0, no - 1);

    for (int i = 0; i < no; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
