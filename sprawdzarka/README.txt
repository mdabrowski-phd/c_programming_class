(p�)AUTOMATYCZNA SPRAWDZARKA ZADA�// Micha� D�browski

1)
Dla ka�dego zadania tworzycie struktur� katalog�w, jaka znajduje si� w folderze zad1. Folder zad1 zawiera wszystko,
co jest potrzebne do sprawdzenia zadania 1, jak r�wnie� wygenerowania test�w. Folder correct zawiera moje propozycje
wzorcowych rozwi�za�, kt�re przydadz� si� do wygenerowania test�w.

2)
Maj�c skopiowan� struktur� katalogu zad1 dla ka�dego z zada�, jego zawarto�� jest nast�puj�ca:

* solutions -> w tym folderze znajduj� si� rozwi�zania wszystkich student�w do jednego z zada� (tu: zad1),
zapisane w formacie nrIndeksu_nrZadania.cpp, w moim przypadku: 290953_1.cpp (tak studenci powinni nazywa� pliki)

* students -> folder, w kt�rym generowane s� indywidualne raporty dla ka�dego studenta; zbiorczy raport pojawia si�
w folderze g��wnym do danego zadania (tu: w folderze zad1)

* tests -> zawiera wzorcowe rozwi�zanie konkretnego zadania wraz z zestawem 10 test�w numerowanych 0.in - 9.in
wywo�anie skryptu ./test1_gen powoduje pojawienie si� w tym samym folderze 10 plik�w 0.out - 9.out zawieraj�cych
poprawne odpowiedzi dla ka�dego przypadku testowego.

3)
Folder tests musi zawiera� rozwi�zanie wzorcowe, w tym wypadku o nazwie zad1.cpp. Chc�c wygenerowa� testy do zadania 1,
wykonujemy skrypt ./test1_gen

* dla innego numeru zadania trzeba zmieni� nast�puj�ce linijki skryptu test1_gen (zmieniaj�c numer sprawdzanego zadania):
g++ zad1.cpp -o zad1
./zad1 <$i.in > $i.out

4)
Maj�c wygenerowane testy do konkretnego zadania, z poziomu g��wnego folderu (tu: zad1) wywo�ujemy skrypt ./check_all
W wyniku tego w folderze students pojawiaj� si� indywidualne raporty, za� w folderze g��wnym plik final.out
zawieraj�cy zestawienie zbiorcze dla prowadz�cego

* np. chc�c sprawdzi� zadanie 1, wykonujemy skrypt ./check_all

* dla innego numeru zadania trzeba zmieni� nast�puj�c� linijk� skryptu check_all (zmieniaj�c numer zadania):
for f in ./solutions/*_1.cpp

5)
Polecam sprawdzi� dzia�anie na przyk�adzie zadania 1 -> wszystkie potrzebne elementy znajduj� si� w katalogu zad1
W razie pyta� �mia�o piszcie na adres mdabrowski@fuw.edu.pl
