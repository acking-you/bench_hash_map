#include <thread>
#include<absl/container/flat_hash_map.h>
#include"lib.h"

class SwissMap {
public:
    absl::flat_hash_map<int32_t, int32_t> data;

    static SwissMap from_i32_range(const int32_t start, const int32_t end) {
        SwissMap map;
        for (int i = start; i < end; ++i) {
            map.data.insert({i, i});
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
    bench_hashmap_get<SwissMap>();
    return 0;
}
