#include <SPI.h>
#include <SD.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#include "Adafruit_Thermal.h"
#include "SoftwareSerial.h"
#define TX_PIN 9 // Arduino tramnsmit  YELLOW WIRE  labeled RX on printer
#define RX_PIN 8 // Arduino receive   GREEN WIRE   labeled TX on printer
SoftwareSerial mySerial(RX_PIN, TX_PIN); // Declare SoftwareSerial obj first
Adafruit_Thermal printer(&mySerial);     // Pass addr to printer constructor
LiquidCrystal_I2C lcd(0x27,20,4);  // set the LCD address to 0x27 for a 16 chars and 2 line display

File myFile;
File myFile2;

int heatTime = 255;
int heatInterval = 255;
char printDensity = 255; 
char printBreakTime = 15;

String sub = "";
int nocode1 = 0;
int nocode2 = 0;
int nocode3 = 0;
int nocode4 = 0;
int nocode5 = 0;
int trap1 = 0;
int trap2 = 0;
int trap3 = 0;
int trap4 = 0;
int trap5 = 0;
int rate1counter = 0;
int rate2counter = 0;
int rate3counter = 0;
int rate4counter = 0;
int rate5counter = 0;
int codecount = 0;
int codecount2 = 0;
int proceed1 = 0;
int rate2codecount = 0;
int rate3codecount = 0;
int rate1codecount = 0;
int rate4codecount = 0;
int rate5codecount = 0;
int halting;
int cd1 = 0;
int cnting = 0;
int cddummy = 0;
int passcountdown = 0;
int timeselectionpass = 0;
int selectedtime = 0;
int countdownholder = 0;
int countdowntimer = 0;
int dummyratecount = 0;
int rate1count = 0;
int rate2count = 0;
int rate3count = 0;
int rate4count = 0;
int rate5count = 0;
int nagcodisplay = 0;
int mrker = 0;
int nadetect = 0;
int niagi = 0;
int cownt = 0;
int hunongloop = 0;
int physicalcount = 0;
int agilang = 0;
int agilang2 = 0;
int agilang3 = 0;
int passprime = 0;
int pass1 = 0;
int okaytogo = 0;
int primeruncheck = 0;
int selectedratepass = 0;
int removeprevious = 0;
int cycles = 0;
int cycles2 = 0;
int passhere = 0;
int empty1 = 0;
int empty2 = 0;
int proceed;
int blinkcounts = 0;
int b = 0;
int a = 0;
int cd = 0;
int firstdisplay = 0;
char c;
String rates[2];
String readString;
String readString1;
int amnt[5];
int cttr = 0;
const int buttonPin = 2;
const int buttonPin2 = 3;
const int buttonPin3 = 4;

char ch;
int halt = 0;
int including = 0;
int indicator = 0;
int getfilecontent = 0;
int buttonPushCounter = 0;   // counter for the number of button presses
int buttonState = 0;         // current state of the button
int lastButtonState = 0;     // previous state of the button
int charactercount = 0;
int buttonState3 = 0;
int lastButtonState3 = 0;
int primerun = 0;
int primeruna = 0;
int primerun2 = 0;
int buttonState2 = 0;
int lastButtonState2 = 0;
int buttonPushSelection = 0;
int ihapon = 0;

int counter = 0;
int blinkpass = 0;
int outpin5 = 5; //Led for lights connection
int outpin6 = 6; //alarm or buzzer connection
int outpin7 = 7; //relay connection for tripping On/Off power for Universal Coinslot
int alarm1 = 0;
int alarm2 = 0;
int indicatorr = 0;
int pause = 0;
int cnt = 0;
int count = 0;
int pass = 0;
int pass2 = 0;
int pass3 = 0;
int pass4 = 0;
int pass6 = 0;
int x = 0;
int y = 0;
int line = 0;
int cycle = 0;
int cntr = 0;
int pass5 = 0;
int holddisplay = 0;
int passalarm = 0;
int rateempty = 0;
int rate1 = 0;
int rate2 = 0;
int rate3 = 0;
int rate4 = 0;
int rate5 = 0;
int firstrun = 0;
int firstrun2 = 0;
int counting = 0;
int savingpass = 0;
int e = 6;
int ctr = 0;

String headername;
String show;
String fyle;

char c1;
int ratedisplay = 0;
int codecountrun = 0;
int buttoncycle = 0;
int selectedrate = 0;

void setup() {
  lcd.init();// initialize the lcd
  // Print a message to the LCD.
  lcd.backlight();
    delay(250);
    lcd.noBacklight();
    delay(250);
    lcd.backlight(); // finish with backlight on  
  lcd.setCursor(0,0); //Start at character 4 on line 0
  lcd.print(F("     Welcome To "));
//  delay(1000);
  lcd.setCursor(0,1); //Start at character 4 on line 0
  lcd.print(F("JKCG WiFi Hotspot"));
  delay(1000);
  lcd.setCursor(0,2);
  lcd.print(F("AvzenTech Industries"));
  delay(1000);
//  lcd.setCursor(0,3);
//  lcd.print(F("JpacNetworkSolution"));
  // Open serial communications and wait for port to open:
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }
  pinMode(buttonPin, INPUT);
  pinMode(buttonPin2, INPUT);
 // pinMode(buttonPin3, INPUT);
  pinMode(outpin5, OUTPUT);
  pinMode(outpin6, OUTPUT);
  pinMode(outpin7, OUTPUT);

  digitalWrite(outpin5, LOW);
  digitalWrite(outpin6, LOW);
  digitalWrite(outpin7, HIGH);
  // maindisplay();

  Serial.print("Initializing SD card...");

  if (!SD.begin(53)) {
    Serial.print("initialization failed!");
    return;
  }
  Serial.print("initialization done.");
}

void loop()
{

  if (codecountrun == 0)
  {
    codecounterdisplay();
    allcodecount();
    delay(3000);
    lcd.clear();
  }
  if (passprime == 0)
  {
    passprime = 1;
    primerunningtest();
  }

  primalrun();
  primalruna();
  primalrun2();

  if (primerun == 1 && primerun2 == 1 )
  {

    if (pass == 0)
    {
      pass = 1;
      maindisplay();
      rate_in();
    }
  }

  if (physicalcount == 3)
  {
    if (buttonPushCounter > amnt[2])
    {
      buttonPushCounter = 0;
    }
  }

  if (physicalcount == 4)
  {
    if (buttonPushCounter > amnt[3])
    {
      buttonPushCounter = 0;
    }
  }

  if (physicalcount == 5)
  {
    if (buttonPushCounter > amnt[4])
    {
      buttonPushCounter = 0;
    }
  }
  displayblinks();
  getresponse();
  getresponse2();
  if (nagcodisplay == 1 && pass5 == 1 )
  {
    buttonState2 = digitalRead(buttonPin2);
    // compare the buttonState to its previous state
    if (buttonState2 != lastButtonState2) {
      // if the state has changed, increment the counter
      if (buttonState2 == HIGH) {
        // if the current state is HIGH then the button
        // wend from off to on:
        buttonPushSelection = 1;
        // cntr = 0;
        Serial.print(buttonPushSelection);
      }
      // Delay a little bit to avoid bouncing
      delay(10);
    }
    // save the current state as the last state,
    //for next time through the loop
    lastButtonState2 = buttonState2;

    if (buttonPushSelection == 1)
    {
      lcd.clear();
      cycle = 21;
      cd1 = cddummy;
      firstrun = 0;
      buttonPushSelection = 0;
      buttonPushCounter = 0;
      nagcodisplay = 0;
      holddisplay = 0;
      pause = 0;
      pass5 = 0;
      ratedisplay = 0;
      digitalWrite(outpin7, HIGH);
      maindisplay();
    }


    cycle++;
    if (cycle <= 20)
    {
      lcd.setCursor(17, 2);
      lcd.print("  ");
      lcd.setCursor(17, 2);
      lcd.print(cd1);
      digitalWrite(outpin5, HIGH);
      digitalWrite(outpin6, HIGH);
      lcd.setCursor(4, 3);
      lcd.print("Press Button");
      // lcd.setCursor(3,2);
      //lcd.print("<<<");
      //lcd.setCursor(13,2);
      //lcd.print(">>>");
      lcd.setCursor(6, 3);
      // lcd.print("<<<O>>>");

    }

    if (cycle > 20 && cycle <= 40) //(ORIG 20,40) -  60 120
    {
      holddisplay++;
      if (holddisplay > countdowntimer) //225 orig value, 2nd value = 500,
      {
        digitalWrite(outpin7, HIGH);
        cd1 = cddummy;
        firstrun = 0;
        buttonPushSelection = 0;
        buttonPushCounter = 0;
        nagcodisplay = 0;
        holddisplay = 0;
        pause = 0;
        pass5 = 0;
        ratedisplay = 0;
        maindisplay();
      }
      lcd.setCursor(4, 3);
      lcd.print("            ");
      digitalWrite(outpin5, LOW);
      digitalWrite(outpin6, LOW);
      lcd.setCursor(0, 1);
      lcd.print(" JKCG WiFi Hotspot ");

    }

    if (cycle == 40)
    {
      cd1--;
      cycle = 0;
    }
  }
}


void getdisplayed()
{
  int e;
  int an;
  an = 0;
  e = 7;
  while (an < 6)
  {
    an++;
    lcd.setCursor(e, 3);
    lcd.print(" ");
    lcd.setCursor(e, 3);
    lcd.print("<");
    e--;
  }
}

void displayblinks()
{
  ratedisplay++;
  if (primerun == 1 && primerun2 == 1 && pause == 0)
  {
    Serial.print(ratedisplay);
    if (physicalcount >= 3)
    {
      if (ratedisplay == 250)
      {
        if(nocode1 == 0)
        {
         lcd.setCursor(5, 3);
         lcd.print(amnt[0]);
         digitalWrite(outpin5, HIGH);
        } 
        else
        {
         lcd.setCursor(5, 3);
         lcd.print("E");
         digitalWrite(outpin5, HIGH); 
        }
      }

      if (ratedisplay == 350)
      {
        digitalWrite(outpin5, LOW);
      }

      if (ratedisplay == 450)
      {
       if (nocode2 == 0)
       { 
        digitalWrite(outpin5, HIGH);
        lcd.setCursor(8, 3);
        lcd.print(amnt[1]);
       }
       else
       {  
        lcd.setCursor(8, 3);
        lcd.print("E");
        digitalWrite(outpin5, HIGH);
       }
      }

      if (ratedisplay == 550)
      {
        digitalWrite(outpin5, LOW);
      }

      if (ratedisplay == 650)
      {
       if(nocode3 == 0)
       { 
        digitalWrite(outpin5, HIGH);
        lcd.setCursor(11, 3);
        lcd.print(amnt[2]);
       }
       else {
        digitalWrite(outpin5, HIGH);
        lcd.setCursor(11, 3);
        lcd.print("E");
       }
      }
      if (ratedisplay == 750)
      {
        digitalWrite(outpin5, LOW);
      }
    }
    if (physicalcount >= 4)
    {
      if (ratedisplay == 850 )
      {
       if(nocode4 == 0)
       {
        digitalWrite(outpin5, HIGH);
        lcd.setCursor(14, 3);
        lcd.print(amnt[3]);
       }
       else {
         digitalWrite(outpin5, HIGH);
        lcd.setCursor(14, 3);
        lcd.print("E");
       }
      }
      if (ratedisplay == 950)
      {
        digitalWrite(outpin5, LOW);
      }
    }
    if (physicalcount == 5)
    {
      if (ratedisplay == 1050)
      {
       if(nocode5 == 0)
       { 
        digitalWrite(outpin5, HIGH);
        lcd.setCursor(17, 3);
        lcd.print(amnt[4]);
       }
       else {
        digitalWrite(outpin5, HIGH);
        lcd.setCursor(17, 3);
        lcd.print("E");
       }
      }
      if (ratedisplay == 1150)
      {
        digitalWrite(outpin5, LOW);
      }
    }


    if (ratedisplay == 1150)
    {
      lcd.setCursor(5, 3);
      lcd.print("               ");
      ratedisplay = 0;
    }
  }
}


void primalrun()
{

  //Select How many rates you want to Run in this machine
  if (primerun == 0) //checker if there is a file containing User Inputs like "Rates", and all necessary Primary Settings
  {
    if (pass == 0)
    {
      pass = 1;
      SD.remove("ratein.txt");
      SD.remove("primerun.txt");
      SD.remove("primer.txt");
      SD.remove("rate1.txt");
      SD.remove("rate2.txt");
      SD.remove("rate3.txt");
      SD.remove("rate4.txt");
      SD.remove("rate5.txt");
      SD.remove("timer.txt");
    }
    lcd.setCursor(0, 0);
    lcd.print("A. How many rates ?");// Fist Display during Data Feeding
    lcd.setCursor(0, 1);
    lcd.print("(Choose 3,4,5 Rates)");// Fist Display during Data Feeding
    lcd.setCursor(0, 3);
    lcd.print(" (Hold Push Button)");// Fist Display during Data Feeding
    if (buttonPushCounter == 1)
    {
      lcd.setCursor(6, 2);
      lcd.print("3 Rates");
      selectedrate = 3;
    }
    if (buttonPushCounter == 2)
    {
      lcd.setCursor(6, 2);
      lcd.print("4 Rates");
      selectedrate = 4;
    }

    if (buttonPushCounter == 3)
    {
      lcd.setCursor(6, 2);
      lcd.print("5 Rates"); // Fist Display during Data Feeding
      selectedrate = 5;
    }

    if (buttonPushCounter > 3 )
    {
      buttonPushCounter = 1;
    }

    buttoncycle++;
    // Serial.print(buttoncycle);
    //**************************************
    buttonState2 = digitalRead(buttonPin2);
    if (buttonState2 != lastButtonState2)
    {
      if (buttonState2 == HIGH)
      {
        buttonPushCounter++;
        Serial.print("on");
        Serial.print("number of button pushes1: ");
        Serial.print(buttonPushCounter);
      }
      else {
        // if the current state is LOW then the button went from on to off:
        Serial.print("off");
      }
      // Delay a little bit to avoid bouncing
      delay(10);
    }
    lastButtonState2 = buttonState2;

    if (buttonState2 == HIGH)
    {
      cycles++;
      Serial.print(cycles);
    }
    else
    {
      cycles = 0;
    }


    if (buttonState2 == HIGH && cycles >= 50)
    {
      cycles = 0;
      primerun = 1;
      pass = 0;
      lcd.setCursor(0, 1);
      lcd.print("                    ");

      while (blinkcounts < 10)
      {
        blinkcounts++;

        // delay(800);
        lcd.setCursor(0, 2);
        lcd.print("                    ");
        lcd.setCursor(3, 2);
        delay(200);
        lcd.print("Saving   Rates");
        lcd.setCursor(10, 2);
        lcd.print(selectedrate);
        delay(200);
      }

      if (selectedrate == 3)
      {
        myFile = SD.open("rate1.txt", FILE_WRITE);
        myFile.close();
        myFile = SD.open("rate2.txt", FILE_WRITE);
        myFile.close();
        myFile = SD.open("rate3.txt", FILE_WRITE);
        myFile.close();
        myFile = SD.open("r1ctr.txt", FILE_WRITE);
        myFile.close();
        myFile = SD.open("r2ctr.txt", FILE_WRITE);
        myFile.close();
        myFile = SD.open("r3ctr.txt", FILE_WRITE);
        myFile.close();
        indicatorr = 3;
        myFile = SD.open("primerun.txt", FILE_WRITE);
        myFile.close();
      }

      if (selectedrate == 4)
      {
        myFile = SD.open("rate1.txt", FILE_WRITE);
        myFile.close();
        myFile = SD.open("rate2.txt", FILE_WRITE);
        myFile.close();
        myFile = SD.open("rate3.txt", FILE_WRITE);
        myFile.close();
        myFile = SD.open("rate4.txt", FILE_WRITE);
        myFile.close();
        myFile = SD.open("r1ctr.txt", FILE_WRITE);
        myFile.close();
        myFile = SD.open("r2ctr.txt", FILE_WRITE);
        myFile.close();
        myFile = SD.open("r3ctr.txt", FILE_WRITE);
        myFile.close();
        myFile = SD.open("r4ctr.txt", FILE_WRITE);
        myFile.close();
        indicatorr = 4;
        myFile = SD.open("primerun.txt", FILE_WRITE);
        myFile.close();

      }

      if (selectedrate == 5)
      {
        myFile = SD.open("rate1.txt", FILE_WRITE);
        myFile.close();
        myFile = SD.open("rate2.txt", FILE_WRITE);
        myFile.close();
        myFile = SD.open("rate3.txt", FILE_WRITE);
        myFile.close();
        myFile = SD.open("rate4.txt", FILE_WRITE);
        myFile.close();
        myFile = SD.open("rate5.txt", FILE_WRITE);
        myFile.close();
        myFile = SD.open("r1ctr.txt", FILE_WRITE);
        myFile.close();
        myFile = SD.open("r2ctr.txt", FILE_WRITE);
        myFile.close();
        myFile = SD.open("r3ctr.txt", FILE_WRITE);
        myFile.close();
        myFile = SD.open("r4ctr.txt", FILE_WRITE);
        myFile.close();
        myFile = SD.open("r5ctr.txt", FILE_WRITE);
        myFile.close();
        indicatorr = 5;
        myFile = SD.open("primerun.txt", FILE_WRITE);
        myFile.close();

      }

      lcd.setCursor(0, 2);
      lcd.print("                    ");
      lcd.setCursor(3, 2);
      lcd.print(selectedrate);
      lcd.setCursor(5, 2);
      lcd.print("Rates Saved!");
      delay(3000);
      buttonPushCounter = 0;
      lcd.clear();
      blinkcounts = 0;
    }


  }


}

void primalruna()
{
  if (primeruna == 0 && primerun == 1)
  {
    lcd.setCursor(0, 0);
    lcd.print("B.Set Code Countdown");// Fist Display during Data Feeding
    lcd.setCursor(0, 1);
    lcd.print("  (13s,26s,39s,65s)");// Fist Display during Data Feeding
    lcd.setCursor(0, 3);
    lcd.print(" (Hold Push Button)");// Fist Display during Data Feeding

    if (buttonPushCounter == 1)
    {
      lcd.setCursor(6, 2);
      lcd.print("13 second");
      selectedtime = 13;
    }
    if (buttonPushCounter == 2)
    {
      lcd.setCursor(6, 2);
      lcd.print("26 sec");
      selectedtime = 26;
    }

    if (buttonPushCounter == 3)
    {
      lcd.setCursor(6, 2);
      lcd.print("39 sec");
      selectedtime = 39;
    }

    if (buttonPushCounter == 4)
    {
      lcd.setCursor(6, 2);
      lcd.print("65 sec");
      selectedtime = 65;
    }

    if (buttonPushCounter > 4)
    {
      buttonPushCounter = 1;
    }


    buttoncycle++;
    // Serial.print(buttoncycle);
    //**************************************
    buttonState2 = digitalRead(buttonPin2);
    if (buttonState2 != lastButtonState2)
    {
      if (buttonState2 == HIGH)
      {
        buttonPushCounter++;
        Serial.print("on");
        Serial.print("number of button pushes2: ");
        Serial.print(buttonPushCounter);
      }
      else {
        // if the current state is LOW then the button went from on to off:
        Serial.print("off");
      }
      // Delay a little bit to avoid bouncing
      delay(10);
    }
    lastButtonState2 = buttonState2;

    if (buttonState2 == HIGH)
    {
      cycles++;
      Serial.print(cycles);
    }
    else
    {
      cycles = 0;
    }


    if (buttonState2 == HIGH && cycles >= 50)
    {
      cycles = 0;
      primeruna = 1;
      pass = 0;
      timeselectionpass = 1;
      lcd.setCursor(0, 1);
      lcd.print("                    ");

      while (blinkcounts < 10)
      {
        blinkcounts++;

        // delay(800);
        lcd.setCursor(0, 2);
        lcd.print("                    ");
        delay(200);
        lcd.setCursor(0, 2);
        lcd.print("Saving   sec. Time");
        lcd.setCursor(7, 2);
        lcd.print(selectedtime);
        delay(200);
      }
      lcd.setCursor(0, 2);
      lcd.print("                    ");
      lcd.setCursor(2, 2);
      lcd.print("   sec.Time Saved!");
      lcd.setCursor(3, 2);
      lcd.print(selectedtime);
      //Serial.print(selectedtime);
      timesaving();
      Serial.print(selectedtime);
      delay(3000);
      buttonPushCounter = 0;
      timeselectionpass = 1;
      lcd.clear();

    }
  }
}


void primalrun2()
{
  //******* (START)THIS LINE IS USED TO SELECT OR SET RATES ******************
  //******* (START)THIS LINE IS USED TO SELECT OR SET RATES ******************
  //selectrate();
  if (primerun2 == 0 && primerun == 1 && halt == 0 && timeselectionpass == 1)
  {

    lcd.setCursor(0, 0);
    lcd.print("C.Please Input Value");

    if (selectedrate >= 3)
    {
      lcd.setCursor(0, 1);
      lcd.print("rate1:>");
      lcd.setCursor(10, 1);
      lcd.print("rate2:>");
      lcd.setCursor(0, 2);
      lcd.print("rate3:>");
    }

    if (selectedrate >= 4)
    {
      lcd.setCursor(10, 2);
      lcd.print("rate4:>");
    }

    if (selectedrate == 5)
    {
      lcd.setCursor(0, 3);
      lcd.print("rate5:>");
    }

    manualrate_input();
    if (selectedrate == selectedratepass  )
    {
      halt = 1;
      Serial.print("Halo Johnny");
      if (pass == 0)
      {
        pass = 1;
        blinkcounts = 0;
        myFile = SD.open("primer.txt", FILE_WRITE);
        myFile.close();
        prompt();
      }


    }
    //******selection button sensor**************
    if (cycles2 < 70)
    {
      if (buttonState2 == HIGH)
      {
        cycles++;
        cycles2 = cycles;
        Serial.print("cycles>> ");
        Serial.print(cycles);
      }
      else
      {
        cycles = 0;
      }


      if ((buttonState2 == HIGH) && (cycles >= 30))
      {
        if ((buttonPushCounter > 0) && (rate1 == 0))
        {
          rate1 = 1;
          selectedratepass++;
          savingrates();
          buttonPushCounter = 0;
        }
        //*****************************************
        if ((buttonPushCounter > 0) && (rate2 == 0 && rate1 == 1))
        {
          rate2 = 1;
          selectedratepass++;
          savingrates();
          buttonPushCounter = 0;
        }

        if ((buttonPushCounter > 0) && (rate3 == 0 && rate2 == 1))
        {
          rate3 = 1;
          selectedratepass++;
          savingrates();
          buttonPushCounter = 0;
        }

        if ((buttonPushCounter > 0) && (rate4 == 0 && rate3 == 1))
        {
          rate4 = 1;
          selectedratepass++;
          savingrates();
          buttonPushCounter = 0;

        }

        if ((buttonPushCounter > 0) && (rate5 == 0 && rate4 == 1))
        {
          // **********************
          rate5 = 1;
          selectedratepass++;
          savingrates();
          buttonPushCounter = 0;
        }
        //buttonPushCounter == 0;
      }
    }

    //*************************************START!!! START !!!THIS PART HERE USED TO EDIT ERONEOUS INPUT**************************
    if (cycles >= 30)
    {
      if (buttonState2 == HIGH)
      {
        cycles2++;
        //cycles2 = cycles;
        Serial.print("cycles2>> ");
        Serial.print(cycles2);
      }
      else
      {
        cycles2 = 0;
        cycles = 0;
      }
      cycles2++;
      if ((buttonState2 == HIGH) && (cycles2 >= 70))
      {
        if ((buttonPushCounter > 0) && (rate1 == 1))
        {
          rate1 = 0;
          selectedratepass--;
          // savingrates();
          SD.remove("ratein.txt");
          lcd.setCursor(7, 1);
          lcd.print("  ");
          lcd.setCursor(17, 1);
          lcd.print("  ");
          lcd.setCursor(7, 2);
          lcd.print("  ");
          lcd.setCursor(17, 2);
          lcd.print("  ");
          lcd.setCursor(17, 2);
          lcd.print("  ");
          buttonPushCounter = 0;
          manualrate_input();

        }
        //*****************************************
        if ((buttonPushCounter == 0) && (rate2 == 0 && rate1 == 1 ))
        {
          rate1 = 0;
          SD.remove("ratein.txt");
          selectedratepass--;
          // savingrates();
          buttonPushCounter = 0;
          lcd.setCursor(17, 1);
          lcd.print("  ");
          lcd.setCursor(7, 1);
          lcd.print("  ");
          manualrate_input();

        }

        if ((buttonPushCounter == 0) && (rate3 == 0 && rate2 == 1))
        {
          rate2 = 0;
          SD.remove("ratein.txt");
          selectedratepass--;
          //  savingrates();
          lcd.setCursor(17, 1);
          lcd.print("  ");
          lcd.setCursor(7, 2);
          lcd.print("  ");
          buttonPushCounter = 0;
          manualrate_input();
        }

        if ((buttonPushCounter == 0) && (rate4 == 0 && rate3 == 1))
        {
          rate3 = 0;
          SD.remove("ratein.txt");
          selectedratepass--;
          // savingrates();
          lcd.setCursor(17, 2);
          lcd.print("  ");
          lcd.setCursor(7, 2);
          lcd.print("  ");
          buttonPushCounter = 0;
          manualrate_input();
        }

        if ((buttonPushCounter == 0) && (rate5 == 0 && rate4 == 1))
        {
          // **********************
          rate4 = 0;
          SD.remove("ratein.txt");
          selectedratepass--;
          //savingrates();
          lcd.setCursor(17, 2);
          lcd.print("  ");
          lcd.setCursor(7, 3);
          lcd.print("  ");
          buttonPushCounter = 0;
          manualrate_input();
        }
        //buttonPushCounter == 0;
      }

      //*************************************ENDING END END!!! THIS PART HERE USED TO EDIT ERONEOUS INPUT**************************
    }

  buttonState2 = digitalRead(buttonPin2);
    if (buttonState2 != lastButtonState2)
    {
      if (buttonState2 == HIGH)
      {
        buttonPushCounter++;
        Serial.print("on");
        Serial.print("number of button pushes3: ");
        Serial.print(buttonPushCounter);
      }
      else {
        // if the current state is LOW then the button went from on to off:
        Serial.print("off");
      }
      // Delay a little bit to avoid bouncing
      delay(10);
    }
    lastButtonState2 = buttonState2;

    buttonState3 = digitalRead(buttonPin3);
    if (buttonState3 != lastButtonState3)
    {
      if (buttonState3 == HIGH)
      {
        if (buttonPushCounter > 0)
        {
          buttonPushCounter--;
        }
        else
        {
          buttonPushCounter = 0;
          lcd.setCursor(7, 1);
          lcd.print("  ");
          lcd.setCursor(17, 1);
          lcd.print("  ");
          lcd.setCursor(7, 2);
          lcd.print("  ");
          lcd.setCursor(17, 2);
          lcd.print("  ");
          lcd.setCursor(17, 2);
          lcd.print("  ");buttonState2 = digitalRead(buttonPin2);
    if (buttonState2 != lastButtonState2)
    {
      if (buttonState2 == HIGH)
      {
        buttonPushCounter++;
        Serial.print("on");
        Serial.print("number of button pushes3: ");
        Serial.print(buttonPushCounter);
      }
      else {
        // if the current state is LOW then the button went from on to off:
        Serial.print("off");
      }
      // Delay a little bit to avoid bouncing
      delay(10);
    }
    lastButtonState2 = buttonState2;

    buttonState3 = digitalRead(buttonPin3);
    if (buttonState3 != lastButtonState3)
    {
      if (buttonState3 == HIGH)
      {
        if (buttonPushCounter > 0)
        {
          buttonPushCounter--;
        }
        else
        {
          buttonPushCounter = 0;
          lcd.setCursor(7, 1);
          lcd.print("  ");
          lcd.setCursor(17, 1);
          lcd.print("  ");
          lcd.setCursor(7, 2);
          lcd.print("  ");
          lcd.setCursor(17, 2);
          lcd.print("  ");
          lcd.setCursor(17, 2);
          lcd.print("  ");
        }
        Serial.print("on");
        Serial.print("number of button pushes3OTEEEN: ");
        Serial.print(buttonPushCounter);
      }
      else {
        // if the current state is LOW then the button went from on to off:
        Serial.print("OTEEENNNNNN");
      }
      // Delay a little bit to avoid bouncing
      delay(10);
    }
    lastButtonState3 = buttonState3;

        }
        Serial.print("on");
        Serial.print("number of button pushes3OTEEEN: ");
        Serial.print(buttonPushCounter);
      }
      else {
        // if the current state is LOW then the button went from on to off:
        Serial.print("OTEEENNNNNN");
      }
      // Delay a little bit to avoid bouncing
      delay(10);
    }
    lastButtonState3 = buttonState3;

      


  }
}


void timesaving()
{
  myFile = SD.open("timer.txt", FILE_WRITE);
  if (myFile)
  {
    Serial.print("Writing to countdown.txt...");
    myFile.print(selectedtime);
    // close the file:
    myFile.close();
    Serial.print("done.");
    Serial.print(selectedtime);
  }
  else
  {
    // if the file didn't open, print an error:
    Serial.print("Error Opening timer.txt");
  }

}


void getresponse()   //*************used to get coin drop event************
{
  buttonState = digitalRead(buttonPin);
  // compare the buttonState to its previous state
  if (buttonState != lastButtonState) {
    // if the state has changed, increment the counter
    if (buttonState == HIGH) {
      nadetect = 0;
      cownt = 0;
      buttonPushSelection = 0;
      digitalWrite(outpin5, LOW);
      pause  = 1;
      lcd.setCursor(0, 3);
      lcd.print("                    ");
      // if the current state is HIGH then the button
      // wend from off to on:
      buttonPushCounter++;
      cntr = 0;
      lcd.setCursor(0, 1);
      lcd.print("   Inserted Coins   ");
      lcd.setCursor(5, 3);
      lcd.print("Php. ");
      lcd.print(buttonPushCounter);
      if ((buttonPushCounter > 0) && (buttonPushCounter == amnt[0] || buttonPushCounter == amnt[1] || buttonPushCounter == amnt[2] || buttonPushCounter == amnt[3] || buttonPushCounter == amnt[4]))
      {
        digitalWrite(outpin5, HIGH);
      }
      else
      {
        digitalWrite(outpin5, LOW);
      }

      //**********************************

      Serial.print("on");
      Serial.print("number of button pushes4:  ");
      Serial.print(buttonPushCounter);
    }
    else {
      // if the current state is LOW then the button
      // wend from on to off:
      Serial.print("off");
    }
    // Delay a little bit to avoid bouncing
    delay(10);
  }
  // save the current state as the last state,
  //for next time through the loop
  lastButtonState = buttonState;
}

void getresponse2() //*******used to get buttonPushSelection Event*****************
{

  if (buttonPushCounter > 0 && nadetect == 0)
  {
    buttonState2 = digitalRead(buttonPin2);
    // compare the buttonState to its previous state
    if (buttonState2 != lastButtonState2) {
      // if the state has changed, increment the counter
      if (buttonState2 == HIGH) {
        // if the current state is HIGH then the button
        // wend from off to on:
        buttonPushSelection = 1;
        // cntr = 0;
        Serial.print(buttonPushSelection);
      }
      // Delay a little bit to avoid bouncing
      delay(10);
    }
    // save the current state as the last state,
    //for next time through the loop
    lastButtonState2 = buttonState2;
    // Serial.print("Amaw");
    if (buttonPushCounter > 0 && buttonPushSelection == 1)
    {
      if (cownt < physicalcount)
      {
        if (buttonPushCounter == amnt[cownt])
        {
          nadetect = 1;
          nagcodisplay = 1;
          pass5 = 1;

          if (cownt == 0)
          {
            mrker = 1;
           // dummyratecount = rate1codecount;
           // dummyratecount--;
           dummyratecount = rate1counter - rate1codecount;
           dummyratecount--;
            
          }
          
          if (cownt == 1)
          {
            mrker = 2;
           // dummyratecount = rate2codecount;
           // dummyratecount--;
           // dummyratecount = rate2codecount - 1;
           dummyratecount = rate2counter - rate2codecount;
           dummyratecount--;
          }
          if (cownt == 2)
          {
            mrker = 3;
           // dummyratecount = rate3codecount;
           // dummyratecount--;
            dummyratecount = rate3counter - rate3codecount;
            dummyratecount--;
          }
          if (cownt == 3)
          {
            mrker = 4;
         //   dummyratecount = rate4codecount;
         //   dummyratecount--;
           dummyratecount = rate4counter - rate4codecount;
           dummyratecount--;
          }
          if (cownt == 4)
          {
            mrker = 5;
            //dummyratecount = rate5codecount;
           // dummyratecount--;
            dummyratecount = rate5counter - rate5codecount;
            dummyratecount--;
          }
          Serial.print("Johnnytipz");
          processingrates();
          cownt = 0;
          mrker = 0;
          buttonPushCounter = 0;
          buttonPushSelection = 0;
          mrker = 0;

        }
        Serial.print("amaw");
        cownt++;
      }
    } //*********last End if for controlling rates distribution
  }
}



//this function is used to display rates available in "RATEIN.TXT".... and used to indicate displays blinking in main page
void rate_in()
{

  myFile = SD.open("ratein.txt");
  if (myFile) {
    Serial.print("ratein");

    // read from the file until there's nothing else in it:
    while (myFile.available()) {
      //Serial.write(myFile.read());
      char a = myFile.read();
      Serial.write(a);
      if (a != '\n' || a != '\r')
      {
        readString += a;
      }

      if (a == '\n' || a == '\r')
      {
        count++;
        if (count == 2)
        {
          b = (readString.toInt());
          count = 0;
          physicalcount++;
          amnt[counter] = b;
          counter++;
          // Serial.print(counter);
          readString = "";
        }
      }
    }
    // close the file:
    myFile.close();
  } else {
    // if the file didn't open, print an error:
    Serial.print("error ratein.txt");
  }
  count = 0;
  Serial.print(" ");
  while ( count < physicalcount)
  {
    Serial.print(amnt[count]);
    count++;
  }
  Serial.print("physical count total rates> ");
  Serial.print(physicalcount);
  Serial.print("");
  cnting = 0;
  read_countdown();
}

void read_countdown()
{
  myFile = SD.open("timer.txt");
  if (myFile) {

    Serial.print("countdowntime");

    // read from the file until there's nothing else in it:
    while (myFile.available()) {
      //Serial.write(myFile.read());
      char a = myFile.read();
      Serial.write(a);

      if (a != '\n' || a != '\r')
      {
        readString += a;
      }

      if (a == '\n' || a == '\r')
      {
        cnting++;
        if (cnting == 2)
        {
          b = (readString.toInt());
          cnting = 0;
          // physicalcounting++;
          selectedtime = b; //********************************************************************************************8
          // countering++;
          Serial.print("TIPDAS TIME IS HERE>>");
          Serial.print(selectedtime);
          readString = "";
        }
      }
    }
    // close the file:
    myFile.close();
  } else {
    // if the file didn't open, print an error:
    Serial.print("error countdown.txt");
  }

}



void savingrates()
{
  myFile = SD.open("ratein.txt", FILE_WRITE);
  if (myFile)
  {
    Serial.print("Writing to ratein.txt...");
    myFile.print(buttonPushCounter);
    // close the file:
    myFile.close();
    Serial.print("done.");
  }
  else
  {
    // if the file didn't open, print an error:
    Serial.print("Error Opening ratein.txt");
  }
}



void processingrates()
{
  if (mrker == 1)
  {
    proceed = 0;
    proceed1 = 0;
    halting = 0;
    codecount = 0;
    //********Opening File for Reading Contents to be transfered to Y*******
    myFile = SD.open("r1ctr.txt");// (opening the numbered textfile to locate the last file numbered)
    if (myFile) {

      Serial.print("r1ctr.txt ");

      while (myFile.available()) {
        //Serial.write(myFile.read());
        char a = myFile.read();
        Serial.write(a);

        if (a != '\n' || a != '\r')
        {
          readString += a;
        }

        if (a == '\n' || a == '\r')
        {
          cnting++;
          if (cnting == 2)
          {
            b = (readString.toInt());// (converting the character into an integer)
            cnting = 0;
            // physicalcounting++;
            rate1codecount = b; //********************************************************************************************8
            
            // countering++;
            Serial.print("TIPDAS TIME IS HERE>>");
            Serial.print(rate1codecount);
            readString = "";
          }
        }
      }
      // close the file:
      myFile.close();//closing the opened file
    } else {
      // if the file didn't open, print an error:
      Serial.print("error countdown.txt");
    }
    //int trap1 = 0;
    while(rate1codecount == rate1counter)
    {
      if (trap1 == 0)
      {
       trap1 = 1;
       codecountrun = 0;
       myFile = SD.open("r1emp.txt", FILE_WRITE); //indicating empty rate1.txt
       myFile.close();   
      }
      lcd.setCursor(0,1);
      lcd.print("  RATE 1 IS EMPTY!  ");
      lcd.setCursor(0,2);
      lcd.print("    Pls. Reload!    ");
      delay(700);
      lcd.setCursor(0,1);
      lcd.print("                    ");
      lcd.setCursor(0,2);
      lcd.print("                    ");
      delay(700);
      digitalWrite(outpin6, HIGH);
      digitalWrite(outpin5, HIGH);
    }
    
    myFile = SD.open("rate1.txt");
    if (myFile) {
      // read from the file until there's nothing else in it:
      while (halting != 1 && myFile.available()) {
        //Serial.write(myFile.read());
        c = myFile.read();
        if (codecount != rate1codecount)
        {
          // readString += c;
          // a++;
          //**************continuation A*********
          if (c == '\n' || c == '\r')
          {
            //a++;
            proceed++;
            b = a;// b is used to put shades in an unwanted ascii character
            //a = 0;// a is the counter of readable characters
          }

          if (proceed == 2)

          {
            proceed = 0;
            firstdisplay++;
            codecount++;
          }
        }
        // if (firstdisplay == 1)
        if (codecount == rate1codecount)
        {

          if (c != '\n' || c != '\r')
          {
            readString += c;
            // Serial.print(readString);
            // delay(800);
          }
          if (c == '\n' || c == '\r')
          {
            proceed1++;
          }
          if (proceed1 == 2)
          {
            proceed1 = 0;
            // Serial.print(readString);
            //  delay(10000);
            display_code();
            codecount++;
            halting = 1;
            rate1codecount += 1;
            Serial.print(firstdisplay);
            SD.remove("r1ctr.txt");
            myFile2 = SD.open("r1ctr.txt", FILE_WRITE); //saving code taken (on its corresponding place in sequencial order)
            if (myFile2)
            {
              myFile2.print(rate1codecount); // "Serial.print("R1_TAKEN_CODE.TXT... ");being saved!"
              myFile2.close();
              // Serial.print("done.");
            }
            // ******* SAVING FILE ******

          }//end if proceed
        }//end if code count
      } //end while
      // close the file:
      myFile.close();
      lcd.setCursor(6, 3);
      lcd.print(codecount);
    } // if (Myfile)
    else
    {
      // if the file didn't open, print an error:
      Serial.print("error opening 3day.txt");
    }// end else


  }

  if (mrker == 2)
  {
    proceed = 0;
    proceed1 = 0;
    halting = 0;
    codecount = 0;
    //********Opening File for Reading Contents to be transfered to Y*******
    myFile = SD.open("r2ctr.txt");// (opening the numbered textfile to locate the last file numbered)
    if (myFile) {

      Serial.print("r2ctr.txt ");

      while (myFile.available()) {
        //Serial.write(myFile.read());
        char a = myFile.read();
        Serial.write(a);

        if (a != '\n' || a != '\r')
        {
          readString += a;
        }

        if (a == '\n' || a == '\r')
        {
          cnting++;
          if (cnting == 2)
          {
            b = (readString.toInt());// (converting the character into an integer)
            cnting = 0;
            // physicalcounting++;
            rate2codecount = b; //********************************************************************************************8
            
            Serial.print("TIPDAS TIME IS HERE>>");
            Serial.print(rate1codecount);
            readString = "";
          }
        }
      }
      // close the file:
      myFile.close();//closing the opened file
    } else {
      // if the file didn't open, print an error:
      Serial.print("error countdown.txt");
    }
    //int trap2 = 0;
    while(rate2codecount == rate2counter)
    {
      if (trap2 == 0)
      {
       trap2 = 1;
       myFile = SD.open("r2emp.txt", FILE_WRITE); //indicating empty rate1.txt
       myFile.close();   
      }
      lcd.setCursor(0,1);
      lcd.print("  RATE 2 IS EMPTY!  ");
      lcd.setCursor(0,2);
      lcd.print("    Pls. Reload!    ");
      delay(700);
      lcd.setCursor(0,1);
      lcd.print("                    ");
      lcd.setCursor(0,2);
      lcd.print("                    ");
      delay(700);
      digitalWrite(outpin6, HIGH);
      digitalWrite(outpin5, HIGH);
    }
    myFile = SD.open("rate2.txt");
    if (myFile) {
      // read from the file until there's nothing else in it:
      while (halting != 1 && myFile.available()) {
        //Serial.write(myFile.read());
        c = myFile.read();
        if (codecount != rate2codecount)
        {
          // readString += c;
          // a++;
          //**************continuation A*********
          if (c == '\n' || c == '\r')
          {
            //a++;
            proceed++;
            b = a;// b is used to put shades in an unwanted ascii character
            //a = 0;// a is the counter of readable characters
          }

          if (proceed == 2)

          {
            proceed = 0;
            firstdisplay++;
            codecount++;
          }
        }
        // if (firstdisplay == 1)
        if (codecount == rate2codecount)
        {
          if (c != '\n' || c != '\r')
          {
            readString += c;
          }
          if (c == '\n' || c == '\r')
          {
            proceed1++;
          }
          if (proceed1 == 2)
          {
            proceed1 = 0;
            Serial.print(readString);
            // delay(10000);
            display_code();

            codecount++;
            halting = 1;
            rate2codecount += 1;
            Serial.print(firstdisplay);
            SD.remove("r2ctr.txt");
            myFile2 = SD.open("r2ctr.txt", FILE_WRITE); //saving code taken (on its corresponding place in sequencial order)
            if (myFile2)
            {
              myFile2.print(rate2codecount); // "Serial.print("R1_TAKEN_CODE.TXT... ");being saved!"
              myFile2.close();
              // Serial.print("done.");
            }
            // ******* SAVING FILE ******

          }//end if proceed
        }//end if code count
      } //end while
      // close the file:
      myFile.close();
      lcd.setCursor(6, 3);
      lcd.print(codecount);
    } // if (Myfile)
    else
    {
      // if the file didn't open, print an error:
      Serial.print("error opening 3day.txt");
    }// end else
  }

  if (mrker == 4)
  {
    proceed = 0;
    proceed1 = 0;
    halting = 0;
    codecount = 0;
    //********Opening File for Reading Contents to be transfered to Y*******
    myFile = SD.open("r4ctr.txt");// (opening the numbered textfile to locate the last file numbered)
    if (myFile) {

      Serial.print("r4ctr.txt ");

      while (myFile.available()) {
        //Serial.write(myFile.read());
        char a = myFile.read();
        Serial.write(a);

        if (a != '\n' || a != '\r')
        {
          readString += a;
        }

        if (a == '\n' || a == '\r')
        {
          cnting++;
          if (cnting == 2)
          {
            b = (readString.toInt());// (converting the character into an integer)
            cnting = 0;
            // physicalcounting++;
            rate4codecount = b; //********************************************************************************************8
            
            // countering++;
            Serial.print("TIPDAS TIME IS HERE>>");
            Serial.print(rate4codecount);
            readString = "";
          }
        }
      }
      // close the file:
      myFile.close();//closing the opened file
    } else {
      // if the file didn't open, print an error:
      Serial.print("error countdown.txt");
    }
    //int trap4 = 0;
    while(rate4codecount == rate4counter)
    {
      if (trap4 == 0)
      {
       trap4 = 1;
       myFile = SD.open("r4emp.txt", FILE_WRITE); //indicating empty rate1.txt
       myFile.close();   
      }
      lcd.setCursor(0,1);
      lcd.print("  RATE 4 IS EMPTY!  ");
      lcd.setCursor(0,2);
      lcd.print("    Pls. Reload!    ");
      delay(700);
      lcd.setCursor(0,1);
      lcd.print("                    ");
      lcd.setCursor(0,2);
      lcd.print("                    ");
      delay(700);
      digitalWrite(outpin6, HIGH);
      digitalWrite(outpin5, HIGH);
    }
    myFile = SD.open("rate4.txt");
    if (myFile) {
      // read from the file until there's nothing else in it:
      while (halting != 1 && myFile.available()) {
        //Serial.write(myFile.read());
        c = myFile.read();
        if (codecount != rate4codecount)
        {
          // readString += c;
          // a++;
          //**************continuation A*********
          if (c == '\n' || c == '\r')
          {
            //a++;
            proceed++;
            b = a;// b is used to put shades in an unwanted ascii character
            //a = 0;// a is the counter of readable characters
          }

          if (proceed == 2)

          {
            proceed = 0;
            firstdisplay++;
            codecount++;
          }
        }
        // if (firstdisplay == 1)
        if (codecount == rate4codecount)
        {
          if (c != '\n' || c != '\r')
          {
            readString += c;
          }
          if (c == '\n' || c == '\r')
          {
            proceed1++;
          }
          if (proceed1 == 2)
          {
            proceed1 = 0;
            Serial.print(readString);
            // delay(10000);
            display_code();

            codecount++;
            halting = 1;
            rate4codecount += 1;
            Serial.print(firstdisplay);
            SD.remove("r4ctr.txt");
            myFile2 = SD.open("r4ctr.txt", FILE_WRITE); //saving code taken (on its corresponding place in sequencial order)
            if (myFile2)
            {
              myFile2.println(rate4codecount); // "Serial.print("R1_TAKEN_CODE.TXT... ");being saved!"
              myFile2.close();
              // Serial.println("done.");
            }
            // ******* SAVING FILE ******

          }//end if proceed
        }//end if code count
      } //end while
      // close the file:
      myFile.close();
      //lcd.setCursor(6,3);
      // lcd.print(codecount);
    } // if (Myfile)
    else
    {
      // if the file didn't open, print an error:
      Serial.println("error opening 3day.txt");
    }// end else
  }

  if (mrker == 3)
  {
    proceed = 0;
    proceed1 = 0;
    halting = 0;
    codecount = 0;
    //********Opening File for Reading Contents to be transfered to Y*******
    myFile = SD.open("r3ctr.txt");// (opening the numbered textfile to locate the last file numbered)
    if (myFile) {

      Serial.println("r3ctr.txt ");

      while (myFile.available()) {
        //Serial.write(myFile.read());
        char a = myFile.read();
        Serial.write(a);

        if (a != '\n' || a != '\r')
        {
          readString += a;
        }

        if (a == '\n' || a == '\r')
        {
          cnting++;
          if (cnting == 2)
          {
            b = (readString.toInt());// (converting the character into an integer)
            cnting = 0;
            // physicalcounting++;
            rate3codecount = b; //********************************************************************************************8
            Serial.println("TIPDAS TIME IS HERE>>");
            Serial.print(rate3codecount);
            readString = "";
          }
        }
      }
      // close the file:
      myFile.close();//closing the opened file
    } else {
      // if the file didn't open, print an error:
      Serial.println("error countdown.txt");
    }
   // int trap3 = 0;
    while(rate3codecount == rate3counter)
    {
      if (trap3 == 0)
      {
       trap3 = 1;
       myFile = SD.open("r3emp.txt", FILE_WRITE); //indicating empty rate1.txt
       myFile.close();   
      }
      lcd.setCursor(0,1);
      lcd.print("  RATE 3 IS EMPTY!  ");
      lcd.setCursor(0,2);
      lcd.print("    Pls. Reload!    ");
      delay(700);
      lcd.setCursor(0,1);
      lcd.print("                    ");
      lcd.setCursor(0,2);
      lcd.print("                    ");
      delay(700);
      digitalWrite(outpin6, HIGH);
      digitalWrite(outpin5, HIGH);
    }


    myFile = SD.open("rate3.txt");
    if (myFile) {
      // read from the file until there's nothing else in it:
      while (halting != 1 && myFile.available()) {
        //Serial.write(myFile.read());
        c = myFile.read();
        if (codecount != rate3codecount)
        {
          // readString += c;
          // a++;
          //**************continuation A*********
          if (c == '\n' || c == '\r')
          {
            //a++;
            proceed++;
            b = a;// b is used to put shades in an unwanted ascii character
            //a = 0;// a is the counter of readable characters
          }

          if (proceed == 2)

          {
            proceed = 0;
            firstdisplay++;
            codecount++;
          }
        }
        // if (firstdisplay == 1)
        if (codecount == rate3codecount)
        {
          if (c != '\n' || c != '\r')
          {
            readString += c;
          }
          if (c == '\n' || c == '\r')
          {
            proceed1++;
          }
          if (proceed1 == 2)
          {
            proceed1 = 0;
            Serial.println(readString);
            // delay(10000);
            display_code();

            codecount++;
            halting = 1;
            rate3codecount += 1;
            Serial.println(firstdisplay);
            SD.remove("r3ctr.txt");
            myFile2 = SD.open("r3ctr.txt", FILE_WRITE); //saving code taken (on its corresponding place in sequencial order)
            if (myFile2)
            {
              myFile2.println(rate3codecount); // "Serial.print("R1_TAKEN_CODE.TXT... ");being saved!"
              myFile2.close();
              // Serial.println("done.");
            }
            // ******* SAVING FILE ******

          }//end if proceed
        }//end if code count
      } //end while
      // close the file:
      myFile.close();
      lcd.setCursor(6, 3);
      lcd.print(codecount);
    } // if (Myfile)
    else
    {
      // if the file didn't open, print an error:
      Serial.println("error opening 3day.txt");
    }// end else
  }

  if (mrker == 5)
  {
    proceed = 0;
    proceed1 = 0;
    halting = 0;
    codecount = 0;
    //********Opening File for Reading Contents to be transfered to Y*******
    myFile = SD.open("r5ctr.txt");// (opening the numbered textfile to locate the last file numbered)
    if (myFile) {

      Serial.println("r5ctr.txt ");

      while (myFile.available()) {
        //Serial.write(myFile.read());
        char a = myFile.read();
        Serial.write(a);

        if (a != '\n' || a != '\r')
        {
          readString += a;
        }

        if (a == '\n' || a == '\r')
        {
          cnting++;
          if (cnting == 2)
          {
            b = (readString.toInt());// (converting the character into an integer)
            cnting = 0;
            // physicalcounting++;
            rate5codecount = b; 
            // countering++;
            Serial.println("TIPDAS TIME IS HERE>>");
            Serial.print(rate5codecount);
            readString = "";
          }
        }
      }
      // close the file:
      myFile.close();//closing the opened file
    } else {
      // if the file didn't open, print an error:
      Serial.println("error countdown.txt");
    }
   // int trap5 = 0;
    while(rate5codecount == rate5counter)
    {
      if (trap5 == 0)
      {
       trap5 = 1;
       myFile = SD.open("r5emp.txt", FILE_WRITE); //indicating empty rate1.txt
       myFile.close();   
      }
      lcd.setCursor(0,1);
      lcd.print("  RATE 5 IS EMPTY!  ");
      lcd.setCursor(0,2);
      lcd.print("    Pls. Reload!    ");
      delay(700);
      lcd.setCursor(0,1);
      lcd.print("                    ");
      lcd.setCursor(0,2);
      lcd.print("                    ");
      delay(700);
      digitalWrite(outpin6, HIGH);
      digitalWrite(outpin5, HIGH);
    }
    myFile = SD.open("rate5.txt");
    if (myFile) {
      // read from the file until there's nothing else in it:
      while (halting != 1 && myFile.available()) {
        //Serial.write(myFile.read());
        c = myFile.read();
        if (codecount != rate5codecount)
        {
          // readString += c;
          // a++;
          //**************continuation A*********
          if (c == '\n' || c == '\r')
          {
            //a++;
            proceed++;
            b = a;// b is used to put shades in an unwanted ascii character
            //a = 0;// a is the counter of readable characters
          }

          if (proceed == 2)

          {
            proceed = 0;
            firstdisplay++;
            codecount++;
          }
        }
        // if (firstdisplay == 1)
        if (codecount == rate5codecount)
        {
          if (c != '\n' || c != '\r')
          {
            readString += c;
          }
          if (c == '\n' || c == '\r')
          {
            proceed1++;
          }
          if (proceed1 == 2)
          {
            proceed1 = 0;
            Serial.println(readString);
            // delay(10000);
            display_code();

            codecount++;
            halting = 1;
            rate5codecount += 1;
            Serial.println(firstdisplay);
            SD.remove("r5ctr.txt");
            myFile2 = SD.open("r5ctr.txt", FILE_WRITE); //saving code taken (on its corresponding place in sequencial order)
            if (myFile2)
            {
              myFile2.println(rate5codecount); // "Serial.print("R1_TAKEN_CODE.TXT... ");being saved!"
              myFile2.close();
              // Serial.println("done.");
            }
            // ******* SAVING FILE ******

          }//end if proceed
        }//end if code count
      } //end while
      // close the file:
      myFile.close();
      // lcd.setCursor(6,3);
      //lcd.print(codecount);
    } // if (Myfile)
    else
    {
      // if the file didn't open, print an error:
      Serial.println("error opening 3day.txt");
    }// end else
  }

}


void maindisplay()
{

  ratedisplay = 0;
  lcd.setCursor(0, 0);
  lcd.print(headername);
  //lcd.print(" Vencris WiFi Vendo");
  lcd.setCursor(0, 1);
  lcd.print(" WiFi Vendo Machine ");
  lcd.setCursor(0, 2);
  lcd.print(" >>>>>>>>><<<<<<<<< ");
  lcd.setCursor(0, 3);
  lcd.print("RATE ");
}

void display_code()
{
  lcd.setCursor(0, 3);
  lcd.print("     ");
  lcd.setCursor(0, 3);
  lcd.setCursor(0, 2);
  lcd.print("                   ");
  lcd.setCursor(0, 1);
  lcd.print("  (Get your code)   ");
  lcd.print(dummyratecount);
  lcd.setCursor(6, 2);
  lcd.print(readString);
  lcd.setCursor(6, 2);
  lcd.print(" ");
  lcd.setCursor(0, 2);
  lcd.print("Code: ");
  lcd.setCursor(14, 2);
  lcd.print("");
  lcd.setCursor(13, 2);
  lcd.print(" ");
  // lcd.setCursor(0,2);
  // lcd.print("==<");
  // b = (b + 3) - 2;
  //lcd.setCursor(b,2);
  //lcd.print("  ");
  // b = 0;
  printVoucher();
  readString = " ";
  buttonPushSelection = 0;
  if (selectedtime == 13)
  {
    countdowntimer = 225;
    cddummy = 13;
  }
  if (selectedtime == 26)
  {
    countdowntimer = 500;
    cddummy = 26;
  }
  if (selectedtime == 39)
  {
    countdowntimer = 750;
    cddummy = 39;
  }
  if (selectedtime == 65)
  {
    countdowntimer = 1250;
    cddummy = 65;
  }


}


void prompt()
{

  lcd.setCursor(0, 0);
  lcd.print("Please Wait.........");
  while (blinkcounts < 10)
  {
    blinkcounts++;

    // delay(800);
    // lcd.setCursor(0,0);
    // lcd.print("                    ");
    lcd.setCursor(0, 1);
    lcd.print("                    ");
    lcd.setCursor(0, 2);
    lcd.print("                    ");
    lcd.setCursor(0, 3);
    lcd.print("                    ");
    lcd.setCursor(3, 2);
    delay(200);
    lcd.print("Saving   Values");
    lcd.setCursor(10, 2);
    lcd.print(selectedrate);
    delay(200);
  }
  lcd.setCursor(0, 2);
  lcd.print("                    ");
  lcd.setCursor(3, 2);
  lcd.print(selectedrate);
  lcd.setCursor(5, 2);
  lcd.print("Values Saved!");
  delay(3000);
  lcd.setCursor(0, 3);
  lcd.print("Your Done,Thank You!");
  delay(3000);
  buttonPushCounter = 0;
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Please Unplug/plug");
  lcd.setCursor(0, 1);
  lcd.print(" JKCG WIFI.");
  delay(3000);
}


void primerunningtest()
{
  passprime = 1;
  char xy;
  // ******* Header "Name of the Hotspot Owner" editable **************
  myFile = SD.open("header.txt");
  if (myFile) {
    Serial.println("header.txt");
    // read from the file until there's nothing else in it:
    while (myFile.available()) {
      // Serial.write(myFile.read());
      xy = myFile.read();
      readString1 += xy;
      headername = readString1;
    }
    // close the file:
    myFile.close();
  } else {
    // if the file didn't open, print an error:
    Serial.println("error opening header.txt");
  }
  // ******* Header "Name of the Hotspot Owner" editable **************

  Serial.println("I pass primerunningtest");
  if (SD.exists("primerun.txt")) {
    Serial.println("primerun.txt exists.");
    agilang = 1;
  } else {
    Serial.println("primerun.txt doesn't exist.");
  }

  if (SD.exists("primer.txt")) {
    Serial.println("primer.txt exists.");
    agilang2 = 1;
  } else {
    Serial.println("primer.txt doesn't exist.");
  }

  if (SD.exists("timer.txt")) {
    Serial.println("countdown.txt exists.");
    agilang3 = 1;
  } else {
    Serial.println("countdown.txt doesn't exist.");
  }

  if (agilang == 1 && agilang2 == 1 && agilang3 == 1)
  {
    primerun = 1;
    primeruna = 1;
    primerun2 = 1;

    halt = 1;
  }
  else
  {
    primerun = 0;
  }
  pass1 = 0;
  pass2 = 0;
}

void manualrate_input()
{
  if (selectedrate >= 3)
  {
    if (rate1 == 0 )
    {
      lcd.setCursor(7, 1);
      lcd.print(buttonPushCounter);
    }

    if (rate2 == 0 && rate1 == 1)
    {
      lcd.setCursor(17, 1);
      lcd.print(buttonPushCounter);
    }

    if (rate3 == 0 && rate2 == 1)
    {
      lcd.setCursor(7, 2);
      lcd.print(buttonPushCounter);
    }
  }

  if (selectedrate >= 4)
  {
    if (rate4 == 0 && rate3 == 1)
    {
      lcd.setCursor(17, 2);
      lcd.print(buttonPushCounter);
    }
  }

  if (selectedrate == 5)
  {
    if (rate5 == 0 && rate4 == 1)
    {
      lcd.setCursor(7, 3);
      lcd.print(buttonPushCounter);
    }
  }

}



void codecounterdisplay()
{
  lcd.clear();
  lcd.setCursor(1, 0);
  lcd.print("  Remaining Codes  ");
  lcd.setCursor(0, 1);
  lcd.print("Rate1>    Rate2>   ");
  lcd.setCursor(0, 2);
  lcd.print("Rate3>    Rate4>  ");
  lcd.setCursor(0, 3);
  lcd.print("Rate5>");
}

void allcodecount()
{
  myFile = SD.open("rate1.txt");
  if (myFile) {
    // read from the file until there's nothing else in it:
    while (myFile.available()) {
      c = myFile.read();
      if (c == '\n' || c == '\r')
      {
        //a++;
        proceed++;
        b = a;// b is used to put shades in an unwanted ascii character
        //a = 0;// a is the counter of readable characters
      }

      if (proceed == 2)

      {
        proceed = 0;
        firstdisplay++;
        codecount++;
        Serial.println(codecount);
        lcd.setCursor(6, 1);
        lcd.print(codecount);
        if (SD.exists("r1emp.txt"))
        {
         lcd.setCursor(6, 1);
         lcd.print("used");
         nocode1 = 1;
        }
      }

    }
    myFile.close();
    
    rate1counter = codecount;
    
  }
 //**********************************
 //codecountrun = 1;
  sub = "r1ctr.txt";
  codeleft();
 codecount = 0;
  proceed = 0;
  myFile = SD.open("rate2.txt");
  if (myFile) {
    // read from the file until there's nothing else in it:
    while (myFile.available()) {
      c = myFile.read();
      if (c == '\n' || c == '\r')
      {
        //a++;
        proceed++;
        b = a;// b is used to put shades in an unwanted ascii character
        //a = 0;// a is the counter of readable characters
      }

      if (proceed == 2)

      {
        proceed = 0;
        firstdisplay++;
        codecount++;
        Serial.println(codecount);
        lcd.setCursor(16, 1);
        lcd.print(codecount);
        if (SD.exists("r2emp.txt"))
        {
         lcd.setCursor(16, 1);
         lcd.print("used");
         nocode2 = 1;
        } 

      }

    }
    myFile.close();
    rate2counter = codecount;
  }
 //**********************************
  sub = "r2ctr.txt";
  codeleft();
 codecount = 0;
  proceed = 0;
  myFile = SD.open("rate3.txt");
  if (myFile) {
    // read from the file until there's nothing else in it:
    while (myFile.available()) {
      c = myFile.read();
      if (c == '\n' || c == '\r')
      {
        //a++;
        proceed++;
        b = a;// b is used to put shades in an unwanted ascii character
        //a = 0;// a is the counter of readable characters
      }

      if (proceed == 2)

      {
        proceed = 0;
        codecount++;

        Serial.println(codecount);
        lcd.setCursor(6, 2);
        lcd.print(codecount);
        if (SD.exists("r3emp.txt"))
        {
         lcd.setCursor(6, 2);
         lcd.print("used");
         nocode3 = 1;
        }
      }

    }
    myFile.close();
    rate3counter = codecount;
  }
 //**********************************
  sub = "r3ctr.txt";
  codeleft();
 codecount = 0;
  proceed = 0;
  myFile = SD.open("rate4.txt");
  if (myFile) {
    // read from the file until there's nothing else in it:
    while (myFile.available()) {
      c = myFile.read();
      if (c == '\n' || c == '\r')
      {
        //a++;
        proceed++;
        b = a;// b is used to put shades in an unwanted ascii character
        //a = 0;// a is the counter of readable characters
      }

      if (proceed == 2)
      {
        proceed = 0;
        firstdisplay++;
        codecount++;
        Serial.println(codecount);
        lcd.setCursor(16,2);
        lcd.print(codecount);
        if (SD.exists("r4emp.txt"))
        {
         lcd.setCursor(16, 2);
         lcd.print("used");
         nocode4 = 1;
        }
      }

    }
    myFile.close();
    rate4counter = codecount;
  }
 //**********************************
  sub = "r4ctr.txt";
  codeleft();
  codecount = 0;
  proceed = 0;
  myFile = SD.open("rate5.txt");
  if (myFile) {
    // read from the file until there's nothing else in it:
    while (myFile.available()) {
      c = myFile.read();
      if (c == '\n' || c == '\r')
      {
        //a++;
        proceed++;
        b = a;// b is used to put shades in an unwanted ascii character
        //a = 0;// a is the counter of readable characters
      }

      if (proceed == 2)
      {
        proceed = 0;
        codecount++;
        Serial.println(codecount);
        lcd.setCursor(6,3);
        lcd.print(codecount);
        if (SD.exists("r5emp.txt"))
        {
         lcd.setCursor(6, 3);
         lcd.print("used");
         nocode5 = 1;
        }

      }

    }
    myFile.close();
    
  }
 //**********************************
 rate5counter = codecount;
 codecountrun = 1;
  sub = "r5ctr.txt";
  codeleft();
}

void codeleft()
{
  b = 0;
   myFile = SD.open(sub);// (opening the numbered textfile to locate the last file numbered)
    if (myFile) {

      Serial.println(sub);

      while (myFile.available()) {
        //Serial.write(myFile.read());
        char a = myFile.read();
        Serial.write(a);

        if (a != '\n' || a != '\r')
        {
          readString += a;
        }

        if (a == '\n' || a == '\r')
        {
          cnting++;
          if (cnting == 2)
          {
            b = (readString.toInt());// (converting the character into an integer)
            cnting = 0;
            // physicalcounting++;
           if (sub == "r1ctr.txt")
           { 
            rate1codecount = b; 
            // countering++;
            Serial.print("rate1 ctr.txt count>> " );
            rate1codecount = codecount - rate1codecount;
            Serial.print(rate1codecount);
            Serial.println();
            lcd.setCursor(6,1);
            lcd.print(rate1codecount);
            readString = "";
           }
           if (sub == "r2ctr.txt")
           { 
            rate2codecount = b; 
            // countering++;
            Serial.print("rate1 ctr.txt count>> " );
            rate2codecount = codecount - rate2codecount;
            Serial.print(rate2codecount);
            Serial.println();
            lcd.setCursor(16,1);
            lcd.print(rate2codecount);
            readString = "";
            }
           if (sub == "r3ctr.txt")
           { 
            rate3codecount = b; 
            // countering++;
            Serial.print("rate3 ctr.txt count>> " );
            rate3codecount = codecount - rate3codecount;
            Serial.print(rate3codecount);
            Serial.println();
            lcd.setCursor(6,2);
            lcd.print(rate3codecount);
            readString = "";
            }
           if (sub == "r4ctr.txt")
           { 
            rate4codecount = b; 
            // countering++;
            Serial.print("rate4 ctr.txt count>> " );
            rate4codecount = codecount - rate4codecount;
            Serial.print(rate4codecount);
            Serial.println();
            lcd.setCursor(16,2);
            lcd.print(rate4codecount);
            readString = "";
            }
           if (sub == "r5ctr.txt")
           { 
            rate5codecount = b; 
            // countering++;
            Serial.print("rate5 ctr.txt count>> " );
            rate5codecount = codecount - rate5codecount;
            Serial.print(rate5codecount);
            Serial.println();
            lcd.setCursor(6,3);
            lcd.print(rate5codecount);
            readString = "";
            }   
          }
        }
      }
      // close the file:
      myFile.close();//closing the opened file
    } else {
      // if the file didn't open, print an error:
      Serial.println("error countdown.txt");
    }
   b = 0;
   
}

void printVoucher()
{
  mySerial.begin(9600);
  printer.begin();
  while (!mySerial)
  {
    ;
  }
 
  printer.println(F("------------------------------"));
  printer.justify('C');
  printer.doubleHeightOn();
  printer.println(readString1); // HeaderName!
  printer.doubleHeightOff();
//  printer.doubleHeightOn();
//  printer.println(F("          Wi-Fi Hotspot"));
//  printer.doubleHeightOff();
//  printer.println(F(" "));
  printer.justify('C');
  printer.print(F("UserName&Password/VoucherCode"));

  printer.println(F(" "));
  printer.doubleHeightOn();
  printer.println(readString);
  printer.doubleHeightOff();
  printer.println(F("    Please Keep this Ticket"));
  printer.println(F("------------------------------"));
  printer.justify('C');
  printer.println(F(" "));
  printer.println(F(" "));
  printer.print(F(" "));

}

void initPrinter()
{
 //Modify the print speed and heat
 mySerial.write(27);
 mySerial.write(55);
 mySerial.write(7); //Default 64 dots = 8*('7'+1)
 mySerial.write(heatTime); //Default 80 or 800us
 mySerial.write(heatInterval); //Default 2 or 20us
 //Modify the print density and timeout
 mySerial.write(18);
 mySerial.write(35);
 int printSetting = (printDensity<<5) | printBreakTime;
 mySerial.write(printSetting); //Combination of printDensity and printBreakTime
}
