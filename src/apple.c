#include <stdio.h>

int n;
int k;
int A[100000];

// int => bool の関数pが単調(p(x) >= p(x-1))のとき、p(x)==1 なる最小のxを調べる
int binarySearch_P (int arr[], int (*p)(int *,int,int), int left, int right) {
  int l = left;
  int r = right;
  for(int mid = (l+r)/2 ; l < r ; mid = (l + r) / 2) {
    if (p(arr,k,mid)) r = mid;
    else l = mid + 1;
  }
  return r;
}

// 小数点以下を全て切り上げる割り算
int Div(unsigned int x, unsigned int y) {
  return (x + y - 1) / y;
}

// 全ての人がりんごを持ち帰れるか調べる。
int canTakeOut(int arr[], int bucketNum, int bucketSize) {
  int tmp = bucketNum;
  if (bucketSize == 0) return 0;
  for (int i=0; i < n; i++) {
    tmp -= Div(arr[i], bucketSize);
    if (tmp < 0) return 0;
  }
  return 1;
}

long int sum(int A[], int n) {
  int s = 0;
  for (int i=0; i<n; i++) s += A[i];
  return s;
}

// 配列の最大値を求める
int max(int arr[], int n) {
  int m = arr[0];
  for(int i=1; i<n; i++) {
    if (m < arr[i]) m = arr[i];
  }
  return m;
}

int main(){
  scanf("%d%d", &n, &k);
  for(int i = 0; i < n; i++){
    scanf("%d", &A[i]);
  }
  printf("%d\n", binarySearch_P(A, canTakeOut, (sum(A, n)-1)/k, (max(A, n)+k/n-1)/(k/n)));
  return 0;
}
