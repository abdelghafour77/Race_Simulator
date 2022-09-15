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
        printf("%d\n",i);
    }
    printf("Course !\n");
}
void printFirstPlaceAfterLap(struct Race race){
    printf("\nApres le tour numero %d\nLa premiere place est occupee par : %s\ndans la voiture de course %s !\n",race.numberOfLaps,race.firstPlaceDriverName,race.firstPlaceRaceCarColor);
}
void printCongratulation(struct Race race){
    printf("\nFelicitons tous %s,\ndans la voiture de course %s, pour son incroyable performance.\nC etait vraiment une belle course et bonne nuit a tous !\n",race.firstPlaceDriverName,race.firstPlaceRaceCarColor);
}

// Logic functions section

int calculateTimeToCompleteLap(){
    int vitesse=(rand() %3)+1 ,acceleration=(rand() % 3)+1 ,nerves=(rand() % 3)+1 ;
    return (vitesse+acceleration+nerves);
}

void updateRaceCar(struct RaceCar * racecar){
    racecar->totalLapTime=racecar->totalLapTime+calculateTimeToCompleteLap();
}

void updateFirstPlace(struct Race *race, struct RaceCar *racecar1, struct RaceCar *racecar2){
    if (racecar1->totalLapTime<racecar2->totalLapTime){
        strcpy(race->firstPlaceDriverName,racecar1->driverName);
        strcpy(race->firstPlaceRaceCarColor,racecar1->raceCarColor);
    }else{
        strcpy(race->firstPlaceDriverName,racecar2->driverName);
        strcpy(race->firstPlaceRaceCarColor,racecar2->raceCarColor);
    }
}

void startRace(struct RaceCar *raceCar1, struct RaceCar* raceCar2){
    struct Race race={5,1,"",""};
    for(int i =0; i<race.numberOfLaps;i++){
        raceCar1->totalLapTime+=calculateTimeToCompleteLap();
        raceCar2->totalLapTime+=calculateTimeToCompleteLap();
        if (raceCar1->totalLapTime>raceCar2->totalLapTime){
            strcpy(race.firstPlaceDriverName,raceCar1->driverName);
            strcpy(race.firstPlaceRaceCarColor,raceCar1->raceCarColor);
        }else{
            strcpy(race.firstPlaceDriverName,raceCar2->driverName);
            strcpy(race.firstPlaceRaceCarColor,raceCar2->raceCarColor);

        }
        printFirstPlaceAfterLap(race);
    }
    printCongratulation(race);

}

int main()
{
    struct RaceCar racecar1={"abdelghafour","red",1};
    struct RaceCar racecar2={"ahmed","black",1};
    srand(time(0));
    printIntro();
    printCountDown();

    startRace(&racecar1,&racecar2);
};
