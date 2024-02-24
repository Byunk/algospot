import sys
input = sys.stdin.readline

class Node:
    def __init__(self, v, next=None):
        self.v = v
        self.next = next

C = int(input())
for _ in range(C):
    N, K = map(int, input())
    head = Node(0)
    node = head

    # Circular linked list 생성
    for i in range(N):
        n = Node(i+1)
        node.next = n
        node = node.next

    # 첫번째 노드 삭제
    node.next = head.next.next
    N -= 1

    while N > 2:
        # K 번째 떨어진 node를 삭제
        for _ in range(K-1):
            node = node.next
        node.next = node.next.next
        N -= 1

    ans = [node.v, node.next.v]
    ans = sorted(ans)
    print(ans)
    