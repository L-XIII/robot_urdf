# robot_controller Node

## Overview

The **robot_controller Node** is a simple ROS 2 node written in C++ that controls a robot to move in a circular trajectory. It achieves this by continuously publishing velocity commands to the `/cmd_vel` topic. Additionally, the node subscribes to the `/odom` topic to log the robot's current position (`x`, `y`).

## Functionality

1. **Publishes Velocity Commands**:
   - Publishes linear and angular velocity commands to the `/cmd_vel` topic to make the robot move in a circular path.
   - Linear velocity: `0.5 m/s`
   - Angular velocity: `0.5 rad/s`

2. **Subscribes to Odometry**:
   - Subscribes to the `/odom` topic to receive the robot's current position.
   - Logs the position (`x`, `y`) in the console.

## Topics

### Published Topics
- **`/cmd_vel`** (geometry_msgs/msg/Twist):  
   Publishes velocity commands to control the robot's movement.

### Subscribed Topics
- **`/odom`** (nav_msgs/msg/Odometry):  
   Subscribes to the robot's odometry data to receive position updates.

## Usage

### Prerequisites
- A ROS 2 environment set up (e.g., ROS 2 Humble or Foxy).
- A robot simulation or hardware capable of handling `/cmd_vel` and `/odom`.

### Steps to Run
1. **Build the Node**:
   Ensure the node is included in your ROS 2 package and built:
   ```bash
   colcon build
   source install/setup.bash
