#include <iostream>
#include <fstream>
#include <string>
#include <random>
#include <vector>
 int random_int(int min, int max) {
    static std::default_random_engine engine { std::random_device{}() };
    std::uniform_int_distribution<int> distro{min, max};
    return distro(engine);
}

using namespace std;
string sqName(int i){
    string name;
    if (i ==0){
        name = "Fo";
    }
    if(i==1){
        name= "Ca";
    }
    if(i==2){
        name = "Ri";
    }
    if(i==3){
        name = "Pl";
    }
    if(i==4){
        name = "Mo";
    }
    return name;
}
int main(){

    int pl = 0;
    cout << "Please choose number of players: ";
    cin >> pl;
    ofstream outfile("test.rr");
    vector<string> pList;

    outfile << "RoadRaceDoc" << "00000000000" << endl;
    outfile << "alias" << " Name none" << " Password" << " Irrelevant" <<endl;
    outfile << "round 1"<< endl;
    outfile << "players ";
    int index= 0;
    while (index < pl){
        cout << "Please put in player names";

        string name;
                cin >> name;
        pList.push_back(name);
             outfile << name << ",";
        index++;
    }
    if(pl<4){
        index = pl;
        while(index <= 4){
            pList.push_back("");
            index++;
        }
    }
    outfile << endl;
    index = 0;
    while( index < pl){
        int Go = 0;
        int Wo = 0;
        int sto = 0;
        int Wa = 0;
        Go = random_int(0,100);
        Wo = random_int(0,100);
        sto = random_int(0,100);
        Wa= random_int(0,100);
        string name = pList.at(index);
        outfile << "info " <<  name << " resources " << "Go," << Go << " Wa," << Wa << " Sto," << sto << " Wo," << Wo << " status score,0 start_time,000000"<<endl;
            index++;
        }
    cout << "Please enter game height ";
        int hit;
        int wid;
    cin >> hit;
        cout << "Please enter game width";
    cin >> wid;
    outfile << "board " << hit << "," << wid << endl;
        int i = 1;
        while (i <= hit){
            int i2=1;
            while(i2<= wid){
                int sq = random_int(0,4);
                string sqn = sqName(sq);
                string prN;
                if ((i2 == 1) && (i == 1)){
                    prN = pList.at(0);
                }
                else if ((i2 == wid) && (i == 1) && (pList.at(1) !="")){
                    prN = pList.at(1);
                }
                else if((i2 == 1) && (i == hit) && (pList.at(2) != "")){
                    prN = pList.at(2);
                }
                else if ((i2 == wid) && (i == hit) && (pList.at(3) != "")){
                    prN = pList.at(3);
                }
                else{
                    prN = "No";
                }
                outfile << sqn <<"," << "No," << prN << " ";
                i2++;
            }
            outfile << endl;
            i++;
        }
    outfile << "EndRoadRaceDoc" << endl;
    outfile.close();

}
