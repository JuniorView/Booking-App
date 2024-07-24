#include <QCoreApplication>
#include <QApplication>
#include "travelagencyui.h"
#include "travelagency.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //TravelAgency agency;
    shared_ptr<TravelAgency> agency = make_shared<TravelAgency>();
    Travelagencyui travelagencyui(agency);
    travelagencyui.setWindowTitle("Up and away");
    travelagencyui.show();

    /*char input;
    bool laufzeit = true;

    while(laufzeit){
        TravelAgency travelAgency;
        cout<<endl;
        cout << "JSON- oder Binaerdatei lesen?" << endl
             << "j- eingeben fuer JSON-Datei" << endl
             << "b- eingeben fuer Binaerdatei" << endl;
        cin >> input;
        switch(input){
        case 'j' :
            try {
            agency.readFile("bookings.json");
            agency.displayBooking();
        }catch (invalid_argument& err) {
                cout<<err.what()<<endl;
                bool iscorrect =false;
                char answer;
                while(!iscorrect){
                    cout<<"Haben Sie schon die Datei korrigiert ? (j/n) \n";
                    cin>>answer;
                    if(answer=='n' || answer=='N'){
                        cout<<"correct first the json file and try again\n";
                    }else if(answer=='j' || answer=='J'){
                        iscorrect=true;
                    }
                }
            }catch(runtime_error& e){
                cout<<e.what()<<endl;
                laufzeit=false;
            }catch (...) {
            cout << "Unbekannter Fehler";
        }

            break;

        case 'b' :
            agency.readBinaryFile("bookingsBinary.bin");
            agency.displayBooking();
            break;

        default :
            cout << "falsche Eingabe" << endl;
        }
    }*/

    return a.exec();
}
