(pó³)AUTOMATYCZNA SPRAWDZARKA ZADAÑ// Micha³ D¹browski

1)
Dla ka¿dego zadania tworzycie strukturê katalogów, jaka znajduje siê w folderze zad1. Folder zad1 zawiera wszystko,
co jest potrzebne do sprawdzenia zadania 1, jak równie¿ wygenerowania testów. Folder correct zawiera moje propozycje
wzorcowych rozwi¹zañ, które przydadz¹ siê do wygenerowania testów.

2)
Maj¹c skopiowan¹ strukturê katalogu zad1 dla ka¿dego z zadañ, jego zawartoœæ jest nastêpuj¹ca:

* solutions -> w tym folderze znajduj¹ siê rozwi¹zania wszystkich studentów do jednego z zadañ (tu: zad1),
zapisane w formacie nrIndeksu_nrZadania.cpp, w moim przypadku: 290953_1.cpp (tak studenci powinni nazywaæ pliki)

* students -> folder, w którym generowane s¹ indywidualne raporty dla ka¿dego studenta; zbiorczy raport pojawia siê
w folderze g³ównym do danego zadania (tu: w folderze zad1)

* tests -> zawiera wzorcowe rozwi¹zanie konkretnego zadania wraz z zestawem 10 testów numerowanych 0.in - 9.in
wywo³anie skryptu ./test1_gen powoduje pojawienie siê w tym samym folderze 10 plików 0.out - 9.out zawieraj¹cych
poprawne odpowiedzi dla ka¿dego przypadku testowego.

3)
Folder tests musi zawieraæ rozwi¹zanie wzorcowe, w tym wypadku o nazwie zad1.cpp. Chc¹c wygenerowaæ testy do zadania 1,
wykonujemy skrypt ./test1_gen

* dla innego numeru zadania trzeba zmieniæ nastêpuj¹ce linijki skryptu test1_gen (zmieniaj¹c numer sprawdzanego zadania):
g++ zad1.cpp -o zad1
./zad1 <$i.in > $i.out

4)
Maj¹c wygenerowane testy do konkretnego zadania, z poziomu g³ównego folderu (tu: zad1) wywo³ujemy skrypt ./check_all
W wyniku tego w folderze students pojawiaj¹ siê indywidualne raporty, zaœ w folderze g³ównym plik final.out
zawieraj¹cy zestawienie zbiorcze dla prowadz¹cego

* np. chc¹c sprawdziæ zadanie 1, wykonujemy skrypt ./check_all

* dla innego numeru zadania trzeba zmieniæ nastêpuj¹c¹ linijkê skryptu check_all (zmieniaj¹c numer zadania):
for f in ./solutions/*_1.cpp

5)
Polecam sprawdziæ dzia³anie na przyk³adzie zadania 1 -> wszystkie potrzebne elementy znajduj¹ siê w katalogu zad1
W razie pytañ œmia³o piszcie na adres mdabrowski@fuw.edu.pl
