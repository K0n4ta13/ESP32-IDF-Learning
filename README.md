# ESP32-IDF-Learning

This repository contains a collection of projects and practical examples created to learn **ESP32 programming** using the **ESP-IDF** (Espressif IoT Development Framework). It serves as a learning resource for those who want to explore and experiment with the capabilities of the ESP32 microcontroller, with hands-on examples ranging from basic concepts to more advanced applications.

## Technologies Used

- **ESP32**: A low-cost, low-power system on a chip (SoC) with integrated Wi-Fi and Bluetooth.
- **ESP-IDF**: The official development framework for the ESP32, providing libraries, tools, and APIs to develop embedded applications.
- **C/C++**: Programming languages used to interact with the hardware and ESP-IDF libraries.

## Prerequisites

Before you start working with the projects, you need to have the following installed:

- **ESP32 Toolchain**: Install the ESP32 toolchain by following the instructions in the [ESP-IDF Getting Started Guide](https://docs.espressif.com/projects/esp-idf/en/latest/get-started/).

## Installation

Follow these steps to set up your development environment:

1. **Install the ESP32 toolchain**:
    - Follow the [ESP-IDF Setup Guide](https://docs.espressif.com/projects/esp-idf/en/latest/get-started/) to install the toolchain and set up the environment.

2. **Clone the repository**:
    ```bash
    git clone https://github.com/your-username/ESP32-IDF-Learning.git
    cd ESP32-IDF-Learning
    ```

3. **Install ESP-IDF dependencies**:
    - Navigate to the root folder of your ESP32 project and run:
    ```bash
    ./install.sh
    ```

## Usage

Each project in this repository is contained in its own folder. To build and upload a project to the ESP32, follow these steps:

1. Navigate to the desired project folder:
    ```bash
    cd project_name
    ```

2. **Configure the project**:
    - Run `idf.py menuconfig` to configure your project settings (Wi-Fi credentials, GPIO, etc.).
    ```bash
    idf.py menuconfig
    ```

3. **Build the project**:
    - To build the project, run the following command:
    ```bash
    idf.py build
    ```

4. **Flash the project to the ESP32**:
    - Connect your ESP32 to your computer via USB and run:
    ```bash
    idf.py flash
    ```

5. **Monitor the ESP32 output**:
    - To view the serial output of the ESP32, use the following command:
    ```bash
    idf.py monitor
    ```

Alternatively, there are `justfile` scripts included in the projects to simplify these commands. You can use the following shortcuts:

- **Set the target**: 
    ```bash
    just t TARGET  # This replaces 'idf.py set-target TARGET'
    ```

- **Build and flash**:
    ```bash
    just r  # This replaces 'idf.py flash monitor'
    ```

- **Load env**:
    ```bash
    just e  # Load the env '. ~/esp-idf/export.sh'

The `justfile` scripts provide an easy and consistent way to execute common commands for building, flashing, and monitoring your projects.

## Projects

This repository includes various projects and examples to help you learn different aspects of ESP32 programming. Some example topics include:

- **Wi-Fi connectivity**: Connecting the ESP32 to a Wi-Fi network.
- **Bluetooth communication**: Setting up Bluetooth communication using the ESP32.
- **GPIO control**: Interfacing with LEDs, buttons, and sensors.
- **Web server**: Building a simple web server on the ESP32.
