; Auto-generated. Do not edit!


(cl:in-package roboboat-msg)


;//! \htmlinclude setpoint.msg.html

(cl:defclass <setpoint> (roslisp-msg-protocol:ros-message)
  ((setpoint
    :reader setpoint
    :initarg :setpoint
    :type cl:fixnum
    :initform 0))
)

(cl:defclass setpoint (<setpoint>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <setpoint>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'setpoint)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name roboboat-msg:<setpoint> is deprecated: use roboboat-msg:setpoint instead.")))

(cl:ensure-generic-function 'setpoint-val :lambda-list '(m))
(cl:defmethod setpoint-val ((m <setpoint>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader roboboat-msg:setpoint-val is deprecated.  Use roboboat-msg:setpoint instead.")
  (setpoint m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <setpoint>) ostream)
  "Serializes a message object of type '<setpoint>"
  (cl:let* ((signed (cl:slot-value msg 'setpoint)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 65536) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    )
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <setpoint>) istream)
  "Deserializes a message object of type '<setpoint>"
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'setpoint) (cl:if (cl:< unsigned 32768) unsigned (cl:- unsigned 65536))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<setpoint>)))
  "Returns string type for a message object of type '<setpoint>"
  "roboboat/setpoint")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'setpoint)))
  "Returns string type for a message object of type 'setpoint"
  "roboboat/setpoint")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<setpoint>)))
  "Returns md5sum for a message object of type '<setpoint>"
  "8ee399a1f7e5b4decdfc42e0ba4ab098")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'setpoint)))
  "Returns md5sum for a message object of type 'setpoint"
  "8ee399a1f7e5b4decdfc42e0ba4ab098")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<setpoint>)))
  "Returns full string definition for message of type '<setpoint>"
  (cl:format cl:nil "int16 setpoint~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'setpoint)))
  "Returns full string definition for message of type 'setpoint"
  (cl:format cl:nil "int16 setpoint~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <setpoint>))
  (cl:+ 0
     2
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <setpoint>))
  "Converts a ROS message object to a list"
  (cl:list 'setpoint
    (cl:cons ':setpoint (setpoint msg))
))
