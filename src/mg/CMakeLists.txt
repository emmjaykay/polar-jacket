INCLUDE_DIRECTORIES(
  ${CMAKE_CURRENT_SOURCE_DIR}
  ${CMAKE_SOURCE_DIR}/include
  ${CMAKE_SOURCE_DIR}/src/modeldb/
)

include_directories("${CMAKE_SOURCE_DIR}/include")

ADD_LIBRARY( mglib STATIC
  mongoose.c
)

TARGET_LINK_LIBRARIES ( mglib )
  
