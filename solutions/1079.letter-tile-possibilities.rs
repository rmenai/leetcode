// @leet start
impl Solution {
    pub fn num_tile_possibilities(tiles: String) -> i32 {
        const ALPHABET_SIZE: usize = 26;
        let mut freq = [0; ALPHABET_SIZE];

        for c in tiles.bytes() {
            freq[(c - b'A') as usize] += 1;
        }

        fn dfs(freq: &mut [i32; ALPHABET_SIZE]) -> i32 {
            let mut count = 0;

            for i in 0..ALPHABET_SIZE {
                if freq[i] > 0 {
                    freq[i] -= 1;
                    count += 1 + dfs(freq);
                    freq[i] += 1;
                }
            }

            count
        }

        dfs(&mut freq)
    }
}
// @leet end
