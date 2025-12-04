# Winter-Little-Games

Console C++ mini-games for the winter term. Each folder is self-contained; build with any C++17 compiler.

## Games

- **Pick Card** (`pick-card/`): Draws a random playing card until you exit.
- **Sentence Counter** (`sentence-counter/`): Counts the number of words in a sentence and repeats on demand.
- **Typing Speed** (`typing-speed/`): Timed alphabet typing challenge with best-time tracking.

## How to run

From each game folder:

```bash
g++ -std=c++17 -O2 -pipe -o game main.cpp
./game
```

Rename `game` to any executable name you prefer.
