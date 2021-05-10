#include <LiquidCrystal.h> 
#include <Keypad.h>

const byte rows = 4; 					// rows on the keypad
const byte cols = 4; 					// columns on the keypad

char keys[rows][cols] = 
 {{'1','2','3','A'},

  {'4','5','6','B'},

  {'7','8','9','C'},

  {'*','0','#','D'}};             // implements the keymap

byte rowPins[rows] = {0,1,2,3};  // the rows of the keypad are connected to these pins on the Arduino bord
byte colPins[cols] = {4,5,6,7}; // the column of the keypad are connected to these pins on the Arduino bord

Keypad kpd = Keypad( makeKeymap(keys), rowPins, colPins, rows, cols ); //for the construction of the keypad

const int rs = 8, 
          en = 9,
          d4 = 10, 
          d5 = 11, 
          d6 = 12, 
          d7 = 13; 					// the pins to which the LCD is connected
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

 long a,b,nr;
 char key,action;
 boolean result = false;
 
void setup() 
{
  lcd.begin(16, 2); 				//this is what we need for a 16*2 LCD display
  lcd.print("   Calculator");		 //intro message on the display
  	
   delay(500);						 //500ms till the screen displays info
   lcd.clear(); 					//clear
}


void loop() {
key = kpd.getKey(); //storing pressed key value in a char

if (key!=NO_KEY)
DetectButtons();

if (result==true)
CalculateResult();

DisplayResult();   
}


void DetectButtons(){       //detects which buttons are pressed on the keypad, and what action to perform

     lcd.clear(); 					//clear
    if (key=='*') 					//cancel button '*' is pressed
    {
    Serial.println ("Cleans the screen"); 
    nr=a=b=0; 
    result=false;}
    
     if (key == '1')                //button 1 is pressed
    {
    Serial.println ("Button 1"); 
    if (nr==0)
    nr=1;                       //when pressed once
    else
    nr = (nr*10) + 1;       //when pressed twice
    }
    
     if (key == '4')        //button 4 is pressed
    {
    Serial.println ("Button 4"); 
    if (nr==0)
    nr=4;                   //when pressed once
    else
    nr = (nr*10) + 4;       //when pressed twice
    }
    
     if (key == '7')		//button 7 is pressed
    {
    Serial.println ("Button 7");
    if (nr==0)
    nr=7;					//when pressed once
    else
    nr = (nr*10) + 7;		//when pressed twice
    } 
  
  
    if (key == '0')
    {
    Serial.println ("Button 0"); 	//button 0 is pressed
    if (nr==0)	
    nr=0;						    //when pressed once
    else
    nr = (nr*10) + 0;		        //when pressed twice
    }
    
     if (key == '2') 				//button 2 is pressed
    {
    Serial.println ("Button 2"); 
    if (nr==0)
    nr=2;						//when pressed once
    else
    nr = (nr*10) + 2; 		    //Pressed twice
    }
    
    if (key == '5')
    {Serial.println ("Button 5"); //button 5 is pressed
    if (nr==0)
    nr=5;						//when pressed once
    else
    nr = (nr*10) + 5;		 //when pressed twice 
    }
    
     if (key == '8')
     {
     Serial.println ("Button 8"); //button 8 is pressed
     if (nr==0)
     nr=8;						//when pressed once
     else
     nr = (nr*10) + 8;		 //when pressed twice
    }   
  

    if (key == '#')                //button equal button '#' is pressed
    {Serial.println ("=");          //equal sign
    b=nr;
    result = true;
    }
    
     if (key == '3')
    {Serial.println ("Button 3"); //button 3 is pressed
     if (nr==0)
    nr=3;						//when pressed once
    else
    nr = (nr*10) + 3; 		   //when pressed twice
    }
    
     if (key == '6')            //button 6 is pressed
    {Serial.println ("Button 6"); 
    if (nr==0)
    nr=6;						//when pressed once
    else
    nr = (nr*10) + 6; 		    //when pressed twice
    }
    
     if (key == '9')
    {Serial.println ("Button 9"); //button 9 is pressed
    if (nr==0)
    nr=9; 						  //when pressed once
    else
    nr = (nr*10) + 9;		      //when pressed twice
    }  
  

   if (key == 'A' || key == 'B' || key == 'C' || key == 'D') //the 'action' buttons
  {
     
    a = nr;    
    nr =0;
     
    if (key == 'A')    //button A is pressed
    {Serial.println ("Adds the numbers"); 
     action = '+';}
     
     if (key == 'B')    //button B is pressed
    {Serial.println ("Substracts the numbers"); 
     action = '-'; }
        
     if (key == 'C')    //button C is pressed
    {Serial.println ("Multiplies the numbers");
     action = '*';}
        
     if (key == 'D')    //button D is pressed
    {Serial.println ("Divides the numbers");
     action = '/';}  

    delay(100);
  }
}

void CalculateResult(){  //function to compute the result

  if (action=='+')
    nr = a+b;          //the numbers are added

  if (action=='-')
    nr = a-b;          //the numbers are substracted

  if (action=='*')
   nr = a*b;           //the numbers are multiplied
	
  if (action=='/')
    nr = a/b;          //the numbers are divided
}


void DisplayResult(){                              //function to display the result on the LCD

  lcd.setCursor(0, 0);   			      // places the cursor to column 0, line 1
  lcd.print(a); lcd.print(action); lcd.print(b); 
  
  if (result==true)
  {lcd.print(" = ");
   lcd.print(nr);
  }                                              //displays the result 
   
  lcd.setCursor(3, 1);                          // places the cursor to column 3, line 2
  lcd.print("Result: "); lcd.print(nr);         //Result:
}