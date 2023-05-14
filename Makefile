#makefile adel
CC = gcc #
LD = gcc # имя редактора связей
CCFLAGS = -Wall -Wextra

TARGET = main
OBJS = main.o queue.o



$(TARGET): $(OBJS)
		$(CC) $(CCFLAGS) -o $(TARGET) $(OBJS)
	
queue.o: queue.c queue.h
		$(CC) $(CCFLAGS) -c queue.c
main.o: main.c queue.h
		$(CC) $(CCFLAGS) -c main.c

clean: rm -f $(OBJS) $(TARGET)