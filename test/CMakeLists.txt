
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

