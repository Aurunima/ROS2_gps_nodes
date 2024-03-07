### Readme

**Platform**: Raspberry Pi 5 \
**Docker image**: arm64v8/ros:humble

_Workspace name_: ros2raspi5_ws \
_Package name_: gps_communication

#### Folder structure
gps_communication/ \
├── CMakeLists.txt \
├── package.xml \
└── src/ \
&emsp;├── gps_publisher.cpp \
&emsp;├── gps_subscriber.cpp

#### Build:
cd ~/ros2raspi5_ws
colcon build --packages-select gps_communication

#### Source the workspace:
source ~/ros2raspi5_ws/install/setup.bash

#### Run the publisher and subscriber nodes in separate terminals:
(Maybe use [tmux](https://www.redhat.com/sysadmin/introduction-tmux-linux) to use multiple bash sessions in same terminal) \

In terminal 1: \
&nbsp;ros2 run gps_communication gps_publisher

In terminal 2: \
&nbsp;ros2 run gps_communication gps_subscriber

