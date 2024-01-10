#include <iostream>

#include "Application.hpp"

int main(int argc, char **argv) {
    try {
        Application::Instance()->init();
        Application::Instance()->run();
        Application::Instance()->clean();
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
