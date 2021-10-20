#include "cmacro.h"

int main() {
    std::cout << CMac_compile("HELLO(world-me, premium)")[0][1] << std::endl;
}