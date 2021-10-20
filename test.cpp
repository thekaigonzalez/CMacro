#include "cmacro.h"

int main() {
    // "premium"
    std::cout << CMac_compile("HELLO(world-me, premium)")["HELLO"][1] << std::endl;
}