# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.5

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/amvui/AUVSI/src

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/amvui/AUVSI/build

# Utility rule file for kocheng_generate_messages_cpp.

# Include the progress variables for this target.
include kocheng/CMakeFiles/kocheng_generate_messages_cpp.dir/progress.make

kocheng/CMakeFiles/kocheng_generate_messages_cpp: /home/amvui/AUVSI/devel/include/kocheng/rc_number.h
kocheng/CMakeFiles/kocheng_generate_messages_cpp: /home/amvui/AUVSI/devel/include/kocheng/override_motor.h


/home/amvui/AUVSI/devel/include/kocheng/rc_number.h: /opt/ros/kinetic/lib/gencpp/gen_cpp.py
/home/amvui/AUVSI/devel/include/kocheng/rc_number.h: /home/amvui/AUVSI/src/kocheng/msg/rc_number.msg
/home/amvui/AUVSI/devel/include/kocheng/rc_number.h: /opt/ros/kinetic/share/gencpp/msg.h.template
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/amvui/AUVSI/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Generating C++ code from kocheng/rc_number.msg"
	cd /home/amvui/AUVSI/src/kocheng && /home/amvui/AUVSI/build/catkin_generated/env_cached.sh /usr/bin/python /opt/ros/kinetic/share/gencpp/cmake/../../../lib/gencpp/gen_cpp.py /home/amvui/AUVSI/src/kocheng/msg/rc_number.msg -Ikocheng:/home/amvui/AUVSI/src/kocheng/msg -Imavros_msgs:/opt/ros/kinetic/share/mavros_msgs/cmake/../msg -Istd_msgs:/opt/ros/kinetic/share/std_msgs/cmake/../msg -Isensor_msgs:/opt/ros/kinetic/share/sensor_msgs/cmake/../msg -Igeometry_msgs:/opt/ros/kinetic/share/geometry_msgs/cmake/../msg -Igeographic_msgs:/opt/ros/kinetic/share/geographic_msgs/cmake/../msg -Iuuid_msgs:/opt/ros/kinetic/share/uuid_msgs/cmake/../msg -p kocheng -o /home/amvui/AUVSI/devel/include/kocheng -e /opt/ros/kinetic/share/gencpp/cmake/..

/home/amvui/AUVSI/devel/include/kocheng/override_motor.h: /opt/ros/kinetic/lib/gencpp/gen_cpp.py
/home/amvui/AUVSI/devel/include/kocheng/override_motor.h: /home/amvui/AUVSI/src/kocheng/msg/override_motor.msg
/home/amvui/AUVSI/devel/include/kocheng/override_motor.h: /opt/ros/kinetic/share/gencpp/msg.h.template
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/amvui/AUVSI/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Generating C++ code from kocheng/override_motor.msg"
	cd /home/amvui/AUVSI/src/kocheng && /home/amvui/AUVSI/build/catkin_generated/env_cached.sh /usr/bin/python /opt/ros/kinetic/share/gencpp/cmake/../../../lib/gencpp/gen_cpp.py /home/amvui/AUVSI/src/kocheng/msg/override_motor.msg -Ikocheng:/home/amvui/AUVSI/src/kocheng/msg -Imavros_msgs:/opt/ros/kinetic/share/mavros_msgs/cmake/../msg -Istd_msgs:/opt/ros/kinetic/share/std_msgs/cmake/../msg -Isensor_msgs:/opt/ros/kinetic/share/sensor_msgs/cmake/../msg -Igeometry_msgs:/opt/ros/kinetic/share/geometry_msgs/cmake/../msg -Igeographic_msgs:/opt/ros/kinetic/share/geographic_msgs/cmake/../msg -Iuuid_msgs:/opt/ros/kinetic/share/uuid_msgs/cmake/../msg -p kocheng -o /home/amvui/AUVSI/devel/include/kocheng -e /opt/ros/kinetic/share/gencpp/cmake/..

kocheng_generate_messages_cpp: kocheng/CMakeFiles/kocheng_generate_messages_cpp
kocheng_generate_messages_cpp: /home/amvui/AUVSI/devel/include/kocheng/rc_number.h
kocheng_generate_messages_cpp: /home/amvui/AUVSI/devel/include/kocheng/override_motor.h
kocheng_generate_messages_cpp: kocheng/CMakeFiles/kocheng_generate_messages_cpp.dir/build.make

.PHONY : kocheng_generate_messages_cpp

# Rule to build all files generated by this target.
kocheng/CMakeFiles/kocheng_generate_messages_cpp.dir/build: kocheng_generate_messages_cpp

.PHONY : kocheng/CMakeFiles/kocheng_generate_messages_cpp.dir/build

kocheng/CMakeFiles/kocheng_generate_messages_cpp.dir/clean:
	cd /home/amvui/AUVSI/build/kocheng && $(CMAKE_COMMAND) -P CMakeFiles/kocheng_generate_messages_cpp.dir/cmake_clean.cmake
.PHONY : kocheng/CMakeFiles/kocheng_generate_messages_cpp.dir/clean

kocheng/CMakeFiles/kocheng_generate_messages_cpp.dir/depend:
	cd /home/amvui/AUVSI/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/amvui/AUVSI/src /home/amvui/AUVSI/src/kocheng /home/amvui/AUVSI/build /home/amvui/AUVSI/build/kocheng /home/amvui/AUVSI/build/kocheng/CMakeFiles/kocheng_generate_messages_cpp.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : kocheng/CMakeFiles/kocheng_generate_messages_cpp.dir/depend

