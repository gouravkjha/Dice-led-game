#  ESP32 Dice Game with LED Matrix

This is an interactive dice game built using an **ESP32 microcontroller**, an **8x32 LED matrix display**, and a **joystick push button**. The game simulates rolling two dice with animated transitions and displays the result on the matrix.

---

##  Features

-  Rolls two dice and displays their faces
-  Single-button input to roll the dice
-  Uses `MD_MAX72XX` and `MD_Parola` libraries for matrix animation
-  Smooth dice rolling animation
-  Idle message scrolls when no input is detected

---

##  Hardware Used

| Component          | Description                   |
|--------------------|-------------------------------|
| ESP32 Board        | Microcontroller               |
| 8x32 LED Matrix    | 4x MAX7219 modules            |
| Push Button        | Joystick-style, digital input |
| (Optional) Buzzer  | Sound feedback on roll        |
| Jumper Wires       | For connections               |

**Pin Configuration:**

| Module     | ESP32 Pin |
|------------|-----------|
| DIN (Data) | GPIO 23   |
| CLK        | GPIO 18   |
| CS         | GPIO 5    |
| Button     | GPIO 14   |

---

##  Circuit Diagram

[Circuit Diagram](esp32_dice_circuit.png)

##  How to Use

1. Upload the code to your ESP32 using Arduino IDE.
2. Power the device — a message will scroll on the matrix.
3. Press the button to roll the dice.
4. Two dice faces appear after a quick animation.
5. Wait for 3 seconds → Prompt will reappear.

---

##  Libraries Required

Install via Arduino Library Manager:

- `MD_MAX72XX`
- `MD_Parola`
- `SPI`

---

##  Future Improvements

- Add score tracking
- Add game-over conditions or prediction logic
- Include buzzer sound feedback
- Extend to multiplayer version

---

##  License

This project is licensed under the [MIT License](LICENSE).  
Feel free to use, modify, and share — just give credit.

---

## 🙌 Author

Made with ❤️ by gouravkrjha  
Feel free to fork, star, and improve this project!

