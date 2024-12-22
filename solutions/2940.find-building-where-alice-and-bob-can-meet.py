import heapq

# @leet start


class OrderedHashSet:
    def __init__(self):
        self.node_map = {}
        self.order = DoublyLinkedList()

    def add(self, key):
        if key not in self.node_map:
            node = self.order.append(key)
            self.node_map[key] = node

    def remove(self, key):
        if key in self.node_map:
            node = self.node_map[key]
            self.order.remove(node)
            del self.node_map[key]

    def traverse(self):
        return self.order.to_list()


class DoublyLinkedList:
    class Node:
        def __init__(self, value):
            self.value = value
            self.prev = None
            self.next = None

    def __init__(self):
        self.head = self.Node(None)
        self.tail = self.Node(None)
        self.head.next = self.tail
        self.tail.prev = self.head

    def append(self, value):
        node = self.Node(value)
        node.prev = self.tail.prev
        node.next = self.tail
        self.tail.prev.next = node
        self.tail.prev = node
        return node

    def remove(self, node):
        node.prev.next = node.next
        node.next.prev = node

    def to_list(self):
        result = []
        current = self.head.next
        while current != self.tail:
            result.append(current.value)
            current = current.next
        return result


class Solution:
    def leftmostBuildingQueries(self, heights: List[int], queries: List[List[int]]) -> List[int]:
        ordered_set = OrderedHashSet()
        for i in range(len(heights)):
            ordered_set.add(i)

        h = [(heights[i], i) for i in range(len(heights))]

        heapq.heapify(h)
        queries.sort(key=lambda a: max(heights[a[0]], heights[a[1]]))

        for i, j in queries:
            m = max(i, j, key=lambda a: heights[a])
            while h[0][0] < heights[m]:
                _, k = heapq.heappop(h)
                ordered_set.remove(k)


# @leet end
