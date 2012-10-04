Glue  (ReadMe)
=====  

*Glue* is a simple MESSAGE building library for Arduino.

*Glue* plays well with its sibling library *Scissors*.  Glue and Scissors are also available for Processing.

As of August 2012, Glue is an alpha release.  It is tested and appears stable.  Please report bugs here:

[https://github.com/hex705/Glue/issues](https://github.com/hex705/Glue/issues "Issues")



Quick Start
---------------

1. Obtain archive (.zip) @  [https://github.com/hex705/Glue](https://github.com/hex705/Glue "Download")

2. Unzip and (if needed) rename folder Glue 

3. Copy folder (OSX) into:   ~/Documents/Arduino/libraries

4. Start building PACKAGES for data streams.

Downloaded folder contains library, and examples.


Usage
-----

GLUE accepts Strings, ints and floats (in any order) as payload ELEMENTS and assembles them into a delimited package.  Packages are prefixed with a START_BYTE and terminated with an END\_BYTE.

Messages assembled with GLUE are String that take the form:

	START_BYTE dataZero DELIMITER dataOne DELIMITER dataTwo DELIMITER ... dataN DELIMITER END_BYTE


DEFAULTS are : START\_BYTE = '*',  END\_BYTE = '#",  DELIMITER =',' and default packages are of the form:


	*dataZero,dataOne,dataTwo, ... dataN,#


(Yes, I know that a delimiter and an END_BYTE side-by-side looks odd -- but it simplifies).


Data ELEMENTS within the package are indexed 0-2 (like an array).

### Include

Include the Glue library.

		#include <Glue.h>

		
The include statement can be added via menu:: Sketch --> Import Library --> Glue

###Instantiate

Glue object must be declared at the top of your sketch:

	Glue glue;

###Defaults Package Parameters

	START_BYTE  *
	END_BYTE    #
	DELIMITER   ,


###Create a new message -- in setup()

	void setup() {

		glue.create( );  // will instantiate with defaults 

	}


####Setting Payload Parameters

	glue.setStartByte( CHAR ); 
    glue.setEndByte  ( CHAR );
    glue.setDelimiter( CHAR );   
   

####Getting Payload Parameters

	char sb = glue.getStartByte( ); 
    char eb = glue.getEndByte  ( );
    char de = glue.getDelimiter( );


###Build Message -- in loop() or in a function.

First clear any old messages.

	glue.clear();  // empty old data frm the glue buffer

Now add ELEMENTS to the MESSAGE

	glue.add ( int ) ;    //  add an int    ELEMENT to PACKAGE  
	glue.add ( float ) ;  //  add a  float  ELEMENT to PACKAGE  
	glue.add ( String ) ; //  add a  String ELEMENT to PACKAGE  

Note:  ELEMENTS can be added in any order.  Mixing TYPES is possible.


###Element Indexing

Elements are added to the MESSAGE package incrementally.  First ELEMENT is zero index (0).

###Sending a MESSAGE

Completed messages can be obtained from the glue object with the following call.

		String package = glue.getPackage();		// returns the package with delimiters, header and tail

The string package can now be send with a SERIAL.write(package); or network (client or server)  . write(package);
depending on use context.

### Example of usage (context == Serial)

	 void loop () {

		glue.clear();      // clear
		
		glue.add(23);		// add elements
		glue.add(4.5f);
		glue.add("Example string");
	
	 	Serial.println( glue.getPackage()) ; //get package and send it out serial port
	

HISTORY
=======
## OCTOBER, 2012:
Added readme.md

##August, 2012:
First version uploaded to GITHUB



____
  
  

TO DO:
------

 * Further Examples

 * tie to Stream not serial -- enabling use with Ethernet Shield
		Note: this will change the instantiation and API

 * full documentation 



