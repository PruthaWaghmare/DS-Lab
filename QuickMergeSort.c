
#include <stdio.h>

void display(int a[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
}

// Quick Sort
int partition(int a[], int low, int high)
{
    int pivot = a[high], i = low - 1, j, temp;

    for (j = low; j < high; j++)
    {
        if (a[j] < pivot)
        {
            i++;
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    }

    temp = a[i + 1];
    a[i + 1] = a[high];
    a[high] = temp;

    return i + 1;
}

void quickSort(int a[], int low, int high)
{
    if (low < high)
    {
        int p = partition(a, low, high);
        quickSort(a, low, p - 1);
        quickSort(a, p + 1, high);
    }
}

// Merge Sort
void merge(int a[], int low, int mid, int high)
{
    int b[100], i = low, j = mid + 1, k = low;

    while (i <= mid && j <= high)
    {
        if (a[i] <= a[j])
            b[k++] = a[i++];
        else
            b[k++] = a[j++];
    }

    while (i <= mid)
        b[k++] = a[i++];

    while (j <= high)
        b[k++] = a[j++];

    for (i = low; i <= high; i++)
        a[i] = b[i];
}

void mergeSort(int a[], int low, int high)
{
    if (low < high)
    {
        int mid = (low + high) / 2;
        mergeSort(a, low, mid);
        mergeSort(a, mid + 1, high);
        merge(a, low, mid, high);
    }
}

int main()
{
    int a[100], b[100], n, i, choice;

    printf("Enter number of elements (1-100): ");
    scanf("%d", &n);

    if (n < 1 || n > 100)
    {
        printf("Invalid number of elements.\n");
        return 1;
    }

    printf("Enter elements:\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
        b[i] = a[i];
    }

    printf("\n1. Quick Sort\n");
    printf("2. Merge Sort\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    if (choice == 1)
    {
        quickSort(a, 0, n - 1);
        printf("Sorted array using Quick Sort: ");
        display(a, n);
    }
    else if (choice == 2)
    {
        mergeSort(b, 0, n - 1);
        printf("Sorted array using Merge Sort: ");
        display(b, n);
    }
    else
        printf("Invalid choice.\n");

    return 0;
}
