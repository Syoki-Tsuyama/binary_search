#include <stdio.h>

int n;
int k;
int A[100000];

// 小数点以下を全て切り上げる割り算
int Div(unsigned int x, unsigned int y) {
  return (x + y - 1) / y;
}

// boolへの関数pが単調減少(p(x) <= p(x-1))のとき、p(x)==1 なる最大のxを調べる
int binarySearch_P (int (*p)(int,int), int left, int right) {
  int l = left;
  int r = right;
  for(int mid = (l+r)/2 ; l < r ; mid = Div(l+r, 2)) {
    if (p(mid, k)) l = mid;
    else r = mid-1;
  }
  return l;
}

// 長さlenの槍をspearNum本作れるか調べる
int canMakeSpears(int len, int spearNum) {
  if (len <= 0) return 0;
  int tmp = spearNum;
  for (int i=0; i < n; i++) {
    tmp -= A[i] / len;
    if (tmp <= 0) return 1;
  }
  return 0;
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
  printf("%d\n", binarySearch_P(canMakeSpears, 0, max(A, n)));
  return 0;
}
