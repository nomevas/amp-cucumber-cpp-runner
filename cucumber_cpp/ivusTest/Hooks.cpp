#include "cucumber_cpp/library/Hooks.hpp"
#include "cucumber_cpp/library/Context.hpp"

#include <iostream>

HOOK_BEFORE_ALL()
{
    std::cout << "HOOK_BEFORE_ALL\n";
}

HOOK_AFTER_ALL()
{
    std::cout << "HOOK_AFTER_ALL\n";
}

HOOK_BEFORE_SCENARIO("@Boom.16:9")
{
    std::cout << "HOOK_BEFORE_SCENARIO @Boom.16:9\n";
}

HOOK_BEFORE_SCENARIO("@Boom.5:4")
{
    std::cout << "HOOK_BEFORE_SCENARIO @Boom.5:4\n";
}

HOOK_BEFORE_SCENARIO("@Cart")
{
    std::cout << "HOOK_BEFORE_SCENARIO @Cart\n";
}

HOOK_BEFORE_SCENARIO()
{
    std::cout << "HOOK_BEFORE_SCENARIO all\n";
}

HOOK_AFTER_SCENARIO()
{
    std::cout << "HOOK_AFTER_SCENARIO all\n";
}

HOOK_BEFORE_STEP()
{
    std::cout << "\n-> HOOK_BEFORE_STEP";
}

HOOK_AFTER_STEP()
{
    std::cout << "\n<- HOOK_AFTER_STEP";
}