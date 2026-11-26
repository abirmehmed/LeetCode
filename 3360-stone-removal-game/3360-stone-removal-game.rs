impl Solution {
    pub fn can_alice_win(n: i32) -> bool {
        let mut remaining = n;
        let mut take = 10;
        let mut alice_turn = true;

        while take > 0 {
            if remaining < take {
                // current player can't move and loses
                return !alice_turn;
            }
            remaining -= take;
            take -= 1;
            alice_turn = !alice_turn;
        }

        // take reached 0: the current player must remove 0 stones, which is
        // not a valid move, so they lose
        !alice_turn
    }
}