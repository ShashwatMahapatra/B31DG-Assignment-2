int led_1 = 12;
int led_2 = 14;
int p     = 5;     //Pin for Potentiometer input
int t;
unsigned long in    = 16;    //Pin for Frequency input for Task 2
unsigned long hi;            //integer for storing time for which wave is high for task 2
unsigned long lo;           //integer for storing time for which wave is low for task 2
unsigned long total;        //integer for storing total time of one cycle for task 2
unsigned long fr;           //integer for storing frequency of wave for task 2

unsigned long in1   = 17;    //Pin for Frequency input for Task 3
unsigned long hi1;           //integer for storing time for which wave is high for task 3
unsigned long lo1;           //integer for storing time for which wave is low for task 3
unsigned long total1;        //integer for storing total time of one cycle for task 3
unsigned long fr1;           //integer for storing frequency of wave for task 3

int m0;            //integer for storing milestones
int m1;            //second integer for storing milestone
int m;             //Time taken for Task 1 to complete

int feqmin = 333;
int feqmax = 1000;
int feqmin1= 500;
int feqmax1= 1000;
int a;
int a1;
int b;
int b1;
int fscale;
int fscale1;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  
  pinMode(in , INPUT);
  pinMode(in1, INPUT);

}

void t2() {
  digitalRead(in);
  hi     = 0;
  hi     = pulseIn(in,HIGH, 3000);
  if (hi > 0){
    fr   = 1000000/(2*hi);
  }
  else{
    fr   = 333;   
  }
   
}

void t3() {
  digitalRead(in1);
  hi1     = 0;
  hi1     = pulseIn(in1,HIGH, 3000);
  if (hi1 > 0){
    fr1   = 1000000/(2*hi1);
  }
  else{
    fr1   = 500;   
  }
    
}

void t5() {
  
  m0 = micros();
  fscale = (99*(fr - feqmin)/(feqmax - feqmin)) ;
  if (fscale > 0){
    a = fscale;
  }
  else {
    a = 0;
  }

  fscale1 = (99*(fr1 - feqmin1))/(feqmax1 - feqmin1) ;
  if (fscale1 > 0){
    a1= fscale1;
  }
  else{
    a1= 0;
  }

Serial.printf(" %d , %d \n", a, a1);
 m1 = micros();
 m = m1 - m0;
 Serial.printf("Time taken: %d " , m);

  }

void loop() {
  // put your main code here, to run repeatedly:
  t2();
  t3();
  t5();

}
