#define LEDP 2 //LED Player - Victory / Invalid Movement as explained in github
#define LEDN 3 //LED North  - ON = possible movement, OFF = invalid movement
#define LEDE 4 //LED East   - ON = possible movement, OFF = invalid movement
#define LEDS 5 //LED South  - ON = possible movement, OFF = invalid movement
#define LEDW 6 //LED West   - ON = possible movement, OFF = invalid movement

//Buttons (North, East, South, West and Reset)
#define BN A0
#define BE A1
#define BS A2
#define BW A3
#define BR A4

//Hardcoded maze
/*
	Legend:
		3 -> Empty player position (player can go there)
		4 -> Initial player position (similar to 3, but its the initial)
		5 -> Final door (it's not possible to the player to get there, cause it's a wall, but the player will win when he/she come to the room that has the final door)
		0 -> Empty walls (player can go through but not stay here)
		1 -> Solid walls (player can't go through)
		2 -> Corner (Not acessible since they're in the diagonals, just here to fill the matrix)
*/
int maze [17][23] = {{2, 5, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2}, {1, 3, 0, 3, 0, 3, 0, 3, 0, 3, 1, 3, 0, 3, 0, 3, 1, 3, 0, 3, 0, 3, 1}, {2, 1, 2, 0, 2, 1, 2, 1, 2, 0, 2, 1, 2, 0, 2, 0, 2, 0, 2, 1, 2, 1, 2}, {1, 3, 0, 3, 1, 3, 0, 3, 0, 3, 0, 3, 0, 3, 1, 3, 1, 3, 0, 3, 0, 3, 1}, {2, 0, 2, 1, 2, 0, 2, 1, 2, 0, 2, 1, 2, 1, 2, 0, 2, 1, 2, 0, 2, 0, 2}, {1, 3, 1, 3, 0, 3, 0, 3, 1, 3, 1, 3, 0, 3, 1, 3, 0, 3, 1, 3, 1, 3, 1}, {2, 0, 2, 0, 2, 1, 2, 1, 2, 0, 2, 0, 2, 0, 2, 1, 2, 0, 2, 1, 2, 0, 2}, {1, 3, 1, 3, 0, 3, 1, 3, 0, 3, 1, 3, 1, 3, 0, 3, 0, 3, 1, 3, 0, 3, 1}, {2, 0, 2, 1, 2, 0, 2, 0, 2, 1, 2, 1, 2, 1, 2, 0, 2, 1, 2, 0, 2, 0, 2}, {1, 3, 1, 3, 0, 3, 1, 3, 0, 3, 0, 3, 0, 3, 1, 3, 0, 3, 0, 3, 1, 3, 1}, {2, 0, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 0, 2, 1, 2, 1, 2, 1, 2, 0, 2}, {1, 3, 1, 3, 0, 3, 1, 3, 0, 3, 0, 3, 0, 3, 1, 3, 0, 3, 1, 3, 0, 3, 1}, {2, 0, 2, 0, 2, 0, 2, 0, 2, 1, 2, 1, 2, 1, 2, 0, 2, 0, 2, 0, 2, 1, 2}, {1, 3, 0, 3, 1, 3, 0, 3, 1, 3, 0, 3, 1, 3, 0, 3, 1, 3, 1, 3, 0, 3, 1}, {2, 1, 2, 1, 2, 1, 2, 1, 2, 0, 2, 1, 2, 0, 2, 0, 2, 1, 2, 1, 2, 0, 2}, {1, 3, 0, 3, 0, 3, 0, 3, 0, 3, 0, 3, 0, 3, 1, 3, 0, 3, 0, 4, 0, 3, 1}, {2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2}};


//coordinates of player in the matrix
int I, J;

int pi, pj;
bool button_pressed;

//Find your initial position (4)
void setupStartCoords() {
  for (int i = 0; i < 17; ++i)
  {
    for (int j = 0; j < 23; ++j)
    {
      if (maze[i][j] == 4){
        I = i;
        J = j;
        break;
      }
    }
  }
}

//Checks if you won the game (i.e. you are located at the cell that has the end door)
bool isDoorNext() {
  if (maze[I+1][J] == 5) return true;
  if (maze[I-1][J] == 5) return true;
  if (maze[I][J+1] == 5) return true;
  if (maze[I][J-1] == 5) return true;
  return false;
}

//Determine if the movement is valid
bool canMove(int pi, int pj) {
  return !maze[I+pi][J+pj];
}

//Turn leds on according to possible movements
void render() {
  digitalWrite(LEDP, isDoorNext());
  digitalWrite(LEDN, canMove(-1, 0));
  digitalWrite(LEDE, canMove(0, 1));
  digitalWrite(LEDS, canMove(1, 0));
  digitalWrite(LEDW, canMove(0, -1));
}

//Poor logic to get pressed button (Assuming there's only one pressed at once)
void getDirection() {
	//pi and pj are global variables that represent the next movement for i and j (displacement)

    pi = pj = 0;
    int d;
    d = analogRead(BN); // Reads input from North
    if (d > 1000 && !button_pressed) { //If first press of North after releasing
      pi = -1; 
      button_pressed = 1;
      return;
    }
    if (d <= 1000) //If not pressing North (cause else won't work)
    	d = analogRead(BE); // Reads input from East
    if (d > 1000 && !button_pressed) { //If first press of East after releasing
      pj = 1; 
      button_pressed = 1;
      return;
    }
    if (d <= 1000) //If not pressing East (cause else won't work)
    	d = analogRead(BS); // Reads input from South
    if (d > 1000 && !button_pressed) { //If first press of South after releasing
      pi = 1; 
      button_pressed = 1;
      return;
    }
    if (d <= 1000) //If not pressing South (cause else won't work)
    	d = analogRead(BW); // Reads input from West
    if (d > 1000 && !button_pressed) { //If first press of East after releasing
      pj = -1; 
      button_pressed = 1;
      return;
    }

    if (d <= 1000) { // If no button is pressed, remove the buttonlock (avoid sending multiple requests)
      button_pressed = 0;  
    }
}

//Invalid movement led blink
void blinkLED() {
  int a = 1;
  for (int i = 0; i < 6; i++) {
    digitalWrite(LEDP, a);
    a = !a;
    delay(90);
  }
}

//Applies the requested movement, if possible, else blink
void processMovement() {
    getDirection();

    //Avoid unnecessary calculations when there is no movement requested
    if (pi == 0 && pj == 0) return;
    
    if (canMove(pi,pj)) {
      I += 2*pi;
      J += 2*pj;
    }
    else {
      blinkLED();
    }
}

void setup() {
    button_pressed = false;
  
    setupStartCoords();

    Serial.begin(9600);

    pinMode(LEDN, OUTPUT);
    pinMode(LEDE, OUTPUT);
    pinMode(LEDS, OUTPUT);
    pinMode(LEDW, OUTPUT);
    pinMode(LEDP, OUTPUT);
}


void loop()
{

  if (analogRead(BR) > 1000) setup();
  
  
  render();
  processMovement();
  delay(10);
}
