// Short hello world in morse code skecth

void setup() {
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(9, OUTPUT);
}

void loop() {
  digitalWrite(11, HIGH);   // .   
  delay(250);              
  digitalWrite(11, LOW);   
  delay(250);
  digitalWrite(11, HIGH);   // .  
  delay(250);              
  digitalWrite(11, LOW);   
  delay(250);
  digitalWrite(11, HIGH);   // .  
  delay(250);              
  digitalWrite(11, LOW);   
  delay(250);
  digitalWrite(11, HIGH);   // .  
  delay(250);              
  digitalWrite(11, LOW);  // silence  
  delay(1000);
  digitalWrite(11, HIGH);   // .  
  delay(250);  
  digitalWrite(11, LOW);  //silence
  delay(1000);
  digitalWrite(11, HIGH); //.  
  delay(250);
  digitalWrite(11, LOW);   
  delay(250);
  digitalWrite(11, HIGH); //- 
  delay(750);
  digitalWrite(11, LOW);   
  delay(250);
  digitalWrite(11, HIGH); //.  
  delay(250);              
  digitalWrite(11, LOW);   
  delay(250);
  digitalWrite(11, HIGH); //.  
  delay(250);              
  digitalWrite(11, LOW);  //silence  
  delay(1000);
  digitalWrite(11, HIGH); // .  
  delay(250);              
  digitalWrite(11, LOW);   
  delay(250);
  digitalWrite(11, HIGH); //- 
  delay(750);
  digitalWrite(11, LOW);   
  delay(250);
  digitalWrite(11, HIGH); // .   
  delay(250);              
  digitalWrite(11, LOW);   
  delay(250);
  digitalWrite(11, HIGH); // .  
  delay(250);              
  digitalWrite(11, LOW);  //silence  
  delay(1000);
  digitalWrite(11, HIGH); //- 
  delay(750);
  digitalWrite(11, LOW);   
  delay(250);
  digitalWrite(11, HIGH); //- 
  delay(750);
  digitalWrite(11, LOW);   
  delay(250);
  digitalWrite(11, HIGH); //- 
  delay(750);
  digitalWrite(11, LOW);   
  delay(1000);
  
// World
 
  digitalWrite(10, HIGH); // .   
  delay(250);              
  digitalWrite(10, LOW);   
  delay(250);
  digitalWrite(10, HIGH); //- 
  delay(750);
  digitalWrite(10, LOW);   
  delay(250);
  digitalWrite(10, HIGH); //- 
  delay(750);
  digitalWrite(10, LOW);   // silence
  delay(1000);
  digitalWrite(10, HIGH); //- 
  delay(750);
  digitalWrite(10, LOW);   
  delay(250);
  digitalWrite(10, HIGH); //- 
  delay(750);
  digitalWrite(10, LOW);   
  delay(250);
  digitalWrite(10, HIGH); //- 
  delay(750);
  digitalWrite(10, LOW);   
  delay(1000);
  digitalWrite(10, HIGH); // .   
  delay(250);              
  digitalWrite(10, LOW);   
  delay(250);
  digitalWrite(10, HIGH); //- 
  delay(750);
  digitalWrite(10, LOW);   
  delay(250);
  digitalWrite(10, HIGH); // .   
  delay(250);              
  digitalWrite(10, LOW);   
  delay(1000);
  digitalWrite(10, HIGH); // .   
  delay(250);              
  digitalWrite(10, LOW);   
  delay(250);
  digitalWrite(10, HIGH); //- 
  delay(750);
  digitalWrite(10, LOW);   
  delay(250);
  digitalWrite(10, HIGH); // .   
  delay(250);              
  digitalWrite(10, LOW);   
  delay(250);
  digitalWrite(10, HIGH); // .   
  delay(250);              
  digitalWrite(10, LOW);   
  delay(1000);
  digitalWrite(10, HIGH); //- 
  delay(750);
  digitalWrite(10, LOW);   
  delay(250);
  digitalWrite(10, HIGH); // .   
  delay(250);              
  digitalWrite(10, LOW);   
  delay(250);
  digitalWrite(10, HIGH); // .   
  delay(250);              
  digitalWrite(10, LOW);   
  delay(250);
  
// Reset signal
  digitalWrite(9, HIGH);   
  delay(500);              
  digitalWrite(9, LOW);   
  delay(500); 
  digitalWrite(9, HIGH);   
  delay(500);              
  digitalWrite(9, LOW);   
  delay(500);      
  digitalWrite(9, HIGH);   
  delay(500);              
  digitalWrite(9, LOW);   
  delay(500); 
  digitalWrite(9, HIGH);   
  delay(500);              
  digitalWrite(9, LOW);   
  delay(500);  

  }
