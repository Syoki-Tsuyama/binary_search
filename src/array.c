#include<stdio.h>

int a[100000];

int binarySearch(int arr[], int target, int left, int right) {
  int l = left;
  int r = right;
  for(int mid = (l+r)/2 ; l < r ; mid = (l + r) / 2) {
    if (arr[mid] < target) l = mid + 1;
    else r = mid;
  }
  return r;
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
