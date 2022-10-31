#include <stdio.h>
#include <time.h>

void printArray(int n, int a[])
{
  for (int i = 0; i < n; i++)
  {
    printf("%d ", a[i]);
  }
  printf("\n");
}

int partition(int a[], int low, int high)
{
  int pivot = a[low];
  int i = low + 1;
  int j = high;
  int temp;

  do
  {
    while (a[i] <= pivot)
    {
      i++;
    }

    while (a[j] > pivot)
    {
      j--;
    }

    if (i < j)
    {
      temp = a[i];
      a[i] = a[j];
      a[j] = temp;
    }

  } while (i < j);

  temp = a[low];
  a[low] = a[j];
  a[j] = temp;

  return j;
}

void Quick_Sort(int a[], int low, int high)
{
  int PivotIndex;

  if (low < high)
  {
    PivotIndex = partition(a, low, high);
    Quick_Sort(a, low, PivotIndex - 1);
    Quick_Sort(a, PivotIndex + 1, high);
  }
}

int main()
{
  clock_t start, end;

  double cpu_time_used;
  int key, n, arr[n];

  printf("Total number of elements : \n");
  scanf("%d", &n);

  printf("Enter The elements : \n");
  for (int i = 0; i < n; i++)
  {
    scanf("%d", &arr[i]);
  }

  printf("Before Sorting Array : \t");
  printArray(n, arr);

  start = clock();
  Quick_Sort(arr, 0, n - 1);
  end = clock();

  printf("After Sorting Array : \n");
  printArray(n, arr);

  cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;

  printf("\n Running time = %lf", cpu_time_used);
  return 0;
}
