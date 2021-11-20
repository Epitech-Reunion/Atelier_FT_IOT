#include <math.h>
#include <SoftwareSerial.h>

typedef SoftwareSerial BLUETOOTH;
void init_bluetooth(void);
String bluetooth_recv(void);
void bluetooth_send(String);


#define ON 1
#define OFF 0
void display(String);
void init_display(void);
void init_fan(void);
int get_temp(int);
void turn(int, int);
