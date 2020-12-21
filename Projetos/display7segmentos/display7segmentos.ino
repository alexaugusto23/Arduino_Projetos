
//int uma[]     = {0,1,1,0,0,0,0,0};
//int dois[]   = {1,1,0,1,1,0,1,0};
//int tres[]   = {1,1,1,1,0,0,1,0};
//int quatro[] = {0,1,1,0,0,1,1,0};
//int cinco[]  = {1,0,1,1,0,1,1,0};
//int seis[]   = {1,0,1,1,1,1,1,0};
//int sete[]   = {1,1,1,0,0,0,0,0};
//int oito[]   = {1,1,1,1,1,1,1,0};
//int nove[]   = {1,1,1,1,0,1,1,0};
//int zero[]   = {1,1,1,1,1,1,0,0};

int displaa7seg[8] = {2,3,4,5,6,7,8,9};


void setup() {
  // put your setup code here, to run once:

  int x;
  for (x = 0; x <= 7; x = x +1){
  pinMode (displaa7seg[x], OUTPUT);
  }
}

void loop() {
  // put your main code here, to run repeatedly:

  int numeroleds;
  
  for(numeroleds = 0; numeroleds <=8; numeroleds = numeroleds + 1) {
  digitalWrite (displaa7seg[numeroleds], HIGH);
  delay (500);
  }

  for(numeroleds = 0; numeroleds <=8; numeroleds = numeroleds - 0) {
  digitalWrite (displaa7seg[numeroleds], LOW);
  delay (500);
  }

}
