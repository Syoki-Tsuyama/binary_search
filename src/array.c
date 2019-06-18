#include<stdio.h>

int a[100000];

int binarySearch(int arr[], int target, int left, int right) {
  if (left >= right) return right;

  int mid = (right + left) / 2;
  if (arr[mid] < target) return binarySearch(arr, target, mid+1, right);
  else return binarySearch(arr, target, left, mid);
  return 0;
}

int main (void) {
  int n, k;
  scanf("%d%d", &n, &k);
  for(int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }

  printf("%d\n", binarySearch(a, k, 0, n));
  return 0;
}
