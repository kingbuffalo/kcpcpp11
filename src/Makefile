CC=g++
CFLAGS=-std=c++14 -I.
OBJFLAG=-lpthread
SRC=${wildcard *.cpp}
OBJ=${patsubst %.cpp,%.o,$(SRC)}

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

main:$(OBJ)
	$(CC) -o $@ $^ $(OBJFLAG)


.PHONY:clean
clean:
	rm -rf main *.o
