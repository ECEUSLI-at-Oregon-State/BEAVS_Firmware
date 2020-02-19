//Accelerometer
const int xInput = A6;
const int yInput = A7;
const int zInput = A8;
//const int buttonPin = 2;

// Raw Ranges:
// initialize to mid-range and allow calibration to
// find the minimum and maximum for each axis
int xRawMin = 510;
int xRawMax = 517;

int yRawMin = 509;
int yRawMax = 516;

int zRawMin = 412;
int zRawMax = 512;

int xRaw, yRaw, zRaw;
long xScaled, yScaled, zScaled;


//Adafruit_GPS GPS(&gpsSerial);
String message;
String temp;
char buf[32];
void setup() {
  Serial.begin(9600);
}

void loop() {
  readAccel();

  message = String("Accelerations: (");
  temp = String(xScaled);
  message = String(message + temp);
  message = String(message + ", ");
  temp = String(yScaled);
  message = String(message + temp);
  message = String(message + ", ");
  temp = String(zScaled);
  message = String(message + temp);
  message = String(message + ")");


  message = String(message + "!\n");

  Serial.println(message);

  delay(500);
}

void readAccel() {
  xRaw = ReadAxis(xInput);
  yRaw = ReadAxis(yInput);
  zRaw = ReadAxis(zInput);
  Serial.print("xRaw: ");
  Serial.println(xRaw);
  Serial.print("yRaw: ");
  Serial.println(yRaw);
  Serial.print("zRaw: ");
  Serial.println(zRaw);
  xScaled = map(xRaw, xRawMin, xRawMax, -1000, 1000);
  yScaled = map(yRaw, yRawMin, yRawMax, -1000, 1000);
  zScaled = map(zRaw, zRawMin, zRawMax, -1000, 1000);
}

int ReadAxis(int axisPin) {
  long reading = 0;
  analogRead(axisPin);
  delay(1);
  for (int i = 0; i < 10; i++)
  {
    reading += analogRead(axisPin);
  }
  return reading / 10;
}
