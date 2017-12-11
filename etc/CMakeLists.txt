cmake_minimum_required(VERSION 3.6)
project(untitled5)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -lpthread")
add_subdirectory(lib/googletest-release-1.8.0)
include_directories(lib/googletest-release-1.8.0/googletest/include)
include_directories(lib/googletest-release-1.8.0/googlemock/include)

set(SOURCE_FILES src/BasicGameRules.h src/BasicGameRules.cpp src/Board.h src/Board.cpp src/BoardDisplayer.h src/ConsoleDisplay.cpp
        src/ConsoleDisplay.h src/GamePlay.h src/GamePlay.cpp src/GameRules.h src/GameRules.cpp src/HumanConsolePlayer.cpp
        src/HumanConsolePlayer.h src/Player.h src/Player.cpp src/Point.h src/Point.cpp src/AIPlayer.h src/AIPlayer.cpp
        src/RemotePlayer.cpp src/RemotePlayer.h src/VirtualPlayer.cpp src/VirtualPlayer.h)

set(TEST_FILES test/JustATest.cpp test/BasicGameRulesTest.cpp test/BoardTest.cpp test/GamePlayTest.cpp test/PointTest.cpp)
set(SERVER_FILES server/Server.cpp server/Server.h server/Client.h server/Client.cpp)

add_executable(server ${SERVER_FILES} server/server_main.cpp)
add_executable(client ${SERVER_FILES} server/client_main.cpp)

add_executable(untitled5 ${SOURCE_FILES} ${TEST_FILES} test/gtest_main.cpp)
add_executable(Reversi ${SOURCE_FILES} src/main.cpp src/Menu.h src/Menu.cpp)
target_link_libraries(untitled5 gtest gtest_main pthread)
add_test(untitled5 untitled5)