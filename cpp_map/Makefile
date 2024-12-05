# Bench std hashmap
cmake --build build-release --config Release --target bench_std_hashmap -j 10
./build-release/bench_std_hashmap

# Bench swiss table(Please ensure that the absl library is installed via `vcpkg install` before running the tests.)
USE_ABSL=ON cmake --build build-release --config Release --target bench_swiss_table -j 10
./build-release/bench_swiss_table