INCLUDE_DIRECTORIES(
  ${CMAKE_CURRENT_SOURCE_DIR}
  ${CMAKE_SOURCE_DIR}/include
)

include_directories("${CMAKE_SOURCE_DIR}/include")

#configure_file (
#  "${PROJECT_SOURCE_DIR}/src/modeldb/modeldb.hpp.in"
#  "${PROJECT_BINARY_DIR}/src/modeldb/modeldb.hpp"
#)

ADD_LIBRARY( modeldb STATIC
  modeldb.cpp
  modeldb.hpp
)

#find_library(LIBLEVELDB libleveldb)
find_library(LIBROCKSDB rocksdb)

#this link-targets things it has already built
#TARGET_LINK_LIBRARIES ( leveldb )
TARGET_LINK_LIBRARIES ( rocksdb )

ADD_DEFINITIONS(-Wall -std=c++11 -g -O2 -DZLIB)
  
