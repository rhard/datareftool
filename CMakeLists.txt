project(datareftool CXX)
add_subdirectory(lib/xplane_sdk)
cmake_minimum_required(VERSION 2.8)

IF( NOT CMAKE_BUILD_TYPE )
	SET( CMAKE_BUILD_TYPE "RelWithDebInfo" )
ENDIF()
message(STATUS "Current build type is : ${CMAKE_BUILD_TYPE}")

add_subdirectory(src)

if(APPLE)
	list(APPEND SRC "src/clipboard_mac.mm")
elseif(WIN32)
	list(APPEND SRC "src/clipboard_win.cpp")
else()
	list(APPEND SRC "src/clipboard_linux.cpp")
endif()

SET(ALL_SRC ${SRC} ${HDR})
LIST(SORT ALL_SRC)

SOURCE_GROUP(src FILES ${ALL_SRC})

add_xplane_plugin(plugin ${ALL_SRC})
add_xplane_plugin(plugin_custom_dataref ${SRC_PLUGIN_EXAMPLE})

#compiler flags
if(WIN32)
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -DCHECK_RESULT_USED=_Check_return_")
	add_definitions(-DNOMINMAX)
else()
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra --std=c++11")
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -DCHECK_RESULT_USED=\"__attribute__ ((warn_unused_result))\"")
endif()

#libraries
set(Boost_USE_STATIC_LIBS ON)
set(Boost_USE_MULTITHREADED ON)
set(Boost_DEBUG OFF)
if(WIN32)
	set(Boost_USE_STATIC_RUNTIME OFF)
	add_definitions( -DBOOST_ALL_NO_LIB ) # disable auto linking
endif()

find_package(Boost 1.54.0 REQUIRED COMPONENTS filesystem system iostreams)
include_directories(SYSTEM ${Boost_INCLUDE_DIRS})
target_link_libraries(plugin PUBLIC ${Boost_LIBRARIES})

if(APPLE)
	SET_PROPERTY(TARGET plugin APPEND_STRING PROPERTY LINK_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} -framework Cocoa")
endif(APPLE)

#linking
link_libraries(m)

#output
set_target_properties(plugin PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/bin/datareftool" )
set_target_properties(plugin PROPERTIES LIBRARY_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/bin/datareftool" )

set_target_properties(plugin_custom_dataref PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/bin/datareftool_custom_dataref_example" )
set_target_properties(plugin_custom_dataref PROPERTIES LIBRARY_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/bin/datareftool_custom_dataref_example" )
