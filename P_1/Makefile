CC=g++
H_FILES:=$(wildcard ./inc/*.h)
C_FILES:=$(wildcard ./src/*.c)

make_project: $(C_FILES)
	$(CC) -o output ./obj/MemoryManager_GNU_GCC.o $(H_FILES) $(C_FILES)
