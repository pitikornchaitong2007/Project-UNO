int sum(int x, int y);
int dif(int x, int y);
int mul(int x, int y);
float divi(int x, int y);

void setup() {
  Serial.begin(9600);   
  delay(500);        

  int a = 10;
  int b = 2;

  Serial.print("Add = ");
  Serial.println(sum(a, b));

  Serial.print("Sub = ");
  Serial.println(dif(a, b));

  Serial.print("Mul = ");
  Serial.println(mul(a, b));

  Serial.print("Div = ");
  Serial.println(divi(a, b));
}

void loop() {

}



int sum(int x, int y) {
  return x + y;
}

int dif(int x, int y) {
  return x - y;
}

int mul(int x, int y) {
  return x * y;
}

float divi(int x, int y) {
  if (y == 0) return 0;
  return (float)x / y;
}