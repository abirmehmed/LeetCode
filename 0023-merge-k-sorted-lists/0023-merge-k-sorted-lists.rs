use std::collections::BinaryHeap;
use std::cmp::Ordering;

#[derive(Eq)]
pub struct Node {
    val: i32,
    next: Option<Box<ListNode>>,
}

impl Ord for Node {
    fn cmp(&self, other: &Self) -> Ordering {
        other.val.cmp(&self.val)
    }
}

impl PartialOrd for Node {
    fn partial_cmp(&self, other: &Self) -> Option<Ordering> {
        Some(self.cmp(other))
    }
}

impl PartialEq for Node {
    fn eq(&self, other: &Self) -> bool {
        self.val == other.val
    }
}

impl Solution {
    pub fn merge_k_lists(lists: Vec<Option<Box<ListNode>>>) -> Option<Box<ListNode>> {
        let mut heap = BinaryHeap::new();
        for list in lists {
            if let Some(mut node) = list {
                heap.push(Node { val: node.val, next: node.next.take() });
            }
        }

        let mut head = None;
        let mut tail = &mut head;

        while let Some(Node { val, mut next }) = heap.pop() {
            if let Some(mut node) = next {
                heap.push(Node { val: node.val, next: node.next.take() });
            }
            *tail = Some(Box::new(ListNode::new(val)));
            tail = &mut tail.as_mut().unwrap().next;
        }

        head
    }
}
