# Control 2-DOF robotic arm by using Arduino.

I designed 2-DOF robotic arm, with two button for forward kinematics (left button) and inverse kinematics (right button).

Forward kinematics: assume the angle values ​​of the motors, and the arm will move to a specific point on the x, y plane (the angle values ​​are known, the final point is unknown).

Inverse kinematics: assume a value for a specific point on the x, y plane, and find the angle values ​​of the motors that we must choose (the endpoint is known, the values ​​of the angles are unknown).

As you can see in the code, you must assume a value for L1 (the length between the first motor and the second motor) and L2 (the length between the second motor and the end of the arm) before pressing any button. Then, when we press the left button (we must assume values ​​for the angles of the motors), the motors will move so that the end of the arm (the end of L2) is at a specific point. But when we press the right button (we must assume values ​​for x and y), it will find the angles ​​for the motors that we must choose to reach the point that was assumed, and then the arm will move to that point.

I added an explanation and more details in the code.


There is a video of a practical application similar to what I did, which is:

<a href="http://www.youtube.com/watch?feature=player_embedded&v=3rFaZMvgNe8
" target="_blank"><img src="http://img.youtube.com/vi/3rFaZMvgNe8/0.jpg" 
alt="IMAGE ALT TEXT HERE" width="480" height="360" border="10" /></a>

To build the circuit, I used:

- Arduino board.

- Two Servo motors.

- Two button for forward and inverse kinematics.
