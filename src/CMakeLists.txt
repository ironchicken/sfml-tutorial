add_executable(
  sfml_tutorial
  Game.cpp
  Ball.cpp
  main.cpp
  )
target_link_libraries(sfml_tutorial PRIVATE sfml-graphics)
