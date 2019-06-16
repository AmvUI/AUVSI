# generated from genmsg/cmake/pkg-genmsg.cmake.em

message(STATUS "kocheng: 10 messages, 0 services")

set(MSG_I_FLAGS "-Ikocheng:/home/mfikih15/Documents/AUVSI/src/kocheng/msg;-Imavros_msgs:/opt/ros/kinetic/share/mavros_msgs/cmake/../msg;-Istd_msgs:/opt/ros/kinetic/share/std_msgs/cmake/../msg;-Isensor_msgs:/opt/ros/kinetic/share/sensor_msgs/cmake/../msg;-Igeographic_msgs:/opt/ros/kinetic/share/geographic_msgs/cmake/../msg;-Igeometry_msgs:/opt/ros/kinetic/share/geometry_msgs/cmake/../msg;-Iuuid_msgs:/opt/ros/kinetic/share/uuid_msgs/cmake/../msg")

# Find all generators
find_package(gencpp REQUIRED)
find_package(geneus REQUIRED)
find_package(genlisp REQUIRED)
find_package(gennodejs REQUIRED)
find_package(genpy REQUIRED)

add_custom_target(kocheng_generate_messages ALL)

# verify that message/service dependencies have not changed since configure



get_filename_component(_filename "/home/mfikih15/Documents/AUVSI/src/kocheng/msg/image_in.msg" NAME_WE)
add_custom_target(_kocheng_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "kocheng" "/home/mfikih15/Documents/AUVSI/src/kocheng/msg/image_in.msg" ""
)

get_filename_component(_filename "/home/mfikih15/Documents/AUVSI/src/kocheng/msg/rc_number.msg" NAME_WE)
add_custom_target(_kocheng_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "kocheng" "/home/mfikih15/Documents/AUVSI/src/kocheng/msg/rc_number.msg" ""
)

get_filename_component(_filename "/home/mfikih15/Documents/AUVSI/src/kocheng/msg/override_value.msg" NAME_WE)
add_custom_target(_kocheng_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "kocheng" "/home/mfikih15/Documents/AUVSI/src/kocheng/msg/override_value.msg" ""
)

get_filename_component(_filename "/home/mfikih15/Documents/AUVSI/src/kocheng/msg/com_auvsi.msg" NAME_WE)
add_custom_target(_kocheng_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "kocheng" "/home/mfikih15/Documents/AUVSI/src/kocheng/msg/com_auvsi.msg" ""
)

get_filename_component(_filename "/home/mfikih15/Documents/AUVSI/src/kocheng/msg/mission_status.msg" NAME_WE)
add_custom_target(_kocheng_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "kocheng" "/home/mfikih15/Documents/AUVSI/src/kocheng/msg/mission_status.msg" ""
)

get_filename_component(_filename "/home/mfikih15/Documents/AUVSI/src/kocheng/msg/image_out.msg" NAME_WE)
add_custom_target(_kocheng_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "kocheng" "/home/mfikih15/Documents/AUVSI/src/kocheng/msg/image_out.msg" ""
)

get_filename_component(_filename "/home/mfikih15/Documents/AUVSI/src/kocheng/msg/decode_status.msg" NAME_WE)
add_custom_target(_kocheng_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "kocheng" "/home/mfikih15/Documents/AUVSI/src/kocheng/msg/decode_status.msg" ""
)

get_filename_component(_filename "/home/mfikih15/Documents/AUVSI/src/kocheng/msg/drone_kocheng.msg" NAME_WE)
add_custom_target(_kocheng_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "kocheng" "/home/mfikih15/Documents/AUVSI/src/kocheng/msg/drone_kocheng.msg" ""
)

get_filename_component(_filename "/home/mfikih15/Documents/AUVSI/src/kocheng/msg/communication.msg" NAME_WE)
add_custom_target(_kocheng_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "kocheng" "/home/mfikih15/Documents/AUVSI/src/kocheng/msg/communication.msg" ""
)

get_filename_component(_filename "/home/mfikih15/Documents/AUVSI/src/kocheng/msg/debug_mission.msg" NAME_WE)
add_custom_target(_kocheng_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "kocheng" "/home/mfikih15/Documents/AUVSI/src/kocheng/msg/debug_mission.msg" ""
)

#
#  langs = gencpp;geneus;genlisp;gennodejs;genpy
#

### Section generating for lang: gencpp
### Generating Messages
_generate_msg_cpp(kocheng
  "/home/mfikih15/Documents/AUVSI/src/kocheng/msg/image_in.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/kocheng
)
_generate_msg_cpp(kocheng
  "/home/mfikih15/Documents/AUVSI/src/kocheng/msg/rc_number.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/kocheng
)
_generate_msg_cpp(kocheng
  "/home/mfikih15/Documents/AUVSI/src/kocheng/msg/override_value.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/kocheng
)
_generate_msg_cpp(kocheng
  "/home/mfikih15/Documents/AUVSI/src/kocheng/msg/com_auvsi.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/kocheng
)
_generate_msg_cpp(kocheng
  "/home/mfikih15/Documents/AUVSI/src/kocheng/msg/mission_status.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/kocheng
)
_generate_msg_cpp(kocheng
  "/home/mfikih15/Documents/AUVSI/src/kocheng/msg/image_out.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/kocheng
)
_generate_msg_cpp(kocheng
  "/home/mfikih15/Documents/AUVSI/src/kocheng/msg/decode_status.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/kocheng
)
_generate_msg_cpp(kocheng
  "/home/mfikih15/Documents/AUVSI/src/kocheng/msg/drone_kocheng.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/kocheng
)
_generate_msg_cpp(kocheng
  "/home/mfikih15/Documents/AUVSI/src/kocheng/msg/communication.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/kocheng
)
_generate_msg_cpp(kocheng
  "/home/mfikih15/Documents/AUVSI/src/kocheng/msg/debug_mission.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/kocheng
)

### Generating Services

### Generating Module File
_generate_module_cpp(kocheng
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/kocheng
  "${ALL_GEN_OUTPUT_FILES_cpp}"
)

add_custom_target(kocheng_generate_messages_cpp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_cpp}
)
add_dependencies(kocheng_generate_messages kocheng_generate_messages_cpp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/mfikih15/Documents/AUVSI/src/kocheng/msg/image_in.msg" NAME_WE)
add_dependencies(kocheng_generate_messages_cpp _kocheng_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/mfikih15/Documents/AUVSI/src/kocheng/msg/rc_number.msg" NAME_WE)
add_dependencies(kocheng_generate_messages_cpp _kocheng_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/mfikih15/Documents/AUVSI/src/kocheng/msg/override_value.msg" NAME_WE)
add_dependencies(kocheng_generate_messages_cpp _kocheng_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/mfikih15/Documents/AUVSI/src/kocheng/msg/com_auvsi.msg" NAME_WE)
add_dependencies(kocheng_generate_messages_cpp _kocheng_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/mfikih15/Documents/AUVSI/src/kocheng/msg/mission_status.msg" NAME_WE)
add_dependencies(kocheng_generate_messages_cpp _kocheng_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/mfikih15/Documents/AUVSI/src/kocheng/msg/image_out.msg" NAME_WE)
add_dependencies(kocheng_generate_messages_cpp _kocheng_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/mfikih15/Documents/AUVSI/src/kocheng/msg/decode_status.msg" NAME_WE)
add_dependencies(kocheng_generate_messages_cpp _kocheng_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/mfikih15/Documents/AUVSI/src/kocheng/msg/drone_kocheng.msg" NAME_WE)
add_dependencies(kocheng_generate_messages_cpp _kocheng_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/mfikih15/Documents/AUVSI/src/kocheng/msg/communication.msg" NAME_WE)
add_dependencies(kocheng_generate_messages_cpp _kocheng_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/mfikih15/Documents/AUVSI/src/kocheng/msg/debug_mission.msg" NAME_WE)
add_dependencies(kocheng_generate_messages_cpp _kocheng_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(kocheng_gencpp)
add_dependencies(kocheng_gencpp kocheng_generate_messages_cpp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS kocheng_generate_messages_cpp)

### Section generating for lang: geneus
### Generating Messages
_generate_msg_eus(kocheng
  "/home/mfikih15/Documents/AUVSI/src/kocheng/msg/image_in.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/kocheng
)
_generate_msg_eus(kocheng
  "/home/mfikih15/Documents/AUVSI/src/kocheng/msg/rc_number.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/kocheng
)
_generate_msg_eus(kocheng
  "/home/mfikih15/Documents/AUVSI/src/kocheng/msg/override_value.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/kocheng
)
_generate_msg_eus(kocheng
  "/home/mfikih15/Documents/AUVSI/src/kocheng/msg/com_auvsi.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/kocheng
)
_generate_msg_eus(kocheng
  "/home/mfikih15/Documents/AUVSI/src/kocheng/msg/mission_status.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/kocheng
)
_generate_msg_eus(kocheng
  "/home/mfikih15/Documents/AUVSI/src/kocheng/msg/image_out.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/kocheng
)
_generate_msg_eus(kocheng
  "/home/mfikih15/Documents/AUVSI/src/kocheng/msg/decode_status.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/kocheng
)
_generate_msg_eus(kocheng
  "/home/mfikih15/Documents/AUVSI/src/kocheng/msg/drone_kocheng.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/kocheng
)
_generate_msg_eus(kocheng
  "/home/mfikih15/Documents/AUVSI/src/kocheng/msg/communication.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/kocheng
)
_generate_msg_eus(kocheng
  "/home/mfikih15/Documents/AUVSI/src/kocheng/msg/debug_mission.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/kocheng
)

### Generating Services

### Generating Module File
_generate_module_eus(kocheng
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/kocheng
  "${ALL_GEN_OUTPUT_FILES_eus}"
)

add_custom_target(kocheng_generate_messages_eus
  DEPENDS ${ALL_GEN_OUTPUT_FILES_eus}
)
add_dependencies(kocheng_generate_messages kocheng_generate_messages_eus)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/mfikih15/Documents/AUVSI/src/kocheng/msg/image_in.msg" NAME_WE)
add_dependencies(kocheng_generate_messages_eus _kocheng_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/mfikih15/Documents/AUVSI/src/kocheng/msg/rc_number.msg" NAME_WE)
add_dependencies(kocheng_generate_messages_eus _kocheng_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/mfikih15/Documents/AUVSI/src/kocheng/msg/override_value.msg" NAME_WE)
add_dependencies(kocheng_generate_messages_eus _kocheng_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/mfikih15/Documents/AUVSI/src/kocheng/msg/com_auvsi.msg" NAME_WE)
add_dependencies(kocheng_generate_messages_eus _kocheng_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/mfikih15/Documents/AUVSI/src/kocheng/msg/mission_status.msg" NAME_WE)
add_dependencies(kocheng_generate_messages_eus _kocheng_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/mfikih15/Documents/AUVSI/src/kocheng/msg/image_out.msg" NAME_WE)
add_dependencies(kocheng_generate_messages_eus _kocheng_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/mfikih15/Documents/AUVSI/src/kocheng/msg/decode_status.msg" NAME_WE)
add_dependencies(kocheng_generate_messages_eus _kocheng_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/mfikih15/Documents/AUVSI/src/kocheng/msg/drone_kocheng.msg" NAME_WE)
add_dependencies(kocheng_generate_messages_eus _kocheng_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/mfikih15/Documents/AUVSI/src/kocheng/msg/communication.msg" NAME_WE)
add_dependencies(kocheng_generate_messages_eus _kocheng_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/mfikih15/Documents/AUVSI/src/kocheng/msg/debug_mission.msg" NAME_WE)
add_dependencies(kocheng_generate_messages_eus _kocheng_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(kocheng_geneus)
add_dependencies(kocheng_geneus kocheng_generate_messages_eus)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS kocheng_generate_messages_eus)

### Section generating for lang: genlisp
### Generating Messages
_generate_msg_lisp(kocheng
  "/home/mfikih15/Documents/AUVSI/src/kocheng/msg/image_in.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/kocheng
)
_generate_msg_lisp(kocheng
  "/home/mfikih15/Documents/AUVSI/src/kocheng/msg/rc_number.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/kocheng
)
_generate_msg_lisp(kocheng
  "/home/mfikih15/Documents/AUVSI/src/kocheng/msg/override_value.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/kocheng
)
_generate_msg_lisp(kocheng
  "/home/mfikih15/Documents/AUVSI/src/kocheng/msg/com_auvsi.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/kocheng
)
_generate_msg_lisp(kocheng
  "/home/mfikih15/Documents/AUVSI/src/kocheng/msg/mission_status.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/kocheng
)
_generate_msg_lisp(kocheng
  "/home/mfikih15/Documents/AUVSI/src/kocheng/msg/image_out.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/kocheng
)
_generate_msg_lisp(kocheng
  "/home/mfikih15/Documents/AUVSI/src/kocheng/msg/decode_status.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/kocheng
)
_generate_msg_lisp(kocheng
  "/home/mfikih15/Documents/AUVSI/src/kocheng/msg/drone_kocheng.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/kocheng
)
_generate_msg_lisp(kocheng
  "/home/mfikih15/Documents/AUVSI/src/kocheng/msg/communication.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/kocheng
)
_generate_msg_lisp(kocheng
  "/home/mfikih15/Documents/AUVSI/src/kocheng/msg/debug_mission.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/kocheng
)

### Generating Services

### Generating Module File
_generate_module_lisp(kocheng
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/kocheng
  "${ALL_GEN_OUTPUT_FILES_lisp}"
)

add_custom_target(kocheng_generate_messages_lisp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_lisp}
)
add_dependencies(kocheng_generate_messages kocheng_generate_messages_lisp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/mfikih15/Documents/AUVSI/src/kocheng/msg/image_in.msg" NAME_WE)
add_dependencies(kocheng_generate_messages_lisp _kocheng_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/mfikih15/Documents/AUVSI/src/kocheng/msg/rc_number.msg" NAME_WE)
add_dependencies(kocheng_generate_messages_lisp _kocheng_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/mfikih15/Documents/AUVSI/src/kocheng/msg/override_value.msg" NAME_WE)
add_dependencies(kocheng_generate_messages_lisp _kocheng_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/mfikih15/Documents/AUVSI/src/kocheng/msg/com_auvsi.msg" NAME_WE)
add_dependencies(kocheng_generate_messages_lisp _kocheng_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/mfikih15/Documents/AUVSI/src/kocheng/msg/mission_status.msg" NAME_WE)
add_dependencies(kocheng_generate_messages_lisp _kocheng_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/mfikih15/Documents/AUVSI/src/kocheng/msg/image_out.msg" NAME_WE)
add_dependencies(kocheng_generate_messages_lisp _kocheng_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/mfikih15/Documents/AUVSI/src/kocheng/msg/decode_status.msg" NAME_WE)
add_dependencies(kocheng_generate_messages_lisp _kocheng_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/mfikih15/Documents/AUVSI/src/kocheng/msg/drone_kocheng.msg" NAME_WE)
add_dependencies(kocheng_generate_messages_lisp _kocheng_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/mfikih15/Documents/AUVSI/src/kocheng/msg/communication.msg" NAME_WE)
add_dependencies(kocheng_generate_messages_lisp _kocheng_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/mfikih15/Documents/AUVSI/src/kocheng/msg/debug_mission.msg" NAME_WE)
add_dependencies(kocheng_generate_messages_lisp _kocheng_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(kocheng_genlisp)
add_dependencies(kocheng_genlisp kocheng_generate_messages_lisp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS kocheng_generate_messages_lisp)

### Section generating for lang: gennodejs
### Generating Messages
_generate_msg_nodejs(kocheng
  "/home/mfikih15/Documents/AUVSI/src/kocheng/msg/image_in.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/kocheng
)
_generate_msg_nodejs(kocheng
  "/home/mfikih15/Documents/AUVSI/src/kocheng/msg/rc_number.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/kocheng
)
_generate_msg_nodejs(kocheng
  "/home/mfikih15/Documents/AUVSI/src/kocheng/msg/override_value.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/kocheng
)
_generate_msg_nodejs(kocheng
  "/home/mfikih15/Documents/AUVSI/src/kocheng/msg/com_auvsi.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/kocheng
)
_generate_msg_nodejs(kocheng
  "/home/mfikih15/Documents/AUVSI/src/kocheng/msg/mission_status.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/kocheng
)
_generate_msg_nodejs(kocheng
  "/home/mfikih15/Documents/AUVSI/src/kocheng/msg/image_out.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/kocheng
)
_generate_msg_nodejs(kocheng
  "/home/mfikih15/Documents/AUVSI/src/kocheng/msg/decode_status.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/kocheng
)
_generate_msg_nodejs(kocheng
  "/home/mfikih15/Documents/AUVSI/src/kocheng/msg/drone_kocheng.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/kocheng
)
_generate_msg_nodejs(kocheng
  "/home/mfikih15/Documents/AUVSI/src/kocheng/msg/communication.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/kocheng
)
_generate_msg_nodejs(kocheng
  "/home/mfikih15/Documents/AUVSI/src/kocheng/msg/debug_mission.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/kocheng
)

### Generating Services

### Generating Module File
_generate_module_nodejs(kocheng
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/kocheng
  "${ALL_GEN_OUTPUT_FILES_nodejs}"
)

add_custom_target(kocheng_generate_messages_nodejs
  DEPENDS ${ALL_GEN_OUTPUT_FILES_nodejs}
)
add_dependencies(kocheng_generate_messages kocheng_generate_messages_nodejs)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/mfikih15/Documents/AUVSI/src/kocheng/msg/image_in.msg" NAME_WE)
add_dependencies(kocheng_generate_messages_nodejs _kocheng_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/mfikih15/Documents/AUVSI/src/kocheng/msg/rc_number.msg" NAME_WE)
add_dependencies(kocheng_generate_messages_nodejs _kocheng_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/mfikih15/Documents/AUVSI/src/kocheng/msg/override_value.msg" NAME_WE)
add_dependencies(kocheng_generate_messages_nodejs _kocheng_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/mfikih15/Documents/AUVSI/src/kocheng/msg/com_auvsi.msg" NAME_WE)
add_dependencies(kocheng_generate_messages_nodejs _kocheng_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/mfikih15/Documents/AUVSI/src/kocheng/msg/mission_status.msg" NAME_WE)
add_dependencies(kocheng_generate_messages_nodejs _kocheng_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/mfikih15/Documents/AUVSI/src/kocheng/msg/image_out.msg" NAME_WE)
add_dependencies(kocheng_generate_messages_nodejs _kocheng_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/mfikih15/Documents/AUVSI/src/kocheng/msg/decode_status.msg" NAME_WE)
add_dependencies(kocheng_generate_messages_nodejs _kocheng_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/mfikih15/Documents/AUVSI/src/kocheng/msg/drone_kocheng.msg" NAME_WE)
add_dependencies(kocheng_generate_messages_nodejs _kocheng_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/mfikih15/Documents/AUVSI/src/kocheng/msg/communication.msg" NAME_WE)
add_dependencies(kocheng_generate_messages_nodejs _kocheng_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/mfikih15/Documents/AUVSI/src/kocheng/msg/debug_mission.msg" NAME_WE)
add_dependencies(kocheng_generate_messages_nodejs _kocheng_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(kocheng_gennodejs)
add_dependencies(kocheng_gennodejs kocheng_generate_messages_nodejs)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS kocheng_generate_messages_nodejs)

### Section generating for lang: genpy
### Generating Messages
_generate_msg_py(kocheng
  "/home/mfikih15/Documents/AUVSI/src/kocheng/msg/image_in.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/kocheng
)
_generate_msg_py(kocheng
  "/home/mfikih15/Documents/AUVSI/src/kocheng/msg/rc_number.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/kocheng
)
_generate_msg_py(kocheng
  "/home/mfikih15/Documents/AUVSI/src/kocheng/msg/override_value.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/kocheng
)
_generate_msg_py(kocheng
  "/home/mfikih15/Documents/AUVSI/src/kocheng/msg/com_auvsi.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/kocheng
)
_generate_msg_py(kocheng
  "/home/mfikih15/Documents/AUVSI/src/kocheng/msg/mission_status.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/kocheng
)
_generate_msg_py(kocheng
  "/home/mfikih15/Documents/AUVSI/src/kocheng/msg/image_out.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/kocheng
)
_generate_msg_py(kocheng
  "/home/mfikih15/Documents/AUVSI/src/kocheng/msg/decode_status.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/kocheng
)
_generate_msg_py(kocheng
  "/home/mfikih15/Documents/AUVSI/src/kocheng/msg/drone_kocheng.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/kocheng
)
_generate_msg_py(kocheng
  "/home/mfikih15/Documents/AUVSI/src/kocheng/msg/communication.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/kocheng
)
_generate_msg_py(kocheng
  "/home/mfikih15/Documents/AUVSI/src/kocheng/msg/debug_mission.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/kocheng
)

### Generating Services

### Generating Module File
_generate_module_py(kocheng
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/kocheng
  "${ALL_GEN_OUTPUT_FILES_py}"
)

add_custom_target(kocheng_generate_messages_py
  DEPENDS ${ALL_GEN_OUTPUT_FILES_py}
)
add_dependencies(kocheng_generate_messages kocheng_generate_messages_py)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/mfikih15/Documents/AUVSI/src/kocheng/msg/image_in.msg" NAME_WE)
add_dependencies(kocheng_generate_messages_py _kocheng_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/mfikih15/Documents/AUVSI/src/kocheng/msg/rc_number.msg" NAME_WE)
add_dependencies(kocheng_generate_messages_py _kocheng_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/mfikih15/Documents/AUVSI/src/kocheng/msg/override_value.msg" NAME_WE)
add_dependencies(kocheng_generate_messages_py _kocheng_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/mfikih15/Documents/AUVSI/src/kocheng/msg/com_auvsi.msg" NAME_WE)
add_dependencies(kocheng_generate_messages_py _kocheng_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/mfikih15/Documents/AUVSI/src/kocheng/msg/mission_status.msg" NAME_WE)
add_dependencies(kocheng_generate_messages_py _kocheng_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/mfikih15/Documents/AUVSI/src/kocheng/msg/image_out.msg" NAME_WE)
add_dependencies(kocheng_generate_messages_py _kocheng_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/mfikih15/Documents/AUVSI/src/kocheng/msg/decode_status.msg" NAME_WE)
add_dependencies(kocheng_generate_messages_py _kocheng_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/mfikih15/Documents/AUVSI/src/kocheng/msg/drone_kocheng.msg" NAME_WE)
add_dependencies(kocheng_generate_messages_py _kocheng_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/mfikih15/Documents/AUVSI/src/kocheng/msg/communication.msg" NAME_WE)
add_dependencies(kocheng_generate_messages_py _kocheng_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/mfikih15/Documents/AUVSI/src/kocheng/msg/debug_mission.msg" NAME_WE)
add_dependencies(kocheng_generate_messages_py _kocheng_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(kocheng_genpy)
add_dependencies(kocheng_genpy kocheng_generate_messages_py)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS kocheng_generate_messages_py)



if(gencpp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/kocheng)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/kocheng
    DESTINATION ${gencpp_INSTALL_DIR}
  )
endif()
if(TARGET mavros_msgs_generate_messages_cpp)
  add_dependencies(kocheng_generate_messages_cpp mavros_msgs_generate_messages_cpp)
endif()
if(TARGET std_msgs_generate_messages_cpp)
  add_dependencies(kocheng_generate_messages_cpp std_msgs_generate_messages_cpp)
endif()
if(TARGET sensor_msgs_generate_messages_cpp)
  add_dependencies(kocheng_generate_messages_cpp sensor_msgs_generate_messages_cpp)
endif()

if(geneus_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/kocheng)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/kocheng
    DESTINATION ${geneus_INSTALL_DIR}
  )
endif()
if(TARGET mavros_msgs_generate_messages_eus)
  add_dependencies(kocheng_generate_messages_eus mavros_msgs_generate_messages_eus)
endif()
if(TARGET std_msgs_generate_messages_eus)
  add_dependencies(kocheng_generate_messages_eus std_msgs_generate_messages_eus)
endif()
if(TARGET sensor_msgs_generate_messages_eus)
  add_dependencies(kocheng_generate_messages_eus sensor_msgs_generate_messages_eus)
endif()

if(genlisp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/kocheng)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/kocheng
    DESTINATION ${genlisp_INSTALL_DIR}
  )
endif()
if(TARGET mavros_msgs_generate_messages_lisp)
  add_dependencies(kocheng_generate_messages_lisp mavros_msgs_generate_messages_lisp)
endif()
if(TARGET std_msgs_generate_messages_lisp)
  add_dependencies(kocheng_generate_messages_lisp std_msgs_generate_messages_lisp)
endif()
if(TARGET sensor_msgs_generate_messages_lisp)
  add_dependencies(kocheng_generate_messages_lisp sensor_msgs_generate_messages_lisp)
endif()

if(gennodejs_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/kocheng)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/kocheng
    DESTINATION ${gennodejs_INSTALL_DIR}
  )
endif()
if(TARGET mavros_msgs_generate_messages_nodejs)
  add_dependencies(kocheng_generate_messages_nodejs mavros_msgs_generate_messages_nodejs)
endif()
if(TARGET std_msgs_generate_messages_nodejs)
  add_dependencies(kocheng_generate_messages_nodejs std_msgs_generate_messages_nodejs)
endif()
if(TARGET sensor_msgs_generate_messages_nodejs)
  add_dependencies(kocheng_generate_messages_nodejs sensor_msgs_generate_messages_nodejs)
endif()

if(genpy_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/kocheng)
  install(CODE "execute_process(COMMAND \"/usr/bin/python\" -m compileall \"${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/kocheng\")")
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/kocheng
    DESTINATION ${genpy_INSTALL_DIR}
  )
endif()
if(TARGET mavros_msgs_generate_messages_py)
  add_dependencies(kocheng_generate_messages_py mavros_msgs_generate_messages_py)
endif()
if(TARGET std_msgs_generate_messages_py)
  add_dependencies(kocheng_generate_messages_py std_msgs_generate_messages_py)
endif()
if(TARGET sensor_msgs_generate_messages_py)
  add_dependencies(kocheng_generate_messages_py sensor_msgs_generate_messages_py)
endif()
