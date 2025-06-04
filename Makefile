.PHONY: all build run test clean

BUILD_DIR = build

all: build

build:
	@mkdir -p $(BUILD_DIR)
	@cd $(BUILD_DIR) && cmake ..
	@cd $(BUILD_DIR) && cmake --build .


run:
	@./$(BUILD_DIR)/main


test:
	@./$(BUILD_DIR)/tests/run_tests


clean:
	@rm -rf $(BUILD_DIR)
