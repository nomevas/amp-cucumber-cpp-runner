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

set(SUPPORTED_SCREENS Boom16x9 Boom5x4 Tsm)
set(SUPPORTED_LANGUAGES en_EN de_DE fr_FR)

macro(add_scenario_test TARGET_NAME)
    set(TEST_RUNNER scenario.${TARGET_NAME})
    add_executable(${TEST_RUNNER} steps/${TARGET_NAME}.cpp)
    target_link_libraries(${TEST_RUNNER} PRIVATE
            scenario.test.runner
    )
    foreach(SCREEN IN LISTS SUPPORTED_SCREENS)
        foreach(LANGUAGE IN LISTS SUPPORTED_LANGUAGES)
            set(TEST_NAME scenario.${TARGET_NAME}.${SCREEN}.${LANGUAGE})
            add_test(NAME ${TEST_NAME} COMMAND ${TEST_RUNNER} run --feature
                    ${CMAKE_CURRENT_SOURCE_DIR}/features/${TARGET_NAME}.feature --report console --screen ${SCREEN} --language ${LANGUAGE})
        endforeach()
    endforeach()
endmacro()

enable_testing()
add_scenario_test(IdentifyingPatient)
add_scenario_test(InspectionOfTomographicImages)


