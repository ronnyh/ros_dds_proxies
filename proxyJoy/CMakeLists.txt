cmake_minimum_required(VERSION 2.4.6)
include($ENV{ROS_ROOT}/core/rosbuild/rosbuild.cmake)

rosbuild_init()

set(CMAKE_CXX_FLAGS "-Wno-ignored-qualifiers")

include(${PROJECT_SOURCE_DIR}/idl/FindOpenSplice.cmake)
include(${PROJECT_SOURCE_DIR}/idl/MacroOpenSplice.cmake)

include_directories(${OpenSplice_INCLUDE_DIRS} ${PROJECT_SOURCE_DIR}/include ${PROJECT_SOURCE_DIR}/idl_gen)
link_directories(${OpenSplice_LIBRARIES})

#set the default path for built executables to the "bin" directory
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
#set the default path for built libraries to the "lib" directory
set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)

SET(additionalIncludes ${additionalIncludes} "${PROJECT_SOURCE_DIR}/idl_gen/ddsJoy.cpp")
SET(additionalIncludes ${additionalIncludes} "${PROJECT_SOURCE_DIR}/idl_gen/ddsJoy.h")
SET(additionalIncludes ${additionalIncludes} "${PROJECT_SOURCE_DIR}/idl_gen/ddsJoyDcps.cpp")
SET(additionalIncludes ${additionalIncludes} "${PROJECT_SOURCE_DIR}/idl_gen/ddsJoyDcps.h")
SET(additionalIncludes ${additionalIncludes} "${PROJECT_SOURCE_DIR}/idl_gen/ddsJoyDcps_impl.cpp")
SET(additionalIncludes ${additionalIncludes} "${PROJECT_SOURCE_DIR}/idl_gen/ddsJoyDcps_impl.h")
SET(additionalIncludes ${additionalIncludes} "${PROJECT_SOURCE_DIR}/idl_gen/ddsJoySplDcps.cpp")
SET(additionalIncludes ${additionalIncludes} "${PROJECT_SOURCE_DIR}/idl_gen/ddsJoySplDcps.h")
SET(additionalIncludes ${additionalIncludes} "${PROJECT_SOURCE_DIR}/idl_gen/ccpp_ddsJoy.h")
SET(additionalIncludes ${additionalIncludes} "${PROJECT_SOURCE_DIR}/idl_gen/Time.cpp")
SET(additionalIncludes ${additionalIncludes} "${PROJECT_SOURCE_DIR}/idl_gen/Time.h")
SET(additionalIncludes ${additionalIncludes} "${PROJECT_SOURCE_DIR}/idl_gen/TimeDcps.cpp")
SET(additionalIncludes ${additionalIncludes} "${PROJECT_SOURCE_DIR}/idl_gen/TimeDcps.h")
SET(additionalIncludes ${additionalIncludes} "${PROJECT_SOURCE_DIR}/idl_gen/TimeDcps_impl.cpp")
SET(additionalIncludes ${additionalIncludes} "${PROJECT_SOURCE_DIR}/idl_gen/TimeDcps_impl.h")
SET(additionalIncludes ${additionalIncludes} "${PROJECT_SOURCE_DIR}/idl_gen/TimeSplDcps.cpp")
SET(additionalIncludes ${additionalIncludes} "${PROJECT_SOURCE_DIR}/idl_gen/TimeSplDcps.h")
SET(additionalIncludes ${additionalIncludes} "${PROJECT_SOURCE_DIR}/idl_gen/ccpp_Time.h")
SET(additionalIncludes ${additionalIncludes} "${PROJECT_SOURCE_DIR}/idl_gen/Header.cpp")
SET(additionalIncludes ${additionalIncludes} "${PROJECT_SOURCE_DIR}/idl_gen/Header.h")
SET(additionalIncludes ${additionalIncludes} "${PROJECT_SOURCE_DIR}/idl_gen/HeaderDcps.cpp")
SET(additionalIncludes ${additionalIncludes} "${PROJECT_SOURCE_DIR}/idl_gen/HeaderDcps.h")
SET(additionalIncludes ${additionalIncludes} "${PROJECT_SOURCE_DIR}/idl_gen/HeaderDcps_impl.cpp")
SET(additionalIncludes ${additionalIncludes} "${PROJECT_SOURCE_DIR}/idl_gen/HeaderDcps_impl.h")
SET(additionalIncludes ${additionalIncludes} "${PROJECT_SOURCE_DIR}/idl_gen/HeaderSplDcps.cpp")
SET(additionalIncludes ${additionalIncludes} "${PROJECT_SOURCE_DIR}/idl_gen/HeaderSplDcps.h")
SET(additionalIncludes ${additionalIncludes} "${PROJECT_SOURCE_DIR}/idl_gen/ccpp_Header.h")

# Create executable files 
rosbuild_add_boost_directories()
#rosbuild_add_executable(rosToDDSddsJoyPublisher src/ddsJoyPublisher.cc ${additionalIncludes})
#rosbuild_add_executable(rosToDDSddsJoySubscriber src/ddsJoySubscriber.cc ${additionalIncludes})
rosbuild_add_executable(proxyJoy src/proxyJoy.cpp src/ddsproxyjoy.cpp src/ddsproxyjoy.h ${additionalIncludes})

# Link the executables to the corresponding libraries. 
#rosbuild_link_boost(rosToDDSddsJoyPublisher thread)
#rosbuild_link_boost(rosToDDSddsJoySubscriber thread)
rosbuild_link_boost(proxyJoy thread)
#target_link_libraries(rosToDDSddsJoyPublisher ${OpenSplice_LIBRARIES} proxy_common)
#target_link_libraries(rosToDDSddsJoySubscriber ${OpenSplice_LIBRARIES} proxy_common)
target_link_libraries(proxyJoy ${OpenSplice_LIBRARIES} proxy_common)
