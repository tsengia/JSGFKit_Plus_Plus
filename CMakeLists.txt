cmake_minimum_required(VERSION 3.0)

project(jsgfkitxx
	VERSION 1.0
	LANGUAGES CXX)

include(GNUInstallDirs)

option(ENABLE_DEBUG "Enables debugging messages" OFF)

set(KIT_SOURCES src/grammar.cpp src/expansion.cpp src/rule.cpp src/matchinfo.cpp src/matchresult.cpp src/tag.cpp
                        src/unparsedsection.cpp src/kleenestar.cpp src/plusoperator.cpp
                        src/optionalgrouping.cpp src/requiredgrouping.cpp src/sequence.cpp
                        src/alternativeset.cpp src/token.cpp src/rulereference.cpp)

set(KIT_HEADERS include/rule.h include/expansion.h include/grammar.h
                  include/unparsedsection.h include/kleenestar.h
                  include/alternativeset.h include/token.h include/tag.h include/matchinfo.h
                  include/matchresult.h include/sequence.h include/plusoperator.h include/requiredgrouping.h
                  include/optionalgrouping.h include/rulereference.h)

add_library(jsgfkit STATIC ${KIT_SOURCES})
target_include_directories(jsgfkit PUBLIC ${PROJECT_BINARY_DIR}/include)

#Set variables for the .pc file
set(prefix "${CMAKE_INSTALL_PREFIX}")
set(exec_prefix "${CMAKE_INSTALL_PREFIX}")
set(libdir "${CMAKE_INSTALL_PREFIX}/${CMAKE_INSTALL_LIBDIR}")
set(includedir "${CMAKE_INSTALL_PREFIX}/${CMAKE_INSTALL_INCLUDEDIR}")
configure_file(jsgfkit.pc.in jsgfkit.pc @ONLY)

install(TARGETS jsgfkit
	ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR})

install(FILES ${KIT_HEADERS} DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/jsgfkit)

install(FILES jsgfkit.pc DESTINATION ${CMAKE_INSTALL_DATAROOT_DIR}/pkgconfig)
