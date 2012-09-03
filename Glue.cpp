//
//  Glue.cpp
//  
//
//  Created by steve daniels on 12-08-19.
//  Copyright (c) 2012 __ribosome.ca__. All rights reserved.
//



#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

#include <Glue.h>
#include <WString.h> // String




void Glue::create( )
{
	
	Glue::init ('*','#',',');
}

void Glue::create(char s, char e, char d) {
	Glue::init (s,e,d);
}


void Glue::init(char _start_byte, char _end_byte, char _delimiter ) {
	
	START_BYTE = _start_byte;
	END_BYTE   = _end_byte;
	DELIMITER  = _delimiter;
	glueMessage = "";
	clear();
}


void Glue::clear() {

  glueMessage = "";
  glueMessage += START_BYTE ;

}

void Glue::add(String stringToAdd) {
   
   glueMessage += stringToAdd ;
   glueMessage += DELIMITER ;

}


void Glue::add(int i) {
	
  glueMessage += i ;
  glueMessage += DELIMITER ;

}



void Glue::add(float f) {
	
//	glueMessage += f ;
//	glueMessage += DELIMITER ;

// after mem -- Arduino forum
// http://www.arduino.cc/cgi-bin/yabb2/YaBB.pl?num=1200716061
  
    int intPart = (int)f;
	glueMessage += intPart ;
	glueMessage += '.';
    
    int decimalPart = (f - (int)f) * 100;
	glueMessage += decimalPart;
	glueMessage += DELIMITER ;

  //Serial.println( abs(temp) );


}



void Glue::send(){
	// impliment here -- or not -- to keep generic use getPacakge
	
	// how do i attach this to the serial port?
	//Serial.println ("I wish I could send");
}

String Glue::debug() {
	
	return glueMessage+END_BYTE;
}

String Glue::getPackage () {
	// closes the package with end byte then returns full string
	glueMessage += END_BYTE ;
	return glueMessage;
}

int Glue::length() {
	
	return glueMessage.length();

} // end length



int Glue::setStartByte(char s) {
  START_BYTE = s;
  return 1;
}


int Glue::setEndByte(char e) {
  END_BYTE = e;
  return 1;
  
}


int Glue::setDelimiter(char d) {
  DELIMITER = d;
  return 1;
  
}

char Glue::getStartByte( ) {
   return START_BYTE;
}


char Glue::getEndByte( ) {
   return END_BYTE;
}


char Glue::getDelimiter( ) {
   return DELIMITER;
}





