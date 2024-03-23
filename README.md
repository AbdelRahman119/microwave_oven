# Microwave Oven Simulator
## Introduction
The Microwave Oven Simulator is designed to simulate the embedded controller in a microwave oven. This project provides a realistic interface for users to interact with, simulating the cooking, defrosting, and operational aspects of a microwave oven through a software application. This simulator is an excellent tool for educational purposes, helping students and enthusiasts understand the workings of microwave oven embedded systems.

## Features
- Simulated Cooking Modes: Users can select from popcorn, beef, or chicken cooking modes, each with specific instructions and cooking times.
- Weight Selection for Defrosting: For defrosting beef or chicken, users can input the weight, affecting the cooking time accordingly.
- Custom Cooking Time: Allows users to input a custom cooking time for various foods.
- Start/Stop/Pause Functionality: Includes realistic simulation of starting, stopping, and pausing the cooking process, complete with conditions such as door being open or closed.
- LED and Buzzer Indications: An array of LEDs simulates the microwave's operational status, and a buzzer sounds upon completion of cooking.

## How It Works
### Starting the Simulator
1. Choose Cooking Mode: Upon starting, users can select from the following options on the keypad:
A: Popcorn
B: Beef
C: Chicken
D: Custom Cooking Time
2. Entering Weight (For Beef and Chicken): If beef or chicken is selected, the user is prompted to enter the weight (1-9 kilos). Incorrect inputs result in an error message.
3. Custom Cooking Time: Users can enter a custom time between 1 and 30 minutes. The input is displayed on the LCD in a minute:second format.
### Cooking Conditions
- The cooking process is controlled by external push buttons SW1 (pause/stop) and SW2 (start). The door's open or closed status is simulated with switch SW3.
- LED array and buzzer signals provide feedback during and upon completion of cooking or defrosting.

## Usage
- Select Mode: Start by selecting your cooking mode using the keypad.
- Enter Weight/Time: Follow the prompts on the LCD to enter the weight or cooking time as required.
- Start Cooking: Ensure the door (switch SW3) is closed, and press SW2 to start. Use SW1 to pause or stop the cooking process.
