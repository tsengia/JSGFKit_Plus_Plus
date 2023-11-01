
add_executable(parse-test ParseAndOutputJSGF.cpp)
target_link_libraries(parse-test PRIVATE jsgfkitxx)
target_include_directories(parse-test
    PUBLIC ${PROJECT_BINARY_DIR}/include
)

add_executable(expansion-type-test ExpansionTypeTest.cpp)
target_link_libraries(expansion-type-test PRIVATE jsgfkitxx)
target_include_directories(expansion-type-test 
    PUBLIC ${PROJECT_BINARY_DIR}/include
)

add_executable(optional-test IsOptionalTest.cpp)
target_link_libraries(optional-test jsgfkit)
target_include_directories(jsgfkitxx 
    PUBLIC ${PROJECT_BINARY_DIR}/include
)

add_executable(jsgf-match MatchingTest.cpp)
target_link_libraries(jsgf-match jsgfkit)
target_include_directories(jsgfkitxx 
    PUBLIC ${PROJECT_BINARY_DIR}/include
)
