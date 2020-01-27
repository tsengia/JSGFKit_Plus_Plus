
add_executable(parsetest ParseAndOutputJSGF.cpp)
target_link_libraries(parsetest jsgfkit)
target_include_directories(jsgfkit PUBLIC ${PROJECT_BINARY_DIR}/include)

add_executable(expansiontypetest ExpansionTypeTest.cpp)
target_link_libraries(expansiontypetest jsgfkit)
target_include_directories(jsgfkit PUBLIC ${PROJECT_BINARY_DIR}/include)

