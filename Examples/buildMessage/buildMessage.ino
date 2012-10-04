
#include <Glue.h>


Glue elmers;

void setup() {
  Serial.begin(9600);
  elmers.create();
}


void loop(){
  
 elmers.clear();
 elmer.add(23);
 elmers.add(4.5);
 elmers.add("steve is silly");
 Serial.println( elmers.getPackage()) ;
 while(1);
  
}


