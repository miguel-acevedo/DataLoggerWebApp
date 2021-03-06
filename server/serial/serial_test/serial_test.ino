void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}
int battery[2] = {0x03,0x88};
int can[2] = {0x06,0x26};
int generic[2] = {0x07,0x23};
int throttle[2] = {0x02,0x00};
int temp[2] = {0x04,0x88};
int tempDegrees[6] = {120,80,40,10,0,250};
int x = 0;
uint32_t voltage = 0;
void loop() {
  // put your main code here, to run repeatedly:
  Serial.write(can[0]);
  Serial.write(can[1]);
  unsigned long tick = millis();
  int time[4];
  time[0] = (unsigned int)((tick&0xFF000000)>>24);
  time[1] = (unsigned int)((tick&0x00FF0000)>>16);
  time[2] = (unsigned int)((tick&0x0000FF00)>>8);
  time[3] = (unsigned int)(tick&0x000000FF);
  Serial.write(time[0]);
  Serial.write(time[1]);
  Serial.write(time[2]);
  Serial.write(time[3]);
  Serial.write(1);
  Serial.write(1);
  Serial.write(1);
  Serial.write(1);
  Serial.write(1);
  Serial.write(1);
  Serial.write(1);
  Serial.write(1);
  Serial.write(0xFF);
  Serial.write('\n');
  Serial.flush();
  Serial.write(throttle[0]);
  Serial.write(throttle[1]);
  tick = millis();
  time[0] = (unsigned int)((tick&0xFF000000)>>24);
  time[1] = (unsigned int)((tick&0x00FF0000)>>16);
  time[2] = (unsigned int)((tick&0x0000FF00)>>8);
  time[3] = (unsigned int)(tick&0x000000FF);
  Serial.write(time[0]);
  Serial.write(time[1]);
  Serial.write(time[2]);
  Serial.write(time[3]);
  Serial.write((x&0xFF00)>>8);
  Serial.write(x&0xFF);
  Serial.write(1);
  Serial.write(1);
  Serial.write(1);
  Serial.write(1);
  Serial.write(1);
  Serial.write(1);
  Serial.write(0xFF);
  Serial.write('\n');
  Serial.flush();
  Serial.write(temp[0]);
  Serial.write(temp[1]);
  tick = millis();
  time[0] = (unsigned int)((tick&0xFF000000)>>24);
  time[1] = (unsigned int)((tick&0x00FF0000)>>16);
  time[2] = (unsigned int)((tick&0x0000FF00)>>8);
  time[3] = (unsigned int)(tick&0x000000FF);
  Serial.write(time[0]);
  Serial.write(time[1]);
  Serial.write(time[2]);
  Serial.write(time[3]);
  Serial.write(x&0xFF);
  Serial.write(tempDegrees[1]);
  Serial.write(tempDegrees[2]);
  Serial.write(tempDegrees[3]);
  Serial.write(tempDegrees[4]);
  Serial.write(tempDegrees[5]);
  Serial.write(0x05);
  Serial.write(250);
  Serial.write(0xFF);
  Serial.write('\n');
  x++;
  if(x>0x7FF) x = 0;
  Serial.write(battery[0]);
  Serial.write(battery[1]);
  tick = millis();
  time[0] = (unsigned int)((tick&0xFF000000)>>24);
  time[1] = (unsigned int)((tick&0x00FF0000)>>16);
  time[2] = (unsigned int)((tick&0x0000FF00)>>8);
  time[3] = (unsigned int)(tick&0x000000FF);
  Serial.write(time[0]);
  Serial.write(time[1]);
  Serial.write(time[2]);
  Serial.write(time[3]);
  Serial.write(1);
  Serial.write(1);
  Serial.write((3000&0xFF00)>>8);
  Serial.write(3000&0xFF);
  Serial.write((voltage&0xFF000000)>>24);
  Serial.write((voltage&0x00FF0000)>>16);
  Serial.write((voltage&0x0000FF00)>>8);
  Serial.write((voltage&0x000000FF));
  Serial.write(0xFF);
  Serial.write('\n');
  voltage+=10;
  if(voltage>12000) voltage = 0;
  Serial.write(generic[0]);
  Serial.write(generic[1]);
  tick = millis();
  time[0] = (unsigned int)((tick&0xFF000000)>>24);
  time[1] = (unsigned int)((tick&0x00FF0000)>>16);
  time[2] = (unsigned int)((tick&0x0000FF00)>>8);
  time[3] = (unsigned int)(tick&0x000000FF);
  Serial.write(time[0]);
  Serial.write(time[1]);
  Serial.write(time[2]);
  Serial.write(time[3]);
  Serial.write(x&0xFF);
  Serial.write(1);
  Serial.write(1);
  Serial.write(1);
  Serial.write(1);
  Serial.write(1);
  Serial.write(1);
  Serial.write(1);
  Serial.write(0xFF);
  Serial.write('\n');
  voltage+=10;
  if(voltage>12000) voltage = 0;
  Serial.flush();
  delay(2);
}
