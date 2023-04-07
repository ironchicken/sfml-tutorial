add_executable(
  sfml_tutorial
  Game.cpp
  Ball.cpp
  InputHandler.cpp
  Command.cpp
  main.cpp
  )
target_link_libraries(sfml_tutorial PRIVATE sfml-graphics)
