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
../application/Layer_ClockHour.cpp \
../application/Layer_ClockMinute.cpp \
../application/Layer_ClockSecond.cpp

OBJ := $(subst ../application/,,$(patsubst %.cpp,%.o,$(SRC)))

GCC_FLAGS := \
-I../application \
-Og \
-g3

$(TARGET): $(OBJ)
	g++ -o $(TARGET) $(OBJ)

$(JSON): $(TARGET) $(SRC)
	./$(TARGET) $(JSON)

%.o: ../application/%.cpp
	g++ $(GCC_FLAGS) -o $@ -c $<

all: $(TARGET) $(JSON)

clean:
	rm -f $(TARGET) $(JSON) $(OBJ)

.PHONY: all clean
