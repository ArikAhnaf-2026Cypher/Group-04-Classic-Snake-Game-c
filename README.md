# Group-04-Classic-Snake-Game-c-(CSE115)
A classic Snake Game developed in C, featuring smooth gameplay, snake growth mechanics, score tracking, and collision detection.

# 🐍 Classic Snake Game 

This is our first-semester project: a professional and robust implementation of the timeless classic Snake game, developed entirely in C. The project features optimized snake-growth mechanics, precise collision detection, dynamic speed scaling, and local score tracking. The implementation emphasizes performance, maintainability, and clean software design principles.

---

## 👥 Group Information

| <img src="https://img.shields.io/badge/Serial--Number-333333?style=for-the-badge" alt="SL"/> | <img src="https://img.shields.io/badge/Full--Name-d73a49?style=for-the-badge" alt="Name"/> | <img src="https://img.shields.io/badge/Student--ID-0052cc?style=for-the-badge" alt="ID"/> | <img src="https://img.shields.io/badge/GitHub--Profile-Bright Retro Green?style=for-the-badge" alt="GitHub"/> |
| :---: | :---: | :---: | :---: |
| 01 | ***Md. Arik Ahnaf***         | **`2621388042`** | [@ArikAhnaf-2026Cypher](https://github.com/ArikAhnaf-2026Cypher)     |
| 02 | ***Md. Faiyaz Farhan Adit*** | **`2624169642`** | [@faiyazfarhan28-dot](https://github.com/faiyazfarhan28-dot)         |
| 03 | ***Jannatul Tufa Rodela***   | **`2622542042`** | [@jannatulrodela262-dot](https://github.com/jannatulrodela262-dot)   |
| 04 | ***Mohammad Farhan Sadik***  | **`2625442042`** | [@mohammadfarhansadik262](https://github.com/mohammadfarhansadik262) |

*Course: **CSE115** | Section: **04** | Faculty: **MSRb***

---

## 🚀 Key Features
*   **Classic Gameplay:** Navigate the snake using arrow keys to collect food and grow longer.
*   **Smooth Gameplay Loop:** Optimized frame-rate handling for responsive snake movement.
*   **Grid-Based Movement:** Smooth rendering and coordinate tracking for fluid control.
*   **Dynamic Speed Scaling:** The game increases in difficulty/speed as the snake grows longer.
*   **Score & High-Score System:** Tracks current score in real-time and saves the all-time high score to a localized data file.
*   **Collision Detection:** Strict boundary and self-collision handling for precise game-over triggers.

---

## 🎮 Controls
* `W` — Move Up
* `A` — Move Left
* `S` — Move Down
* `D` — Move Right
  
---

## 🗃️ Repository Architecture
This repository strictly follows the course layout rules:
*   `main.c` — The primary entry point containing the core game loop.
*   `requirements.txt` — Compilation and system library dependencies.
*   `README.md` — Repository documentation and execution guide (***this file***).
*   📂 `data/` — Local storage for high scores, custom maps, or configurations.
*   📂 `support/` — Modular C source files (e.g., snake mechanics, food spawning, display layout).
*   📂 `others/` — Contains academic documentation, project reports, presentations, and demo videos.

---

## 🛠️ How to Compile and Run

### Prerequisites
*   A C compiler installed (GCC recommended) or an IDE like Code::Blocks.

### Execution Instructions

1. Clone the repository to your local machine:
```bash
git clone https://github.com/ArikAhnaf-2026Cypher/Group-04-Classic-Snake-Game-c.git
```
2. Navigate into the project root directory:
```bash
cd Group-04-Classic-Snake-Game-c
```
3. Compile the source code using GCC:
```bash
gcc main.c -o SnakeGame
```
4. Launch the game executable:
```bash
./SnakeGame
```
