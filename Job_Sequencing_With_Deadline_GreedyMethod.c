#include <stdio.h>
#include <stdlib.h>

#define max 100

typedef struct node {
    char id[6];
    int deadline;
    int profit;
} job;

void func(job jobs[], int n);
int min(int a, int b);

int main() {
    int n;

    printf("Enter the number of jobs: ");
    scanf("%d", &n);

    job jobs[max];
    job temp;

    // Input jobs information from user
    for (int i = 0; i < n; i++) {
        printf("Enter job ID, profit, and deadline for job %d: ", i + 1);
        scanf("%s %d %d", jobs[i].id, &jobs[i].profit, &jobs[i].deadline);
    }

    // Sort jobs based on profit (descending order)
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (jobs[j].profit > jobs[i].profit) {
                temp = jobs[i];
                jobs[i] = jobs[j];
                jobs[j] = temp;
            }
        }
    }

    printf("\nID  PROFIT  DEADLINE\n");
    for (int i = 0; i < n; i++) {
        printf("%s  ", jobs[i].id);
        printf("%d    ", jobs[i].profit);
        printf("%d  \n", jobs[i].deadline);
    }

    func(jobs, n);

    return 0;
}

void func(job jobs[], int n) {
    int maxd = 0;
    int timestamp[max] = {0};

    // Find the maximum deadline
    for (int i = 0; i < n; i++) {
        if (maxd < jobs[i].deadline) {
            maxd = jobs[i].deadline;
        }
    }

    int filledtime = 0;
    for (int i = 1; i <= maxd; i++) {
        timestamp[i] = -1;
    }

    for (int i = 1; i <= n; i++) {
        int k = jobs[i - 1].deadline;
        while (k >= 1) {
            if (timestamp[k] == -1) {
                timestamp[k] = i - 1;
                filledtime++;
                break;
            }
            k--;
        }
        if (filledtime == maxd) {
            break;
        }
    }

    printf("\nREQUIRED JOBS:\n");
    for (int i = 1; i <= maxd; i++) {
        if (timestamp[i] != -1) {
            printf("%s", jobs[timestamp[i]].id);
            if (i < maxd) {
                printf("-->");
            }
        }
    }

    int maxprofit = 0;
    for (int i = 1; i <= maxd; i++) {
        if (timestamp[i] != -1) {
            maxprofit += jobs[timestamp[i]].profit;
        }
    }
    printf("\nMAX PROFIT::%d\n", maxprofit);
}

int min(int a, int b) {
    if (a > b) {
        return b;
    } else {
        return a;
    }
}
