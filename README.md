# Thermoduino
Arduino code for an extremity temperature-sensing and notification device for people with  spinal cord injury.

People with spinal cord injuries or diseases such as Multiple Sclerosis are often unable to perceive temperature changes in their 
extremities. We created a temperature warning device dubbed the "Thermoduino" which reduces the risk of severe problems associated
with hot or cold extremities by notifying the user of significant changes in body temperature. The device contains an Arduino, which
reads in analog data from a thermistor, and uses it to control a servo motor and two LEDs. The servo rings a bell to notify the user
when their temperature is dramatically outside of the ideal range. The LEDs (one red, one blue) light up when the temperature is only
slightly too cold or slightly too warm, as a more discreet notification method. 

The main parameters controlling the function of Thermoduino are the resistance values, which have been calculated using measurements 
of a person with a spinal cord injury at room temperature, and values over repeated trials of people without spinal cord injuries
under uncomfortably cold or uncomfortably warm positions. The safest option was chosen for each resistance value. A set of "demo"
values are also included (but commented out), which run the Thermoduino so that the bell will ring and the lights will turn on and off
when the thermistor is at room temperature, then heated up in a warm hand or the crook of an elbow. This provides efficient testing of
the mechanics of the device.

This project was completed by Sara Vannah and Jenny Gubner at Wellesley College as part of a project for ENGR 160 in Spring 2016.
