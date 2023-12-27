/*
0 1 4 5
----
88	99	73	73
90	101	73	73
91	103	73	73
91	102	74	74
92	103	73	73
316	315	216	216
2267	2107	1862	1862
3335	3173	3025	3025
4092	4085	4094	4094
*/

#include <M5Atom.h>     // https://github.com/m5stack/M5Atom
#include <M5_PbHub.h>   // https://github.com/thomasfredericks/M5_PbHub


#define RED 0xFF0000
#define ORANGE 0xFF8000
#define YELLOW 0xFFFF00
#define GREEN 0x00FF00
#define BLUE 0x0000FF
#define INDIGO 0x4B0082
#define VIOLET 0xEE82EE
#define BLACK 0x000000
#define MAGENTA 0xFF00FF
#define CYAN 0x00FFFF
#define WHITE 0xFFFFFF


M5_PbHub myPbHub;
unsigned long lastLoop = 0;
unsigned int buttonCount = 0;
const float adjust0 = 0.928;
const float adjust1 = 0.884;
const float adjust4 = 1.125;
const float adjust5 = 1.126;

void setup() 
{
  M5.begin( true, false, true );
  Serial.begin( 115200 );
	M5.dis.drawpix( 0, WHITE );
  myPbHub.begin();
  Serial.println( "Setup has completed." );
}

void loop() 
{
  M5.update();

 	if( M5.Btn.wasPressed() )
	{
		switch( buttonCount )
		{
			case 0:
				M5.dis.drawpix( 0, RED ); // RED  红色
				break;
			case 1:
				M5.dis.drawpix( 0, ORANGE );
				break;
			case 2:
				M5.dis.drawpix( 0, YELLOW ); // YELLOW 黄色
				break;
			case 3:
				M5.dis.drawpix( 0, GREEN ); // GREEN  绿色
				break;
			case 4:
				M5.dis.drawpix( 0, BLUE ); // BLUE  蓝色
				break;
			case 5:
				M5.dis.drawpix( 0, INDIGO );
				break;
			case 6:
				M5.dis.drawpix( 0, VIOLET );
				break;
			default:
				break;
		}
		buttonCount++;
		if( buttonCount >= 7 )
			buttonCount = 0;
	}

  if (millis() - lastLoop >= 50) 
  {
		// M5.dis.drawpix( 0, RED );
    int raw0 = myPbHub.analogRead( 0 );
    float adjusted0 = raw0 * adjust0;
    int raw1 = myPbHub.analogRead( 1 );
    float adjusted1 = raw1 * adjust1;
    int raw4 = myPbHub.analogRead( 4 );
    float adjusted4 = raw4 * adjust4;
    int raw5 = myPbHub.analogRead( 5 );
    float adjusted5 = raw5 * adjust5;
    Serial.printf( "L0:%.2f L1:%.2f L4:%.2f L5:%.2f\n", adjusted0, adjusted1, adjusted4, adjusted5 );
		// M5.dis.drawpix( 0, BLUE );

    lastLoop = millis();
  }
}
