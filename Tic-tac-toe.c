#include <stdio.h>
#include <stdlib.h>

char square[10] = {'0','1','2','3','4','5','6','7','8','9'};
int choice,player;

int checkForWin();
void displayBoard();
void markBoard(char mark);

int main(){

  int gameStatus;
  char mark;

  player = 1;
  do{
    displayBoard();
    player = (player %2 ) ? 1 : 2;

    printf("Player %d, enter a number: ", player);
    scanf("%d", &choice);

    if (choice < 1 || choice > 9 || square[choice] != (choice + '0')) {
      printf("INVALID MOVE! Please try again.\nYou will return to the board in 3 seconds.");
      sleep(3);
      continue; 
    }

    mark = (player ==1) ? 'x' : 'o';

    markBoard(mark);

    gameStatus = checkForWin();
  

    player++;
  }while(gameStatus == -1);

  displayBoard();

  if (gameStatus==1){
    printf("Player %d won",--player);
  }
  if (gameStatus==0){
    printf("Draw!!");
  }

  

  return 0;
}

// Function to return game status
// 1 for game is over with results
// -1 for game is in progress
// 0 game is over and no result

int checkForWin(){
  int returnValue = 0;
  if (square[1]==square[2] && square[2]==square[3]){
    returnValue=1;
  }
  else if(square[4]==square[5]&&square[5]==square[6]){
    returnValue = 1;
  }  
  else if(square[7]==square[8]&&square[8]==square[9]){
    returnValue = 1;
  }
  else if(square[1]==square[5]&&square[5]==square[9]){
    returnValue = 1;
  }  
  else if(square[3]==square[5]&&square[5]==square[7]){
    returnValue = 1;
  }  
  else if(square[1]==square[4]&&square[4]==square[7]){
    returnValue = 1;
  }
  else if(square[2]==square[5]&&square[5]==square[8]){
    returnValue = 1;
  }  
  else if(square[3]==square[6]&&square[6]==square[9]){
    returnValue = 1;}
  else if(square[1] !='1' && square[2] !='2' && square[3] !='3' && square[4] !='4' && square[5] !='5' &&
   square[6] !='6' && square[7] !='7' && square[8] !='7' && square[9] !='9'){
    returnValue = 0;
  }
  else{
    returnValue = -1;
  }

  return returnValue; 
}


//func to draw board

void displayBoard(){
  system("cls");
  printf("Player1 (x)  -  Player(2) (o) \n\n\n");

  printf("    |    |    \n");
  printf(" %c  | %c  | %c \n",square[7],square[8],square[9]);
  printf("--------------\n");

  printf("    |    |    \n");
  printf(" %c  | %c  | %c \n",square[4],square[5],square[6]);
  printf("--------------\n");

  printf("    |    |    \n");
  printf(" %c  | %c  | %c \n",square[1],square[2],square[3]);
  
}
//set the board with x or o

void markBoard(char mark) {
  // Mark the square with the player's symbol
  square[choice] = mark;
  }
