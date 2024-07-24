#include "travelagencyui.h"
#include "ui_travelagencyui.h"
#include "flightbooking.h"
#include "hotelbooking.h"
#include "trainticket.h"
#include "rentalcarreservation.h"
#include <QFileDialog>
#include <QMessageBox>
#include <QDate>
#include <QInputDialog>
Travelagencyui::Travelagencyui(shared_ptr<TravelAgency> travelagency ,QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Travelagencyui),
    travelagency(travelagency),
    check(travelagency)
{
    ui->setupUi(this);
    ui->customerGroupBox->setVisible(false); //hide the customerGroupBox
    ui->travelGroupBox->setVisible(false);
    ui->bookingGroupBox->setVisible(false);
    ui->tabWidget->setTabIcon(0,QIcon("plane.png"));
    ui->tabWidget->setTabIcon(1,QIcon ("Car.png"));
    ui->tabWidget->setTabIcon(2,QIcon ("hotel.png"));
    ui->tabWidget->setTabIcon(3,QIcon ("train.png"));

    ui->savePushButton->setEnabled(false);
    ui->cancelPushButton->setEnabled(false);

    // connect Signal to Slot for enabling button wenn the lineEdit are clicked or edited
    connect(ui->fromDateEdit,&QDateEdit::editingFinished,this, &Travelagencyui::enableButtons);
    connect(ui->toDateEdit,&QDateEdit::editingFinished,this, &Travelagencyui::enableButtons);
    connect(ui->priceSpinBox,&QDoubleSpinBox::editingFinished,this, &Travelagencyui::enableButtons);
    // Connect signals to slots for enabling buttons when flight booking details are clicked and edited
    connect(ui->airlineEdit, &QLineEdit::editingFinished, this, &Travelagencyui::enableButtons);
    connect(ui->fromDateFlug, &QLineEdit::editingFinished, this, &Travelagencyui::enableButtons);
    connect(ui->toDateflug, &QLineEdit::editingFinished, this, &Travelagencyui::enableButtons);
    connect(ui->bookingclassFlug, &QLineEdit::editingFinished, this, &Travelagencyui::enableButtons);
    // Connect signals to slots for enabling buttons when car rental details are clicked and edited
    connect(ui->pickuplocationEdit, &QLineEdit::editingFinished, this, &Travelagencyui::enableButtons);
    connect(ui->returnlocationedit, &QLineEdit::editingFinished, this, &Travelagencyui::enableButtons);
    connect(ui->companyedit, &QLineEdit::editingFinished, this, &Travelagencyui::enableButtons);
    connect(ui->vehicleclassedit, &QLineEdit::editingFinished, this, &Travelagencyui::enableButtons);
    // Connect signals to slots for enabling buttons when hotel booking details are clicked and edited
    connect(ui->hotelEdit, &QLineEdit::editingFinished, this, &Travelagencyui::enableButtons);
    connect(ui->townEdit, &QLineEdit::editingFinished, this, &Travelagencyui::enableButtons);
    connect(ui->roomtypeedit, &QLineEdit::editingFinished, this, &Travelagencyui::enableButtons);
    //Connect signals to slots for enabling buttons when train booking details are clicked and edited
    connect(ui->fromDestEdit, &QLineEdit::editingFinished,this,&Travelagencyui::enableButtons);
    connect(ui->toDestEdit, &QLineEdit::editingFinished,this,&Travelagencyui::enableButtons);
    connect(ui->departureTimeEdit, &QTimeEdit::editingFinished,this,&Travelagencyui::enableButtons);
    connect(ui->arrivalTimeEdit, &QTimeEdit::editingFinished,this,&Travelagencyui::enableButtons);
   // connect signals to checkslot.
    connect(this,checkSignal,this,slotCheck);
}

Travelagencyui::~Travelagencyui()
{
    delete ui;

}

void Travelagencyui::on_actionEinlesen_triggered()
{
    ui->customerGroupBox->setVisible(false);
    QString filename= QFileDialog::getOpenFileName(this,tr("open a File"),"",tr("JSON Files (*.json)"));
    bool isFileValid=true;
    while(isFileValid){
        try{
            travelagency->readFile(filename);
            travelagency->readIataCodes("iatacodes.json");
            //addToList();

//            // texture check
//            QString message ;
//            if(!check.checkTravelsDisjunct(message)){
//                QMessageBox::critical(nullptr, "Error", message);
//            }
            check() ;
            ui->statusbar->showMessage("<html><b>Datei erfolgreich gelesen!</b></html>",7000);
            QMessageBox::information(this,"Datei erfolgreich eingelesen",travelagency->getBookinInfo());

            isFileValid=false;
        }
        catch(invalid_argument& err){
            QMessageBox mesgbox;
            mesgbox.setWindowTitle("Fehler beim Einlesen der Buchungen");
            mesgbox.setText(err.what());
            mesgbox.setInformativeText("Das Einlesen der Buchungen wurde in der betroffenen Zeile gestoppt."
                                       "Die vorangehenden Buchungen wurden erfolgreich angelegt.");

            mesgbox.setDetailedText("Wenn Sie die Datei bereits korrigiert haben, wählen Sie 'Retry'. Wählen Sie 'Discard' um alle Buchungen "
                                    "zu löschen und 'Cancel',um die vohandenen Buchungen stehenzulassen und diesen Dialog zu verlassen.");
            mesgbox.setStandardButtons(QMessageBox::Retry|QMessageBox::Discard|QMessageBox::Cancel );
            mesgbox.setDefaultButton(QMessageBox::Retry);

            mesgbox.setIcon(QMessageBox::Critical);
            int rec =mesgbox.exec();
            switch (rec) {
            case QMessageBox::Retry:
                isFileValid=true;
                break;
            case QMessageBox::Discard:
                //travelagency->clearBooking();
                // clearAllBookings();
                // clearBookingsDetails();
                isFileValid=true;
                break;
            case QMessageBox::Cancel:
                // addToList();
                isFileValid=false;

                break;
            default:
                // Should not be reached
                break;

            }

        }catch(runtime_error e){

            QMessageBox mesgbox;
            mesgbox.setText(e.what());
            mesgbox.setWindowTitle("Fehler beim Einlesen der Buchungen");
            mesgbox.setInformativeText("Das Einlesen der Buchungen wurde in der betroffenen Zeile gestoppt."
                                       "Die vorangehenden Buchungen wurden erfolgreich angelegt.");

            mesgbox.setDetailedText("Wenn Sie die Datei bereits korrigiert haben, wählen Sie 'Retry'. Wählen Sie 'Discard' um alle Buchungen "
                                    "zu löschen und 'Cancel',um die vohandenen Buchungen stehenzulassen und diesen Dialog zu verlassen.");
            mesgbox.setStandardButtons(QMessageBox::Retry|QMessageBox::Discard|QMessageBox::Cancel );
            mesgbox.setDefaultButton(QMessageBox::Retry);

            mesgbox.setIcon(QMessageBox::Critical);
            int rec =mesgbox.exec();
            switch (rec) {
            case QMessageBox::Retry:
                isFileValid=true;
                break;
            case QMessageBox::Discard:
                //travelagency->clearBooking();
                // clearAllBookings();
                // clearBookingsDetails();
                isFileValid=true;
                break;
            case QMessageBox::Cancel:
                //  addToList();
                isFileValid=false;

                break;
            default:
                // Should not be reached
                break;

            }
        }
    }
}

void Travelagencyui::on_actionsuchen_triggered()
{
     ui->customerGroupBox->setVisible(false);
     ui->travelGroupBox->setVisible(false);
     ui->bookingGroupBox->setVisible(false);
    //create an instance of customerdialog
    CustomerSearchDialog customerSearchDialog(this);

    //show the dialog
    customerSearchDialog.setWindowTitle("Kund*innenSuche");
    int result = customerSearchDialog.exec();

    if(result==QDialog::Accepted){
        long customerId= customerSearchDialog.getCustomerId();
        //perform the search
        searchCustomer(customerId);
    }else{

    }


}
bool findId(int id, vector<int> vec){
    for(auto i: vec ){
        if(id == i)
            return true;
    }
    return false;
}
void Travelagencyui::searchCustomer(long customerId){
    ui->customerGroupBox->setVisible(false);// hide the customergroupbox

    shared_ptr<Customer> customer= travelagency->findCustomer(customerId);

    if(customer != nullptr){
        // set Id ,vorname und nachname
        ui->customerIdEdit->setText(QString::number( customer->getId()));
        ui->customerNachnameedit->setText(QString::fromStdString(customer->getLastName()));
        ui->customerVornameEdit->setText(QString::fromStdString(customer->getFirstName()));
        //clear existing content
        ui->customerTravelTable->clearContents();
        ui->customerTravelTable->setRowCount(0);

        //get the Travellist
        const vector<shared_ptr<Travel>> &travelList= customer->getTravelList();


       //int rowCount=travelList.size();
       int rowCount=0;
       vector<int> countId; // zum Speichern von travelIds
       int it{};

       // compute the number of row our table,since we don,t want repetitive ids
       for(unsigned int travel_element=0; travel_element<travelList.size();travel_element++){
         shared_ptr<Travel> travel= travelList[travel_element];
         if (findId(travel->getId(),countId)){
            continue;
         }
         rowCount++; //zum hinzufügen einer zeile in der customertravelTable
         it = travel->getId();
         countId.push_back(it);
       }

      ui->customerTravelTable->setRowCount(rowCount);// set the nummber of row in the table
      countId.clear();
      vector<int> countIdd;
      int customer_table_row=-1;// to count the row of the table.

        // filling  the table
       for( unsigned int row=0; row<travelList.size();row++){
            shared_ptr<Travel> travel= travelList[row];
            if (findId(travel->getId(),countIdd)){
               continue; // skip if the id  already exists in coundid
            }
            it = travel->getId();
            countIdd.push_back(it);

            customer_table_row++;
            QTableWidgetItem* IdItem= new QTableWidgetItem (QString::fromStdString(std::to_string(it))) ;
            pair<string,string> travelDates= travel->calculateTravelDates();

            // Convert earliest start date
            QDateTime earliestStartDateTime = QDateTime::fromString(QString::fromStdString(travelDates.first), "yyyyMMdd");
            QString formattedEarliestStartDate = QLocale("de_DE").toString(earliestStartDateTime, "dddd, d. MMMM yyyy");

            // Convert latest end date
            QDateTime latestEndDateTime = QDateTime::fromString(QString::fromStdString(travelDates.second), "yyyyMMdd");
            QString formattedLatestEndDate = QLocale("de_DE").toString(latestEndDateTime, "dddd, d. MMMM yyyy");

            QTableWidgetItem* earliestStartDateTimeItem= new QTableWidgetItem(formattedEarliestStartDate);
            QTableWidgetItem* latestEndDateItem= new QTableWidgetItem(formattedLatestEndDate);

            ui->customerTravelTable->setItem(customer_table_row,0,IdItem);
            ui->customerTravelTable->setItem(customer_table_row,1,earliestStartDateTimeItem);
            ui->customerTravelTable->setItem(customer_table_row,2,latestEndDateItem);

        }
        //to make the table not editable
//        ui->customerTravelTable->setColumnWidth(0,80);
//        ui->customerTravelTable->setColumnWidth(1,200);
//        ui->customerTravelTable->setColumnWidth(2,200);
        ui->customerTravelTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
        ui->customerIdEdit->setReadOnly(true);
        ui->customerNachnameedit->setReadOnly(true);
        ui->customerVornameEdit->setReadOnly(true);

        //show travel history
        ui->customerGroupBox->setVisible(true);
    }else{
        // customerId not found
        QMessageBox::critical(this,"Error","CustomerId not found!");
        ui->customerGroupBox->setVisible(false);
    }
};

void Travelagencyui::on_travelTable_itemDoubleClicked(QTableWidgetItem *item)
{
    // create an instance of buchungsdetails
//    BuchungsDetails *buchungsDetails= new BuchungsDetails(this);
//    buchungsDetails->setWindowTitle("Buchungsdetails");

    //retireve the traveId
    QString travelIdString =ui->travelIdEdit->text();
    long travelId = travelIdString.toLong();
    shared_ptr<Travel> travel= travelagency->findTravel(travelId);

    //get the row.
    int selectedrow=ui->travelTable->row(item);
//    //int selectedcolumn=ui->travelTable->column(item); //get the column

    shared_ptr<Booking> selectedBooking= travel->getTravelBookings()[selectedrow];
    //set id
    ui->bookingIdEdit->setText(QString::fromStdString(selectedBooking->getId()));
    //set date
    QDate fromDate= QDate::fromString(QString::fromStdString(selectedBooking->getFromDate()),"yyyyMMdd");
    QDate toDate=  QDate::fromString(QString::fromStdString(selectedBooking->getToDate()),"yyyyMMdd");
    ui->fromDateEdit->setDate(fromDate);
    ui->toDateEdit->setDate(toDate);
    //set price
    ui->priceSpinBox->setMaximum(999.99);
    ui->priceSpinBox->setValue(selectedBooking->getPrice());

    if(dynamic_pointer_cast<FlightBooking>(selectedBooking)){
        //Pop-up the flug tabwidget
        ui->tabWidget->setCurrentWidget(ui->flug);
        //voherige details loeschen
        clearBookingsDetails();
        //casting selected booking to flightbooking
        shared_ptr<FlightBooking> flight= dynamic_pointer_cast<FlightBooking>(selectedBooking);
        ui->fromDateFlug->setText(QString::fromStdString(flight->getFromDestination()));
        ui->toDateflug->setText(QString::fromStdString(flight->getToDestination()));
        ui->airlineEdit->setText(QString::fromStdString(flight->getAirLine()));
        ui->bookingclassFlug->setText(QString::fromStdString(flight->getBookingClass()));

        shared_ptr<Airport> departure=travelagency->findAirport(flight->getFromDestination());
        ui->departurAirportNameEdit->setText(QString::fromStdString(departure->getName()));
        ui->departurAirportNameEdit->setReadOnly(true);
        shared_ptr<Airport> arrival=travelagency->findAirport(flight->getToDestination());
        ui->arrivalAirportNameEdit->setText(QString::fromStdString(arrival->getName()));
        ui->arrivalAirportNameEdit->setReadOnly(true);

    }else if(dynamic_pointer_cast<HotelBooking>(selectedBooking)){
        //Pop-up the flug tabwidget
        ui->tabWidget->setCurrentWidget(ui->hotel);
        //voherige details loeschen
        clearBookingsDetails();
        //casting selected booking to HotelBooking
        shared_ptr<HotelBooking> hotel= dynamic_pointer_cast<HotelBooking>(selectedBooking);
        ui->hotelEdit->setText(QString::fromStdString(hotel->getHotel()));
        ui->townEdit->setText(QString::fromStdString(hotel->getTown()));
        ui->roomtypeedit->setText(QString::fromStdString(hotel->getRoomType()));
    }else if(dynamic_pointer_cast<RentalCarReservation>(selectedBooking)){
        //Pop-up the flug tabwidget
        ui->tabWidget->setCurrentWidget(ui->mietwagen);
        //voherige details loeschen
        clearBookingsDetails();
        //casting selected booking to RentalCarReservation
        shared_ptr<RentalCarReservation> rental= dynamic_pointer_cast<RentalCarReservation>(selectedBooking);
        ui->pickuplocationEdit->setText(QString::fromStdString(rental->getPickupLocation()));
        ui->returnlocationedit->setText(QString::fromStdString(rental->getReturnLocation()));
        ui->companyedit->setText(QString::fromStdString(rental->getCompany()));
        ui->vehicleclassedit->setText(QString::fromStdString(rental->getVehicleClass()));

    }else if(dynamic_pointer_cast<TrainTicket>(selectedBooking)){

        //Pop-up the flug tabwidget
        ui->tabWidget->setCurrentWidget(ui->zug);
        //voherige details loeschen
        clearBookingsDetails();
        //casting selected booking to TrainTicket
        shared_ptr<TrainTicket> train= dynamic_pointer_cast<TrainTicket>(selectedBooking);
        ui->fromDestEdit->setText(QString::fromStdString(train->getFromDestination()));
        ui->toDestEdit->setText(QString::fromStdString(train->getToDestination()));
        ui->arrivalTimeEdit->setTime(QTime::fromString(QString::fromStdString(train->getArrivalTime()),"hh:mm"));
        ui->departureTimeEdit->setTime(QTime::fromString(QString::fromStdString(train->getDepartureTime()),"hh:mm"));
        ui->ticketTypEdit->setText(QString::fromStdString(train->getBookingClass()));

        for(unsigned int i=0;i<train->getConnectingStations().size();i++){
            QString bookingsInfo =QString::fromStdString(train->getConnectingStations()[i].StationsName);
            ui->connectionsStationlistWidget->addItem(bookingsInfo);// add the booking info as a new item in the list widget
        }
    }

     ui->bookingIdEdit->setReadOnly(true);
     ui->bookingGroupBox->setVisible(true);

}


void Travelagencyui::on_customerTravelTable_itemDoubleClicked(QTableWidgetItem *item)
{
    ui->travelGroupBox->setVisible(true);
    QIcon carIcon("Car.png");
    QIcon planeIcon("plane.png");
    QIcon hotelIcon("hotel.png");
    QIcon trainIcon("train.png");
    //retrieve the customer id from the customerIDEdit
    QString customerIdString = ui->customerIdEdit->text();
    long customerId = customerIdString.toLong();
    shared_ptr<Customer> customer = travelagency->findCustomer(customerId);

    int selectedRow = ui->customerTravelTable->row(item); // retrieve the selected row
       QTableWidgetItem *itemm =ui->customerTravelTable->item(selectedRow, 0);
       QString value = itemm->text();
       long travelIdd=value.toLong();
   // shared_ptr<Travel> selectedTravel = customer->getTravelList()[selectedRow];
       shared_ptr<Travel> selectedTravel = customer->findTravel_2(travelIdd);
    //set ID
    long travelId = selectedTravel->getId();
    QString travelIdString = QString::number(travelId);
    ui->travelIdEdit->setText(travelIdString);

    /////////////////// to schow on the map
    travelagency->displayBookingsOnMap(travelagency->findTravel(travelId));

    //get the travelBookings
    const std::vector<shared_ptr<Booking>>& travelBookings = selectedTravel->getTravelBookings();
    // Set the number of rows in the table
    int rowCount = travelBookings.size();
    ui->travelTable->setRowCount(rowCount);

    //filling the table
    for(int row=0; row < rowCount; row++ ){
        shared_ptr<Booking> booking= travelBookings[row];
        // Convert earliest start date
        QDateTime StartDateTime = QDateTime::fromString(QString::fromStdString(booking->getFromDate()), "yyyyMMdd");
        QString formattedStartDate = QLocale("de_DE").toString(StartDateTime, "dddd, d. MMMM yyyy");

        // Convert latest end date
        QDateTime EndDateTime = QDateTime::fromString(QString::fromStdString(booking->getToDate()), "yyyyMMdd");
        QString formattedEndDate = QLocale("de_DE").toString(EndDateTime, "dddd, d. MMMM yyyy");

        QTableWidgetItem *startDateItem= new QTableWidgetItem(formattedStartDate);
        QTableWidgetItem *endDateItem= new QTableWidgetItem(formattedEndDate);
        QTableWidgetItem *priceItem= new QTableWidgetItem(QString::number(booking->getPrice()));


        if(dynamic_pointer_cast<FlightBooking>(booking)){
            QTableWidgetItem *icon = new QTableWidgetItem();
            icon->setIcon(planeIcon);
            ui->travelTable->setItem(row,0,icon);


        }
        if (dynamic_pointer_cast<HotelBooking>(booking)){
            QTableWidgetItem *icon = new QTableWidgetItem();
            icon->setIcon(hotelIcon);
            ui->travelTable->setItem(row,0,icon);

        }
        if(dynamic_pointer_cast<RentalCarReservation>(booking)){
            QTableWidgetItem *icon = new QTableWidgetItem();
            icon->setIcon(carIcon);
            ui->travelTable->setItem(row,0,icon);

        }
        if(dynamic_pointer_cast<TrainTicket>(booking)){
            QTableWidgetItem *icon = new QTableWidgetItem();
            icon->setIcon(trainIcon);
            ui->travelTable->setItem(row,0,icon);

        }
      ui->travelTable->setItem(row,1,startDateItem);
      ui->travelTable->setItem(row,2,endDateItem);
      ui->travelTable->setItem(row,3,priceItem);
      ui->travelTable->setColumnWidth(0,50);
      ui->travelTable->setColumnWidth(1,200);
      ui->travelTable->setColumnWidth(2,200);
      ui->travelTable->setColumnWidth(3,200);
      ui->travelTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
      ui->travelIdEdit->setReadOnly(true); //wird nicht geändert
       // Show the QTableWidget for travel history
      ui->travelGroupBox->setVisible(true);

    }
}

void Travelagencyui::clearBookingsDetails(){
    ui->airlineEdit->clear();
    ui->fromDateFlug->clear();
    ui->toDestEdit->clear();
    ui->bookingclassFlug->clear();

    ui->pickuplocationEdit->clear();
    ui->returnlocationedit->clear();
    ui->companyedit->clear();
    ui->vehicleclassedit->clear();

    ui->hotelEdit->clear();
    ui->townEdit->clear();
    ui->roomtypeedit->clear();

    ui->departureTimeEdit->clear();
    ui->arrivalTimeEdit->clear();
    ui->fromDestEdit->clear();
    ui->toDestEdit->clear();
    ui->ticketTypEdit->clear();
    ui->connectionsStationlistWidget->clear();
};


void Travelagencyui::on_savePushButton_clicked()
{
   emit checkSignal();

  //update the selected booking
    updateSelectedBooking();

  //disable the button
    disableButtons();

  //update the the detailsview
    updateDetailsView();

}


void Travelagencyui::on_cancelPushButton_clicked()
{
    //disable the button
      disableButtons();

    //update the the detailsview
      updateDetailsView();
}

void Travelagencyui::enableButtons(){
    ui->savePushButton->setEnabled(true);
    ui->cancelPushButton->setEnabled(true);
};
void Travelagencyui::disableButtons(){
    ui->savePushButton->setEnabled(false);
    ui->cancelPushButton->setEnabled(false);
};
void Travelagencyui::updateSelectedBooking(){
     //retrieve the Id of the booking
    QString Id= ui->bookingIdEdit->text();
    shared_ptr<Booking> selectedbooking=travelagency->findBooking(Id.toStdString());

    QDate fromdate= ui->fromDateEdit->date();
    QString fromdateQString=fromdate.toString("yyyyMMdd");
    selectedbooking->setFromDate(fromdateQString.toStdString());
    QDate todate= ui->toDateEdit->date();
    QString todateQString=todate.toString("yyyyMMdd");
    selectedbooking->setToDate(todateQString.toStdString());
    long price =ui->priceSpinBox->value();
    selectedbooking->setPrice(price);

    if (dynamic_pointer_cast<FlightBooking>(selectedbooking)) {
        shared_ptr<FlightBooking> flight =dynamic_pointer_cast<FlightBooking>(selectedbooking);
        QString airlineS= ui->airlineEdit->text();
        flight->setAirline(airlineS.toStdString());
        //check if right format
        //if(ui->fromDateFlug->text().toStdString().length() == 3 && ui->toDateflug->text().toStdString().length() == 3){
        if(travelagency->findAirport( ui->fromDateFlug->text().toStdString()) &&
                travelagency->findAirport(ui->toDateflug->text().toStdString())){

            flight->setFromDestination(ui->fromDateFlug->text().toStdString());
            flight->setToDestination(ui->toDateflug->text().toStdString());

        }
        //else QMessageBox::critical(this, "Error", "wrong airport abbreviation");
        else{
            QMessageBox msgBox;
            msgBox.setWindowTitle("Error");
            msgBox.setText("Ungültiger Iata-Code");
            msgBox.setStyleSheet("QLabel{ color : red; }");
            msgBox.exec();
        }


        QString bookingClass = ui->bookingclassFlug->text();
        if(bookingClass == "Economy class"){
            flight->setBookingClass('Y');
        }
        else if(bookingClass == "Premium Economy class"){
            flight->setBookingClass('W');
        }
        else if(bookingClass == "Business class"){
            flight->setBookingClass('J');
        }
        else if(bookingClass == "First class"){
            flight->setBookingClass('F');
        }
        else QMessageBox::critical(this, "Error", "Unknown Booking Class type!");
    }
    else if (dynamic_pointer_cast<RentalCarReservation>(selectedbooking)) {
        //casting selectedBooking to RentalCarReservation
        shared_ptr<RentalCarReservation> rentalCarReservation =dynamic_pointer_cast<RentalCarReservation>(selectedbooking);
        rentalCarReservation->setPickupLocation(ui->pickuplocationEdit->text().toStdString());
        rentalCarReservation->setReturnLocation(ui->returnlocationedit->text().toStdString());
        rentalCarReservation->setCompany(ui->companyedit->text().toStdString());
        rentalCarReservation->setVehicleClass(ui->vehicleclassedit->text().toStdString());
    }
    else if (dynamic_pointer_cast<HotelBooking>(selectedbooking)) {
        //casting selectedBooking to HotelBooking
        shared_ptr<HotelBooking> hotelBooking = dynamic_pointer_cast<HotelBooking>(selectedbooking);
        hotelBooking->setHotel(ui->hotelEdit->text().toStdString());
        hotelBooking->setTown(ui->townEdit->text().toStdString());

        QString roomType = ui->roomtypeedit->text();
        if(roomType == "Einzelzimmer"){
            hotelBooking->setRoomType("EZ");
        }
        else if(roomType == "Doppelzimmer"){
            hotelBooking->setRoomType("DZ");
        }
        else if(roomType == "Apartment"){
            hotelBooking->setRoomType("AP");
        }
        else if(roomType == "Suite"){
            hotelBooking->setRoomType("SU");
        }
        else QMessageBox::critical(this, "Error", "Unknown Hotel Room type!");
    }
    else if (dynamic_pointer_cast<TrainTicket>(selectedbooking)) {
        shared_ptr<TrainTicket> train= dynamic_pointer_cast<TrainTicket>(selectedbooking);
        train->setFromDestinattion(ui->fromDestEdit->text().toStdString());
        train->settoDestination(ui->toDestEdit->text().toStdString());
        QString bookingClass= ui->ticketTypEdit->text();
        if(bookingClass== "Supersparpreis 1. Klasse")
            train->setbookingClass("SSP1");

        else if(bookingClass =="Supersparpreis 2. Klasse" )
            train->setbookingClass("SSP2");
        else if(bookingClass == "Sparpreis 1. Klasse")
             train->setbookingClass("SP1");

        else if(bookingClass == "Sparpreis 2. Klasse")
             train->setbookingClass("SP2");

        else if(bookingClass ==  "Flexpreis 1. Klasse")
                 train->setbookingClass("FP1");

        else if(bookingClass == "Flexpreis 2. Klasse")
                 train->setbookingClass("FP2");
        else QMessageBox::critical(this,"Error","unknow train type!!");

    vector <string> connections;
    for (int i = 0; i < ui->connectionsStationlistWidget->count(); ++i) {
        QListWidgetItem *item = ui->connectionsStationlistWidget->item(i);
            QString text = item->text();
            connections.push_back(text.toStdString());
    }
    train->setConnectingStations(connections);

 }
};

void Travelagencyui::updateDetailsView(){ // we will also reset the details at the same time ,if nothing were changed
    //retrieve the customer id from the customerIDEdit
    QString bookingId = ui->bookingIdEdit->text();
    shared_ptr<Booking> selectedBooking = travelagency->findBooking(bookingId.toStdString());

    //set id text
   // ui->bookingIdEdit->setText(QString::fromStdString(selectedBooking->getId()));braucht man nicht , da nicht geändert wird

    //set date
    QDate startDate = QDate::fromString(QString::fromStdString(selectedBooking->getFromDate()), "yyyyMMdd");
    ui->fromDateEdit->setDate(startDate);
    QDate endDate = QDate::fromString(QString::fromStdString(selectedBooking->getToDate()), "yyyyMMdd");
    ui->toDateEdit->setDate(endDate);

    //set price
    ui->priceSpinBox->setValue(selectedBooking->getPrice());

    if (dynamic_pointer_cast<FlightBooking>(selectedBooking)) {
        //Pop the tab Flight Booking up
        ui->tabWidget->setCurrentWidget(ui->flug);
        //clear others details
        clearBookingsDetails();
        //casting selectedBooking to FlightBooking
        shared_ptr<FlightBooking> flightBooking = dynamic_pointer_cast<FlightBooking>(selectedBooking);
        ui->airlineEdit->setText(QString::fromStdString(flightBooking->getAirLine()));
        ui->fromDateFlug->setText(QString::fromStdString(flightBooking->getFromDestination()));
        ui->toDateflug->setText(QString::fromStdString(flightBooking->getToDestination()));
        ui->bookingclassFlug->setText(QString::fromStdString(flightBooking->getBookingClass()));

    }
    else if (dynamic_pointer_cast<RentalCarReservation>(selectedBooking)) {
        //Pop the tab Car Rental up
        ui->tabWidget->setCurrentWidget(ui->mietwagen);
        //clear others details
        clearBookingsDetails();

        //casting selectedBooking to RentalCarReservation
        shared_ptr<RentalCarReservation> rentalCarReservation = dynamic_pointer_cast<RentalCarReservation>(selectedBooking);
        ui->pickuplocationEdit->setText(QString::fromStdString(rentalCarReservation->getPickupLocation()));
        ui->returnlocationedit->setText(QString::fromStdString(rentalCarReservation->getReturnLocation()));
        ui->companyedit->setText(QString::fromStdString(rentalCarReservation->getCompany()));
        ui->vehicleclassedit->setText(QString::fromStdString(rentalCarReservation->getVehicleClass()));

    }
    else if (dynamic_pointer_cast<HotelBooking>(selectedBooking)) {
        //Pop the tab HotelBooking up
        ui->tabWidget->setCurrentWidget(ui->hotel);
        //clear others details
        clearBookingsDetails();

        //casting selectedBooking to HotelBooking
        shared_ptr<HotelBooking> hotelBooking = dynamic_pointer_cast<HotelBooking>(selectedBooking);
        ui->hotelEdit->setText(QString::fromStdString(hotelBooking->getHotel()));
        ui->townEdit->setText(QString::fromStdString(hotelBooking->getTown()));
        ui->roomtypeedit->setText(QString::fromStdString(hotelBooking->getRoomType()));

    }
    else if (dynamic_pointer_cast<TrainTicket>(selectedBooking)){
        //Pop-up the flug tabwidget
        ui->tabWidget->setCurrentWidget(ui->zug);
        //voherige details loeschen
        clearBookingsDetails();
        //casting selected booking to TrainTicket
        shared_ptr<TrainTicket> train= dynamic_pointer_cast<TrainTicket>(selectedBooking);
        ui->fromDestEdit->setText(QString::fromStdString(train->getFromDestination()));
        ui->toDestEdit->setText(QString::fromStdString(train->getToDestination()));
        ui->arrivalTimeEdit->setTime(QTime::fromString(QString::fromStdString(train->getArrivalTime()),"hh:mm"));
        ui->departureTimeEdit->setTime(QTime::fromString(QString::fromStdString(train->getDepartureTime()),"hh:mm"));
        ui->ticketTypEdit->setText(QString::fromStdString(train->getBookingClass()));

        for(unsigned int i=0;i<train->getConnectingStations().size();i++){
            QString bookingsInfo =QString::fromStdString(train->getConnectingStations()[i].StationsName);
            ui->connectionsStationlistWidget->addItem(bookingsInfo);// add the booking info as a new item in the list widget
        }

    }
};


void Travelagencyui::on_actionSpeichern_triggered()
{

    QString fileName = QFileDialog::getSaveFileName(this, "Speichern als JSON", QString(), "JSON-Dateien (*.json)");

    if (!fileName.isEmpty()) {

    QJsonDocument jsonDocument;
    //QJsonObject jsonObject;

    QJsonArray jsonArraybooking;
    for(auto &booking : travelagency->getBookings()){

        QJsonObject bookingJsonObject ;

         bookingJsonObject["id"]=QString::fromStdString(booking->getId());
         bookingJsonObject["price"]=booking->getPrice();

         bookingJsonObject["fromDate"]=QString::fromStdString(booking->getFromDate());
         bookingJsonObject["toDate"]=QString::fromStdString(booking->getToDate());
         bookingJsonObject["travelId"]=static_cast<qint64>(booking->getTravelId()) ;
         shared_ptr<Travel> travel =travelagency->findTravel(booking->getTravelId());

         bookingJsonObject["customerId"]= static_cast<qint64>(travel->getCustomerId());
         shared_ptr<Customer> customer =travelagency->findCustomer(travel->getCustomerId());
         bookingJsonObject["firstName"]=QString::fromStdString(customer->getFirstName());
         bookingJsonObject["lastName"]=QString::fromStdString(customer->getLastName());
         if(dynamic_pointer_cast<FlightBooking>(booking)){
             shared_ptr<FlightBooking> flight=dynamic_pointer_cast<FlightBooking>(booking);
             bookingJsonObject["airline"]=QString::fromStdString(flight->getAirLine());
             bookingJsonObject["toDest"]=QString::fromStdString(flight->getToDestination());
             bookingJsonObject["fromDest"]=QString::fromStdString(flight->getFromDestination());
             bookingJsonObject["bookingClass"]=QString::fromStdString(flight->getBookingClass());



         }else if(dynamic_pointer_cast<HotelBooking>(booking)){
             shared_ptr<HotelBooking> hotel= (dynamic_pointer_cast<HotelBooking>(booking));
             bookingJsonObject["town"]=QString::fromStdString(hotel->getTown());
             bookingJsonObject["hotel"]=QString::fromStdString(hotel->getHotel());
             bookingJsonObject["roomType"]=QString::fromStdString(hotel->getRoomType());
         }else if(dynamic_pointer_cast<RentalCarReservation>(booking)){
             shared_ptr<RentalCarReservation> rental=dynamic_pointer_cast<RentalCarReservation>(booking);
             bookingJsonObject["company"]=QString::fromStdString(rental->getCompany());
             bookingJsonObject["vehicleClass"]=QString::fromStdString(rental->getVehicleClass());
             bookingJsonObject["pickupLocation"]=QString::fromStdString(rental->getPickupLocation());
             bookingJsonObject["returnLocationm"]=QString::fromStdString(rental->getReturnLocation());
         }else  if(dynamic_pointer_cast<TrainTicket>(booking)){
             shared_ptr<TrainTicket> train = dynamic_pointer_cast<TrainTicket>(booking);
             bookingJsonObject["departureTime"]=QString::fromStdString(train->getDepartureTime());
             bookingJsonObject["arrivalTime"]=QString::fromStdString(train->getArrivalTime());
             bookingJsonObject["fromDest"]=QString::fromStdString(train->getFromDestination());
             bookingJsonObject["toDest"]=QString::fromStdString(train->getToDestination());

             QJsonArray jsonarryconnections;
             vector<string> connections=train->getConnectingStationsName();
             for(auto &i : connections){
                 jsonarryconnections.push_back(QString::fromStdString(i));
             }
             bookingJsonObject["connectingStations"]=jsonarryconnections;
         }

         jsonArraybooking.push_back(bookingJsonObject);
    }

    jsonDocument.setArray(jsonArraybooking);

    QFile datei(fileName);
    if (!datei.open(QIODevice::WriteOnly))
    std::cerr << "Datei konnte nicht geoeffnet werden";
    datei.write(jsonDocument.toJson());
    datei.close();

    }
}

void Travelagencyui::slotCheck()
{
    check();
}


void Travelagencyui::on_fromDateFlug_textChanged(const QString &arg1)
{
    shared_ptr<Airport> airport = travelagency->findAirport(arg1);
    if(airport)
    {
        ui->departurAirportNameEdit->setStyleSheet("color:black;");
        ui->departurAirportNameEdit->setText(QString::fromStdString(airport->getName()));
    }
    else{
        ui->departurAirportNameEdit->setStyleSheet("color:red;");
        ui->departurAirportNameEdit->setText("ungueltiger iata-code");
    }
}


void Travelagencyui::on_toDateflug_textChanged(const QString &arg1)
{
    shared_ptr<Airport> airport = travelagency->findAirport(arg1);
    if(airport)
    {
        ui->arrivalAirportNameEdit->setStyleSheet("color:black;");
        ui->arrivalAirportNameEdit->setText(QString::fromStdString(airport->getName()));
    }
    else{
        ui->arrivalAirportNameEdit->setStyleSheet("color:red;");
        ui->arrivalAirportNameEdit->setText("ungueltiger iata-code");
    }

}


void Travelagencyui::on_actionAnzeigen_triggered()
{

    Meldungen *window = new Meldungen(travelagency->getIncorrectReservations(), this);
    window->show();
    //check();
}


void Travelagencyui::on_actionset_config_triggered()
{
    configurationWindow * configuration = new configurationWindow(travelagency,this);
    configuration->show();
    //check();

}

 Check &Travelagencyui::getCheck()
{
    return check;
}

