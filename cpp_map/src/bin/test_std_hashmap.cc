#include <thread>
#include <unordered_map>
#include"lib.h"

class MyStdMap {
public:
    std::unordered_map<int32_t, int32_t> data;

    static MyStdMap from_i32_range(const int32_t start, const int32_t end) {
        MyStdMap map;
        for (int i = start; i < end; ++i) {
            map.data.insert(std::make_pair(i, i));
        }
        return std::move(map);
    }

    [[nodiscard]] std::optional<int> get(const int32_t key) const {
        auto it = data.find(key);
        if (it != data.end()) {
            return it->second;
        }
        return std::nullopt;
    }
};


int main() {
    bench_hashmap_get<MyStdMap>();
    return 0;
}
