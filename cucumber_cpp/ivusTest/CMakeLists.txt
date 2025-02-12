set(CMAKE_COMPILE_WARNING_AS_ERROR On)

# core
add_library(scenario.test.runner OBJECT ${CCR_EXCLUDE_FROM_ALL})
target_sources(scenario.test.runner PRIVATE
        Main.cpp
        Hooks.cpp
        Fixture.hpp
)
target_link_libraries(scenario.test.runner PUBLIC
        cucumber_cpp.library
        cucumber_cpp.runner
)

enable_testing()

# foreach feature file in fixtures
add_executable(scenario.IdentifyPatient steps/IdentifyingPatient.cpp)
target_link_libraries(scenario.IdentifyPatient PRIVATE
        scenario.test.runner
)
add_test(NAME scenario.IdentifyPatient COMMAND scenario.IdentifyPatient run --feature
        ${CMAKE_CURRENT_SOURCE_DIR}/features/IdentifyingPatient.feature --report console)

add_executable(scenario.InspectionOfTomographicImages steps/InspectionOfTomographicImages.cpp)
target_link_libraries(scenario.InspectionOfTomographicImages PRIVATE
        scenario.test.runner
)
add_test(NAME scenario.InspectionOfTomographicImages COMMAND scenario.InspectionOfTomographicImages run --feature
        ${CMAKE_CURRENT_SOURCE_DIR}/features/InspectionOfTomographicImages.feature --report console)




