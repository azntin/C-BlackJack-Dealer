cmake_minimum_required(VERSION 3.20)
project(Player_class_test)
add_subdirectory(googletest)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/bin")

ADD_EXECUTABLE(runPlayerTests
    test/testPlayer.cpp
    src/dealer.cpp
    src/realplayer.cpp
    src/card.cpp
    src/handevaluator.cpp
    src/betting.cpp
)
ADD_EXECUTABLE(runCardTest
    test/testCard.cpp
    src/card.cpp
    src/deck.cpp
)
ADD_EXECUTABLE(runDeckTest
    test/testDeck.cpp
    src/card.cpp
    src/deck.cpp
)

ADD_EXECUTABLE(playGame
    src/main.cpp 
    src/game.cpp
    src/player.cpp 
    src/realplayer.cpp 
    src/dealer.cpp
    src/deck.cpp
    src/card.cpp
    src/handevaluator.cpp 
    src/betting.cpp
)

target_link_libraries(runPlayerTests gmock gtest gtest_main)
target_link_libraries(runCardTest gmock gtest gtest_main)
target_link_libraries(runDeckTest gmock gtest gtest_main)

add_test(NAME PlayerTests COMMAND runPlayerTests)
add_test(NAME CardTests COMMAND runCardTest)
add_test(NAME DeckTests COMMAND runDeckTest)