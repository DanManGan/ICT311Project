
/** 
  * @class MathExtra
  * @brief Math Helper class
  * 
  * Maths helper class with etra math helper functions and definitions
  * 
  * 
  * 
  * 
  * @author Justin Pettit
  * @version 01
  * @date 20.04.15
  * @status under construction
  * 
  * @author 
  * @version 
  * @date 
  * @status 
  * 
  * @todo 
  * 
  * @bugs 
  */

#include <math.h>

//--------------------------------------------------------------
//		CONSTANTS 
//--------------------------------------------------------------

#define PI		   3.1415926535897932384626433832795f
#define PIOVER180  0.0174532925199432957692369076848861f
#define PIUNDER180 57.2957795130823208767981548141052f
#define EPSILON	   1.0e-8
#define SMALL	   1.0e-4f
#define BIG		   1.0e+10f

//--------------------------------------------------------------
//		MACROS	
//--------------------------------------------------------------

#define DEG_TO_RAD( angle )	  ( ( angle )*PIOVER180 )
#define RAD_TO_DEG( radians ) ( ( radians )*PIUNDER180 )

#define SQR( number )		( number*number )
#define CUBE( number )		( number*number*number )