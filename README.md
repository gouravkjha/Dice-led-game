# ESP32 Dice Game with LED Matrix

This is an interactive dice game built using an ESP32 microcontroller, an 8x32 LED matrix display, and a push button. The game simulates rolling two dice with animated transitions and displays the result on the matrix.

---

## Features

- Rolls two dice and displays their faces
- Single push button to trigger dice roll
- Uses `MD_MAX72XX` and `MD_Parola` libraries for matrix control and animations
- Smooth rolling animation before displaying the result
- Idle messages scroll when no input is detected

---

## Hardware Used

| Component          | Description                   |
|--------------------|-------------------------------|
| ESP32 Board        | Microcontroller               |
| 8x32 LED Matrix    | 4x MAX7219 modules            |
| Push Button        | Digital input (GPIO 14)       |
| (Optional) Buzzer  | Sound feedback (future scope) |
| Jumper Wires       | For connections               |

### Pin Configuration

| Module     | ESP32 Pin |
|------------|-----------|
| DIN (Data) | GPIO 23   |
| CLK        | GPIO 18   |
| CS         | GPIO 5    |
| Button     | GPIO 14   |

---

## Circuit Diagram

[Circuit Diagram](esp32_dice_circuit.png)

---

## Live Simulation

You can view and test this project online in your browser using Wokwi:

[ESP32 Dice Game Simulation on Wokwi](https://wokwi.com/projects/435618335373574145)

This simulation shows the LED matrix animation and button interaction as intended.

---

## How to Use

1. Upload the code to your ESP32 using the Arduino IDE.
2. Power the board. The display will prompt: "Press Button To Roll".
3. Press the button to roll the dice.
4. Two random dice faces appear after an animation.
5. After a short delay, the game resets and is ready for the next roll.

---

## Libraries Required

Install via Arduino Library Manager:

- `MD_MAX72XX`
- `MD_Parola`
- `SPI` (comes with Arduino)

---

## Future Improvements

- Add scoring system
- Add buzzer sound feedback
- Add prediction modes and game-over logic
- Add multiplayer support

---

## License

This project is licensed under the [MIT License](LICENSE).  
You are free to use, modify, and share this project with attribution.

---

## Author

Created by [@gouravkrjha](https://github.com/gouravkjha)  
Feel free to fork, star, or contribute to the project.
