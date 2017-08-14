JSON := test.js
TARGET := InfinityClockJson

SRC := \
../src/testmain.cpp \
../src/Time.cpp \
../src/Canvas.cpp \
../src/JsonCanvas.cpp \
../src/Color.cpp \
../src/EventLoop.cpp \
../src/StateMachine_Initial.cpp \
../src/StateMachine_Clock.cpp

OBJ := $(subst ../src/,,$(patsubst %.cpp,%.o,$(SRC)))

GCC_FLAGS := \
-I../include

$(TARGET): $(OBJ)
	g++ -o $(TARGET) $(OBJ)

$(JSON): $(TARGET) $(SRC)
	./$(TARGET) $(JSON)

%.o: ../src/%.cpp
	g++ $(GCC_FLAGS) -o $@ -c $<

all: $(TARGET) $(JSON)
