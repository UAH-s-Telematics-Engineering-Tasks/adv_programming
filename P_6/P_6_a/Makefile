CC=g++
H_FILES:=$(wildcard ./inc/*.h)
CPP_FILES:=$(wildcard ./src/*.cpp)
CLASS_H_FILES:=$(wildcard ./inc_class/*.h)
CLASS_CPP_FILES:=$(wildcard ./src_class/*.cpp)
FLAGS=-Wall -Wextra

make_project: $(CPP_FILES)
	$(CC) -o P_6_a.ex $(H_FILES) $(CPP_FILES) $(CLASS_H_FILES) $(CLASS_CPP_FILES) $(FLAGS)
