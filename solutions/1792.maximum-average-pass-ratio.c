#include <stdlib.h>

// @leet start
#include <float.h>

struct Heap {
  double** arr;
  int size;
  int capacity;
};

typedef struct Heap heap;

heap* createHeap(int capacity, double** nums);
void insertHelper(heap* h, int index);
void heapify(heap* h, int index);
double *extractMin(heap* h);
void insert(heap* h, double *data);

heap* createHeap(int capacity, double** nums) {
  heap* h = (heap*)malloc(sizeof(heap));

  if (h == NULL) {
    return NULL;
  }

  h->size = 0;
  h->capacity = capacity;

  h->arr = (double**)malloc(capacity * sizeof(double *));

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
    double *temp = h->arr[parent];
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
    double *temp = h->arr[min];
    h->arr[min] = h->arr[index];
    h->arr[index] = temp;

    heapify(h, min);
  }
}

double *extractMin(heap* h) {
  double *deleteItem;

  if (h->size == 0) {
    return NULL;
  }

  deleteItem = h->arr[0];

  h->arr[0] = h->arr[h->size - 1];
  h->size--;

  heapify(h, 0);
  return deleteItem;
}

void insert(heap* h, double *data) {
  if (h->size < h->capacity) {
    h->arr[h->size] = data;
    insertHelper(h, h->size);
    h->size++;
  }
}

double maxAverageRatio(int** classes, int classesSize, int* classesColSize, int extraStudents) {
  double** ratios = (double**)malloc(classesSize * sizeof(double*));
  for (int i = 0; i < classesSize; i++) {
    ratios[i] = (double*)malloc(2 * sizeof(double));

    double a = classes[i][0];
    double b = classes[i][1];

    if (a == b) {
      ratios[i][0] = DBL_MAX;
      ratios[i][1] = b;
      continue;
    }

    ratios[i][0] = b * (b + 1) / (b - a);
    ratios[i][1] = b;
  }

  heap *hp = createHeap(classesSize, ratios);

  for (int _ = 0; _ < extraStudents; _++) {
    double *class = extractMin(hp);
    double b = class[1];

    class[0] *= (b + 2) / (b);
    class[1] = b + 1;

    insert(hp, class);
  }

  double passRatio = 0;
  for (int _ = 0; _ < classesSize; _++) {
    double *class = extractMin(hp);
    double b = class[1];
    double ratio = 1 - ((b + 1) / class[0]);

    passRatio += ratio / classesSize;
    free(class);
  }

  free(hp);
  free(ratios);
  return passRatio;
}
// @leet end
