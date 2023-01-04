CC=g++

INCLUDE_DIR := ./include
SRC_DIR := ./src
OBJ_DIR := ./obj
BIN_DIR := ./bin
LIB_DIR := ./lib

CFLAGS := -std=c++17 -g

day01 := day01.exe
day02 := day02.exe
day03 := day03.exe
day04 := day04.exe
day05 := day05.exe
day06 := day06.exe
day07 := day07.exe
day08 := day08.exe
day09 := day09.exe
day10 := day10.exe
day11 := day11.exe
day12 := day12.exe
day13 := day13.exe
day14 := day14.exe
day15 := day15.exe
day16 := day16.exe
day17 := day17.exe
day18 := day18.exe
day19 := day19.exe
day20 := day20.exe
day21 := day21.exe
day22 := day22.exe
day23 := day23.exe
day24 := day24.exe
day25 := day25.exe

#MYLIB := libmylib.a

all : $(day01) $(day02) $(day03) $(day04) $(day05) $(day06) $(day07) $(day08) $(day09) $(day10) $(day11) $(day12) $(day13) $(day14) $(day15) $(day16) $(day17) $(day18) $(day19) $(day20) $(day21) $(day22) $(day23) $(day24) $(day25)

$(day25) : objdir bindir $(OBJ_DIR)/day25.o
	$(CC) $(CFLAGS) -static $(OBJ_DIR)/day25.o -o $(BIN_DIR)/$(day25) 

$(day24) : objdir bindir $(OBJ_DIR)/day24.o
	$(CC) $(CFLAGS) -static $(OBJ_DIR)/day24.o -o $(BIN_DIR)/$(day24) 

$(day23) : objdir bindir $(OBJ_DIR)/day23.o
	$(CC) $(CFLAGS) -static $(OBJ_DIR)/day23.o -o $(BIN_DIR)/$(day23) 

$(day22) : objdir bindir $(OBJ_DIR)/day22.o
	$(CC) $(CFLAGS) -static $(OBJ_DIR)/day22.o -o $(BIN_DIR)/$(day22) 

$(day21) : objdir bindir $(OBJ_DIR)/day21.o
	$(CC) $(CFLAGS) -static $(OBJ_DIR)/day21.o -o $(BIN_DIR)/$(day21) 

$(day20) : objdir bindir $(OBJ_DIR)/day20.o
	$(CC) $(CFLAGS) -static $(OBJ_DIR)/day20.o -o $(BIN_DIR)/$(day20) 

$(day19) : objdir bindir $(OBJ_DIR)/day19.o
	$(CC) $(CFLAGS) -static $(OBJ_DIR)/day19.o -o $(BIN_DIR)/$(day19) 

$(day18) : objdir bindir $(OBJ_DIR)/day18.o
	$(CC) $(CFLAGS) -static $(OBJ_DIR)/day18.o -o $(BIN_DIR)/$(day18) 

$(day17) : objdir bindir $(OBJ_DIR)/day17.o
	$(CC) $(CFLAGS) -static $(OBJ_DIR)/day17.o -o $(BIN_DIR)/$(day17) 

$(day16) : objdir bindir $(OBJ_DIR)/day16.o
	$(CC) $(CFLAGS) -static $(OBJ_DIR)/day16.o -o $(BIN_DIR)/$(day16) 

$(day15) : objdir bindir $(OBJ_DIR)/day15.o
	$(CC) $(CFLAGS) -static $(OBJ_DIR)/day15.o -o $(BIN_DIR)/$(day15) 

$(day14) : objdir bindir $(OBJ_DIR)/day14.o
	$(CC) $(CFLAGS) -static $(OBJ_DIR)/day14.o -o $(BIN_DIR)/$(day14) 

$(day13) : objdir bindir $(OBJ_DIR)/day13.o
	$(CC) $(CFLAGS) -static $(OBJ_DIR)/day13.o -o $(BIN_DIR)/$(day13) 

$(day12) : objdir bindir $(OBJ_DIR)/day12.o
	$(CC) $(CFLAGS) -static $(OBJ_DIR)/day12.o -o $(BIN_DIR)/$(day12) 

$(day11) : objdir bindir $(OBJ_DIR)/day11.o
	$(CC) $(CFLAGS) -static $(OBJ_DIR)/day11.o -o $(BIN_DIR)/$(day11) 

$(day10) : objdir bindir $(OBJ_DIR)/day10.o
	$(CC) $(CFLAGS) -static $(OBJ_DIR)/day10.o -o $(BIN_DIR)/$(day10) 

$(day09) : objdir bindir $(OBJ_DIR)/day09.o
	$(CC) $(CFLAGS) -static $(OBJ_DIR)/day09.o -o $(BIN_DIR)/$(day09) 

$(day08) : objdir bindir $(OBJ_DIR)/day08.o
	$(CC) $(CFLAGS) -static $(OBJ_DIR)/day08.o -o $(BIN_DIR)/$(day08) 

$(day07) : objdir bindir $(OBJ_DIR)/day07.o
	$(CC) $(CFLAGS) -static $(OBJ_DIR)/day07.o -o $(BIN_DIR)/$(day07) 

$(day06) : objdir bindir $(OBJ_DIR)/day06.o
	$(CC) $(CFLAGS) -static $(OBJ_DIR)/day06.o -o $(BIN_DIR)/$(day06) 

$(day05) : objdir bindir $(OBJ_DIR)/day05.o
	$(CC) $(CFLAGS) -static $(OBJ_DIR)/day05.o -o $(BIN_DIR)/$(day05) 

$(day04) : objdir bindir $(OBJ_DIR)/day04.o
	$(CC) $(CFLAGS) -static $(OBJ_DIR)/day04.o -o $(BIN_DIR)/$(day04) 

$(day03) : objdir bindir $(OBJ_DIR)/day03.o
	$(CC) $(CFLAGS) -static $(OBJ_DIR)/day03.o -o $(BIN_DIR)/$(day03) 

$(day02) : objdir bindir $(OBJ_DIR)/day02.o
	$(CC) $(CFLAGS) -static $(OBJ_DIR)/day02.o -o $(BIN_DIR)/$(day02) 

$(day01) : objdir bindir $(OBJ_DIR)/day01.o
	$(CC) $(CFLAGS) -static $(OBJ_DIR)/day01.o -o $(BIN_DIR)/$(day01) 

#$(MYLIB) : objdir libdir $(OBJ_DIR)/data.o $(OBJ_DIR)/display.o
#	ar rcs $(LIB_DIR)/$(MYLIB) $(OBJ_DIR)/data.o $(OBJ_DIR)/display.o
#	ranlib $(LIB_DIR)/$(MYLIB)

objdir:
	mkdir -p $(OBJ_DIR)

bindir:
	mkdir -p $(BIN_DIR)

#libdir:
#	mkdir -p $(LIB_DIR)

obj/day25.o: $(SRC_DIR)/day25.cpp
	$(CC) $(CFLAGS) -O -c $(SRC_DIR)/day25.cpp -I $(INCLUDE_DIR) -o $(OBJ_DIR)/day25.o

obj/day24.o: $(SRC_DIR)/day24.cpp
	$(CC) $(CFLAGS) -O -c $(SRC_DIR)/day24.cpp -I $(INCLUDE_DIR) -o $(OBJ_DIR)/day24.o

obj/day23.o: $(SRC_DIR)/day23.cpp
	$(CC) $(CFLAGS) -O -c $(SRC_DIR)/day23.cpp -I $(INCLUDE_DIR) -o $(OBJ_DIR)/day23.o

obj/day22.o: $(SRC_DIR)/day22.cpp
	$(CC) $(CFLAGS) -O -c $(SRC_DIR)/day22.cpp -I $(INCLUDE_DIR) -o $(OBJ_DIR)/day22.o

obj/day21.o: $(SRC_DIR)/day21.cpp
	$(CC) $(CFLAGS) -O -c $(SRC_DIR)/day21.cpp -I $(INCLUDE_DIR) -o $(OBJ_DIR)/day21.o

obj/day20.o: $(SRC_DIR)/day20.cpp
	$(CC) $(CFLAGS) -O -c $(SRC_DIR)/day20.cpp -I $(INCLUDE_DIR) -o $(OBJ_DIR)/day20.o

obj/day19.o: $(SRC_DIR)/day19.cpp
	$(CC) $(CFLAGS) -O -c $(SRC_DIR)/day19.cpp -I $(INCLUDE_DIR) -o $(OBJ_DIR)/day19.o

obj/day18.o: $(SRC_DIR)/day18.cpp
	$(CC) $(CFLAGS) -O -c $(SRC_DIR)/day18.cpp -I $(INCLUDE_DIR) -o $(OBJ_DIR)/day18.o

obj/day17.o: $(SRC_DIR)/day17.cpp
	$(CC) $(CFLAGS) -O -c $(SRC_DIR)/day17.cpp -I $(INCLUDE_DIR) -o $(OBJ_DIR)/day17.o

obj/day16.o: $(SRC_DIR)/day16.cpp
	$(CC) $(CFLAGS) -O -c $(SRC_DIR)/day16.cpp -I $(INCLUDE_DIR) -o $(OBJ_DIR)/day16.o

obj/day15.o: $(SRC_DIR)/day15.cpp
	$(CC) $(CFLAGS) -O -c $(SRC_DIR)/day15.cpp -I $(INCLUDE_DIR) -o $(OBJ_DIR)/day15.o

obj/day14.o: $(SRC_DIR)/day14.cpp
	$(CC) $(CFLAGS) -O -c $(SRC_DIR)/day14.cpp -I $(INCLUDE_DIR) -o $(OBJ_DIR)/day14.o

obj/day13.o: $(SRC_DIR)/day13.cpp
	$(CC) $(CFLAGS) -O -c $(SRC_DIR)/day13.cpp -I $(INCLUDE_DIR) -o $(OBJ_DIR)/day13.o

obj/day12.o: $(SRC_DIR)/day12.cpp
	$(CC) $(CFLAGS) -O -c $(SRC_DIR)/day12.cpp -I $(INCLUDE_DIR) -o $(OBJ_DIR)/day12.o

obj/day11.o: $(SRC_DIR)/day11.cpp
	$(CC) $(CFLAGS) -O -c $(SRC_DIR)/day11.cpp -I $(INCLUDE_DIR) -o $(OBJ_DIR)/day11.o

obj/day10.o: $(SRC_DIR)/day10.cpp
	$(CC) $(CFLAGS) -O -c $(SRC_DIR)/day10.cpp -I $(INCLUDE_DIR) -o $(OBJ_DIR)/day10.o

obj/day09.o: $(SRC_DIR)/day09.cpp
	$(CC) $(CFLAGS) -O -c $(SRC_DIR)/day09.cpp -I $(INCLUDE_DIR) -o $(OBJ_DIR)/day09.o

obj/day08.o: $(SRC_DIR)/day08.cpp
	$(CC) $(CFLAGS) -O -c $(SRC_DIR)/day08.cpp -I $(INCLUDE_DIR) -o $(OBJ_DIR)/day08.o

obj/day07.o: $(SRC_DIR)/day07.cpp
	$(CC) $(CFLAGS) -O -c $(SRC_DIR)/day07.cpp -I $(INCLUDE_DIR) -o $(OBJ_DIR)/day07.o

obj/day06.o: $(SRC_DIR)06/day06.cpp
	$(CC) $(CFLAGS) -O -c $(SRC_DIR)/day06.cpp -I $(INCLUDE_DIR) -o $(OBJ_DIR)/day06.o

obj/day05.o: $(SRC_DIR)/day05.cpp
	$(CC) $(CFLAGS) -O -c $(SRC_DIR)/day05.cpp -I $(INCLUDE_DIR) -o $(OBJ_DIR)/day05.o

obj/day04.o: $(SRC_DIR)/day04.cpp
	$(CC) $(CFLAGS) -O -c $(SRC_DIR)/day04.cpp -I $(INCLUDE_DIR) -o $(OBJ_DIR)/day04.o

obj/day03.o: $(SRC_DIR)/day03.cpp
	$(CC) $(CFLAGS) -O -c $(SRC_DIR)/day03.cpp -I $(INCLUDE_DIR) -o $(OBJ_DIR)/day03.o

obj/day02.o: $(SRC_DIR)/day02.cpp
	$(CC) $(CFLAGS) -O -c $(SRC_DIR)/day02.cpp -I $(INCLUDE_DIR) -o $(OBJ_DIR)/day02.o

obj/day01.o: $(SRC_DIR)/day01.cpp
	$(CC) $(CFLAGS) -O -c $(SRC_DIR)/day01.cpp -I $(INCLUDE_DIR) -o $(OBJ_DIR)/day01.o

#run:
#	./bin/$(APP)

clean:
	rm -rf ./obj
	rm -rf ./bin
#	rm -rf ./lib
