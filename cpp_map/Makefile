
bench_std_hashmap:
	# Bench std hashmap
	rm -rf build-release
	cmake -DCMAKE_BUILD_TYPE=Release -B build-release
	cmake --build build-release --target bench_std_hashmap -j 10
	./build-release/bench_std_hashmap

bench_swiss_table:
	# Bench swiss table(Please ensure that the $VCPKG_CMAKE_PATH $CC $CXX $PROGRAM set correctly)
	rm -rf build-release
	echo "CC:$(CC)"
	echo "CXX:$(CXX)"
	echo "PROGRAM:$(PROGRAM)"
	echo "VCPKG_CMAKE_PATH:$(VCPKG_CMAKE_PATH)"
	cmake -DCMAKE_BUILD_TYPE=Release -DCMAKE_C_COMPILER=$(CC) -DCMAKE_CXX_COMPILER=$(CXX) -DCMAKE_MAKE_PROGRAM=$(PROGRAM) -DCMAKE_TOOLCHAIN_FILE=$(VCPKG_CMAKE_PATH) -DUSE_ABSL=ON -G Ninja -S . -B build-release
	cmake --build build-release --target bench_swiss_table -j 10
	./build-release/bench_swiss_table