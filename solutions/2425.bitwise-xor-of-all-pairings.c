// @leet start
int xorAllNums(int* nums1, int nums1Size, int* nums2, int nums2Size) {
  int total = 0;
  if (nums2Size % 2 == 1) {
    for (int i = 0; i < nums1Size; i++) {
      total ^= nums1[i];
    }
  }

  if (nums1Size % 2 == 1) {
    for (int i = 0; i < nums2Size; i++) {
      total ^= nums2[i];
    }
  }

  return total;
}
// @leet end
