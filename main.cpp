#include "additional_service.h"
#include "guest.h"
#include "hotel_receptionist.h"
#include "hotel_system.h"
#include "room.h"
#include <cstddef>
#include <ctime>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

time_t
convertDate(int year, int month,
            int day) { // zamienia human readable date z powrotem na timestamp
  struct tm startDate_tm = {};
  startDate_tm.tm_year = year - 1900;
  startDate_tm.tm_mon = month - 1;
  startDate_tm.tm_mday = day;
  startDate_tm.tm_hour = 0;
  startDate_tm.tm_min = 0;
  startDate_tm.tm_sec = 0;
  startDate_tm.tm_isdst = -1;

  return mktime(&startDate_tm);
}

time_t readDate(
    const string &label) { // funkcja pomocnicza do wczytania daty z terminala
  int year, month, day;
  cout << "Podaj datę " << label << ":\n";
  cout << "Rok: ";
  cin >> year;
  cout << "Miesiąc (1-12): ";
  cin >> month;
  cout << "Dzień (1-31): ";
  cin >> day;
  return convertDate(year, month, day);
}

void showAvailableRooms(HotelSystem &hotelSystem) {
  time_t from = readDate("rozpoczęcia pobytu");
  time_t to = readDate("zakończenia pobytu");
  vector<int> availableRooms = hotelSystem.checkAvailability(from, to);
  cout << "Dostępne pokoje w zaznaczonym terminie:" << endl;
  for (size_t i{0}; i < availableRooms.size(); i++) {
    cout << "- Numer pokoju: " << availableRooms[i] << endl;
  }
}

void showPerson(const Person &p) { p.displayData(); }

int main() {
  cout << "Witamy w hotelu" << endl;
  HotelSystem hotelSystem;
  vector<Room> rooms;

  // rooms with rate 100.0:
  for (int n = 1; n <= 5; n++) {
    Room room(n, 100.0);
    rooms.push_back(room);
  }

  // rooms with rate 120.0:
  for (int n = 6; n <= 10; n++) {
    Room room(n, 120.0);
    rooms.push_back(room);
  }

  // rooms with rate 150.0:
  for (int n = 11; n <= 15; n++) {
    Room room(n, 150.0);
    rooms.push_back(room);
  }

  // Dodanie pokoi:
  for (size_t r = 0; r < rooms.size(); r++) {
    hotelSystem.addRoom(rooms[r]);
  }

  // Dodanie usług dodatkowych:
  AdditionalService breakfast("Śniadanie", 60.0);
  AdditionalService parking("Parking", 40.0);

  hotelSystem.newService(breakfast);
  hotelSystem.newService(parking);

  // Recepcjonista:
  HotelReceptionist receptionist("Aleksandra", "Zalewska", 94071, 63127);

  while (true) {
    int choice;
    cout << "Wybierz użytkownika:\n1. Gość\n2. Recepcjonista\n3. Ustaw datę "
            "systemową\n4. Koniec"
         << endl;
    cin >> choice;

    if (choice == 4) {
      break;
    }
    if (choice == 3) {
      hotelSystem.setCurrentTime(readDate("systemową"));
      cout << "Ustawiono datę systemową" << endl;
      continue;
    }

    while (choice == 2) {
      int choiceR;
      cout << "Wybierz akcję:\n1. Wyświetl dane recepcjonisty\n2. Zamelduj "
              "gościa\n3. Wymelduj gościa\n4. Sprawdź dostępność\n5. Powrót"
           << endl;
      cin >> choiceR;

      if (choiceR == 5) {
        break;
      }
      if (choiceR == 1) {
        showPerson(receptionist);
      }
      if (choiceR == 2) {
        int guestID;
        cout << "Podaj ID gościa: ";
        cin >> guestID;
        if (hotelSystem.displayGuestReservations(guestID)) {
          int reservationID;
          cout << "Podaj numer rezerwacji: ";
          cin >> reservationID;
          receptionist.guestCheckIn(reservationID, hotelSystem);
        } else {
          cout << "Gość nie istnieje albo nie ma rezerwacji." << endl;
        }
      }
      if (choiceR == 3) {
        int guestID;
        cout << "Podaj ID gościa: ";
        cin >> guestID;
        if (hotelSystem.displayGuestReservations(guestID)) {
          int reservationID;
          cout << "Podaj numer rezerwacji: ";
          cin >> reservationID;
          receptionist.guestCheckOut(reservationID, hotelSystem);
        } else {
          cout << "Gość nie istnieje albo nie ma rezerwacji." << endl;
        }
      }
      if (choiceR == 4) {
        showAvailableRooms(hotelSystem);
      }
    }
    if (choice == 1) {
      string name;
      string surname;
      int guestID;

      cout << "Podaj imię i nazwisko\nImię: ";
      cin >> name;
      cout << "\nNazwisko: ";
      cin >> surname;
      cout << "\nPodaj ID: ";
      cin >> guestID;

      const Guest *guest = hotelSystem.findGuest(guestID);
      if (guest == nullptr) {
        cout << "Nie istnieje jeszcze gość o podanym ID, tworzenie gościa\n";
        hotelSystem.addGuest(Guest(name, surname, guestID));
        guest = hotelSystem.findGuest(guestID);
        cout << "Dodano gościa: ";
      } else {
        cout << "Gość: ";
      }
      showPerson(*guest);

      while (true) {
        int choiceG;
        cout
            << "Wybierz akcję:\n1. Utwórz rezerwację\n2. Anuluj "
               "rezerwację\n3. Sprawdź opłaty\n4. Sprawdź dostępność\n5. Powrót"
            << endl;
        cin >> choiceG;

        if (choiceG == 5) {
          break;
        }
        if (choiceG == 1) {
          cout << "Utwórz rezerwację" << endl;

          time_t from = readDate("rozpoczęcia pobytu");
          time_t to = readDate("zakończenia pobytu");

          cout << "Dostępne pokoje w zaznaczonym terminie: " << endl;
          vector<int> availableRooms = hotelSystem.checkAvailability(from, to);
          for (size_t i = 0; i < availableRooms.size(); i++) {
            cout << "- Numer pokoju: " << availableRooms[i] << endl;
          }
          cout << "Wybierz numer pokoju: ";
          int roomNumber;
          cin >> roomNumber;

          cout << "Tworzenie rezerwacji..." << endl;
          int reservationID;
          reservationID =
              hotelSystem.makeReservation(guestID, from, to, roomNumber);
          if (reservationID == -1) {
            cout << "Nie udało się utworzyć rezerwacji, spróbuj ponownie";
          } else {
            cout << "Rezerwacja utworzona" << endl;
            cout << "ID rezerwacji: " << reservationID << endl;

            int addServiceChoice;
            cout << "Czy chcesz dołączyć usługi dodatkowe?\n1. Tak\n2. Nie"
                 << endl;
            cin >> addServiceChoice;

            if (addServiceChoice == 1) {
              cout << "Lista usług dodatkowych:" << endl;
              vector<string> additionalServiceList =
                  hotelSystem.getServiceNames();
              for (size_t a = 0; a < additionalServiceList.size(); a++) {
                cout << a + 1 << ". " << additionalServiceList[a] << endl;
              }
              while (true) {
                cout << "Wybierz numer usługi, którą chcesz dodać (0 - "
                        "kontynuuj): ";
                cin >> addServiceChoice;
                if (addServiceChoice == 0) {
                  break;
                }
                for (size_t c = 0; c < additionalServiceList.size(); c++) {
                  if (addServiceChoice ==
                      static_cast<int>(c) +
                          1) { // zamiana c na int żeby uniknąć dodawania
                               // różnych typów
                    hotelSystem.addService(reservationID,
                                           additionalServiceList[c]);
                    cout << "Dodano usługę " << additionalServiceList[c]
                         << endl;
                  }
                }
              }
            }
          }
        }

        if (choiceG == 2) {
          cout << "Anulowanie rezerawcji" << endl;
          if (!hotelSystem.displayGuestReservations(guestID)) {
            cout << "Nie masz żadnych rezerwacji." << endl;
            continue;
          }
          int reservationID;
          cout << "Podaj numer rezerwacji: ";
          cin >> reservationID;

          if (hotelSystem.cancelReservation(guestID, reservationID)) {
            cout << "Anulowano rezerwację" << endl;
          } else {
            cout << "Wystąpił błąd, nie udało się anulować rezerwacji";
          }
        }

        if (choiceG == 3) {
          showPerson(*hotelSystem.findGuest(guestID));
        }
        if (choiceG == 4) {
          showAvailableRooms(hotelSystem);
        }
      }
    }
  }
}
