CC=g++
CFLAGS=
LDFLAGS=
EXEC=main
SRC=Data.cpp DataHandler.cpp Test.cpp main.cpp IdHash.cpp
OBJ=$(SRC:.cpp=.o)

all: $(EXEC)

main: $(OBJ)
	$(CC) -o $@ $^ $(LDFLAGS)

%.o: %.cpp
	$(CC) -o $@ -c $< $(CFLAGS)

main.o: main.cpp

DataHandler.o : DataHandler.cpp DataHandler.h
	$(CC) -o $@ -c $< $(CFLAGS)

.PHONY:clean

clean:
	rm -rf $(OBJ) $(EXEC)
