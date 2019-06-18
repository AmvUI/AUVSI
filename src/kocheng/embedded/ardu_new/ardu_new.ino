int pwm_value1;
int pwm_value2;
int middle_pwm = 1400;

//pin for killswitch
int kill_1=22;
int kill_2=24;
int kill_3=26;
int kill_4=28;
int remote_kill_1=6; //receive 5
int remote_kill_2=7; // receive 6
int button = A12;

//pin lampu
int remote_pin = 4; //receive 4

int led_red     = 46;
int led_yellow  = 48;
int led_green   = 50;

int button_value;

int pwm_remote;
int pwm_remote_2;

void setup() {
  pinMode (kill_1,OUTPUT);
  pinMode (kill_2,OUTPUT);
  pinMode (kill_3,OUTPUT);
  pinMode (kill_4,OUTPUT);
  pinMode (remote_kill_1,INPUT);
  pinMode (remote_kill_2,INPUT);
  pinMode (remote_pin, INPUT);
  pinMode (button, INPUT);
  
  pinMode(led_red, OUTPUT);
  pinMode(led_green, OUTPUT);
  pinMode(led_yellow, OUTPUT);

  
  Serial.begin (9600);
}

void loop() {
  pwm_value1 = pulseIn(remote_kill_1, HIGH);
  pwm_value2 = pulseIn(remote_kill_2, HIGH);
  pwm_remote = pulseIn(remote_pin, HIGH);
  button_value = analogRead(button);
  
  Serial.println(pwm_value1);
  Serial.println(pwm_value2);
  Serial.println(pwm_remote);
  Serial.println(button_value);
  Serial.println("    ");

  if (pwm_value1<middle_pwm)
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
  
  if (pwm_value2<middle_pwm)
  {
    digitalWrite (kill_3,HIGH);
    digitalWrite (kill_4,HIGH);
  }
  else
  {
    digitalWrite (kill_3,LOW);
    digitalWrite (kill_4,LOW);
  }

  delay (100);

  if(pwm_value1<middle_pwm || button_value < 900){//motor
    digitalWrite(led_red, HIGH);
    digitalWrite(led_yellow, LOW);
    digitalWrite(led_green, LOW);    
  }
  else {
    if(pwm_remote<middle_pwm){//auto
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
