#include <16F877.h>
#fuses XT, NOWDT, NOPROTECT, NOLVP
#use delay(clock=4000000)

#include <lcd.c>

// Define pins
#define TRIG_PIN PIN_B0
#define ECHO_PIN PIN_B1
#define MOTOR_PIN PIN_C0
#define BUZZER_PIN PIN_C1

// Function to initialize hardware
void initialize() {
    lcd_init();                     // Initialize LCD
    output_low(MOTOR_PIN);          // Motor initially off
    output_low(BUZZER_PIN);         // Buzzer initially off
    lcd_gotoxy(1, 1);
    lcd_putc("Initializing...");    // Display initialization message
    delay_ms(1000);
    lcd_clear();
}

// Function to measure distance using ultrasonic sensor
float measure_distance() {
    unsigned int16 duration;
    float distance;

    // Send trigger pulse
    output_high(TRIG_PIN);
    delay_us(10);
    output_low(TRIG_PIN);

    // Wait for echo signal
    while (!input(ECHO_PIN)); // Wait for high
    set_timer1(0);            // Start timer
    while (input(ECHO_PIN));  // Wait for low

    duration = get_timer1();             // Read timer value
    distance = (duration * 0.034) / 2;   // Convert to distance in cm

    return distance;
}

void main() {
    float distance;

    initialize(); // Initialize system

    while (true) {
        distance = measure_distance(); // Get distance

        lcd_gotoxy(1, 1);
        printf(lcd_putc, "Distance: %.2fcm", distance);

        if (distance < 50.0) { // Threshold for crack detection
            output_low(MOTOR_PIN);    // Stop motor
            output_high(BUZZER_PIN);  // Activate buzzer
            lcd_gotoxy(1, 2);
            lcd_putc("Crack Detected! ");
        } else {
            output_high(MOTOR_PIN);   // Resume motor
            output_low(BUZZER_PIN);   // Deactivate buzzer
            lcd_gotoxy(1, 2);
            lcd_putc("Track Clear     ");
        }

        delay_ms(500); // Delay between readings
    }
}
