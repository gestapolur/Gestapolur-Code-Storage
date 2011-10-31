CC=g++
OBJS=sns0.o
FLAGS = -g -Wall
EXEC=ugc_stat
$(EXEC):$(OBJS)
	$(CC) -o $@ $^  $(FLAGS)
$(OBJS):sns0.cpp
	$(CC) -c $< $(FLAGS)
clean:
	rm -rf $(EXEC) *.o