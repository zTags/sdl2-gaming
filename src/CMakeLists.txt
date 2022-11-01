add_executable(sdl2-gaming
    main.cpp
    Game.cpp
    Vector2.cpp
    Sprite.cpp
    Player.cpp
    GameObject.cpp
    MainMenu.cpp
    GameState.cpp
    Font.cpp
    Dropper.cpp
    Background.cpp
)

target_link_libraries(sdl2-gaming 
 	SDL2::SDL2
    SDL2::SDL2main
    SDL2_image
    SDL2_ttf
)
target_link_options(sdl2-gaming PRIVATE /SUBSYSTEM:WINDOWS)

configure_file("${CMAKE_CURRENT_SOURCE_DIR}/assets/hello.png" "${CMAKE_CURRENT_BINARY_DIR}/Debug/assets/hello.png" COPYONLY)
configure_file("${CMAKE_CURRENT_SOURCE_DIR}/assets/drop.png" "${CMAKE_CURRENT_BINARY_DIR}/Debug/assets/drop.png" COPYONLY)
configure_file("${CMAKE_CURRENT_SOURCE_DIR}/assets/PressStart2P.ttf" "${CMAKE_CURRENT_BINARY_DIR}/Debug/assets/PressStart2P.ttf" COPYONLY)