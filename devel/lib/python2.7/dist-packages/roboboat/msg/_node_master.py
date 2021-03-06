# This Python file uses the following encoding: utf-8
"""autogenerated by genpy from roboboat/node_master.msg. Do not edit."""
import sys
python3 = True if sys.hexversion > 0x03000000 else False
import genpy
import struct


class node_master(genpy.Message):
  _md5sum = "9783f29d89cc75e92f81094e627988e9"
  _type = "roboboat/node_master"
  _has_header = False #flag to mark the presence of a Header object
  _full_text = """bool override_status
bool pid_status
bool simple_manuver
bool simple_speed
bool record_manuver
bool record_speed
bool path_manuver
bool path_speed
"""
  __slots__ = ['override_status','pid_status','simple_manuver','simple_speed','record_manuver','record_speed','path_manuver','path_speed']
  _slot_types = ['bool','bool','bool','bool','bool','bool','bool','bool']

  def __init__(self, *args, **kwds):
    """
    Constructor. Any message fields that are implicitly/explicitly
    set to None will be assigned a default value. The recommend
    use is keyword arguments as this is more robust to future message
    changes.  You cannot mix in-order arguments and keyword arguments.

    The available fields are:
       override_status,pid_status,simple_manuver,simple_speed,record_manuver,record_speed,path_manuver,path_speed

    :param args: complete set of field values, in .msg order
    :param kwds: use keyword arguments corresponding to message field names
    to set specific fields.
    """
    if args or kwds:
      super(node_master, self).__init__(*args, **kwds)
      #message fields cannot be None, assign default values for those that are
      if self.override_status is None:
        self.override_status = False
      if self.pid_status is None:
        self.pid_status = False
      if self.simple_manuver is None:
        self.simple_manuver = False
      if self.simple_speed is None:
        self.simple_speed = False
      if self.record_manuver is None:
        self.record_manuver = False
      if self.record_speed is None:
        self.record_speed = False
      if self.path_manuver is None:
        self.path_manuver = False
      if self.path_speed is None:
        self.path_speed = False
    else:
      self.override_status = False
      self.pid_status = False
      self.simple_manuver = False
      self.simple_speed = False
      self.record_manuver = False
      self.record_speed = False
      self.path_manuver = False
      self.path_speed = False

  def _get_types(self):
    """
    internal API method
    """
    return self._slot_types

  def serialize(self, buff):
    """
    serialize message into buffer
    :param buff: buffer, ``StringIO``
    """
    try:
      _x = self
      buff.write(_get_struct_8B().pack(_x.override_status, _x.pid_status, _x.simple_manuver, _x.simple_speed, _x.record_manuver, _x.record_speed, _x.path_manuver, _x.path_speed))
    except struct.error as se: self._check_types(struct.error("%s: '%s' when writing '%s'" % (type(se), str(se), str(locals().get('_x', self)))))
    except TypeError as te: self._check_types(ValueError("%s: '%s' when writing '%s'" % (type(te), str(te), str(locals().get('_x', self)))))

  def deserialize(self, str):
    """
    unpack serialized message in str into this message instance
    :param str: byte array of serialized message, ``str``
    """
    try:
      end = 0
      _x = self
      start = end
      end += 8
      (_x.override_status, _x.pid_status, _x.simple_manuver, _x.simple_speed, _x.record_manuver, _x.record_speed, _x.path_manuver, _x.path_speed,) = _get_struct_8B().unpack(str[start:end])
      self.override_status = bool(self.override_status)
      self.pid_status = bool(self.pid_status)
      self.simple_manuver = bool(self.simple_manuver)
      self.simple_speed = bool(self.simple_speed)
      self.record_manuver = bool(self.record_manuver)
      self.record_speed = bool(self.record_speed)
      self.path_manuver = bool(self.path_manuver)
      self.path_speed = bool(self.path_speed)
      return self
    except struct.error as e:
      raise genpy.DeserializationError(e) #most likely buffer underfill


  def serialize_numpy(self, buff, numpy):
    """
    serialize message with numpy array types into buffer
    :param buff: buffer, ``StringIO``
    :param numpy: numpy python module
    """
    try:
      _x = self
      buff.write(_get_struct_8B().pack(_x.override_status, _x.pid_status, _x.simple_manuver, _x.simple_speed, _x.record_manuver, _x.record_speed, _x.path_manuver, _x.path_speed))
    except struct.error as se: self._check_types(struct.error("%s: '%s' when writing '%s'" % (type(se), str(se), str(locals().get('_x', self)))))
    except TypeError as te: self._check_types(ValueError("%s: '%s' when writing '%s'" % (type(te), str(te), str(locals().get('_x', self)))))

  def deserialize_numpy(self, str, numpy):
    """
    unpack serialized message in str into this message instance using numpy for array types
    :param str: byte array of serialized message, ``str``
    :param numpy: numpy python module
    """
    try:
      end = 0
      _x = self
      start = end
      end += 8
      (_x.override_status, _x.pid_status, _x.simple_manuver, _x.simple_speed, _x.record_manuver, _x.record_speed, _x.path_manuver, _x.path_speed,) = _get_struct_8B().unpack(str[start:end])
      self.override_status = bool(self.override_status)
      self.pid_status = bool(self.pid_status)
      self.simple_manuver = bool(self.simple_manuver)
      self.simple_speed = bool(self.simple_speed)
      self.record_manuver = bool(self.record_manuver)
      self.record_speed = bool(self.record_speed)
      self.path_manuver = bool(self.path_manuver)
      self.path_speed = bool(self.path_speed)
      return self
    except struct.error as e:
      raise genpy.DeserializationError(e) #most likely buffer underfill

_struct_I = genpy.struct_I
def _get_struct_I():
    global _struct_I
    return _struct_I
_struct_8B = None
def _get_struct_8B():
    global _struct_8B
    if _struct_8B is None:
        _struct_8B = struct.Struct("<8B")
    return _struct_8B
