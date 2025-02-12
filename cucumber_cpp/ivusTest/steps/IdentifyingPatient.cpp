#include "cucumber_cpp/library/Context.hpp"
#include "cucumber_cpp/library/Steps.hpp"

#include "gmock/gmock.h"
#include "gtest/gtest.h"

#include <cstdint>

namespace
{
    auto& log()
    {
        return std::cout << std::endl;
    }
}

GIVEN(R"(the following studies)")
{
    // Background step don't do anything
}

GIVEN(R"(the clinical user started the study with identification number "{int}")",
      (std::uint32_t identificationNumber))
{
    log() << identificationNumber;
}

GIVEN(R"(the current date is {string})", (std::string date))
{
    log() << date;
}

WHEN(R"(the clinical user starts the application)")
{
}

THEN(R"(the application shows the date of birth of the patient is {string})",
     (std::string dateOfBirth))
{
    log() << dateOfBirth;
}

THEN(R"(the application shows the age of the patient is {string})", (std::string age))
{
    log() << age;
}

THEN(R"(the application shows the study is in progress)")
{}

THEN(R"(the application shows the name of the patient is {string})", (std::string patientName))
{
    log() << patientName;
}

THEN(R"(the application shows the identification number of the patient is {string})",
     (std::string idNumber))
{
    log() << idNumber;
}
