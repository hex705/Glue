//
//  Glue.h
//  
//
//  Created by steve daniels on 12-08-19.
//  Copyright (c) 2012 __ribosome.ca__. All rights reserved.
//


#ifndef Glue_h
#define Glue_h


#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

#include <WString.h>        // String


class Glue
{
	
public: 
		
    String glueMessage ; 
   
	// constructors
	void create( );
	void create (char,char,char);
	void clear();

	// glue functions
	void add( String );
	void add( int ) ;
	void add( float ) ;
	
	String getPackage ( );
	String debug ( );
	int length( ); 
	void send( );  // remove ??

 	// setters
	int setStartByte( char s );
	int setEndByte( char e );
	int setDelimiter( char d );
 
	// getters
	char getStartByte( );
	char getEndByte( ) ;
	char getDelimiter( ) ;
  

private:
	
	// internal vars & parsing variables
	char START_BYTE;
	char END_BYTE  ;
	char DELIMITER ;  
	
	void init(char,char,char);

}; // end of class

#endif