#include "cucumber_cpp/library/Application.hpp"
#include <string>

int main(int argc, char** argv)
{
    cucumber_cpp::library::Application application{};

    application.CliParser().add_option("--language", *application.ProgramContext().EmplaceAt<std::string>("--language"))->required();
    application.CliParser().add_option("--screen", *application.ProgramContext().EmplaceAt<std::string>("--screen"))->required();

    return application.Run(argc, argv);
}
