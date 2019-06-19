#include <stdio.h>

int n;
int k;
int A[100000];

// int => bool の関数pが単調(p(x) >= p(x-1))のとき、p(x)==1 なる最小のxを調べる
int binarySearch_P (int arr[], int (*p)(int), int left, int right) {
  if (left >= right) return right;
  
  int mid = (left + right) / 2;

  if (p(mid)) return binarySearch_P(arr, p, left, mid);
  else return binarySearch_P(arr, p, mid + 1, right);
}

// 仕事量がもっとも多い人の仕事量がmaxTaskである場合、k人に仕事を配分できるか調べる
int canAssign(int maxTask) {
  int assign = k;
  int tmp = 0;
  for(int i=0; i < n; i++) {
    tmp += A[i];
    if (tmp > maxTask) {
      assign -= 1;
      tmp = A[i];
      if (assign <= 0) return 0;
      if (A[i] > maxTask) return 0;
    }
  }
  return 1;
}

// 配列の要素の合計を求める
int sum(int arr[], int n) {
  int sum = 0;
  for (int i=0; i < n; i++) {
    sum += arr[i];
  }
  return sum;
}

// 配列の最大値
// int max (int arr[], int n) {
//   int m = arr[0];
//   for (int i = 0; i < n; i++) {
//     if (m < arr[i]) m = arr[i];
//     return m;
//   }
// }

int main(){
  int i, lb, ub;
  scanf("%d%d", &n, &k);
  for(i = 0; i < n; i++){
    scanf("%d", &A[i]);
  }

  printf("%d\n", binarySearch_P(
    A,
    canAssign,
    A[n-1], /* max(A) でも良かったが、多少よい下限を取るためにわざわざO(n)の計算をさせるのもいかがなものかと思った */
    sum(A, n)
  ));

  return 0;
}
