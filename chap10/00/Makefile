CC = g++
CFLAGS = -std=c++11 -Wall
TARGET = usestock

# 定义源文件
SRCS = usestock0.cxx stock00.cxx

OBJS = $(SRCS:.cxx=.o)
all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

%.o: %.cxx
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)

run: $(TARGET)
	./$(TARGET)

# 默认目标为 all
.PHONY: all clean run