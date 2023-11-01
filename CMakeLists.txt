cmake_minimum_required(VERSION 3.0)

project(jsgfkitxx
	VERSION 1.1
	LANGUAGES CXX
)

set(JSGF_KIT_XX_SOURCES 
    src/Grammar.cpp
    src/Expansion.cpp 
    src/Rule.cpp 
    src/MatchInfo.cpp 
    src/MatchResult.cpp 
    src/Tag.cpp                
    src/UnparsedSection.cpp 
    src/KleeneStar.cpp 
    src/PlusOperator.cpp            
    src/OptionalGrouping.cpp 
    src/RequiredGrouping.cpp 
    src/Sequence.cpp     
    src/AlternativeSet.cpp 
    src/Token.cpp 
    src/RuleReference.cpp
)

add_library(jsgfkitxx STATIC ${JSGF_KIT_XX_SOURCES})
target_include_directories(jsgfkitxx PUBLIC ${PROJECT_SOURCE_DIR}/include)

include(GNUInstallDirs)

#Set variables for the .pc file
set(prefix "${CMAKE_INSTALL_PREFIX}")
set(exec_prefix "${CMAKE_INSTALL_PREFIX}")
set(libdir "${CMAKE_INSTALL_PREFIX}/${CMAKE_INSTALL_LIBDIR}")
set(includedir "${CMAKE_INSTALL_PREFIX}/${CMAKE_INSTALL_INCLUDEDIR}")
configure_file(jsgfkitxx.pc.in jsgfkitxx.pc @ONLY)

install(TARGETS jsgfkitxx
	ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
)

install(FILES ${KIT_HEADERS} DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/jsgfkitxx)

install(FILES jsgfkitxx.pc DESTINATION ${CMAKE_INSTALL_DATAROOT_DIR}/pkgconfig)

# Build Tests
enable_testing ()
add_subdirectory(test)
add_test (NAME ParseTest COMMAND test/parsetest)
add_test (NAME BatchTest COMMAND test/BatchTest/test.sh)
add_test (NAME ExpansionTypeTest COMMAND test/expansiontypetest)
