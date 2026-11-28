impl Solution {
    pub fn maximum_sale_items(items: Vec<Vec<i32>>, budget: i32) -> i32 {
        let n = items.len();
        let mut cnt = vec![0i64; n + 1];
        for it in &items {
            cnt[it[0] as usize] += 1;
        }
        // mult[f] = number of items whose factor is a multiple of f
        let mut mult = vec![0i64; n + 1];
        for f in 1..=n {
            let mut k = f;
            while k <= n {
                mult[f] += cnt[k];
                k += f;
            }
        }

        // (price, d)
        let mut v: Vec<(i64, i64)> = items
            .iter()
            .map(|it| (it[1] as i64, mult[it[0] as usize] - 1))
            .collect();
        v.sort();

        let pmin = v[0].0;
        let mut rem = budget as i64;
        let mut m: i64 = 0;
        for &(p, d) in &v {
            if p > 2 * pmin {
                break;
            }
            let t = d.min(rem / p);
            m += t;
            rem -= t * p;
        }
        (2 * m + rem / pmin) as i32
    }
}