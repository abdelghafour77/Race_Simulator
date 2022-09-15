#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Structures section
struct Race{
    int numberOfLaps;
    int currentLap;
    char firstPlaceDriverName[30];
    char firstPlaceRaceCarColor[30];
};

struct RaceCar{
    char driverName[30];
    char raceCarColor[20];
    int totalLapTime;
};

// Print functions section

void printIntro(){
    printf("\nBienvenue a notre evenement principal, les fans de course numerique !\nJ espere que tout le monde a pris son gouter car nous allons commencer !\n");
}

void printCountDown(){
    printf("\nCoureurs prets ! Dans...\n");
    for(int i=5;i>0;i--){
        delay(1);
        printf("%d\n",i);
    }
    printf("Course !\n");
}
void printFirstPlaceAfterLap(struct Race race){
    printf("\nApres le tour numero %d\nLa premiere place est occupee par : %s\ndans la voiture de course %s !\n",race.currentLap,race.firstPlaceDriverName,race.firstPlaceRaceCarColor);
}
void printCongratulation(struct Race race){
    printf("\n\tFelicitons tous %s,\n\tdans la voiture de course %s, pour son incroyable performance.\n\tC etait vraiment une belle course et bonne nuit a tous !\n",race.firstPlaceDriverName,race.firstPlaceRaceCarColor);
}

// Logic functions section

void delay(int number_of_seconds)
{
    // Converting time into milli_seconds
    int milli_seconds = 1000 * number_of_seconds;

    // Storing start time
    clock_t start_time = clock();

    // looping till required time is not achieved
    while (clock() < start_time + milli_seconds);
}

int calculateTimeToCompleteLap(){
    int vitesse=(rand() %3)+1 ,acceleration=(rand() % 3)+1 ,nerves=(rand() % 3)+1 ;
    return (vitesse+acceleration+nerves);
}

void updateRaceCar(struct RaceCar * racecar){
    racecar->totalLapTime=racecar->totalLapTime+calculateTimeToCompleteLap();
}

void updateFirstPlace(struct Race *race, struct RaceCar *racecar1, struct RaceCar *racecar2){
    if (racecar1->totalLapTime<=racecar2->totalLapTime){
        strcpy(race->firstPlaceDriverName,racecar1->driverName);
        strcpy(race->firstPlaceRaceCarColor,racecar1->raceCarColor);
    }else{
        strcpy(race->firstPlaceDriverName,racecar2->driverName);
        strcpy(race->firstPlaceRaceCarColor,racecar2->raceCarColor);
    }
}

void startRace(struct RaceCar *raceCar1, struct RaceCar* raceCar2){
    struct Race race={5,1,"",""};
    for(int i =1; i<=race.numberOfLaps;i++){
        delay(1);
        race.currentLap=i;
        updateRaceCar(raceCar1);
        updateRaceCar(raceCar2);
        updateFirstPlace(&race,raceCar1,raceCar2);
        printFirstPlaceAfterLap(race);
    }
    delay(1);
    printCongratulation(race);

}

int main()
{
    struct RaceCar racecar1={"abdelghafour","red"};
    struct RaceCar racecar2={"ahmed","black"};
    srand(time(0));
    printIntro();
    printCountDown();

    startRace(&racecar1,&racecar2);
};
