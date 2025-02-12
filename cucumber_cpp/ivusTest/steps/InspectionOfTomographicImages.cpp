
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

GIVEN(R"(Display recorded tomographic images)")
{
    // Background step don't do anything
}

GIVEN(R"(Showing recorded tomographic images)")
{
    // Background step don't do anything
}

GIVEN(R"(the clinical user started a recording)")
{}

GIVEN(R"(the field of view is configured at "{int}" millimeters)", (std::uint32_t fieldOfView))
{
    log() << fieldOfView;
}

GIVEN(R"(the catheter supports a graticule spacing of "{int}" millimeter)", (std::uint32_t graticuleSpacing))
{
    log() << graticuleSpacing;
}

WHEN(R"(the clinical user stops the recording)")
{}

WHEN(R"(the application presents the pullback recording)")
{}

THEN(R"(the application presents the tomographic image with frame number "{int}")",
     (std::uint32_t frameNumber))
{
    log() << frameNumber;
}

THEN(R"(the catheter supports a graticule spacing of {int} millimeter)",
     (std::uint32_t graticuleSpacing))
{
    log() << graticuleSpacing;
}

THEN(R"(the application presents the frame number of the tomographic image)")
{}

THEN(R"(the application presents the acquisition date and time of the tomographic image)")
{}

THEN(R"(the field of view is configured at "{int}" millimeters)", (std::uint32_t fieldOfView))
{
    log() << fieldOfView;
}

THEN(R"(the application presents "{int}" graticules evenly spaced across the horizontal and vertical axis on the tomographic image)", (std::uint32_t numOfGraticules))
{
    log() << numOfGraticules;
}