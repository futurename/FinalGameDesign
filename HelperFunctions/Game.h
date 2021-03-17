#include "imports.h"
#include "../Player.h"
#include "../Continent.h"
#include "MapManager.h"

enum GameStage {
    DEPLOYMENT, ATTACK, MOVE, EXCHANGE_CARDS


};

class Game {
private:
    static vector<Player> players;

    static map<string, Country> allCountries;      //<countryName, countryObject>
    static map<string, Continent> allContinents;   //<continentName, continentObject>
    const static int DEFAULT_PLAYERS = 4;
    const static int DEFAULT_NUM_UNDEPLOYED;   //defaul num of undeployed armies
    static int curPlayerIndex;
    static GameStage curGameStage;   // switch to ??
    static MapManager mapManager;

public:
    static vector<Player> getAllPlayers();

    static void initPlayersAndCountries();

    static map<string, Country> &getAllCountries();

    static void setAllCountries(map<string, Country> &countries);

    static void setAllContinents(map<string, Continent> &continents);

    static map<string, Continent> &getAllContinents();

    static void printAllCountries();

    static void printAllContinents();

    static void attackFrom(Country attacker, Country defender);

    static bool isContinentConquered(int index, const string &continentName);

    static void initPlayers();

    static void assignCountriesToPlayers();

    static void checkInitContinentsOwner();


    static bool deployArmy(Country& country, Player& player, int numToDeploy);

    static void conquerTheCountry(Country &attackCountry, Country &defendCountry);

    static void setCurPlayerIndex(int index);

    static int getCurPlayerIndex();

    static void setGameStage(GameStage stage);

    static GameStage getGameStage();

    static void runGame();
    //initiallize everything (call mapmanager.start())
    //WHILE(True)




};
