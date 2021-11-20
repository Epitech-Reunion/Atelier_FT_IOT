
void init_bluetooth(void)
{
  my_bt_module.begin(38400);
}

String bluetooth_recv(void)
{
  if (my_bt_module.available()) {
    return my_bt_module.readString();    
  }
  else {
    return "";
  }
}

void bluetooth_send(String str)
{
  my_bt_module.print(str + "\n>");
}

void turn(int state, int pin)
{
  String state_str;
  if (state == 1) {
    state_str = "on";
  }
  if (state == 0) {
    state_str = "off";
  }
  display("Turning " + state_str + " pin number " + String(pin));  
  digitalWrite(pin, state);
}

void display(String x)
{
  Serial.println(x);
}

void init_display(void)
{
  Serial.begin(9600);
}
void init_fan(void)
{
  pinMode(fan, OUTPUT);
}

int get_temp(int pin) {
 double Temp;
 int RawADC = analogRead(pin);
 Temp = log(10000.0/(1024.0/RawADC-1));
 Temp = 1 / (0.001129148 + (0.000234125 + (0.0000000876741 * Temp * Temp ))* Temp );
 Temp = Temp - 273.15;       
 return (int)Temp;
}

