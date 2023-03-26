# g++ -o everloop everloop.cpp -std=c++11 -lmatrix_creator_hal

TARGET:=everloop
SRCS:=everloop.c
CC:=g++
OBJS:=$(SRCS:.c=.o)
LHAL:=-lmatrix_creator_hal
CVERS:=-std=c++11

.PHONY: clean

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) -o $@ $^ $(CVERS) $(LHAL)

%.o: %.c %.h
	$(CC) -c $<

%.o: %.c
	$(CC) -c $<

clean:
	rm -rf $(OBJS) $(TARGET)



