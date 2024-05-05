import precompiled "leetcode/precompiled"

// mergeTwoLists merges two sorted linked-lists into one sorted linked-list.
func mergeTwoLists(l1, l2 *precompiled.ListNode) *precompiled.ListNode {
    dummy := &precompiled.ListNode{}
    current := dummy

    for l1 != nil && l2 != nil {
        if l1.Val < l2.Val {
            current.Next = l1
            l1 = l1.Next
        } else {
            current.Next = l2
            l2 = l2.Next
        }
        current = current.Next
    }

    if l1 != nil {
        current.Next = l1
    } else {
        current.Next = l2
    }

    return dummy.Next
}

// mergeKLists merges k sorted linked-lists into one sorted linked-list using divide and conquer.
func mergeKLists(lists []*precompiled.ListNode) *precompiled.ListNode {
    if len(lists) == 0 {
        return nil
    }

    interval := 1
    for interval < len(lists) {
        for i := 0; i < len(lists)-interval; i += interval * 2 {
            lists[i] = mergeTwoLists(lists[i], lists[i+interval])
        }
        interval *= 2
    }

    return lists[0]
}
