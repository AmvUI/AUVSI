int pwm_value1;
int pwm_value2;
int middle_pwm = 1600;

//pin for killswitch
int kill_1=3;
int kill_2=4;
int kill_3=5;
int kill_4=6;
int remote_kill_1=9;
int remote_kill_2=10;

//pin lampu
int remote_pin = A3;
int remote_pin_2 = A4;

int led_red     = A0;
int led_yellow  = A1;
int led_green   = A2;

int pwm_remote;
int pwm_remote_2;
int middle_analog = 130;

void setup() {
  pinMode (kill_1,OUTPUT);
  pinMode (kill_2,OUTPUT);
  pinMode (kill_3,OUTPUT);
  pinMode (kill_4,OUTPUT);
  pinMode (remote_kill_1,INPUT);
  pinMode (remote_kill_2,INPUT);
  
  pinMode(led_red, OUTPUT);
  pinMode(led_green, OUTPUT);
  pinMode(led_yellow, OUTPUT);

  pinMode(remote_pin, INPUT);
  pinMode(remote_pin_2, INPUT);
  
  Serial.begin (9600);
}

void loop() {
  pwm_value1 = pulseIn(remote_kill_1, HIGH);
  pwm_value2 = pulseIn(remote_kill_2, HIGH);
  Serial.println(pwm_value1);
  Serial.println(pwm_value2);
  Serial.println("    ");

  if (pwm_value1>middle_pwm)
  {
    digitalWrite (kill_1,HIGH);
    digitalWrite (kill_2,HIGH);
  }
  else
  {
    digitalWrite (kill_1,LOW);
    digitalWrite (kill_2,LOW);
  }
  delay (100);
  
  if (pwm_value2>middle_pwm)
  {
    digitalWrite (kill_3,HIGH);
    digitalWrite (kill_4,HIGH);
  }
  else
  {
    digitalWrite (kill_3,LOW);
    digitalWrite (kill_4,LOW);
  }

  pwm_remote = analogRead(remote_pin);
  pwm_remote_2 = pulseIn(remote_pin_2, HIGH);
  delay (100);

    if(pwm_remote>middle_analog){//motor
    digitalWrite(led_red, HIGH);
    digitalWrite(led_yellow, LOW);
    digitalWrite(led_green, LOW);    
  }
  else {
    if(pwm_remote_2>middle_pwm){//auto
      digitalWrite(led_red, LOW);
      digitalWrite(led_yellow, LOW);
      digitalWrite(led_green, HIGH);
    }
    else {//motor
      digitalWrite(led_red, LOW);
      digitalWrite(led_yellow, HIGH);
      digitalWrite(led_green, LOW);      
    }
  }
}
