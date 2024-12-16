#include <stdlib.h>

// @leet start
struct Heap {
  int** arr;
  int size;
  int capacity;
};

typedef struct Heap heap;

heap* createHeap(int capacity, int** nums);
void insertHelper(heap* h, int index);
void heapify(heap* h, int index);
int* extractMin(heap* h);
void insert(heap* h, int* data);

heap* createHeap(int capacity, int** nums) {
  heap* h = (heap*)malloc(sizeof(heap));

  if (h == NULL) {
    return NULL;
  }

  h->size = 0;
  h->capacity = capacity;

  h->arr = (int**)malloc(capacity * sizeof(int*));

  if (h->arr == NULL) {
    return NULL;
  }

  int i;
  for (i = 0; i < capacity; i++) {
    h->arr[i] = nums[i];
  }

  h->size = i;
  i = (h->size - 2) / 2;
  while (i >= 0) {
    heapify(h, i);
    i--;
  }
  return h;
}

void insertHelper(heap* h, int index) {
  int parent = (index - 1) / 2;

  if (h->arr[parent][0] > (h->arr[index])[0]) {
    int* temp = h->arr[parent];
    h->arr[parent] = h->arr[index];
    h->arr[index] = temp;

    insertHelper(h, parent);
  }
}

void heapify(heap* h, int index) {
  int left = index * 2 + 1;
  int right = index * 2 + 2;
  int min = index;

  if (left >= h->size || left < 0) left = -1;
  if (right >= h->size || right < 0) right = -1;

  if (left != -1 && (h->arr[left])[0] < (h->arr[index])[0]) min = left;
  if (right != -1 && (h->arr[right])[0] < (h->arr[min])[0]) min = right;

  if (min != index) {
    int* temp = h->arr[min];
    h->arr[min] = h->arr[index];
    h->arr[index] = temp;

    heapify(h, min);
  }
}

int* extractMin(heap* h) {
  int* deleteItem;

  if (h->size == 0) {
    return NULL;
  }

  deleteItem = h->arr[0];

  h->arr[0] = h->arr[h->size - 1];
  h->size--;

  heapify(h, 0);
  return deleteItem;
}

void insert(heap* h, int* data) {
  if (h->size < h->capacity) {
    h->arr[h->size] = data;
    insertHelper(h, h->size);
    h->size++;
  }
}

int* getFinalState(int* nums, int numsSize, int k, int multiplier, int* returnSize) {
  int *hp = mn
}
// @leet end
