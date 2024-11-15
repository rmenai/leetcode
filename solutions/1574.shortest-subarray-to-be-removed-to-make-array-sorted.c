#include <stdbool.h>

// @leet start
int findLengthOfShortestSubarray(int* arr, int arrSize) {
  int right = arrSize - 1;
  while (right > 0 && arr[right] >= arr[right - 1]) {
    right--;
  }

  int answer = right;
  int left = 0;
  while (left < right && (left == 0 || arr[left - 1] <= arr[left])) {
    while (right < arrSize && arr[left] > arr[right]) {
      right++;
    }

    int distance = right - left - 1;
    if (distance < answer) {
      answer = distance;
    }

    left++;
  }

  return answer;
}
// @leet end
