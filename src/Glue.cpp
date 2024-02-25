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

Glue::Glue(){;}

void Glue::begin(Stream &s){
	theStream = &s;
	init('*','#',',');
}

void Glue::begin(Stream &s,char _start_byte, char _end_byte, char _delimiter){
	theStream = &s;
		init( _start_byte,  _end_byte,  _delimiter);
}

void Glue::begin( )
{
	Glue::init ('*','#',',');
}

void Glue::begin(char s, char e, char d) {
	Glue::init (s,e,d);
}


void Glue::init(char _start_byte, char _end_byte, char _delimiter ) {

	START_BYTE = _start_byte;
	END_BYTE   = _end_byte;
	DELIMITER  = _delimiter;
	glueMessage = "";
	clear();
}

void Glue::create(){
	clear();
}

void Glue::create(String s){
	clear();
	add(s);
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

    int decimalPart = (f - (int)f) * 1000;
	glueMessage += decimalPart;
	glueMessage += DELIMITER ;

  //Serial.println( abs(temp) );

}

// add the END_BYTE
void Glue::endPackage(){
	glueMessage += END_BYTE ;
}

// send the message using STREAM interface
void Glue::send(){
   endPackage();
   theStream->println(getPackage());
}

// get the package in its current state
// same as debug() below
String Glue::getPackage() {
	// returns full string 
	return glueMessage;
}

// use this to see message contents 
// same as getPackage() above
String Glue::debug() {
	return glueMessage;  // 2024 -- take the end byte away! 
	//return glueMessage+END_BYTE; // why are you doing the +END_BYTE ?
		//return glueMessage; // should it not be this ?  
}



int Glue::length() {
	return glueMessage.length();
} // end length

// setters
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

// getters
char Glue::getStartByte( ) {
   return START_BYTE;
}


char Glue::getEndByte( ) {
   return END_BYTE;
}


char Glue::getDelimiter( ) {
   return DELIMITER;
}
