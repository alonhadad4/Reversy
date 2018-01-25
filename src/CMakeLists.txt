cmake_minimum_required(VERSION 3.6)
project(untitled5)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -lpthread")
add_subdirectory(lib/googletest-release-1.8.0)
include_directories(lib/googletest-release-1.8.0/googletest/include)
include_directories(lib/googletest-release-1.8.0/googlemock/include)

set(CLIENT_FILES client/BasicGameRules.h client/BasicGameRules.cpp client/Board.h client/Board.cpp client/BoardDisplayer.h client/ConsoleDisplay.cpp
        client/ConsoleDisplay.h client/GamePlay.h client/GamePlay.cpp client/GameRules.h client/GameRules.cpp client/HumanConsolePlayer.cpp
        client/HumanConsolePlayer.h client/Player.h client/Player.cpp client/Point.h client/Point.cpp client/AIPlayer.h client/AIPlayer.cpp
        client/RemotePlayer.cpp client/RemotePlayer.h client/VirtualPlayer.cpp client/VirtualPlayer.h)

set(TEST_FILES test/JustATest.cpp test/BasicGameRulesTest.cpp test/BoardTest.cpp test/GamePlayTest.cpp test/PointTest.cpp)
set(SERVER_FILES server/Server.cpp server/Server.h server/Client.h server/Client.cpp)

add_executable(server ${SERVER_FILES} server/server_main.cpp)
add_executable(client ${SERVER_FILES} server/client_main.cpp)

add_executable(untitled5 ${CLIENT_FILES} ${TEST_FILES} test/gtest_main.cpp)
add_executable(Reversi ${CLIENT_FILES} client/main.cpp client/Menu.h client/Menu.cpp)
target_link_libraries(untitled5 gtest gtest_main pthread)
add_test(untitled5 untitled5)
