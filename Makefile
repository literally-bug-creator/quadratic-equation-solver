.SILENT:

# ============ PARAMS ============
CXX = g++
CXXFLAGS = -Wall -Wextra -Iinclude
SRC_DIR = src
OBJ_DIR = obj
BIN = main

SRCS := $(wildcard $(SRC_DIR)/*.cpp) $(wildcard $(SRC_DIR)/**/*.cpp)
OBJS = $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SRCS))

# ============ AIM ============

all: $(BIN)

$(BIN): $(OBJS)
	@echo "Linking $@"
	$(CXX) $(OBJS) -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(dir $@)
	@echo "Compiling $<"
	$(CXX) $(CXXFLAGS) -c $< -o $@

# ============ BUILD & RUN TESTS ============

.PHONY: tests build_tests run_tests coverage report

tests: build_tests run_tests

build_tests:
	@echo "Configuring CMake..."
	cmake --preset default
	@echo "Building tests..."
	$(MAKE) -C build

run_tests:
	@echo "Running tests..."
	./build/tests

coverage:
	@echo "Collecting coverage..."
	lcov --capture --directory build --output-file coverage.info
	@echo "Filtering unwanted files..."
	lcov --remove coverage.info "/usr/*" "*/_deps/*" "*/tests/*" -o coverage_filtered.info

report: coverage
	@echo "Generating HTML report..."
	genhtml coverage_filtered.info --output-directory coverage_report
	@xdg-open coverage_report/index.html || open coverage_report/index.html || echo "Report generated at coverage_report/index.html"

# ============ CLEANING ============

.PHONY: clean clean_tests clean_all

clean:
	@echo "Cleaning project build..."
	@rm -rf $(OBJ_DIR) $(BIN)

clean_tests:
	@echo "Cleaning tests build..."
	@rm -rf build coverage.info coverage_filtered.info coverage_report

clean_all: clean clean_tests
