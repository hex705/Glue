// simple example of building a SERIAL package with 
// GLUE library

#include <Glue.h>

Glue elmers;

void setup() {
  Serial.begin(9600);
  while(!Serial); // blocks-do not use in production code

  elmers.begin(Serial);
}

void loop(){
 elmers.create("/hi");
 elmers.add(23);
 elmers.add(4.501f);
 elmers.add("steve is silly");
 elmers.send(); // send with lib -- adds end byte automatically 
 
 while(1);
}
