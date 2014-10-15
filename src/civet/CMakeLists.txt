INCLUDE_DIRECTORIES(
  ${CMAKE_CURRENT_SOURCE_DIR}
  ${CMAKE_SOURCE_DIR}/include
  ${CMAKE_SOURCE_DIR}/src/civet/
)

include_directories("${CMAKE_SOURCE_DIR}/include")

ADD_LIBRARY( civetlib STATIC
  CivetServer.cpp
  civetweb.c
)

TARGET_LINK_LIBRARIES ( civetlib )

