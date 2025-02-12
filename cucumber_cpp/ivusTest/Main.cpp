#include "cucumber_cpp/library/Application.hpp"
#include <string>

int main(int argc, char** argv)
{
    cucumber_cpp::library::Application application{};

    return application.Run(argc, argv);
}
