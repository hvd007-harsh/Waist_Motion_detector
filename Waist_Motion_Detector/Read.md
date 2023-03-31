Aim :
Develop an system that use sensors to detect seating , standing , sleeping and walking with high accuracy.

Develop algorithms to process the data from the sensors and Classify the Activities

Material Required :
Microcontroller STM32F401RE based NUCLEOF401RE
MPU6050(GYI_SENSOR)
Logic Analyzer for testing

Approach:
By making an API System for writing the driver code for MPU6050
It take I2C connection with each other and initialising it by sending the I2C data connection
First, we will send the data using on address where we will clear the data bus and also implement it using that
next,
We will write the register code of the MPU6050
After developing MPU6050.h And MPU6050.c

We will set the MPU6050Sensor In main function then we will implement the Duration and threshold of the MPU6050 By writing the MPU6050_Duration and MPU6050_Threshold

Let's implement it

MPU6050_Init(&hi2c1); //Initializing the I2C1 connection with I2C1

MPU6050_SetInterruptMode(MPU6050_INTMODE_ACTIVEHIGH);
MPU6050_SetInterruptDrive(MPU6050_INTDRV_PUSHPULL);
MPU6050_SetInterruptLatch(MPU6050_INTLATCH_WAITCLEAR);
MPU6050_SetInterruptLatchClear(MPU6050_INTCLEAR_STATUSREAD);

MPU6050_SetIntEnableRegister(0); //Disable all interrupts

//Enable Motion Interrupts

MPU6050_SetIntEnableRegister(0); //Disable all Interrupts

//Enable Motion Interrupts

MPU6050_SetDHPFMode(MPU6050_DHPF_5);

MPU6050_SetIntMotionEnabled(1);
MPU6050_SetIntZeroMotionEnabled(1);
MPU6050_SetIntFreeFallEnabled(1);

MPU6050_SetFreeFallDetectionDuration(2);
MPU6050_SetFreeFallDetectionThreshold(2);

MPU6050_SetMotionDetectionDuration(5);
MPU6050_SetMotionDetectionThreshold(5);

MPU6050_SetZeroMotionDetectionDuration(2);
MPU6050_SetZeroMotionDetectionThreshold(4);

- -
  - For getting the acceleration of the body
  - so for calculating the acceleration and gyroparameter
  -
  - we will Use the API :
  - MPU6050_GetAccelerometerScaled(&ax,&ay,&az);
  - MPU6050_GetGyroscopeScaled(&gx, &gy, &gz);
    \*/
    MPU6050_GetAccelerometerScaled(&ax, &ay, &az);
    MPU6050_GetGyroscopeScaled(&gx, &gy, &gz);
    // Here we are getting the acceleration and gyro parameter

  memset(buffer,0,128);

  sprintf((char\*)buffer, "ACC: X: %0.2f Y: %0.2f Z: %0.2f \n\r GYR: X:%0.2f Y: %0.2f Z:%0.2f \n\r",ax,ay,az,gx,gy,gz);

  /\*

  - Better option is that we take the roll and pitch of the movement and if
  - we get any kind of roll or pitch then we can say object is in movement
  -
  -
  - so for calculating the roll and pitch
  - we will Use the API :
  - MPU6050_GetRollPitch(&roll,&pitch);
    \*/

  MPU6050_GetRollPitch(&roll, &pitch);

  if(roll >0 || pitch > 0 ){
  sprintf((char\*)buffer,"The body is moving Person is in walking position");
  sprintf("The body is moving person is in standing position");

  }
  if(ax > 0 && ay>0 ){ //Here we can check the position with movement
  sprintf((char\*)buffer,"person is in standing position");
  sprintf("person is in standing position");
  }

      if(ax ==0 && az == 0 && ay ==0){ //Here we are checking that person is in still position

  sprintf((char*)buffer,"Person is not moving might be in seat position");
  sprintf("Person is not moving might be in seat position");
  }
  /*
  _ Further we will move for the angle of the user by using arc tangent
  _ we will calculate the acceleration and with using mathematics we will calculate the angle by making tangent
  _ if Ax >= 45Deg and Ay >= 45Deg then we can say the angle is moving
  _ upward

       Now we can send this to any screen
       Using Uart


