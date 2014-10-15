INCLUDE_DIRECTORIES(
  ${CMAKE_CURRENT_SOURCE_DIR}
  ${CMAKE_SOURCE_DIR}/include
  ${CMAKE_SOURCE_DIR}/src/modeldb
)

include_directories("${CMAKE_SOURCE_DIR}/include")

ADD_LIBRARY( putlib STATIC
  put.cpp
  put.hpp
)

TARGET_LINK_LIBRARIES ( putlib civetlib )
  
ADD_DEFINITIONS(-Wall -std=c++11 -g -O2 -DZLIB)