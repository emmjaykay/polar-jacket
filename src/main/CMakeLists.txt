INCLUDE_DIRECTORIES(
  ${CMAKE_CURRENT_SOUCE_DIR}
  ${CMAKE_SOURCE_DIR}/src/main
  ${CMAKE_SOURCE_DIR}/src/hw/
  ${CMAKE_SOURCE_DIR}/src/put/
  ${CMAKE_SOURCE_DIR}/src/get/
  ${CMAKE_SOURCE_DIR}/src/modeldb/
  ${CMAKE_SOURCE_DIR}/src/civet/
  ${CMAKE_SOURCE_DIR}/include/
  ${CMAKE_SOURCE_DIR}/lib
)

configure_file (
  "${PROJECT_SOURCE_DIR}/src/main/main.hpp.in"
  "${PROJECT_BINARY_DIR}/src/main/main.hpp"
)                                                                            

include_directories("${CMAKE_SOURCE_DIR}/include")
link_directories("${CMAKE_SOURCE_DIR}/lib")

add_executable(ioswitch main.cpp)
add_dependencies(ioswitch putlib getlib modeldb civetlib)
target_link_libraries(ioswitch boost_system)
target_link_libraries(ioswitch rocksdb)
target_link_libraries(ioswitch civetlib)

target_link_libraries(ioswitch putlib getlib modeldb civetlib ${CMAKE_SOURCE_DIR}/lib/librocksdb.a snappy z bz2 )

#target_link_libraries(ioswitch httpserver)

target_link_libraries(ioswitch boost_thread boost_system pthread dl)
ADD_DEFINITIONS(-Wall -std=c++11 -g -O2 -DZLIB)

install(TARGETS ioswitch COMPONENT ioswitch RUNTIME DESTINATION ${PROJECT_SOURCE_DIR})

