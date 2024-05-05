import (
    "container/heap"
    // Assume 'precompiled' is the alias for the package where ListNode is defined
    precompiled "leetcode/precompiled"
)

// MinHeap is a min-heap of ListNodes.
type MinHeap []*precompiled.ListNode

func (h MinHeap) Len() int           { return len(h) }
func (h MinHeap) Less(i, j int) bool { return h[i].Val < h[j].Val }
func (h MinHeap) Swap(i, j int)      { h[i], h[j] = h[j], h[i] }

func (h *MinHeap) Push(x interface{}) {
    *h = append(*h, x.(*precompiled.ListNode))
}

func (h *MinHeap) Pop() interface{} {
    old := *h
    n := len(old)
    x := old[n-1]
    *h = old[0 : n-1]
    return x
}

// mergeKLists merges k sorted linked-lists into one sorted linked-list.
func mergeKLists(lists []*precompiled.ListNode) *precompiled.ListNode {
    minHeap := &MinHeap{}
    heap.Init(minHeap)

    // Initialize the min heap with the head of each list.
    for _, list := range lists {
        if list != nil {
            heap.Push(minHeap, list)
        }
    }

    // Create a dummy head for the result list.
    dummy := &precompiled.ListNode{}
    current := dummy

    // Extract the smallest element from the heap and add it to the result list.
    for minHeap.Len() > 0 {
        smallest := heap.Pop(minHeap).(*precompiled.ListNode)
        current.Next = smallest
        current = current.Next

        // If there is a next element in the list, add it to the heap.
        if smallest.Next != nil {
            heap.Push(minHeap, smallest.Next)
        }
    }

    return dummy.Next
}
