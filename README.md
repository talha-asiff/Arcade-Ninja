# 🥷 Naruto vs. Sasuke — Arcade Fighting Game

A 2D local multiplayer, arcade-style fighting game inspired by *Naruto*, built from scratch in **C++** using the **Raylib** graphics and audio library. Pit Naruto Uzumaki against Sasuke Uchiha in a classic 1v1 showdown complete with sprite animations, animated backgrounds, and background music.

---

## 📸 Screenshots
![Gameplay Screenshot 1](https://i.ibb.co/WvpPy6vN/image.png)

![Gameplay Screenshot 2](https://i.ibb.co/0RbXd7y4/image.png)

![Gameplay Screenshot 3](https://i.ibb.co/YBbs6xBr/image.png)
---

## 🛠️ Tech Stack

* **Language:** C++[cite: 1]
* **Graphics & Windowing:** [Raylib](https://www.raylib.com/) (`InitWindow`, `DrawTexture`, `DrawTexturePro`, `DrawTextureEx`)[cite: 1]
* **Audio Engine:** Raylib Audio (`InitAudioDevice`, `LoadMusicStream`, `UpdateMusicStream`)[cite: 1]
* **Animation:** Frame-by-frame sprite toggling & dynamic GPU texture updating for animated GIF backgrounds (`LoadImageAnim`, `UpdateTexture`)[cite: 1]

---

## ✨ Features

* **2-Player Local Multiplayer:** Play head-to-head on a single keyboard as **Naruto (Player 1)** and **Sasuke (Player 2)**[cite: 1].
* **Animated Title & Intro Sequence:** Features a custom developer splash screen, animated GIF stage backdrop, flashing start prompt, and a classic `"FIGHT!"` round transition[cite: 1].
* **Dynamic Character Animations:** Distinct sprite states for idle stances, running, jumping, and two separate melee attack combos per character[cite: 1].
* **Combat & Health:** Attacks damage opponents within melee range, health bars track each fighter, and the winner is announced when a fighter is defeated.
* **Automatic Sprite Scaling:** Dynamically scales Sasuke's sprites relative to Naruto's sprite dimensions for consistent proportions on screen[cite: 1].
* **Background Music:** Continuous looping soundtrack powered by Raylib's audio stream system[cite: 1].

---

## 🎮 Controls

### Menu
| Action | Key |
| :--- | :--- |
| **Start Game** | `P`[cite: 1] |

### Player 1 — Naruto
| Action | Key |
| :--- | :--- |
| **Move Left** | `A`[cite: 1] |
| **Move Right** | `D`[cite: 1] |
| **Jump** | `Space`[cite: 1] |
| **Punch Combo** | `R`[cite: 1] |
| **Special / Fight Attack** | `F`[cite: 1] |

### Player 2 — Sasuke
| Action | Key |
| :--- | :--- |
| **Move Left** | `J`[cite: 1] |
| **Move Right** | `L`[cite: 1] |
| **Jump** | `Enter`[cite: 1] |
| **Punch Combo** | `[` (Left Bracket)[cite: 1] |
| **Special / Fight Attack** | `]` (Right Bracket)[cite: 1] |

---

## 📂 Project Structure

```text
├── main.cpp                # Core game loop, rendering, physics, and input handling
├── assets/
│   ├── background.gif      # Animated stage background
│   ├── logo.png            # Title screen logo
│   ├── naruto*.png         # Naruto idle, run, punch, and attack sprites
│   └── sasuke*.png         # Sasuke idle, run, punch, and attack sprites
└── audio/
    └── bg1.mp3             # Background music track
```

## 🚀 Getting Started

### Prerequisites
* A C++ compiler (`g++`, `clang++`, or MSVC)
* [Raylib](https://github.com/raysan5/raylib) installed on your system

### Build & Run

#### Linux / macOS
```bash
g++ main.cpp -o NarutoFighter -lraylib -lGL -lm -lpthread -ldl -lrt -lX11
./NarutoFighter
```
