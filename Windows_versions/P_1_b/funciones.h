#include <iostream> //Include cin and cout
#include <new>
#include <limits> //For stream limits!
#include <vector>
#include <string>

std::vector<std::vector<float>> build_matrix(int, int);
void input_data(std::vector<std::vector<float>>&);
void show_matrix(const std::vector<std::vector<float>>&);
int read_int(char*);
int read_int(char*, bool, int);
float read_float(std::string);
