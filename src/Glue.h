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
	// constructors
	Glue();

  String glueMessage ;

	// init
	void begin( );
	void begin ( char,char,char );
	void begin( Stream & );
	void begin ( Stream &, char,char,char );

    // start (create) a message
    void create();
	void create( String );
	void clear();

	// glue functions
	void add( String );
	void add( int ) ;
	void add( float ) ;
	void endPackage();

	String getPackage();

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

	Stream *theStream;

	// internal vars & parsing variables
	char START_BYTE;
	char END_BYTE  ;
	char DELIMITER ;

	void init( char,char,char );

}; // end of class

#endif
