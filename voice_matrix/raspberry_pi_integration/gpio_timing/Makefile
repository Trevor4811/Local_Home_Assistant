CFLAGS=-g -lpigpio -pthread
TARGET=gpio_timing
SOURCE=gpio_timing.c

$(TARGET): $(SOURCE)
		$(CC) $(CFLAGS) -o $@ $^

all: $(TARGET)

clean:
		rm -rf *.o $(TARGET)

.PHONY: clean
