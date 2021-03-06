// Generated by gencpp from file roboboat/rc_number.msg
// DO NOT EDIT!


#ifndef ROBOBOAT_MESSAGE_RC_NUMBER_H
#define ROBOBOAT_MESSAGE_RC_NUMBER_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace roboboat
{
template <class ContainerAllocator>
struct rc_number_
{
  typedef rc_number_<ContainerAllocator> Type;

  rc_number_()
    : rc_number(0)  {
    }
  rc_number_(const ContainerAllocator& _alloc)
    : rc_number(0)  {
  (void)_alloc;
    }



   typedef int16_t _rc_number_type;
  _rc_number_type rc_number;





  typedef boost::shared_ptr< ::roboboat::rc_number_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::roboboat::rc_number_<ContainerAllocator> const> ConstPtr;

}; // struct rc_number_

typedef ::roboboat::rc_number_<std::allocator<void> > rc_number;

typedef boost::shared_ptr< ::roboboat::rc_number > rc_numberPtr;
typedef boost::shared_ptr< ::roboboat::rc_number const> rc_numberConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::roboboat::rc_number_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::roboboat::rc_number_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace roboboat

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': True, 'IsMessage': True, 'HasHeader': False}
// {'geographic_msgs': ['/opt/ros/kinetic/share/geographic_msgs/cmake/../msg'], 'roboboat': ['/home/mfikih15/Documents/AUVSI/src/roboboat/msg'], 'std_msgs': ['/opt/ros/kinetic/share/std_msgs/cmake/../msg'], 'sensor_msgs': ['/opt/ros/kinetic/share/sensor_msgs/cmake/../msg'], 'mavros_msgs': ['/opt/ros/kinetic/share/mavros_msgs/cmake/../msg'], 'geometry_msgs': ['/opt/ros/kinetic/share/geometry_msgs/cmake/../msg'], 'uuid_msgs': ['/opt/ros/kinetic/share/uuid_msgs/cmake/../msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::roboboat::rc_number_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::roboboat::rc_number_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::roboboat::rc_number_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::roboboat::rc_number_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::roboboat::rc_number_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::roboboat::rc_number_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::roboboat::rc_number_<ContainerAllocator> >
{
  static const char* value()
  {
    return "2244ae5f9aac7ce5c8daccbb71337be0";
  }

  static const char* value(const ::roboboat::rc_number_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x2244ae5f9aac7ce5ULL;
  static const uint64_t static_value2 = 0xc8daccbb71337be0ULL;
};

template<class ContainerAllocator>
struct DataType< ::roboboat::rc_number_<ContainerAllocator> >
{
  static const char* value()
  {
    return "roboboat/rc_number";
  }

  static const char* value(const ::roboboat::rc_number_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::roboboat::rc_number_<ContainerAllocator> >
{
  static const char* value()
  {
    return "int16 rc_number\n\
";
  }

  static const char* value(const ::roboboat::rc_number_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::roboboat::rc_number_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.rc_number);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct rc_number_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::roboboat::rc_number_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::roboboat::rc_number_<ContainerAllocator>& v)
  {
    s << indent << "rc_number: ";
    Printer<int16_t>::stream(s, indent + "  ", v.rc_number);
  }
};

} // namespace message_operations
} // namespace ros

#endif // ROBOBOAT_MESSAGE_RC_NUMBER_H
