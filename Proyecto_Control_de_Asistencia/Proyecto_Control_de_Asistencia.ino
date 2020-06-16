

/*Control de Asistencia para personal Santa Isabel de Hungria
Codigo de ejecucion para el sistema de asistencia, cuenta con claves para confirmar asistencia.
Juan Camilo Vélez Olaya 11-2
El codigo se basa en teclado, LCD, Password, sonido y Led's para cumplir una función determinada.
*/

#include <Password.h> // se Incluye la libreria Password
#include <Keypad.h> // se Incluye la libreria del teclado
#include <LiquidCrystal.h> // se incluye la libreria de la LCD
#include <Wire.h> 
#include "RTClib.h"

RTC_DS1307 RTC;


const byte ROWS = 4; // Cuatro Filas
const byte COLS = 4; // Cuatro Columnas

char keys[ROWS][COLS] = {             // Se crea la matriz del teclado filaxcolumna
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};
byte rowPins[ROWS] = { 25, 26, 27, 28 };// Conectar los keypads ROW1, ROW2, ROW3 y ROW4 a esos Pines de Arduino.
byte colPins[COLS] = { 29, 30, 31, 32 };// Conectar los keypads COL1, COL2, COL3 y COL4 a esos Pines de Arduino.


int PASS = 6; // Limite de digitos
int ledWrong = 22; // LED indicador ROJO de incorrecto o funcionando
int ledRigth = 23; // LED indicador VERDE de correcto
int passw; // Pass
int ledPress = 24; // LED Pulsador, cada vez que se presiona una tecla iluminará.
int w,S; //Sonido


Password password = Password("400671");   // Passwords
Password password1 = Password("400504");
Password password2 = Password("400279");
Password password3 = Password("400811");
Password password4 = Password("400083");
Password password5 = Password("400731");
Password password6 = Password("400230");
Password password7 = Password("400296");
Password password8 = Password("400086");
Password password9 = Password("400937");
Password password10 = Password("400792");
Password password11 = Password("400623");
Password password12 = Password("400123");
Password password13 = Password("400496");
Password password14 = Password("400318");
Password password15 = Password("400227");
Password password16 = Password("400785");
Password password17 = Password("400526");
Password password18 = Password("400451");
Password password19 = Password("400609");
Password password20 = Password("400359");
Password password21 = Password("400689");
Password password22 = Password("400393");
Password password23 = Password("400558");
Password password24 = Password("400027");
Password password25 = Password("400293");
Password password26 = Password("400313");
Password password27 = Password("400207");
Password password28 = Password("400476");
Password password29 = Password("400058");
Password password30 = Password("400277");
Password password31 = Password("400455");
Password password32 = Password("400477");
Password password33 = Password("400195");
Password password34 = Password("400548");
Password password35 = Password("400020");
Password password36 = Password("400756");
Password password37 = Password("400030");
Password password38 = Password("400857");
Password password39 = Password("400058");
Password password40 = Password("400880");
Password password41 = Password("400716");
Password password42 = Password("400455");
Password password43 = Password("400927");
Password password44 = Password("ABCD98");

LiquidCrystal lcd(A1,A0,A2,A3,A4,A5);   // Se define los pines en los que se encuentra la LCD en el Arduino, en este caso maneje los pines Analogos para tener mas espacio en los digitales.
Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS); //se crea el teclado

void setup(){ //El Setup es laoperacion que realiza siempre que se inicia y cumple una funcion 
  Serial.begin(9600);
 

  keypad.addEventListener(keypadEvent);
  pinMode(ledWrong, OUTPUT); // Definimos los led en los pines como salidas para que enciendan correctamente.
  pinMode(ledRigth, OUTPUT);
  pinMode(ledPress, OUTPUT);

  digitalWrite(ledWrong, HIGH);
  digitalWrite(ledRigth, LOW);

  lcd.begin(16, 2);

  lcd.setCursor(0, 0);    // Pantalla Inicial
  lcd.clear();
  lcd.print("   BIENVENIDO  ");
  lcd.setCursor(0, 1);
  lcd.print(" INGRESE SU PIN   ");

  Wire.begin(); // Inicia el puerto I2C
RTC.begin(); // Inicia la comunicación con el RTC
//RTC.adjust(DateTime(__DATE__, __TIME__)); // Establece la fecha y hora (Comentar una vez establecida la hora)

}// fin setup

void loop(){
keypad.getKey();
}
void HoraFecha(){
DateTime now = RTC.now(); // Obtiene la fecha y hora del RTC   

Serial.println("Fecha:");
Serial.print(now.year(), DEC); // Año
Serial.print('/');
Serial.print(now.month(), DEC); // Mes
Serial.print('/');
Serial.print(now.day(), DEC); // Dia
Serial.print(' ');
Serial.println("  ");
Serial.println("Hora:");
Serial.print(now.hour(), DEC); // Horas
Serial.print(':');
Serial.print(now.minute(), DEC); // Minutos
Serial.print(':');
Serial.print(now.second(), DEC); // Segundos
Serial.println();
Serial.println("-------------------------------------");
lcd.setCursor(0,0);
lcd.print("Fecha: ");
lcd.print(now.year(), DEC);
lcd.print("/");
lcd.print(now.month(), DEC);
lcd.print("/");
lcd.print(now.day(), DEC);
lcd.print("   ");
lcd.setCursor(0,1);
lcd.print("Hora: ");
lcd.print(now.hour(), DEC);
lcd.print(":");
lcd.print(now.minute(), DEC);
}

void keypadEvent(KeypadEvent eKey){


  switch (keypad.getState()){
    case PRESSED:
    int i;
    for( i = 1; i <= 1; i++ ){
    digitalWrite(ledPress, HIGH);  
    delay(100);            
    digitalWrite(ledPress, LOW);  
    delay(100);      
  
}   // for 
 

  S=7;                              // Sonido al presionar una tecla
  w=100;
  playPress();
  noTone(S);
 
switch (eKey){
 
default:
passw=passw+1;                           // Las contraseñas.
password.append(eKey);
password1.append(eKey);
password2.append(eKey);
password3.append(eKey);
password4.append(eKey);
password5.append(eKey);
password6.append(eKey);
password7.append(eKey);
password8.append(eKey);
password9.append(eKey);
password10.append(eKey);
password11.append(eKey);
password12.append(eKey);
password13.append(eKey);
password14.append(eKey);
password15.append(eKey);
password16.append(eKey);
password17.append(eKey);
password18.append(eKey);
password19.append(eKey);
password20.append(eKey);
password21.append(eKey);
password22.append(eKey);
password23.append(eKey);
password24.append(eKey);
password25.append(eKey);
password26.append(eKey);
password27.append(eKey);
password28.append(eKey);
password29.append(eKey);
password30.append(eKey);
password31.append(eKey);
password32.append(eKey);
password33.append(eKey);
password34.append(eKey);
password35.append(eKey);
password36.append(eKey);
password37.append(eKey);
password38.append(eKey);
password39.append(eKey);
password40.append(eKey);
password41.append(eKey);
password42.append(eKey);
password43.append(eKey);
password44.append(eKey);
}
 
if(passw == 1)                           // -Si- Condicion en la introduccion de la clave.
{
lcd.clear();
lcd.setCursor(1,0);
lcd.print("   PASSWORD ");
lcd.setCursor(0,1);
lcd.print("*_");
}
if(passw == 2)
{
lcd.clear();
lcd.setCursor(1,0);
lcd.print("   PASSWORD ");
lcd.setCursor(0,1);
lcd.print("**_");
}
if(passw == 3)
{
lcd.clear();
lcd.setCursor(1,0);
lcd.print("   PASSWORD ");
lcd.setCursor(0,1);
lcd.print("***_");
}
if(passw == 4)
{
lcd.clear();
lcd.setCursor(1,0);
lcd.print("   PASSWORD ");
lcd.setCursor(0,1);
lcd.print("****_");
}
if(passw == 5)
{
lcd.clear();
lcd.setCursor(1,0);
lcd.print("   PASSWORD ");
lcd.setCursor(0,1);
lcd.print("*****_");
}
if(passw == 6)
{
lcd.clear();
lcd.setCursor(1,0);
lcd.print("   PASSWORD ");
lcd.setCursor(0,1);
lcd.print("******");
}

 
if(passw == PASS)           // Si, la contraseña cuenta con los digitos (6) se validará o no según las claves asignadas.
{
delay(250);
checkPasswordd();         //check
passw = 0;
}
}
}

void checkPasswordd()
{
    if (password.evaluate()){                     //  Primera Contraseña (0)
    int i;
    for( i = 1; i <= 3; i++ ){
    digitalWrite(ledPress, HIGH);  
    delay(120);            
    digitalWrite(ledPress, LOW);  
    delay(70);      
}    
    passw = 0;
    reset_password();

Serial.println("-------------------------------------");
    Serial.println("BETSY AGUALIMPIA ZORRILLA");
          
  
    digitalWrite(ledWrong, LOW);
    digitalWrite(ledRigth, HIGH);
 
    lcd.clear();
    lcd.setCursor(0,0);
    delay(1000);   
    lcd.print("ASSIST: OK");    
    lcd.setCursor(0,1);
    lcd.print("HOLA BETSY A.");

    S=7;                          // Sonido que indica que fue correcto el PIN 
    w=100;
    playBueno();
    noTone(S);
    delay(3500);
    digitalWrite(ledRigth, LOW);
    digitalWrite(ledWrong, HIGH);
     lcd.clear();
  HoraFecha();
  delay(3500);

       
    setup(); // al inicio
 
  } else if(password1.evaluate()){              // Si no se ingresa la (0) se leerá la (1).

  int i;
  for( i = 1; i <= 3; i++ ){
  digitalWrite(ledPress, HIGH);  
  delay(120);            
  digitalWrite(ledPress, LOW);  
  delay(70);      
}    
    passw = 0;
    reset_password();
    Serial.println("-------------------------------------");
    Serial.println("ANAYANSI ALZATE CEBALLOS");    
 
    digitalWrite(ledWrong, LOW);
    digitalWrite(ledRigth, HIGH);
 
    lcd.clear();
    lcd.setCursor(0,0);
    delay(1000);
    lcd.print("ASSIST: OK");    
    lcd.setCursor(0,1);
    lcd.print("HOLA ANAYANSI A."); 
    S=7;                                              // Sonido
    w=100;
    playBueno();
    noTone(S);
    delay(3500);
    digitalWrite(ledRigth, LOW);
    digitalWrite(ledWrong, HIGH);
    lcd.clear();
  HoraFecha(); 
  delay(3500);      
 setup(); // al inicio  

    
    }  else if(password2.evaluate()){       // Si no se ingresa la (0), (1), leerá la (2).

  int i;
  for( i = 1; i <= 3; i++ ){
  digitalWrite(ledPress, HIGH);  
  delay(120);            
  digitalWrite(ledPress, LOW);  
  delay(70);      
}    
   passw = 0;
   reset_password();
    Serial.println("-------------------------------------");
    Serial.println("ADRIANA BARONA VALENCIA");    
 
    digitalWrite(ledWrong, LOW);
    digitalWrite(ledRigth, HIGH);
 
    lcd.clear();
    lcd.setCursor(0,0);
    delay(1000);
    lcd.print("ASSIST: OK");    
    lcd.setCursor(0,1);
    lcd.print("HOLA ADRIANA B."); 
    S=7;                            // Sonido
    w=100;
    playBueno();
    noTone(S);
    delay(3500);
    digitalWrite(ledRigth, LOW);
    digitalWrite(ledWrong, HIGH);
        lcd.clear();
   HoraFecha();     
    delay(3500);
    setup(); // al inicio  
  
}else if(password3.evaluate()){           // Del mismo modo si no lee las anteriores, leerá la (3).

  int i;    
  for( i = 1; i <= 3; i++ ){
  digitalWrite(ledPress, HIGH);  
  delay(120);            
  digitalWrite(ledPress, LOW);  
  delay(70);      
}    
   passw = 0;
   reset_password();
    Serial.println("-------------------------------------");
    Serial.println("CLAUDIA JIMENA BOLAÑOS BENAVIDES");    
 
    digitalWrite(ledWrong, LOW);
    digitalWrite(ledRigth, HIGH);
 
    lcd.clear();
    lcd.setCursor(0,0);
    delay(1000);
    lcd.print("ASSIST: OK");    
    lcd.setCursor(0,1);
    lcd.print("HOLA,CLAUDIA B."); 
    S=7;                        //Sonido
    w=100;
    playBueno();
    noTone(S);
    delay(3500);
    digitalWrite(ledRigth, LOW);
    digitalWrite(ledWrong, HIGH);
        lcd.clear();
     HoraFecha();
     delay(3500);
    setup(); // al inicio  

}else if(password4.evaluate()){            // Leerá la (4).

  int i;
  for( i = 1; i <= 3; i++ ){
  digitalWrite(ledPress, HIGH);  
  delay(120);            
  digitalWrite(ledPress, LOW);  
  delay(70);      
}
  passw = 0;
  reset_password();
    Serial.println("-------------------------------------");
    Serial.println("JHON ALEX BONILLA GALLEGO");    
 
    digitalWrite(ledWrong, LOW);
    digitalWrite(ledRigth, HIGH);
 
    lcd.clear();
    lcd.setCursor(0,0);
    delay(1000);
    lcd.print("ASSIST: OK");    
    lcd.setCursor(0,1);
    lcd.print("HOLA JHON ALEX B."); 
    S=7;                          //Sonido
    w=100;
    playBueno();
    noTone(S);
    delay(3500);
    digitalWrite(ledRigth, LOW);
    digitalWrite(ledWrong, HIGH);
        lcd.clear();
    HoraFecha();   
      delay(3500);
    setup(); // al inicio  

}else if(password5.evaluate()){            // Leerá la (4).

  int i;
  for( i = 1; i <= 3; i++ ){
  digitalWrite(ledPress, HIGH);  
  delay(120);            
  digitalWrite(ledPress, LOW);  
  delay(70);      
}    
   passw = 0;
   reset_password();
    Serial.println("-------------------------------------");
    Serial.println("ANA MARIA CARDONA OSPINA");    
 
    digitalWrite(ledWrong, LOW);
    digitalWrite(ledRigth, HIGH);
 
    lcd.clear();
    lcd.setCursor(0,0);
    delay(1000);
    lcd.print("ASSIST: OK");    
    lcd.setCursor(0,1);
    lcd.print("HOLA,ANA MARIA C."); 
    
    S=7;                          //Sonido
    w=100;
    playBueno();
    noTone(S);
    delay(3500);
    digitalWrite(ledRigth, LOW);
    digitalWrite(ledWrong, HIGH);
        lcd.clear();
   HoraFecha();    
      delay(3500);
    setup(); // al inicio  

     }  else if(password6.evaluate()){       // Si no se ingresa la (0), (1), leerá la (2).

  int i;
  for( i = 1; i <= 3; i++ ){
  digitalWrite(ledPress, HIGH);  
  delay(120);            
  digitalWrite(ledPress, LOW);  
  delay(70);      
}    
   passw = 0;
   reset_password();
    Serial.println("-------------------------------------");
    Serial.println("MANUEL ANDRES CAICEDO CASTRO");    
 
    digitalWrite(ledWrong, LOW);
    digitalWrite(ledRigth, HIGH);
 
    lcd.clear();
    lcd.setCursor(0,0);
    delay(1000);
    lcd.print("ASSIST: OK");    
    lcd.setCursor(0,1);
    lcd.print("HOLA,MANUEL C."); 
    S=7;                            // Sonido
    w=100;
    playBueno();
    noTone(S);
    delay(3500);
    digitalWrite(ledRigth, LOW);
    digitalWrite(ledWrong, HIGH);
       
    lcd.clear();
  HoraFecha();     
      delay(3500);
    setup(); // al inicio  

}  else if(password7.evaluate()){       // Si no se ingresa la (0), (1), leerá la (2).

  int i;
  for( i = 1; i <= 3; i++ ){
  digitalWrite(ledPress, HIGH);  
  delay(120);            
  digitalWrite(ledPress, LOW);  
  delay(70);      
}    
   passw = 0;
   reset_password();
    Serial.println("-------------------------------------");
    Serial.println("ERIKA CASTILLO MORENO");    
 
    digitalWrite(ledWrong, LOW);
    digitalWrite(ledRigth, HIGH);
 
    lcd.clear();
    lcd.setCursor(0,0);
    delay(1000);
    lcd.print("ASSIST: OK");    
    lcd.setCursor(0,1);
    lcd.print("HOLA,ERIKA C."); 
    S=7;                            // Sonido
    w=100;
    playBueno();
    noTone(S);
    delay(3500);
    digitalWrite(ledRigth, LOW);
    digitalWrite(ledWrong, HIGH);
        lcd.clear();
   
  HoraFecha();     
      delay(3500);
    setup(); // al inicio  

}  else if(password8.evaluate()){       // Si no se ingresa la (0), (1), leerá la (2).

  int i;
  for( i = 1; i <= 3; i++ ){
  digitalWrite(ledPress, HIGH);  
  delay(120);            
  digitalWrite(ledPress, LOW);  
  delay(70);      
}    
   passw = 0;
   reset_password();
    Serial.println("-------------------------------------");
    Serial.println("OSCAR EDUARDO CORRALES GRAJALES");    
 
    digitalWrite(ledWrong, LOW);
    digitalWrite(ledRigth, HIGH);
 
    lcd.clear();
    lcd.setCursor(0,0);
    delay(1000);
    lcd.print("ASSIST: OK");    
    lcd.setCursor(0,1);
    lcd.print("HOLA,OSCAR C."); 
    S=7;                            // Sonido
    w=100;
    playBueno();
    noTone(S);
    delay(3500);
    digitalWrite(ledRigth, LOW);
    digitalWrite(ledWrong, HIGH);
       
    lcd.clear();
   HoraFecha();    
      delay(3500);
    setup(); // al inicio  

}  else if(password9.evaluate()){       // Si no se ingresa la (0), (1), leerá la (2).

  int i;
  for( i = 1; i <= 3; i++ ){
  digitalWrite(ledPress, HIGH);  
  delay(120);            
  digitalWrite(ledPress, LOW);  
  delay(70);      
}    
   passw = 0;
   reset_password();

    Serial.println("-------------------------------------");
    Serial.println("CLAUDIA JUDITH CORTES SANDOVAL");    
 
    digitalWrite(ledWrong, LOW);
    digitalWrite(ledRigth, HIGH);
 
    lcd.clear();
    lcd.setCursor(0,0);
    delay(1000);
    lcd.print("ASSIST: OK");    
    lcd.setCursor(0,1);
    lcd.print("HOLA,CLAUDIA J.C."); 
    S=7;                            // Sonido
    w=100;
    playBueno();
    noTone(S);
    delay(3500);
    digitalWrite(ledRigth, LOW);
    digitalWrite(ledWrong, HIGH);
       
    lcd.clear();
    HoraFecha();   
      delay(3500);
    setup(); // al inicio  
    
}  else if(password10.evaluate()){       // Si no se ingresa la (0), (1), leerá la (2).

  int i;
  for( i = 1; i <= 3; i++ ){
  digitalWrite(ledPress, HIGH);  
  delay(120);            
  digitalWrite(ledPress, LOW);  
  delay(70);      
}    
   passw = 0;
   reset_password();
    Serial.println("-------------------------------------");
    Serial.println("WILSON ESCOBAR RIASCOS");    
 
    digitalWrite(ledWrong, LOW);
    digitalWrite(ledRigth, HIGH);
 
    lcd.clear();
    lcd.setCursor(0,0);
    delay(1000);
    lcd.print("ASSIST: OK");    
    lcd.setCursor(0,1);
    lcd.print("HOLA,WILSON E."); 
    S=7;                            // Sonido
    w=100;
    playBueno();
noTone(S);
    delay(3500);
    digitalWrite(ledRigth, LOW);
    digitalWrite(ledWrong, HIGH);
       
    lcd.clear();
  HoraFecha();     
      delay(3500);
    setup(); // al inicio  

}  else if(password11.evaluate()){       // Si no se ingresa la (0), (1), leerá la (2).

    int i;
for( i = 1; i <= 3; i++ ){
  digitalWrite(ledPress, HIGH);  
  delay(120);            
  digitalWrite(ledPress, LOW);  
  delay(70);      
}    
    passw = 0;
   reset_password();
    Serial.println("-------------------------------------");
    Serial.println("SLLEY GALLEGO");    
 
    digitalWrite(ledWrong, LOW);
    digitalWrite(ledRigth, HIGH);
 
   lcd.clear();
    lcd.setCursor(0,0);
    delay(1000);
    lcd.print("ASSIST: OK");    
    lcd.setCursor(0,1);
    lcd.print("HOLA,SLLEY G."); 
              S=7;                            // Sonido
w=100;
playBueno();
noTone(S);
    delay(3500);
    digitalWrite(ledRigth, LOW);
    digitalWrite(ledWrong, HIGH);
        lcd.clear();
   
   HoraFecha();    
      delay(3500);
    setup(); // al inicio  

}  else if(password12.evaluate()){       // Si no se ingresa la (0), (1), leerá la (2).

    int i;
for( i = 1; i <= 3; i++ ){
  digitalWrite(ledPress, HIGH);  
  delay(120);            
  digitalWrite(ledPress, LOW);  
  delay(70);      
}    
    passw = 0;
   reset_password();
    Serial.println("-------------------------------------");
    Serial.println("LIZETH GARCIA CAICEDO");    
 
    digitalWrite(ledWrong, LOW);
    digitalWrite(ledRigth, HIGH);
 
   lcd.clear();
    lcd.setCursor(0,0);
    delay(1000);
    lcd.print("ASSIST: OK");    
    lcd.setCursor(0,1);
    lcd.print("HOLA,LIZETH G."); 
              S=7;                            // Sonido
w=100;
playBueno();
noTone(S);
    delay(3500);
    digitalWrite(ledRigth, LOW);
    digitalWrite(ledWrong, HIGH);
       
    lcd.clear();
    HoraFecha();   
      delay(3500);
    setup(); // al inicio  

}  else if(password13.evaluate()){       // Si no se ingresa la (0), (1), leerá la (2).

    int i;
for( i = 1; i <= 3; i++ ){
  digitalWrite(ledPress, HIGH);  
  delay(120);            
  digitalWrite(ledPress, LOW);  
  delay(70);      
}    
    passw = 0;
   reset_password();
    Serial.println("-------------------------------------");
    Serial.println("CAMILA ANDREA GARCIA CORZO");    
 
    digitalWrite(ledWrong, LOW);
    digitalWrite(ledRigth, HIGH);
 
   lcd.clear();
    lcd.setCursor(0,0);
    delay(1000);
    lcd.print("ASSIST: OK");    
    lcd.setCursor(0,1);
    lcd.print("HOLA,CAMILA G."); 
              S=7;                            // Sonido
w=100;
playBueno();
noTone(S);
    delay(3500);
    digitalWrite(ledRigth, LOW);
    digitalWrite(ledWrong, HIGH);
       
    lcd.clear();
  HoraFecha();     
      delay(3500);
    setup(); // al inicio  

}  else if(password14.evaluate()){       // Si no se ingresa la (0), (1), leerá la (2).

    int i;
for( i = 1; i <= 3; i++ ){
  digitalWrite(ledPress, HIGH);  
  delay(120);            
  digitalWrite(ledPress, LOW);  
  delay(70);      
}    
    passw = 0;
   reset_password();
    Serial.println("-------------------------------------");
    Serial.println("LINA MARIA GIRALDO CARDONA");    
 
    digitalWrite(ledWrong, LOW);
    digitalWrite(ledRigth, HIGH);
 
   lcd.clear();
    lcd.setCursor(0,0);
    delay(1000);
    lcd.print("ASSIST: OK");    
    lcd.setCursor(0,1);
    lcd.print("HOLA,LINA G."); 
              S=7;                            // Sonido
w=100;
playBueno();
noTone(S);
    delay(3500);
    digitalWrite(ledRigth, LOW);
    digitalWrite(ledWrong, HIGH);
       
    lcd.clear();
       HoraFecha();
      delay(3500);
    setup(); // al inicio  

}  else if(password15.evaluate()){       // Si no se ingresa la (0), (1), leerá la (2).

    int i;
for( i = 1; i <= 3; i++ ){
  digitalWrite(ledPress, HIGH);  
  delay(120);            
  digitalWrite(ledPress, LOW);  
  delay(70);      
}    
    passw = 0;
   reset_password();
    Serial.println("-------------------------------------");
    Serial.println("CAROLINA GRIMALDI CASTILLO");    
 
    digitalWrite(ledWrong, LOW);
    digitalWrite(ledRigth, HIGH);
 
   lcd.clear();
    lcd.setCursor(0,0);
    delay(1000);
    lcd.print("ASSIST: OK");    
    lcd.setCursor(0,1);
    lcd.print("HOLA,CAROLINA G."); 
              S=7;                            // Sonido
w=100;
playBueno();
noTone(S);
    delay(3500);
    digitalWrite(ledRigth, LOW);
    digitalWrite(ledWrong, HIGH);
        lcd.clear();
   
    HoraFecha();   
      delay(3500);
    setup(); // al inicio  

}  else if(password16.evaluate()){       // Si no se ingresa la (0), (1), leerá la (2).

    int i;
for( i = 1; i <= 3; i++ ){
  digitalWrite(ledPress, HIGH);  
  delay(120);            
  digitalWrite(ledPress, LOW);  
  delay(70);      
}    
    passw = 0;
   reset_password();
    Serial.println("-------------------------------------");
    Serial.println("PAULA ANDRE HERNANDEZ QUICENO");    
 
    digitalWrite(ledWrong, LOW);
    digitalWrite(ledRigth, HIGH);
 
   lcd.clear();
    lcd.setCursor(0,0);
    delay(1000);
    lcd.print("ASSIST: OK");    
    lcd.setCursor(0,1);
    lcd.print("PAULA H."); 
              S=7;                            // Sonido
w=100;
playBueno();
noTone(S);
    delay(3500);
    digitalWrite(ledRigth, LOW);
    digitalWrite(ledWrong, HIGH);
       
    lcd.clear();
    HoraFecha();   
      delay(3500);
    setup(); // al inicio  

}  else if(password17.evaluate()){       // Si no se ingresa la (0), (1), leerá la (2).

    int i;
for( i = 1; i <= 3; i++ ){
  digitalWrite(ledPress, HIGH);  
  delay(120);            
  digitalWrite(ledPress, LOW);  
  delay(70);      
}    
    passw = 0;
   reset_password();
    Serial.println("-------------------------------------");
    Serial.println("GINA MARIA MARIN GOMEZ");    
 
    digitalWrite(ledWrong, LOW);
    digitalWrite(ledRigth, HIGH);
 
   lcd.clear();
    lcd.setCursor(0,0);
    delay(1000);
    lcd.print("ASSIST: OK");    
    lcd.setCursor(0,1);
    lcd.print("HOLA,GINA M."); 
              S=7;                            // Sonido
w=100;
playBueno();
noTone(S);
    delay(3500);
    digitalWrite(ledRigth, LOW);
    digitalWrite(ledWrong, HIGH);
        lcd.clear();
   
       HoraFecha();
      delay(3500);
    setup(); // al inicio  

}  else if(password18.evaluate()){       // Si no se ingresa la (0), (1), leerá la (2).

    int i;
for( i = 1; i <= 3; i++ ){
  digitalWrite(ledPress, HIGH);  
  delay(120);            
  digitalWrite(ledPress, LOW);  
  delay(70);      
}    
    passw = 0;
   reset_password();
    Serial.println("-------------------------------------");
    Serial.println("JHON FABER MARQUEZ ZULUAGA");    
 
    digitalWrite(ledWrong, LOW);
    digitalWrite(ledRigth, HIGH);
 
   lcd.clear();
    lcd.setCursor(0,0);
    delay(1000);
    lcd.print("ASSIST: OK");    
    lcd.setCursor(0,1);
    lcd.print("HOLA,JHON FABER"); 
              S=7;                            // Sonido
w=100;
playBueno();
noTone(S);
    delay(3500);
    digitalWrite(ledRigth, LOW);
    digitalWrite(ledWrong, HIGH);
        lcd.clear();
   
  HoraFecha();     
      delay(3500);
    setup(); // al inicio  

}  else if(password19.evaluate()){       // Si no se ingresa la (0), (1), leerá la (2).

    int i;
for( i = 1; i <= 3; i++ ){
  digitalWrite(ledPress, HIGH);  
  delay(120);            
  digitalWrite(ledPress, LOW);  
  delay(70);      
}    
    passw = 0;
   reset_password();
    Serial.println("-------------------------------------");
    Serial.println("MARIA LUISA MINA JAVELA");    
 
    digitalWrite(ledWrong, LOW);
    digitalWrite(ledRigth, HIGH);
 
   lcd.clear();
    lcd.setCursor(0,0);
    delay(1000);
    lcd.print("ASSIST: OK");    
    lcd.setCursor(0,1);
    lcd.print("HOLA,MARIA LUISA"); 
              S=7;                            // Sonido
w=100;
playBueno();
noTone(S);
    delay(3500);
    digitalWrite(ledRigth, LOW);
    digitalWrite(ledWrong, HIGH);
        lcd.clear();
   
     HoraFecha();  
      delay(3500);
    setup(); // al inicio  

}  else if(password20.evaluate()){       // Si no se ingresa la (0), (1), leerá la (2).

    int i;
for( i = 1; i <= 3; i++ ){
  digitalWrite(ledPress, HIGH);  
  delay(120);            
  digitalWrite(ledPress, LOW);  
  delay(70);      
}    
    passw = 0;
   reset_password();
    Serial.println("-------------------------------------");
    Serial.println("DEYSI MARIN VELASQUEZ");    
 
    digitalWrite(ledWrong, LOW);
    digitalWrite(ledRigth, HIGH);
 
   lcd.clear();
    lcd.setCursor(0,0);
    delay(1000);
    lcd.print("ASSIST: OK");    
    lcd.setCursor(0,1);
    lcd.print("HOLA,DEYSI M."); 
              S=7;                            // Sonido
w=100;
playBueno();
noTone(S);
    delay(3500);
    digitalWrite(ledRigth, LOW);
    digitalWrite(ledWrong, HIGH);
       
    lcd.clear();
    HoraFecha();   
      delay(3500);
    setup(); // al inicio  

}  else if(password21.evaluate()){       // Si no se ingresa la (0), (1), leerá la (2).

    int i;
for( i = 1; i <= 3; i++ ){
  digitalWrite(ledPress, HIGH);  
  delay(120);            
  digitalWrite(ledPress, LOW);  
  delay(70);      
}    
    passw = 0;
   reset_password();
    Serial.println("-------------------------------------");
    Serial.println("CARMEN ELENA OBANDO PEREA");    
 
    digitalWrite(ledWrong, LOW);
    digitalWrite(ledRigth, HIGH);
 
   lcd.clear();
    lcd.setCursor(0,0);
    delay(1000);
    lcd.print("ASSIST: OK");    
    lcd.setCursor(0,1);
    lcd.print("HOLA,CARMEN O."); 
              S=7;                            // Sonido
w=100;
playBueno();
noTone(S);
    delay(3500);
    digitalWrite(ledRigth, LOW);
    digitalWrite(ledWrong, HIGH);
       
    lcd.clear();
    HoraFecha();   
      delay(3500);
    setup(); // al inicio  

}  else if(password22.evaluate()){       // Si no se ingresa la (0), (1), leerá la (2).

    int i;
for( i = 1; i <= 3; i++ ){
  digitalWrite(ledPress, HIGH);  
  delay(120);            
  digitalWrite(ledPress, LOW);  
  delay(70);      
}    
    passw = 0;
   reset_password();
    Serial.println("-------------------------------------");
    Serial.println("MAYRA ALEJANDRA OROZCO OSPINA");    
 
    digitalWrite(ledWrong, LOW);
    digitalWrite(ledRigth, HIGH);
 
   lcd.clear();
    lcd.setCursor(0,0);
    delay(1000);
    lcd.print("ASSIST: OK");    
    lcd.setCursor(0,1);
    lcd.print("HOLA,MAYRA O."); 
              S=7;                            // Sonido
w=100;
playBueno();
noTone(S);
    delay(3500);
    digitalWrite(ledRigth, LOW);
    digitalWrite(ledWrong, HIGH);
       
    lcd.clear();
  HoraFecha();     
      delay(3500);
    setup(); // al inicio  

}  else if(password23.evaluate()){       // Si no se ingresa la (0), (1), leerá la (2).

    int i;
for( i = 1; i <= 3; i++ ){
  digitalWrite(ledPress, HIGH);  
  delay(120);            
  digitalWrite(ledPress, LOW);  
  delay(70);      
}    
    passw = 0;
   reset_password();
    Serial.println("-------------------------------------");
    Serial.println("PAOLA ANDREA ORTIZ JARAMILLO");    
 
    digitalWrite(ledWrong, LOW);
    digitalWrite(ledRigth, HIGH);
 
   lcd.clear();
    lcd.setCursor(0,0);
    delay(1000);
    lcd.print("ASSIST: OK");    
    lcd.setCursor(0,1);
    lcd.print("HOLA,PAOLA O."); 
              S=7;                            // Sonido
w=100;
playBueno();
noTone(S);
    delay(3500);
    digitalWrite(ledRigth, LOW);
    digitalWrite(ledWrong, HIGH);
        lcd.clear();
   HoraFecha();
       delay(3500);
      
    setup(); // al inicio  

}  else if(password24.evaluate()){       // Si no se ingresa la (0), (1), leerá la (2).

    int i;
for( i = 1; i <= 3; i++ ){
  digitalWrite(ledPress, HIGH);  
  delay(120);            
  digitalWrite(ledPress, LOW);  
  delay(70);      
}    
    passw = 0;
   reset_password();
    Serial.println("-------------------------------------");
    Serial.println("NHORA ELENA PADILLA QUINTERO");    
 
    digitalWrite(ledWrong, LOW);
    digitalWrite(ledRigth, HIGH);
 
   lcd.clear();
    lcd.setCursor(0,0);
    delay(1000);
    lcd.print("ASSIST: OK");    
    lcd.setCursor(0,1);
    lcd.print("HOLA,NHORA P."); 
              S=7;                            // Sonido
w=100;
playBueno();
noTone(S);
    delay(3500);
    digitalWrite(ledRigth, LOW);
    digitalWrite(ledWrong, HIGH);
        lcd.clear();
   HoraFecha();
       delay(3500);
      
    setup(); // al inicio  

}  else if(password25.evaluate()){       // Si no se ingresa la (0), (1), leerá la (2).

    int i;
for( i = 1; i <= 3; i++ ){
  digitalWrite(ledPress, HIGH);  
  delay(120);            
  digitalWrite(ledPress, LOW);  
  delay(70);      
}    
    passw = 0;
   reset_password();
    Serial.println("-------------------------------------");
    Serial.println("MARIO FERNANDO RODRIGUEZ QUIÑONES");    
 
    digitalWrite(ledWrong, LOW);
    digitalWrite(ledRigth, HIGH);
 
   lcd.clear();
    lcd.setCursor(0,0);
    delay(1000);
    lcd.print("ASSIST: OK");    
    lcd.setCursor(0,1);
    lcd.print("HOLA,MARIO R."); 
              S=7;                            // Sonido
w=100;
playBueno();
noTone(S);
    delay(3500);
    digitalWrite(ledRigth, LOW);
    digitalWrite(ledWrong, HIGH);
        lcd.clear();
   HoraFecha();
       delay(3500);
      
    setup(); // al inicio  

}  else if(password26.evaluate()){       // Si no se ingresa la (0), (1), leerá la (2).

    int i;
for( i = 1; i <= 3; i++ ){
  digitalWrite(ledPress, HIGH);  
  delay(120);            
  digitalWrite(ledPress, LOW);  
  delay(70);      
}    
    passw = 0;
   reset_password();
    Serial.println("-------------------------------------");
    Serial.println("BORIS RIVERA RODRIGUEZ");    
 
    digitalWrite(ledWrong, LOW);
    digitalWrite(ledRigth, HIGH);
 
   lcd.clear();
    lcd.setCursor(0,0);
    delay(1000);
    lcd.print("ASSIST: OK");    
    lcd.setCursor(0,1);
    lcd.print("HOLA,BORIS R."); 
              S=7;                            // Sonido
w=100;
playBueno();
noTone(S);
    delay(3500);
    digitalWrite(ledRigth, LOW);
    digitalWrite(ledWrong, HIGH);
        lcd.clear();
   HoraFecha();
   delay(5000);
       delay(3500);
      
    setup(); // al inicio  

}  else if(password27.evaluate()){       // Si no se ingresa la (0), (1), leerá la (2).

    int i;
for( i = 1; i <= 3; i++ ){
  digitalWrite(ledPress, HIGH);  
  delay(120);            
  digitalWrite(ledPress, LOW);  
  delay(70);      
}    
    passw = 0;
   reset_password();
    Serial.println("-------------------------------------");
    Serial.println("GUSTAVO ADOLFO TABARES GALLEGO");    
 
    digitalWrite(ledWrong, LOW);
    digitalWrite(ledRigth, HIGH);
 
   lcd.clear();
    lcd.setCursor(0,0);
    delay(1000);
    lcd.print("ASSIST: OK");    
    lcd.setCursor(0,1);
    lcd.print("HOLA,GUSTAVO T."); 
              S=7;                            // Sonido
w=100;
playBueno();
noTone(S);
    delay(3500);
    digitalWrite(ledRigth, LOW);
    digitalWrite(ledWrong, HIGH);
        lcd.clear();
   HoraFecha();
       delay(3500);
      
    setup(); // al inicio  

}  else if(password28.evaluate()){       // Si no se ingresa la (0), (1), leerá la (2).

    int i;
for( i = 1; i <= 3; i++ ){
  digitalWrite(ledPress, HIGH);  
  delay(120);            
  digitalWrite(ledPress, LOW);  
  delay(70);      
}    
    passw = 0;
   reset_password();
    Serial.println("-------------------------------------");
    Serial.println("ERICKA MARIA VENTE VALENCIA");    
 
    digitalWrite(ledWrong, LOW);
    digitalWrite(ledRigth, HIGH);
 
   lcd.clear();
    lcd.setCursor(0,0);
    delay(1000);
    lcd.print("ASSIST: OK");    
    lcd.setCursor(0,1);
    lcd.print("HOLA,ERICKA B. "); 
              S=7;                            // Sonido
w=100;
playBueno();
noTone(S);
    delay(3500);
    digitalWrite(ledRigth, LOW);
    digitalWrite(ledWrong, HIGH);
        lcd.clear();
   HoraFecha();
       delay(3500);
      
    setup(); // al inicio  

}  else if(password29.evaluate()){       // Si no se ingresa la (0), (1), leerá la (2).

    int i;
for( i = 1; i <= 3; i++ ){
  digitalWrite(ledPress, HIGH);  
  delay(120);            
  digitalWrite(ledPress, LOW);  
  delay(70);      
}    
    passw = 0;
   reset_password();
    Serial.println("-------------------------------------");
    Serial.println("MARTHA ISABEL ZAPATA");    
 
    digitalWrite(ledWrong, LOW);
    digitalWrite(ledRigth, HIGH);
 
   lcd.clear();
    lcd.setCursor(0,0);
    delay(1000);
    lcd.print("ASSIST: OK");    
    lcd.setCursor(0,1);
    lcd.print("HOLA,MARTHA I.Z."); 
              S=7;                            // Sonido
w=100;
playBueno();
noTone(S);
    delay(3500);
    digitalWrite(ledRigth, LOW);
    digitalWrite(ledWrong, HIGH);
        lcd.clear();
   HoraFecha();
       delay(3500);
      
    setup(); // al inicio  

}  else if(password30.evaluate()){       // Si no se ingresa la (0), (1), leerá la (2).

    int i;
for( i = 1; i <= 3; i++ ){
  digitalWrite(ledPress, HIGH);  
  delay(120);            
  digitalWrite(ledPress, LOW);  
  delay(70);      
}    
    passw = 0;
   reset_password();
    Serial.println("-------------------------------------");
    Serial.println("YOLANDA CERON");    
 
    digitalWrite(ledWrong, LOW);
    digitalWrite(ledRigth, HIGH);
 
   lcd.clear();
    lcd.setCursor(0,0);
    delay(1000);
    lcd.print("ASSIST: OK");    
    lcd.setCursor(0,1);
    lcd.print("HOLA,YOLANDA C."); 
              S=7;                            // Sonido
w=100;
playBueno();
noTone(S);
    delay(3500);
    digitalWrite(ledRigth, LOW);
    digitalWrite(ledWrong, HIGH);
        lcd.clear();
   HoraFecha();
       delay(3500);
      
    setup(); // al inicio  

}  else if(password31.evaluate()){       // Si no se ingresa la (0), (1), leerá la (2).

    int i;
for( i = 1; i <= 3; i++ ){
  digitalWrite(ledPress, HIGH);  
  delay(120);            
  digitalWrite(ledPress, LOW);  
  delay(70);      
}    
    passw = 0;
   reset_password();
    Serial.println("-------------------------------------");
    Serial.println("ARGENIS MENDEZ");    
 
    digitalWrite(ledWrong, LOW);
    digitalWrite(ledRigth, HIGH);
 
   lcd.clear();
    lcd.setCursor(0,0);
    delay(1000);
    lcd.print("ASSIST: OK");    
    lcd.setCursor(0,1);
    lcd.print("HOLA,ARGENIS M."); 
              S=7;                            // Sonido
w=100;
playBueno();
noTone(S);
    delay(3500);
    digitalWrite(ledRigth, LOW);
    digitalWrite(ledWrong, HIGH);
        lcd.clear();
   HoraFecha();
       delay(3500);
      
    setup(); // al inicio  

}  else if(password32.evaluate()){       // Si no se ingresa la (0), (1), leerá la (2).

    int i;
for( i = 1; i <= 3; i++ ){
  digitalWrite(ledPress, HIGH);  
  delay(120);            
  digitalWrite(ledPress, LOW);  
  delay(70);      
}    
    passw = 0;
   reset_password();
    Serial.println("-------------------------------------");
    Serial.println("DIANA MARCELA GRIJALBA CANTOR");    
 
    digitalWrite(ledWrong, LOW);
    digitalWrite(ledRigth, HIGH);
 
   lcd.clear();
    lcd.setCursor(0,0);
    delay(1000);
    lcd.print("ASSIST: OK");    
    lcd.setCursor(0,1);
    lcd.print("HOLA,DIANA G."); 
              S=7;                            // Sonido
w=100;
playBueno();
noTone(S);
    delay(3500);
    digitalWrite(ledRigth, LOW);
    digitalWrite(ledWrong, HIGH);
        lcd.clear();
   HoraFecha();
       delay(3500);
      
    setup(); // al inicio  

}  else if(password33.evaluate()){       // Si no se ingresa la (0), (1), leerá la (2).

    int i;
for( i = 1; i <= 3; i++ ){
  digitalWrite(ledPress, HIGH);  
  delay(120);            
  digitalWrite(ledPress, LOW);  
  delay(70);      
}    
    passw = 0;
   reset_password();
    Serial.println("-------------------------------------");
    Serial.println("OSCAR ALBERTO GALLEGO ALVAREZ");    
 
    digitalWrite(ledWrong, LOW);
    digitalWrite(ledRigth, HIGH);
 
   lcd.clear();
    lcd.setCursor(0,0);
    delay(1000);
    lcd.print("ASSIST: OK");    
    lcd.setCursor(0,1);
    lcd.print("HOLA,OSCAR G."); 
              S=7;                            // Sonido
w=100;
playBueno();
noTone(S);
    delay(3500);
    digitalWrite(ledRigth, LOW);
    digitalWrite(ledWrong, HIGH);
        lcd.clear();
   HoraFecha();
       delay(3500);
      
    setup(); // al inicio  

}  else if(password34.evaluate()){       // Si no se ingresa la (0), (1), leerá la (2).

    int i;
for( i = 1; i <= 3; i++ ){
  digitalWrite(ledPress, HIGH);  
  delay(120);            
  digitalWrite(ledPress, LOW);  
  delay(70);      
}    
    passw = 0;
   reset_password();
    Serial.println("-------------------------------------");
    Serial.println("EMMA DORIS MINA BALANTA");    
 
    digitalWrite(ledWrong, LOW);
    digitalWrite(ledRigth, HIGH);
 
   lcd.clear();
    lcd.setCursor(0,0);
    delay(1000);
    lcd.print("ASSIST: OK");    
    lcd.setCursor(0,1);
    lcd.print("HOLA,EMMA M."); 
              S=7;                            // Sonido
w=100;
playBueno();
noTone(S);
    delay(3500);
    digitalWrite(ledRigth, LOW);
    digitalWrite(ledWrong, HIGH);
        lcd.clear();
   HoraFecha();
       delay(3500);
      
    setup(); // al inicio  

}  else if(password35.evaluate()){       // Si no se ingresa la (0), (1), leerá la (2).

    int i;
for( i = 1; i <= 3; i++ ){
  digitalWrite(ledPress, HIGH);  
  delay(120);            
  digitalWrite(ledPress, LOW);  
  delay(70);      
}    
    passw = 0;
   reset_password();
    Serial.println("-------------------------------------");
    Serial.println("CELESTE RODRIGUEZ ESPAÑA");    
 
    digitalWrite(ledWrong, LOW);
    digitalWrite(ledRigth, HIGH);
 
   lcd.clear();
    lcd.setCursor(0,0);
    delay(1000);
    lcd.print("ASSIST: OK");    
    lcd.setCursor(0,1);
    lcd.print("HOLA,CELESTE R."); 
              S=7;                            // Sonido
w=100;
playBueno();
noTone(S);
    delay(3500);
    digitalWrite(ledRigth, LOW);
    digitalWrite(ledWrong, HIGH);
        lcd.clear();
   HoraFecha();
       
      delay(3500);
    setup(); // al inicio  

}  else if(password36.evaluate()){       // Si no se ingresa la (0), (1), leerá la (2).

    int i;
for( i = 1; i <= 3; i++ ){
  digitalWrite(ledPress, HIGH);  
  delay(120);            
  digitalWrite(ledPress, LOW);  
  delay(70);      
}    
    passw = 0;
   reset_password();
    Serial.println("-------------------------------------");
    Serial.println("SANDRA PATRICIA CAMBINDO");    
 
    digitalWrite(ledWrong, LOW);
    digitalWrite(ledRigth, HIGH);
 
   lcd.clear();
    lcd.setCursor(0,0);
    delay(1000);
    lcd.print("ASSIST: OK");    
    lcd.setCursor(0,1);
    lcd.print("HOLA,SANDRA C."); 
              S=7;                            // Sonido
w=100;
playBueno();
noTone(S);
    delay(3500);
    digitalWrite(ledRigth, LOW);
    digitalWrite(ledWrong, HIGH);
        lcd.clear();
   HoraFecha();
       delay(3500);
      
    setup(); // al inicio  

}  else if(password37.evaluate()){       // Si no se ingresa la (0), (1), leerá la (2).

    int i;
for( i = 1; i <= 3; i++ ){
  digitalWrite(ledPress, HIGH);  
  delay(120);            
  digitalWrite(ledPress, LOW);  
  delay(70);      
}    
    passw = 0;
   reset_password();
    Serial.println("-------------------------------------");
    Serial.println("EFRAIN GUERRERO CARDENAS");    
 
    digitalWrite(ledWrong, LOW);
    digitalWrite(ledRigth, HIGH);
 
   lcd.clear();
    lcd.setCursor(0,0);
    delay(1000);
    lcd.print("ASSIST: OK");    
    lcd.setCursor(0,1);
    lcd.print("HOLA,EFRAIN G."); 
              S=7;                            // Sonido
w=100;
playBueno();
noTone(S);
    delay(3500);
    digitalWrite(ledRigth, LOW);
    digitalWrite(ledWrong, HIGH);
        lcd.clear();
   HoraFecha();
       delay(3500);
      
    setup(); // al inicio  

}  else if(password38.evaluate()){       // Si no se ingresa la (0), (1), leerá la (2).

    int i;
for( i = 1; i <= 3; i++ ){
  digitalWrite(ledPress, HIGH);  
  delay(120);            
  digitalWrite(ledPress, LOW);  
  delay(70);      
}    
    passw = 0;
   reset_password();
    Serial.println("-------------------------------------");
    Serial.println("LORENA FERNANDEZ BARRERA");    
 
    digitalWrite(ledWrong, LOW);
    digitalWrite(ledRigth, HIGH);
 
   lcd.clear();
    lcd.setCursor(0,0);
    delay(1000);
    lcd.print("ASSIST: OK");    
    lcd.setCursor(0,1);
    lcd.print("HOLA,LORENA F."); 
              S=7;                            // Sonido
w=100;
playBueno();
noTone(S);
    delay(3500);
    digitalWrite(ledRigth, LOW);
    digitalWrite(ledWrong, HIGH);
        lcd.clear();
   HoraFecha();
       delay(3500);
      
    setup(); // al inicio  

}  else if(password39.evaluate()){       // Si no se ingresa la (0), (1), leerá la (2).

    int i;
for( i = 1; i <= 3; i++ ){
  digitalWrite(ledPress, HIGH);  
  delay(120);            
  digitalWrite(ledPress, LOW);  
  delay(70);      
}    
    passw = 0;
   reset_password();
    Serial.println("-------------------------------------");
    Serial.println("ALEJANDRINA MURILLO RAMOS");    
 
    digitalWrite(ledWrong, LOW);
    digitalWrite(ledRigth, HIGH);
 
   lcd.clear();
    lcd.setCursor(0,0);
    delay(1000);
    lcd.print("ASSIST: OK");    
    lcd.setCursor(0,1);
    lcd.print("HOLA,ALEJANDRINA M."); 
              S=7;                            // Sonido
w=100;
playBueno();
noTone(S);
    delay(3500);
    digitalWrite(ledRigth, LOW);
    digitalWrite(ledWrong, HIGH);
        lcd.clear();
   HoraFecha();
       delay(3500);
      
    setup(); // al inicio  

}  else if(password40.evaluate()){       // Si no se ingresa la (0), (1), leerá la (2).

    int i;
for( i = 1; i <= 3; i++ ){
  digitalWrite(ledPress, HIGH);  
  delay(120);            
  digitalWrite(ledPress, LOW);  
  delay(70);      
}    
    passw = 0;
   reset_password();
    Serial.println("-------------------------------------");
    Serial.println("ESTEBAN BETANCUR");    
 
    digitalWrite(ledWrong, LOW);
    digitalWrite(ledRigth, HIGH);
 
   lcd.clear();
    lcd.setCursor(0,0);
    delay(1000);
    lcd.print("ASSIST: OK");    
    lcd.setCursor(0,1);
    lcd.print("HOLA,ESTEBAN B."); 
              S=7;                            // Sonido
w=100;
playBueno();
noTone(S);
    delay(3500);
    digitalWrite(ledRigth, LOW);
    digitalWrite(ledWrong, HIGH);
        lcd.clear();
   HoraFecha();
       delay(3500);
      
    setup(); // al inicio  

}  else if(password41.evaluate()){       // Si no se ingresa la (0), (1), leerá la (2).

    int i;
for( i = 1; i <= 3; i++ ){
  digitalWrite(ledPress, HIGH);  
  delay(120);            
  digitalWrite(ledPress, LOW);  
  delay(70);      
}    
    passw = 0;
   reset_password();
    Serial.println("-------------------------------------");
    Serial.println("WILLIAM ANDRES GALLEGO MARMOLEJO");    
 
    digitalWrite(ledWrong, LOW);
    digitalWrite(ledRigth, HIGH);
 
   lcd.clear();
    lcd.setCursor(0,0);
    delay(1000);
    lcd.print("ASSIST: OK");    
    lcd.setCursor(0,1);
    lcd.print("HOLA,WILLAM A.G."); 
              S=7;                            // Sonido
w=100;
playBueno();
noTone(S);
    delay(3500);
    digitalWrite(ledRigth, LOW);
    digitalWrite(ledWrong, HIGH);
        lcd.clear();
   HoraFecha();
       delay(3500);
      
    setup(); // al inicio  

}  else if(password42.evaluate()){       // Si no se ingresa la (0), (1), leerá la (2).

    int i;
for( i = 1; i <= 3; i++ ){
  digitalWrite(ledPress, HIGH);  
  delay(120);            
  digitalWrite(ledPress, LOW);  
  delay(70);      
}    
    passw = 0;
   reset_password();
    Serial.println("-------------------------------------");
    Serial.println("HUMBERTO RODAS GUTIERREZ");    
 
    digitalWrite(ledWrong, LOW);
    digitalWrite(ledRigth, HIGH);
 
   lcd.clear();
    lcd.setCursor(0,0);
    delay(1000);
    lcd.print("ASSIST: OK");    
    lcd.setCursor(0,1);
    lcd.print("HOLA,HUMBERTO R."); 
              S=7;                            // Sonido
w=100;
playBueno();
noTone(S);
    delay(3500);
    digitalWrite(ledRigth, LOW);
    digitalWrite(ledWrong, HIGH);
        lcd.clear();
   
      HoraFecha(); 
      delay(3500);
    setup(); // al inicio  

}  else if(password43.evaluate()){       // Si no se ingresa la (0), (1), leerá la (2).

    int i;
for( i = 1; i <= 3; i++ ){
  digitalWrite(ledPress, HIGH);  
  delay(120);            
  digitalWrite(ledPress, LOW);  
  delay(70);      
}    
    passw = 0;
   reset_password();
    Serial.println("-------------------------------------");
    Serial.println("EMERSON ECHEVERRY OLIVEROS");    
 
    digitalWrite(ledWrong, LOW);
    digitalWrite(ledRigth, HIGH);
 
   lcd.clear();
    lcd.setCursor(0,0);
    delay(1000);
    lcd.print("ASSIST: OK");    
    lcd.setCursor(0,1);
    lcd.print("HOLA,EMERSON E."); 
              S=7;                            // Sonido
w=100;
playBueno();
noTone(S);
    delay(3500);
    digitalWrite(ledRigth, LOW);
    digitalWrite(ledWrong, HIGH);
        lcd.clear();
   HoraFecha();
   delay(3500);
       
      
    setup(); // al inicio  
}
else if(password44.evaluate()){              // Si no se ingresa la (0) se leerá la (1).

  int i;
  for( i = 1; i <= 3; i++ ){
  digitalWrite(ledPress, HIGH);  
  delay(120);            
  digitalWrite(ledPress, LOW);  
  delay(70);      
}    
    passw = 0;
    reset_password();
    Serial.println("-------------------------------------");
    Serial.println("ADMINISTRADOR");    
 
    digitalWrite(ledWrong, LOW);
    digitalWrite(ledRigth, HIGH);
 
    lcd.clear();
    lcd.setCursor(0,0);
    delay(1000);
    lcd.print("HOLA CREADOR");    
    lcd.setCursor(0,1);
    lcd.print("SR. VELEZ"); 
    S=7;                                              // Sonido
    w=100;
    playBueno();
    noTone(S);
    delay(3500);
    digitalWrite(ledRigth, LOW);
    digitalWrite(ledWrong, HIGH);
    lcd.clear();
  HoraFecha();       
  delay(3500);
 setup(); // al inicio  

    
    

}else  { // aqui va todo lo malo, es decir si no coincide con ninguna contraseña asignada, dará error y regresa al incio (setup).
int i;
for( i = 1; i <= 1; i++ )
{
  digitalWrite(ledPress, HIGH);  
  delay(300);            
  digitalWrite(ledPress, LOW);  
  delay(100);      
}  
    passw = 0;  

 
     digitalWrite(ledRigth, LOW);
    digitalWrite(ledWrong, LOW);
    delay(150);
    digitalWrite(ledRigth, LOW);
    digitalWrite(ledWrong, HIGH);
    delay(150);
    digitalWrite(ledRigth, LOW);
    digitalWrite(ledWrong, LOW);
    delay(150);
    digitalWrite(ledRigth, LOW);
    digitalWrite(ledWrong, HIGH);    
             
    lcd.clear();
    lcd.setCursor(0,1);
    lcd.print(" PIN INCORRECTO");
    reset_password();

     S=7;                                // Sonido que indica el "Incorrecto"
w=500;
playWrong();
noTone(S);
    
    delay(2000);


   
   
  setup(); // al inicio

  
  }

  
}// fin del metodocheck


void reset_password(){                                                         // Reseteos para que luego no considere las pass como incorrectas en un futuro.
    password1.reset(); // resetea password despues de entrada correcta    
    password.reset(); // resetea password despues de entrada correcta
    password2.reset(); // resetea password despues de entrada correcta
    password3.reset(); // resetea password despues de entrada correcta
    password4.reset(); // resetea password despues de entrada correcta
    password5.reset(); 
    password6.reset();
    password7.reset();
    password8.reset();
    password9.reset();
    password10.reset();
    password11.reset();
    password12.reset();
    password13.reset();
    password14.reset();
    password15.reset();
    password16.reset();
    password16.reset();
    password17.reset();
    password18.reset();
    password19.reset();
    password20.reset();
    password21.reset();
    password22.reset();
    password23.reset();
    password24.reset();
    password25.reset();
    password26.reset();
    password27.reset();
    password28.reset();
    password29.reset();
    password30.reset();
    password31.reset();
    password32.reset();
    password33.reset();
    password34.reset();
    password35.reset();
    password36.reset();
    password37.reset();
    password38.reset();
    password39.reset();
    password40.reset();
    password41.reset();
    password42.reset();
    password43.reset();
    password44.reset();
}


void playWrong(){                             // voids de los sonidos.
  tone(S, 77.785, 500);
  delay(w);
  noTone(S);
  tone(S, 0, 200);
  delay(w);
  noTone(S);

 }

void playBueno(){
   tone(S, 600, 350);
  delay(w);
  noTone(S);
  tone(S, 0, 200);
  delay(w);
  noTone(S);
   tone(S, 600, 350);
  delay(w);
  noTone(S);
  tone(S, 0, 200);
  delay(w);
  noTone(S);
}

void playPress(){
  tone(S, 400, 380);
  delay(w);
  noTone(S);
  tone(S, 0, 200);
  delay(w);
  noTone(S);
}


