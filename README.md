# Arduino Transdimentional Maze
This is the first release of Transdimentional Maze. It's a game for arduino that simulates a first person perspective of an adventure over a maze.

## How to play

The game is played using 4 push buttons and 5 leds. Each button sends to the code which direction to move (North, East, South or West). 4 of 5 leds show possible movements within the square (cell of the maze) the player is located (you can think of it as a room with 4 doors, where each activated led is an open door that you can go in). The 5th led blinks when the player tries to make an invalid movement (e.g. walk into a closed door, indicated by a led off) and turns on when the player wins (i.e. escapes the maze).

## Features (W.I.P) - Playable

Due to deadlines, the group was not able to implement all the planned features, but here is a complete list of all of them:

- [x] Python script to generate matrix representation out of human readable mazes
- [x] Visualization of the surroundings of the maze using 4 leds (1x1 cell)
- [ ] Visualization of the surroundings of the maze using 24 leds (3x3 cell)
- [x] Move buttons and camera adapting to new position
- [x] Blink led when invalid movement
- [x] Turn led on on victory
- [ ] Random maze generator
- [x] Reset button
- [ ] Display to show passed time (speedrun like) (that's why we used analogic pins for buttons, but we ended up not using the display, so there are a bunch of digital pins free now)
- [ ] Levels of dificulty (1x1, 2x2 ou 3x3 grid)
- [ ] Send maze to android by bluetooth


## Components (For implemented features): 

* 1 Arduino with 9 ports (the code uses 5 digital pins and 4 analog (due to Display), but it is not needed to be analogic (changes needed to the code))
* 5 LEDs
* 4 Buttons

![Circuit conections image](http://i.imgur.com/cpwzk4F.png)

### Pin mapping:

#### LEDS:
* 2 -> Victory / Invalid Movement LED
* 3 -> North door LED
* 4 -> East door LED
* 5 -> South door LED
* 6 -> West door LED

#### Buttons:

* A0 -> North button
* A1 -> East button
* A2 -> South button
* A3 -> West button

## How the code works (TODO)

### Maze Translation

There is a python script we made that converts human readable mazes (sort of) to a number matrix that is exported (manually) to arduinos code (hardcoded by now).

TODO: PUT RAW MAZE EXAMPLE
OBS: We plan to add a feature that randomizes new mazes, so hardcoding will not be necessary anymore.

### REST OF THE CODE. TODO: EXPLAIN

## Group:

* Dalton Hiroshi Sato
* Marcus Vinicius Castelo Branco Martins
* Vinícius Eduardo de Araújo
* Vitor Souza Amim

