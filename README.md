## Temat 5: System Zarządzania Hotelem

System zarządzania hotelem ma za zadanie umożliwić gościom dokonywanie rezerwacji i dołączanie usług dodatkowych. Anulowanie rezerwacji po określonym czasie będzie się wiązało z naliczeniem opłaty manipulacyjnej. Recepcjoniści mają mieć możliwość meldowania i wymeldowywania gości. System jest odpowiedzialny za sprawdzanie dostępności pokoi oraz blokowanie tych zarezerwowanych. Przy wymeldowaniu gościa system ma wystawić fakturę biorącą pod uwagę ilość dób spędzonych w hotelu pomnożonych przez dzienną stawkę + koszt usług dodatkowych.

### User Stories:

#### Typ: Wyszukiwanie / Przeglądanie

- **Jako** Gość
- **chcę** sprawdzić dostępność pokoi w wybranym przedziale czasowym,
- **aby** upewnić się, że hotel dysponuje wolnymi miejscami przed rozpoczęciem rezerwacji.
- Kryterium akceptacji: System przeszukuje bazę i zwraca listę dostępnych pokoi, pomijając te, które są już zablokowane lub zarezerwowane w podanych datach.

#### Typ: Zarządzanie Rezerwacjami

- **Jako** Gość
- **chcę** zarezerwować wybrany pokój na konkretny termin,
- **aby** mieć zagwarantowany nocleg podczas mojego wyjazdu.
- Kryterium akceptacji: System tworzy nową rezerwację, wiąże ją z profilem gościa i natychmiast blokuje wybrany pokój na ten termin, aby nikt inny go nie zajął.

#### Typ: Zarządzanie Usługami

- **Jako** Gość
- **chcę** dołączyć usługi dodatkowe (np. śniadanie, parking) do mojej rezerwacji,
- **aby** dostosować pobyt w hotelu do moich potrzeb.
- Kryterium akceptacji: Wybrane usługi zostają poprawnie przypisane do rezerwacji, a ich koszt zostaje zapamiętany przez system do późniejszego uwzględnienia na fakturze.

#### Typ: Anulowanie Rezerwacji

- **Jako** Gość
- **chcę** mieć możliwość anulowania mojej rezerwacji,
- **aby** zrezygnować z pobytu w przypadku nagłej zmiany planów.
- Kryterium akceptacji: System odblokowuje pokój. Jeśli anulowanie następuje po upływie określonego w regulaminie czasu, system automatycznie nalicza opłatę manipulacyjną przypisaną do konta gościa.

#### Typ: Obsługa Gościa (Meldowanie)

- **Jako** Recepcjonista
- **chcę** zameldować gościa przy jego przyjeździe,
- **aby** formalnie rozpocząć jego pobyt w systemie i móc wydać mu klucze do pokoju.
- Kryterium akceptacji: Status rezerwacji w systemie zmienia się na aktywny (zameldowany), a czas rozpoczęcia pobytu zostaje odnotowany.

#### Typ: Rozliczenie / Wymeldowanie

- **Jako** Recepcjonista
- **chcę** wymeldować gościa przy wyjeździe,
- **aby** zakończyć jego pobyt i wystawić odpowiedni rachunek za usługi.
- Kryterium akceptacji: System zwalnia pokój i automatycznie generuje Fakturę, obliczając całkowity koszt pobytu (liczba dób pobytu × dzienna stawka za pokój + zsumowany koszt wybranych usług dodatkowych).

### Przypadki użycia

1. Sprawdź dostępność pokoi
- Aktorzy: Gość, Recepcjonista
- Opis: Użytkownik wprowadza zakres dat, dla którego system sprawdza dostępność pokoi, wyświetla dostępne a odrzuca zarezerwowane w tym terminie
- Powiązanie z User Story: Odpowiada pierwszej historii użytkownika (wyszukiwanie/przeglądanie)

2. Utwórz rezerwację
- Aktor: Gość
- Opis: Gość wybiera pokój z listy dostępnych pokoi, podaje swoje dane oraz termin pobytu i zatwierdza rezerwację. System potwierdza dostępność pokoju i zgodność danych, tworzy rezerwację powiązaną z danymi gościa i blokuje wyznaczony pokój w wybranym przedziale czasowym
- Powiązanie z User Story: Odpowiada drugiej historii użytkownika (Zarządzanie rezerwacjami) 

3. Dołącz usługę dodatkową
- Aktor: Gość 
- Opis: Gość wybiera z listy usług dodatkowych usługi dodatkowe, które przypisuje do swojej aktywnej rezerwacji. System zapisuje koszt wskazanych usług w bilansie rezerwacji, w celu późniejszego uwzględnienia tej kwoty w fakturze
- Powiązanie z User Story: Odpowiada trzeciej historii użytkownika (zarządzanie usługami)

4. Anuluj rezerwację
- Aktor: Gość
- Opis: Gość wybiera swoją rezerwację i zgłasza chęć jej anulowania, rezerwacja zostaje oflagowana w systemie jako anulowana
- Powiązanie z User Story: Odpowiada czwartej historii użytkownika (anulowanie rezerwacji)

5. Zamelduj gościa 
- Aktor: Recepcjonista
- Opis: Recepcjonista wyszukuje rezerwację gościa w dniu jego przyjazdu i inicjuje proces meldowania. System odnotowuje datę i godzinę rozpoczęcia pobytu oraz zmienia status gościa na zameldowanego
- User Story: Odpowiada piątej historii użytkownika (obsługa gościa/meldowanie)

6. Wymelduj gościa 
- Aktor: Recepcjonista 
- Opis: Recepcjonista wymeldowuje gościa przy wyjeździe, poprzez usunięcie go z listy gości i usunięcie jego rezerwacji
- User Story: Odpowiada szóstej historii użytkownika (rozliczanie/wymeldowanie)

7. Nalicz opłatę manipulacyjną 
- Aktor: Gość 
- Opis: Naliczenie opłaty manipulacyjnej jeśli anulowanie rezerwacji nastąpi po czasie określonym przez hotel

8. Nalicz fakturę
- Aktor: Recepcjonista 
- Opis: Obliczenie faktury według wzoru dni*stawka+usługi dodatkowe naliczana automatycznie przy wymeldowaniu gościa
