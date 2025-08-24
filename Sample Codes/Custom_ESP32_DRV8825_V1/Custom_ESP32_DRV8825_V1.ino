// Include the AccelStepper Library
#include <AccelStepper.h>

// Define pin connections
#define stepper_1_stepPin 6
#define stepper_1_dirPin 7


// Define motor interface type
#define motorInterfaceType 1 //AccelStepper::DRIVER (1) means a stepper driver (with Step and Direction pins)
#define no_of_steppers 1

#define movesteps 8000

//define an array of stepper pointers. initialize the pointer to NULL (null pointer) for safety (see below)
AccelStepper *steppers[no_of_steppers] = {NULL};

// Creates an instance
// AccelStepper myStepper(motorInterfaceType, stepPin, dirPin);

void setup() {

// Create stepper instances
steppers[0] = new AccelStepper(motorInterfaceType, stepper_1_stepPin, stepper_1_dirPin);

  // Configure each stepper as needed

 if (steppers[0]) {
    steppers[0]->setMaxSpeed(4000); //steps per second
    steppers[0]->setAcceleration(4000.0); //desired acceleration in steps per second per second
    steppers[0]->moveTo(movesteps);   
 }
  
 
}

void loop() {

	if (steppers[0]->distanceToGo() == 0) { 
	  // Change direction once the motor reaches target position
		steppers[0]->moveTo(-steppers[0]->currentPosition());

	}

	// Move the motor one step
	steppers[0]->run();

    
}
