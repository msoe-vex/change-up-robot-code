#ifndef _ROS_geometry_msgs_PoseWithCovariance_h
#define _ROS_geometry_msgs_PoseWithCovariance_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros_lib/ros/msg.h"
#include "ros_lib/geometry_msgs/Pose.h"

namespace geometry_msgs
{

  class PoseWithCovariance : public ros::Msg
  {
    public:
      typedef geometry_msgs::Pose _pose_type;
      _pose_type pose;
      float covariance[36];

    PoseWithCovariance():
      pose(),
      covariance()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->pose.serialize(outbuffer + offset);
      for( uint32_t i = 0; i < 36; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->covariance[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->pose.deserialize(inbuffer + offset);
      for( uint32_t i = 0; i < 36; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->covariance[i]));
      }
     return offset;
    }

    virtual const char * getType() override { return "geometry_msgs/PoseWithCovariance"; };
    virtual const char * getMD5() override { return "c23e848cf1b7533a8d7c259073a97e6f"; };

  };

}
#endif
