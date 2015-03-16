int R_in = 2;  //channel numbers and variables
int G_in = 3;
int B_in = 4;
int R_out = 5;
int G_out = 6;
int B_out = 7;
int R_val;
int G_val;
int B_val;
int R_val_out;
int G_val_out;
int B_val_out;

void setup()
{
 pinMode(R_in, INPUT);  //set pin modes
 pinMode(G_in, INPUT);
 pinMode(B_in, INPUT);
 pinMode(R_out, OUTPUT);
 pinMode(G_out, OUTPUT);
 pinMode(B_out, OUTPUT);
}

void loop()
{
  //read pulse width of signals
  R_val = pulseIn(R_in, HIGH);
  G_val = pulseIn(G_in, HIGH);
  B_val = pulseIn(B_in, HIGH);
  //convert pulse width into pwm
  R_val_out = map(R_val, 1000, 2000, -372.5, 627.5);
  R_val_out = constrain(R_val_out, 0, 255);
  //convert pulse width into pwm
  G_val_out = map(G_val, 1000, 2000, -372.5, 627.5);
  G_val_out = constrain(G_val_out, 0, 255);
  //convert pulse width into pwm
  B_val_out = map(B_val, 1000, 2000, -372.5, 627.5);
  B_val_out = constrain(B_val_out, 0, 255);
  //output analog signal
  analogWrite(R_out, R_val_out);
  analogWrite(G_out, G_val_out);
  analogWrite(B_out, B_val_out);
}