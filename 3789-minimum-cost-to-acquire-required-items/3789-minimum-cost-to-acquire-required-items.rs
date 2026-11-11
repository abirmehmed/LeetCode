impl Solution {
    pub fn minimum_cost(cost1: i32, cost2: i32, cost_both: i32, need1: i32, need2: i32) -> i64 {
        let cost1 = cost1 as i64;
        let cost2 = cost2 as i64;
        let cost_both = cost_both as i64;
        let need1 = need1 as i64;
        let need2 = need2 as i64;

        let cost_at = |z: i64| -> i64 {
            let x = (need1 - z).max(0);
            let y = (need2 - z).max(0);
            z * cost_both + x * cost1 + y * cost2
        };

        cost_at(0)
            .min(cost_at(need1))
            .min(cost_at(need2))
    }
}