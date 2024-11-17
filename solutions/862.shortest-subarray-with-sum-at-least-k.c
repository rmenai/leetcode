#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

// @leet start
typedef struct{
  int index;
  long long prefixSum;
} Element;

typedef struct {
  Element *data;
  int front, rear, size, capacity;
}

Deque *createDeque(int capacity) {
  Deque *deque = (Deque *)malloc(sizeof(Deque));
  deque->data = (Element *)malloc(capacity * sizeof(Element));
  deque->front = 0;
  deque->rear = -1;
  deque->size = 0;
  deque->capacity = capacity;
  return deque;
}

int isEmpty(Deque *deque) {
  return deque->size == 0;
}

void pushBack(Deque *deque, Element elem) {
  deque->rear = (deque->rear + 1) % deque->capacity;
  deque->data[deque->rear] = elem;
  deque->size++;
}

Element popFront(Deque *deque) {
  Element elem = deque->data[deque->front];
  deque->front = (deque->front + 1) % deque->capacity;
  deque->size--;
  return elem;
}

Element back(Deque *deque) {
  return deque->data[deque->rear];
}

Element front(Deque *deque) {
  return deque->data[deque->front];
}

void popBack(Deque *deque) {
  deque->rear = (deque->rear - 1 + deque->capacity) % deque->capacity;
  deque->size--;
}

void freeDeque(Deque *deque) {
  free(deque->data);
  free(deque);
}


int shortestSubarray(int* nums, int numsSize, int k) {
  long long *prefixSum = (long long *)malloc(numsSize * sizeof(long long));
  prefixSum[0] = 0;
  for (int i = 0; i < numsSize; i++) {
    prefixSum[i + 1] = prefixSum[i] + nums[i];
  }

  Deque *deque = createDeque(numsSize + 1);
  int minLength = INT_MAX;

  for (int i = 0; i <= numsSize; i++) {
    while (!isEmpty(deque) && prefixSum[i] - front(deque).prefixSum >= k) {
      int length = i - front(deque).index;
      minLength = length < minLength ? length : minLength;
      popFront(deque);
    }

    while (!isEmpty(deque) && prefixSum[i] <= back(deque).prefixSum) {
      popBack(deque);
    }

    Element elem = {i, prefixSum[i]};
    pushBack(deque, elem);
  }

  free(prefixSum);
  freeDeque(deque);
  
  return minLength == INT_MAX ? -1 : minLength;
}
// @leet end
