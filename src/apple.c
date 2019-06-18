#include <stdio.h>

int n;
int k;
int A[100000];

// int => bool の関数pが単調(p(x) >= p(x-1))のとき、p(x)==1 なる最小のxを調べる
int binarySearch_P (int arr[], int (*p)(int *,int,int), int left, int right) {
  if (left >= right) return right;
  
  int mid = (left + right) / 2;

  if (p(arr,k,mid)) return binarySearch_P(arr, p, left, mid);
  else return binarySearch_P(arr, p, mid + 1, right);
}

// 小数点以下を全て切り上げる割り算
int Div(unsigned int x, unsigned int y) {
  if (x % y == 0) return x / y;
  else return (x / y) + 1;
}

// 全ての人がりんごを持ち帰れるか調べる。
int check(int arr[], int index, int backetNum, int backetSize) {
  if (backetNum < 0) return 0;
  if (backetSize == 0) return 0;
  if (index >= n) return 1;
  return check(arr, index+1, backetNum - Div(arr[index], backetSize), backetSize);
}
int canTakeOut(int arr[], int backetNum, int backetSize) {
  return check(arr, 0, backetNum, backetSize);
}

int main(){
  scanf("%d%d", &n, &k);
  for(int i = 0; i < n; i++){ 
    scanf("%d", &A[i]);
  }
  printf("%d\n", binarySearch_P(A, canTakeOut, 0, A[n-1]));

  return 0;
}
