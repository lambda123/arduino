//www.elegoo.com
//2016.12.8

// Define Pins
#define BLUE 3
#define GREEN 5
#define RED 6
#define delayTime 10 // fading time between colors


void setup()
{
pinMode(RED, OUTPUT);
pinMode(GREEN, OUTPUT);
pinMode(BLUE, OUTPUT);
digitalWrite(RED, LOW);
digitalWrite(GREEN, LOW);
digitalWrite(BLUE, LOW);
}

// define variables
int redValue;
int greenValue;
int blueValue;

int maxdelay;
int maxlight;


void fade_blue_red (int timer, int maxlight) {
	greenValue = 0;
	redValue = 0;
	blueValue = maxlight;
	for (int i = 0 ; i < timer ; i += 1) {
		blueValue -= 1;
		redValue += 1;
		analogWrite(BLUE, blueValue);
		analogWrite(RED, redValue);
		analogWrite(GREEN, greenValue);
		delay(delayTime);
	}
}

void fade_red_blue (int timer, int maxlight) {
	greenValue = 0;
	blueValue = 0;
	redValue = maxlight;
	for (int i = 0 ; i < timer ; i += 1) {
		blueValue -= 1;
		redValue += 1;
		analogWrite(BLUE, blueValue);
		analogWrite(RED, redValue);
		analogWrite(GREEN, greenValue);
		delay(delayTime);
	}
}


void fade_green_red (int timer, int maxlight) {
	blueValue = 0;
	redValue = 0;
	greenValue = maxlight;
	for (int i = 0 ; i < timer ; i += 1) {
		greenValue -= 1;
		redValue += 1;
		analogWrite(BLUE, greenValue);
		analogWrite(RED, redValue);
		analogWrite(GREEN, greenValue);
		delay(delayTime);
	}
}

void fade_red_green (int timer, int maxlight) {
	blueValue = 0;
	greenValue = 0;
	redValue = maxlight;
	for (int i = 0 ; i < timer ; i += 1) {
		greenValue -= 1;
		redValue += 1;
		analogWrite(BLUE, greenValue);
		analogWrite(RED, redValue);
		analogWrite(GREEN, greenValue);
		delay(delayTime);
	}
}


void fade_green_blue (int timer, int maxlight) {
	redValue = 0;
	blueValue = 0;
	greenValue = maxlight;
	for (int i = 0 ; i < timer ; i += 1) {
		greenValue -= 1;
		blueValue += 1;
		analogWrite(BLUE, greenValue);
		analogWrite(RED, blueValue);
		analogWrite(GREEN, greenValue);
		delay(delayTime);
	}
}

void fade_blue_green (int timer, int maxlight) {
	greenValue = 0;
	redValue = 0;
	blueValue = maxlight;
	for (int i = 0 ; i < timer ; i += 1) {
		greenValue -= 1;
		blueValue += 1;
		analogWrite(BLUE, greenValue);
		analogWrite(RED, blueValue);
		analogWrite(GREEN, greenValue);
		delay(delayTime);
	}
}



// main loop
void loop()
{

// fade_blue_red(127, 127);



//for (int j = 0 ; j < 127 ; j += 1) {
//	fade_blue_red(j, 127);
//	fade_red_green(j, 127);
//	fade_green_blue(j, 127);
//	fade_blue_green(j, 127);
//	fade_green_red(j, 127);
//	fade_red_blue(j, 127);
//}

analogWrite(BLUE, 0);
analogWrite(RED, redValue);
analogWrite(GREEN, greenValue);


// maxlight = 64;
// blueValue = maxlight; // choose a value between 1 and 255 to change the color.
// greenValue = 0;
// //blueValue = 0;

// // this is unnecessary as we've either turned on RED in SETUP
// // or in the previous loop ... regardless, this turns RED off
// analogWrite(RED, 0);
// // delay(1000);

// for(int i = 0; i < maxlight; i += 1) // fades out red bring green full when i=255
// {
// blueValue -= 1;
// greenValue += 1;
// // The following was reversed, counting in the wrong directions
// // analogWrite(RED, 255 - redValue);
// // analogWrite(GREEN, 255 - greenValue);
// analogWrite(BLUE, redValue);
// analogWrite(GREEN, greenValue);
// delay(delayTime);
// }

// //redValue = 0;
// //greenValue = maxlight;
// //blueValue = 0;

// for(int i = 0; i < maxlight; i += 1) // fades out green bring blue full when i=255
// {
// greenValue -= 1;
// blueValue += 1;
// // The following was reversed, counting in the wrong directions
// // analogWrite(GREEN, 255 - greenValue);
// // analogWrite(BLUE, 255 - blueValue);
// analogWrite(GREEN, greenValue);
// analogWrite(BLUE, blueValue);
// delay(delayTime);
// }

//redValue = 0;
//greenValue = 0;
//blueValue = maxlight;
//
//for(int i = 0; i < maxlight; i += 1) // fades out blue bring red full when i=255
//{
//// The following code has been rearranged to match the other two similar sections
//blueValue -= 1;
//redValue += 1;
//// The following was reversed, counting in the wrong directions
//// analogWrite(BLUE, 255 - blueValue);
//// analogWrite(RED, 255 - redValue);
//analogWrite(BLUE, blueValue);
//analogWrite(RED, redValue);
//delay(delayTime);
//}
}
