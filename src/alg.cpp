// Copyright 2021 NNTU-CS

int get(int* arr, int i) {
  return *(arr + i);
}

int countPairs1(int *arr, int len, int value) {
  int cnt = 0;
  for (int i = 0; i < len; i++) {
    for (int j = i + 1; j < len; j++) {
      if (get(arr, i) + get(arr, j) == value) cnt++;
    }
  }
  return cnt;
}

int countPairs2(int *arr, int len, int value) {
  int cnt = 0, i = 0;
  while (i < len) {
    int target = value - get(arr, i);
    if (target < get(arr, i)) break;
    int j = i + 1;
    while (j < len) {
      if (get(arr, j) == target) {
        cnt++; j++;
        while (j < len && get(arr, j) == target) {
          cnt++; j++;
        }
        break;
      }
      j++;
    }
    i++;
  }
  return cnt;
}

int countPairs3(int* arr, int len, int value) {
  int cnt = 0;
  for (int i = 0; i < len; i++) {
    int target = value - get(arr, i);
    if (target < get(arr, i)) break;
    int L = i + 1, R = len - 1;
    while (L < R) {
      int mid = L + (R - L) / 2;
      if (get(arr, mid) < target) L = mid + 1;
      else R = mid;
    }
    if (get(arr, L) == target) {
      cnt++;
      while (L + 1 < len && get(arr, L) == get(arr, L + 1)) {
        cnt++; L++;
      }
    }
  }
  return cnt;
}
