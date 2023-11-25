// https://wokwi.com/projects/381104105246734337
const int led_green = 13;
const int led_red = 11;
const int button = 9;
const int pir_motion_sensor = 8;
int pir_motion_sensor_value = 0; // estado del sensor de movimiento
int old_pir_motion_sensor_value = 0;
int val = 0; // estado de "button"
int state = 0;
int old_val = 0; // Antiguo valor de "val"
void setup() {
  pinMode (led_green, OUTPUT);
  pinMode (led_red, OUTPUT);
  pinMode (button, INPUT);
  pinMode (pir_motion_sensor, INPUT);
}
void loop() {
  val = digitalRead(button);
  if ((val == HIGH) && (old_val == LOW)){
  state = 1-state;
  delay(10);
  }
  old_val = val;
  if (state==1){
    digitalWrite(led_green, HIGH);
  }else{
    digitalWrite(led_green, LOW);
  }
  pir_motion_sensor_value = digitalRead(pir_motion_sensor);
  if (pir_motion_sensor_value != old_pir_motion_sensor_value && pir_motion_sensor_value == HIGH) {
    digitalWrite(led_red, HIGH);
  } else if (pir_motion_sensor_value != old_pir_motion_sensor_value && pir_motion_sensor_value == LOW) {
    digitalWrite(led_red, LOW);
  }
  old_pir_motion_sensor_value = pir_motion_sensor_value;
}
