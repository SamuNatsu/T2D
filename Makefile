TARGET_R := t2d.dll
TARGET_D := t2d-d.dll
TARGET_T := main

BUILD_DIR := ./build
SRC_DIRS := ./src
INC_DIRS := ./include

TGT_DIR := ./test

BUILD_R_DIR := $(BUILD_DIR)/release
BUILD_D_DIR := $(BUILD_DIR)/debug
BUILD_T_DIR := $(BUILD_DIR)/test

SRCS := $(shell find $(SRC_DIRS) -name '*.cpp')
SRCS_T := $(shell find $(TGT_DIR) -name '*.cpp')

OBJS_R := $(SRCS:%=$(BUILD_R_DIR)/%.o)
OBJS_D := $(SRCS:%=$(BUILD_D_DIR)/%.o)
OBJS_T := $(SRCS_T:%=$(BUILD_T_DIR)/%.o)

DEPS_R := $(OBJS_R:.o=.d)
DEPS_D := $(OBJS_D:.o=.d)
DEPS_T := $(OBJS_T:.o=.d)

INC_FLAGS := $(addprefix -I,$(INC_DIRS))

CPPFLAGS := $(INC_FLAGS) -MMD -MP -Wall -Werror -finput-charset=UTF-8 -fexec-charset=UTF-8 -std=c++17
CPPFLAGS_R := $(CPPFLAGS) -O3 -fPIC -DT2D_EXPORT
CPPFLAGS_D := $(CPPFLAGS) -g -fPIC -DT2D_EXPORT
CPPFLAGS_T := $(CPPFLAGS) -O3

LDFLAGS := -lsfml-graphics -lsfml-window -lsfml-system

all: release debug test

release: $(BUILD_R_DIR)/$(TARGET_R)

debug: $(BUILD_D_DIR)/$(TARGET_D)

test: $(BUILD_T_DIR)/$(TARGET_T)

$(BUILD_R_DIR)/$(TARGET_R): $(OBJS_R)
	$(CXX) $(OBJS_R) -shared -O3 -o $@ $(LDFLAGS)
	cp $(BUILD_R_DIR)/$(TARGET_R) $(TGT_DIR)/$(TARGET_R)

$(BUILD_D_DIR)/$(TARGET_D): $(OBJS_D)
	$(CXX) $(OBJS_D) -shared -g -o $@ $(LDFLAGS)
	cp $(BUILD_D_DIR)/$(TARGET_D) $(TGT_DIR)/$(TARGET_D)

$(BUILD_T_DIR)/$(TARGET_T): $(OBJS_T) $(BUILD_R_DIR)/$(TARGET_R)
	$(CXX) $(OBJS_T) -O3 -o $@ $(BUILD_R_DIR)/$(TARGET_R) $(LDFLAGS)
	cp $(BUILD_T_DIR)/$(TARGET_T) $(TGT_DIR)/$(TARGET_T)

$(BUILD_R_DIR)/%.cpp.o: %.cpp
	mkdir -p $(dir $@)
	$(CXX) $(CPPFLAGS_R) -c $< -o $@

$(BUILD_D_DIR)/%.cpp.o: %.cpp
	mkdir -p $(dir $@)
	$(CXX) $(CPPFLAGS_D) -c $< -o $@

$(BUILD_T_DIR)/%.cpp.o: %.cpp
	mkdir -p $(dir $@)
	$(CXX) $(CPPFLAGS_T) -c $< -o $@

.PHONY: clean
clean:
	rm -r $(BUILD_DIR)

-include $(DEPS)
