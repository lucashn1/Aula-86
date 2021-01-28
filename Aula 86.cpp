void setup() {

pinMode (2, OUTPUT);   //Configuração dos pinos 2 e 3
pinMode (3, OUTPUT);
pinMode (4, OUTPUT);
Serial.begin(9600);     //Velocidade de iniciação
int temperatura=0;
 int sensor=0;

}

void loop () {

 int sensor = analogRead(A0);
 int temperatura = map(((analogRead(A0)- 20) * 3.04), 0 , 1023, -40 ,125);
 
  Serial.print("Temperatura do sistema ");
  Serial.print (temperatura);
  Serial.println (" C");

if (temperatura <=25 ) {
Serial.println ("Sistema com temperatura estavel");
digitalWrite(2, HIGH);
  delay (5000);

}


  if (temperatura >25 && temperatura<70) {
Serial.println ("Sistema em risco, temperatura acima do seguro");

   digitalWrite(2, LOW) ;
    digitalWrite(3, HIGH);
delay (1000);
digitalWrite(3, LOW);
    delay (1000);
digitalWrite(3, HIGH);
delay (1000);
digitalWrite(3, LOW);
    delay (1000);
}

  if(temperatura >=70){
Serial.println("Sistema em estado critico, Diminua a temperatura urgente"); 
digitalWrite(2, LOW) ;
    digitalWrite(4 , HIGH); 
delay (500);
digitalWrite(4,LOW);
    delay(500);
    digitalWrite(4 , HIGH); 
delay (500);
digitalWrite(4,LOW);
    delay(500);digitalWrite(4 , HIGH); 
delay (500);
digitalWrite(4,LOW);
    delay(500);
  }

}


