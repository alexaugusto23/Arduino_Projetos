const int QtdLEDs = 10;
const int levels[] = {0,1,3,5,7,10} ;
const int pinsLEds[] = {2,3,4,5,6,7,8,9,10,11};
const int pinsensor = 0;

int tmp = 0; 
int LED = 13; 
int i;

void setup () {

  Serial.begin(9600); 
  Serial.println("Sensor de Umidade");
  pinMode(pinsensor, INPUT);
  pinMode(LED, OUTPUT); 
  
  for(int i = 0; i <= QtdLEDs ; i++ ){ 
    pinMode(pinsLEds[i], OUTPUT); 
  }
}

void loop () {
  Serial.print("Leitura do Sensor - EntradaAnalAO = "); 
  Serial.println( analogRead( pinsensor ) );

  if (analogRead( pinsensor ) >= 950){
  digitalWrite(LED, HIGH);
  for(i = 0; i <= levels[5] ; i++ ){ 
    digitalWrite(pinsLEds[i], HIGH);} 
  }else{
  digitalWrite(LED, LOW); 
  for(i = levels[5]; i >= 0 ; i-- ){
  digitalWrite(pinsLEds[i], LOW);}
  } 
  
  if (analogRead( pinsensor ) >= 850){
  digitalWrite(LED, HIGH); 
  for(i = 0; i <= levels[4] ; i++ ){ 
    digitalWrite(pinsLEds[i], HIGH);}
  }else{
  digitalWrite(LED, LOW); 
  for(i = levels[4]; i >= 0 ; i-- ){
    digitalWrite(pinsLEds[i], LOW);}
  }
  
  if (analogRead( pinsensor ) >= 750){
  digitalWrite(LED, HIGH); 
  for(i = 0; i <= levels[3] ; i++ ){ 
    digitalWrite(pinsLEds[i], HIGH);  
  }
  }else{
  digitalWrite(LED, LOW); 
  for(i = levels[3]; i >= 0 ; i-- ){
    digitalWrite(pinsLEds[i], LOW);}
  }

  if (analogRead( pinsensor ) >=650){
  digitalWrite(LED, HIGH); 
  for(i = 0; i <= levels[2] ; i++ ){
    digitalWrite(pinsLEds[i], HIGH);  
  }
  }else{
  digitalWrite(LED, LOW); 
  for(i = levels[2]; i >= 0 ; i-- ){
    digitalWrite(pinsLEds[i], LOW);}
  }  
  
  if (analogRead( pinsensor ) >= 450){
    digitalWrite(LED, HIGH); 
    for(i = 0; i <= levels[1] ; i++){
      digitalWrite(pinsLEds[i], HIGH);  
    }
  }else{
  digitalWrite(LED, LOW); 
  for(i = levels[1]; i >= 0 ; i-- ){
    digitalWrite(pinsLEds[i], LOW);}
  }    
}
