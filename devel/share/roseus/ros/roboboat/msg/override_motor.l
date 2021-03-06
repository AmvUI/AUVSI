;; Auto-generated. Do not edit!


(when (boundp 'roboboat::override_motor)
  (if (not (find-package "ROBOBOAT"))
    (make-package "ROBOBOAT"))
  (shadow 'override_motor (find-package "ROBOBOAT")))
(unless (find-package "ROBOBOAT::OVERRIDE_MOTOR")
  (make-package "ROBOBOAT::OVERRIDE_MOTOR"))

(in-package "ROS")
;;//! \htmlinclude override_motor.msg.html


(defclass roboboat::override_motor
  :super ros::object
  :slots (_steering _throttle _header ))

(defmethod roboboat::override_motor
  (:init
   (&key
    ((:steering __steering) 0)
    ((:throttle __throttle) 0)
    ((:header __header) 0)
    )
   (send-super :init)
   (setq _steering (round __steering))
   (setq _throttle (round __throttle))
   (setq _header (round __header))
   self)
  (:steering
   (&optional __steering)
   (if __steering (setq _steering __steering)) _steering)
  (:throttle
   (&optional __throttle)
   (if __throttle (setq _throttle __throttle)) _throttle)
  (:header
   (&optional __header)
   (if __header (setq _header __header)) _header)
  (:serialization-length
   ()
   (+
    ;; int16 _steering
    2
    ;; int16 _throttle
    2
    ;; int16 _header
    2
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; int16 _steering
       (write-word _steering s)
     ;; int16 _throttle
       (write-word _throttle s)
     ;; int16 _header
       (write-word _header s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; int16 _steering
     (setq _steering (sys::peek buf ptr- :short)) (incf ptr- 2)
   ;; int16 _throttle
     (setq _throttle (sys::peek buf ptr- :short)) (incf ptr- 2)
   ;; int16 _header
     (setq _header (sys::peek buf ptr- :short)) (incf ptr- 2)
   ;;
   self)
  )

(setf (get roboboat::override_motor :md5sum-) "b0615c31df605e09b8a673bfb5e75c5e")
(setf (get roboboat::override_motor :datatype-) "roboboat/override_motor")
(setf (get roboboat::override_motor :definition-)
      "int16 steering
int16 throttle
int16 header

")



(provide :roboboat/override_motor "b0615c31df605e09b8a673bfb5e75c5e")


