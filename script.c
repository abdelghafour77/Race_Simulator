#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Structures section
struct Race {
  int numberOfLaps;
  int currentLap;
  char firstPlaceDriverName[40];
  char firstPlaceRaceCarColor[20];
};

struct RaceCar {
  char driverName[40];
  char raceCarColor[20];
  int totalLapTime;
};

// Print functions section
void printIntro(){
  printf("Welcome to our main event digital race fans!\nI hope everybody has their snacks because we are about to begin!\n");
}

void printCountDown(){
  printf("Racers Ready! in...\n");

  for(int i =5; i>0;i--){
    clock_t start_time = clock();
    while (clock() < start_time + 10000);
    printf("\n%d",i);
  }
  printf("Race !\n");
}

void printFirstPlaceAfterLap(struct Race race){
  printf("After lap number %d\nFirst Place Is: %s in the %s race car!\n",  race.currentLap, race.firstPlaceDriverName,race.firstPlaceRaceCarColor);
}

void printCongratulation(struct Race race){
  printf("Let's all congratulate %s in the %s race car for an amazing performance.\nIt truly was a great race and everybody have a good day!\n",race.firstPlaceDriverName, race.firstPlaceRaceCarColor);
}

// Logic functions section
int calculateTimeToCompleteLap(){
  int speed,acceleration, nerves;
  speed = rand()%3+1;
  acceleration = rand()%3+1;
  nerves = rand()%3+1;
  printf("\n%d\n", speed+acceleration+nerves);
  return speed+acceleration+nerves;
}

void updateRaceCar(struct RaceCar* raceCar){
  raceCar->totalLapTime+=calculateTimeToCompleteLap();
}

void updateFirstPlace(struct Race *race, struct RaceCar *raceCar1, struct RaceCar *raceCar2){
  //using strcpy and if else shorthand to assigne values
  strcpy(race->firstPlaceDriverName, (raceCar1->totalLapTime<raceCar2->totalLapTime) ? (raceCar1->driverName) : (raceCar2->driverName));
  strcpy(race->firstPlaceRaceCarColor , (raceCar1->totalLapTime<raceCar2->totalLapTime) ? (raceCar1->raceCarColor) : (raceCar2->raceCarColor));
}

void startRace(struct RaceCar *raceCar1, struct RaceCar *raceCar2){
  struct Race race={5,1,"",""};
  for(int i=0;i<race.numberOfLaps;i++){
    updateRaceCar(raceCar1);
    updateRaceCar(raceCar2);
    updateFirstPlace(&race,raceCar1,raceCar2);
    printFirstPlaceAfterLap(race);
  }
  printCongratulation(race);
}
int main() {
	srand(time(0));
  struct RaceCar dacia= {"Ahmed","Pink",0};
  struct RaceCar ferari= {"Aymane","Black", 0};
  printIntro();
  printCountDown();
  startRace(&
  dacia,&ferari);
};