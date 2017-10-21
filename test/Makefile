JSON := test.js
TARGET := InfinityClockJson

SRC := \
../application/testmain.cpp \
../application/Time.cpp \
../application/Canvas.cpp \
../application/JsonCanvas.cpp \
../application/Color.cpp \
../application/EventLoop.cpp \
../application/StateMachine_Initial.cpp \
../application/StateMachine_Clock.cpp \
../application/layers/ClockHour.cpp \
../application/layers/ClockMinute.cpp \
../application/layers/ClockSecond.cpp \
../application/layers/ClockMarker.cpp

OBJ := $(subst ../application/,,$(patsubst %.cpp,%.o,$(SRC)))

GCC_FLAGS := \
-I../application \
-Og \
-g3

$(TARGET): $(OBJ)
	@echo "============="
	@echo "Linking the target $@"
	@echo "============="
	g++ -o $(TARGET) $(OBJ)
	@echo -- Link finished --

$(JSON): $(TARGET) $(SRC)
	./$(TARGET) $(JSON)

%.o: ../application/%.cpp
	@mkdir -p $(dir $@)
	@echo "============="
	@echo "Compiling $<"
	g++ $(GCC_FLAGS) -o $@ -c $<

layers/%.o: ../application/layers/%.cpp
	@mkdir -p $(dir $@)
	@echo "============="
	@echo "Compiling $<"
	g++ $(GCC_FLAGS) -o $@ -c $<

all: $(TARGET) $(JSON)

clean:
	rm -Rf $(TARGET) $(JSON) $(OBJ) layers

.PHONY: all clean
