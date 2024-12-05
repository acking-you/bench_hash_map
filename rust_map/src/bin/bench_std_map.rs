use std::hash::RandomState;

use rust_map::{bench_hashmap_get, MyHashMap};

struct StdHashMap<S>(std::collections::HashMap<i32, i32, S>);

impl<S: std::hash::BuildHasher + Default> MyHashMap for StdHashMap<S> {
    fn from_i32_range(v: std::ops::Range<i32>) -> Self {
        Self(v.map(|i| (i, i)).collect())
    }

    fn get(&self, key: &i32) -> Option<&i32> {
        self.0.get(key)
    }
}

fn main() {
    println!("StdHashMap default hash_builder:");
    bench_hashmap_get::<StdHashMap<RandomState>>();
    println!("StdHashMap no_hash_builder:");
    bench_hashmap_get::<StdHashMap<nohash::BuildNoHashHasher<i32>>>();
}
