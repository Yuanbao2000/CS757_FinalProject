BUILD_DIR := cmake-build-debug
TARGET := gpu_scheduler

.PHONY: all configure build brun run profile profile-gpu profile-api clean rebuild

# default: build only
all: build

# CMake config
configure:
	cmake -S . -B $(BUILD_DIR) \
		-DCMAKE_BUILD_TYPE=Debug \
		-DCMAKE_C_COMPILER=/usr/bin/gcc \
		-DCMAKE_CXX_COMPILER=/usr/bin/g++ \
		-DCMAKE_CUDA_COMPILER=/usr/local/cuda/bin/nvcc \
		-G Ninja

# build
build: $(BUILD_DIR)/CMakeCache.txt
	cmake --build $(BUILD_DIR) --parallel $(shell nproc)

# configure if build dir doesn't exist yet
$(BUILD_DIR)/CMakeCache.txt:
	$(MAKE) configure

# build and run
brun: build
	./$(BUILD_DIR)/$(TARGET)

# run
run:
	./$(BUILD_DIR)/$(TARGET)

# profile all experiments with nvprof
profile: build
	nvprof --print-gpu-trace --print-api-trace --log-file nvprof_all.txt ./$(BUILD_DIR)/$(TARGET)

# profile GPU kernel timeline only
profile-gpu: build
	nvprof --print-gpu-trace --log-file nvprof_gpu_trace_all.txt ./$(BUILD_DIR)/$(TARGET)

# profile CUDA API calls only
profile-api: build
	nvprof --print-api-trace --log-file nvprof_api_trace_all.txt ./$(BUILD_DIR)/$(TARGET)

# clean
clean:
	rm -rf $(BUILD_DIR)

# rebuild
rebuild: clean build
