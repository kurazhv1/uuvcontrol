# Uuvcontrol #

## Cloning the project ##
Clone using:  
```
git clone git@github.com:NoriBu/uuvcontrol.git --recurse-submodules
```

## Launching ##
  
1. Go to 'uuvcontrol/catkin_ws_sim/'
      
2. Build with either 
```
catkin_make
```
or
```
catkin build
``` 
3. Launch world with
```
roslaunch uuv_gazebo_worlds auv_underwater_world.launch
```   
- Other worlds are available to test, these can be found by pressing Tab after writing 'roslaunch uuv_gazebo_worlds'

4. Spawn the robot to the world with 
```
roslaunch uuvfloat_description upload_uuvfloat.launch
```
- **NOTE**: Spawning the robot can in some cases cause the simulation environment to crash. In this case, close all the processes and try launching the world again.
 
 5.  Launch the density publisher with 
 
 ```
 rosrun density_map density_publisher.py 
 ```

 - The environment is now set and the different diving logics can be tested.

 ### Initial diving cycle ###

 To run the initial diving cycle, use

 ```
rosrun depthcontrol depthlogic.py
 ``` 
This will send the robot to go down until it is within 8 meter of the bottom of the ocean. When it reaches this level, it will start taking CTD measurements to get the density, as well as the depth using the DVL. When surfaced, it uses this data to create a 2nd degree polynomial describing the denisty-depth relationship. This polynomial will be printed in the terminal. 

  ## Making changes in submodules and pushing to git ##
  
 - Go to submodule file where changes are made, i.e 'uuvcontrol/catkin_ws_sim/src/uuvfloat'
 - Make sure you are in master branch ('git checkout master')
 - git add -> git commit -> git push
 - Go to the main workspace source 'uuvcontrol/catkin_ws_sim/src/' and git add -> git commit -> git push again
