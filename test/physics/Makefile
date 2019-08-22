# `make` not working? use `emmake make` with emscripten in your path (see installation guide for path setup)
CC = em++
CFLAGS = -std=c++17 -O3 -Wall --memory-init-file 1 --llvm-lto 3 --llvm-opts 3 --js-opts 1 --closure 1 --shell-file template.html
WASMFLAGS = -s ENVIRONMENT=web -s ALLOW_MEMORY_GROWTH=1 -s ABORTING_MALLOC=1 -s AGGRESSIVE_VARIABLE_ELIMINATION=1 -s EXIT_RUNTIME=0 -s NO_FILESYSTEM=1 -s DISABLE_EXCEPTION_CATCHING=2 -s BINARYEN_TRAP_MODE='allow' 

build/index.html: main.o
	em++ $(CFLAGS) $(WASMFLAGS) $^ -o $@

main.o: main.cpp
	em++ $(CFLAGS) $(WASMFLAGS) $^ -o $@

clean:
	rm -f *.o
	rm -f build/index.html
	rm -f build/index.js
	rm -f build/index.wasm
