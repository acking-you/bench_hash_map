use hashbrown::DefaultHashBuilder;
use rust_map::{bench_hashmap_get, MyHashMap};

struct HashbrownMap<S>(hashbrown::HashMap<i32, i32, S>);

impl<S: std::hash::BuildHasher + Default> MyHashMap for HashbrownMap<S> {
    fn from_i32_range(v: std::ops::Range<i32>) -> Self {
        Self(v.map(|i| (i, i)).collect())
    }

    fn get(&self, key: &i32) -> Option<&i32> {
        self.0.get(key)
    }
}

fn main() {
    println!("HashbrownMap default hash_builder:");
    bench_hashmap_get::<HashbrownMap<DefaultHashBuilder>>();
    println!("HashbrownMap no_hash_builder:");
    bench_hashmap_get::<HashbrownMap<nohash::BuildNoHashHasher<i32>>>();
}
