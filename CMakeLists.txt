
cmake_minimum_required(VERSION 3.6)
project(untitled5)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")
#add_subdirectory(lib/googletest-release-1.8.0)
#include_directories(lib/googletest-release-1.8.0/googletest/include)
#include_directories(lib/googletest-release-1.8.0/googlemock/include)

set(SOURCE_FILES src/client/BasicGameRules.h src/client/BasicGameRules.cpp src/client/Board.h src/client/Board.cpp src/client/BoardDisplayer.h src/client/ConsoleDisplay.cpp
        src/client/ConsoleDisplay.h src/client/GamePlay.h src/client/GamePlay.cpp src/client/GameRules.h src/client/GameRules.cpp src/client/HumanConsolePlayer.cpp
        src/client/HumanConsolePlayer.h src/client/Player.h src/client/Player.cpp src/client/Point.h src/client/Point.cpp src/client/AIPlayer.h src/client/AIPlayer.cpp
        src/client/RemotePlayer.cpp src/client/RemotePlayer.h src/client/VirtualPlayer.cpp src/client/VirtualPlayer.h src/client/Menu.h src/client/Menu.cpp src/client/Client.txt)

#set(TEST_FILES test/JustATest.cpp test/BasicGameRulesTest.cpp test/BoardTest.cpp test/GamePlayTest.cpp test/PointTest.cpp)
set(SERVER_FILES src/server/Server.cpp src/server/Server.h src/server/server_main.cpp src/server/Server.txt src/server/Command.h src/server/CommandsManager.cpp src/server/CommandsManager.h src/server/StartCommand.cpp src/server/StartCommand.h src/server/ListGamesCommand.cpp src/server/ListGamesCommand.h src/server/JoinGameCommand.cpp src/server/JoinGameCommand.h src/server/PlayCommand.cpp src/server/PlayCommand.h src/server/CloseCommand.cpp src/server/CloseCommand.h src/server/Task.h src/server/gameLoopTask.cpp src/server/gameLoopTask.h src/server/ThreadPool.cpp src/server/ThreadPool.h)

add_executable(server ${SERVER_FILES} src/server/server_main.cpp )

#add_executable(untitled5 ${SOURCE_FILES} ${TEST_FILES} test/gtest_main.cpp)
add_executable(Reversi ${SOURCE_FILES} src/client/main.cpp)
#target_link_libraries(untitled5 gtest gtest_main pthread)
add_test(untitled5 untitled5)
