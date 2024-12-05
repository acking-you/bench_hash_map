pub trait MyHashMap {
    fn from_i32_range(v: std::ops::Range<i32>) -> Self;
    fn get(&self, key: &i32) -> Option<&i32>;
}

pub const RANGE: std::ops::Range<i32> = 0..1_000_000;

pub fn bench_hashmap_get<Map>()
where
    Map: MyHashMap,
{
    let map = Map::from_i32_range(RANGE);
    for t in 0..100 {
        let start = std::time::Instant::now();
        let sum = RANGE.map(|i| map.get(&i).unwrap()).sum::<i32>();
        if t > 95 {
            println!(
                "test round {}, sum:{}, elapsed:{:?}",
                t,
                sum,
                start.elapsed()
            );
        }
    }
}
