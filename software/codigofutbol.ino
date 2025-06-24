#include <PS4Controller.h>

// Pines motores
#define IN1_MOTOR_A 3
#define IN2_MOTOR_A 4
#define IN1_MOTOR_B 5
#define IN2_MOTOR_B 6

void setup() {
  pinMode(IN1_MOTOR_A, OUTPUT);
  pinMode(IN2_MOTOR_A, OUTPUT);
  pinMode(IN1_MOTOR_B, OUTPUT);
  pinMode(IN2_MOTOR_B, OUTPUT);

  Serial.begin(115200);

  // Colocá la dirección MAC de tu joystick PS4
  PS4.begin("xx:xx:xx:xx:xx:xx"); // ← REEMPLAZAR por la MAC real del control
  Serial.println("Esperando conexión del PS4...");
}

void loop() {
  if (!PS4.isConnected()) {
    detener();
    return;
  }

  int ly = PS4.LStickY(); // Eje vertical del stick izquierdo
  int lx = PS4.LStickX(); // Eje horizontal del stick izquierdo

  int deadzone = 20;

  if (abs(ly) < deadzone && abs(lx) < deadzone) {
    detener();
  }
  else if (ly < -deadzone) {
    avanzar();
  }
  else if (ly > deadzone) {
    retroceder();
  }
  else if (lx < -deadzone) {
    girarIzquierda();
  }
  else if (lx > deadzone) {
    girarDerecha();
  }
}

// Movimiento
void avanzar() {
  digitalWrite(IN1_MOTOR_A, HIGH);
  digitalWrite(IN2_MOTOR_A, LOW);
  digitalWrite(IN1_MOTOR_B, HIGH);
  digitalWrite(IN2_MOTOR_B, LOW);
}

void retroceder() {
  digitalWrite(IN1_MOTOR_A, LOW);
  digitalWrite(IN2_MOTOR_A, HIGH);
  digitalWrite(IN1_MOTOR_B, LOW);
  digitalWrite(IN2_MOTOR_B, HIGH);
}

void girarIzquierda() {
  digitalWrite(IN1_MOTOR_A, LOW);
  digitalWrite(IN2_MOTOR_A, HIGH);
  digitalWrite(IN1_MOTOR_B, HIGH);
  digitalWrite(IN2_MOTOR_B, LOW);
}

void girarDerecha() {
  digitalWrite(IN1_MOTOR_A, HIGH);
  digitalWrite(IN2_MOTOR_A, LOW);
  digitalWrite(IN1_MOTOR_B, LOW);
  digitalWrite(IN2_MOTOR_B, HIGH);
}

void detener() {
  digitalWrite(IN1_MOTOR_A, LOW);
  digitalWrite(IN2_MOTOR_A, LOW);
  digitalWrite(IN1_MOTOR_B, LOW);
  digitalWrite(IN2_MOTOR_B, LOW);
}
