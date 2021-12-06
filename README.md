# Pierwsze własne funkcje i rekurencja
## **Podejście proceduralne**
Wszystkie zagadnienia poruszone we wcześniejszych rozdziałach były omawiane przy użyciu programów napisanych w podejściu strukturalnym. Podejście to polega na stworzeniu całego programu wewnątrz funkcji głównej `main`. W praktyce, tego podejścia nie używa się praktycznie wcale. Dużo prościej i przejrzyściej tworzy się kod korzystają z podejścia proceduralnego. Polega ono na tworzeniu własnych procedur i funkcji obsługujących poszczególne problemy, a funkcja `main` służy jedynie do złożenia wszystkich funkcji w działający program, spełniający swoje założenia działania.



*Schemat (7.0) podejście strukturalne a podejście proceduralne* ([Karol Kuczmarski „Od zera do gierkodera”](http://www.cs.put.poznan.pl/arybarczyk/Kurs%20C++.pdf))

![Schemat0](https://user-images.githubusercontent.com/71324202/143834923-c328668b-ffa6-484f-84f1-89ecfd7e974a.png)

## **Deklaracja i tworzenie własnych funkcji**
Aby zadeklarować funkcję należy najpierw podać typ wartości jaką funkcja będzie zwracać. Typy wartości są identyczne jak typy wartości zmiennych (`int`, `char`, `float`, `double`). Warto jeszcze wspomnieć tutaj o typie używanym często jako typ funkcji `void`, który nie zwraca żadnej wartości. Funkcja typu `void` nazywana jest procedurą. Drugą składową potrzebną do stworzenia funkcji jest jej nazwa (identyfikator). Również jak w przypadku zmiennych, nazwę funkcji nadaje programista. Po identyfikatorze funkcji konieczne jest wystąpienie nawiasów, wewnątrz których, opcjonalnym jest zadeklarowanie parametrów funkcji. Parametry funkcji to zmienne, podawane funkcji od których zależy wynik działania funkcji. Ostatnim elementem składowym funkcji jest, blok kodu źródłowego funkcji. Należy pamiętać, że każda funkcja określona typem różnym niż `void` musi zwracać wartość za pośrednictwem operatora *return,* odpowiadającą typowi funkcji. 
```
typ nazwa_funkcji(typ_zmiennej nazwy_parametrów,…) 
{
/* kod źródłowy funkcji */
/* jeżeli typ funkcji to void to return nie występuje */
	return wartość_zgodna_z_typem_funkcji; 
/* można użyć zmiennej  jako wartości zwracanej*/
}

```

Deklaracji funkcji można dokonać powyżej lub poniżej funkcji `main`. W pierwszym przypadku stosujemy pełen zapis funkcji wraz z jej kodem źródłowym powyżej funkcji `main` dzięki czemu wewnątrz `main` możemy swobodnie wywoływać działanie naszej funkcji. Taki sposób jednak powoduje pewne problemy, kiedy tworzymy więcej niż jedną własną funkcję, a one odwołują się do siebie nawzajem. Dlatego preferowaną deklaracją użycia kodu, jest deklaracja funkcji poniżej funkcji `main`. W takim przypadku powyżej funkcji `main`, deklarujemy w sposób skrócony istnienie funkcji poprzez podanie jej typu, nazwy oraz typów parametrów. Takie zadeklarowanie funkcji, nazywa się prototypem i daje sygnał kompilatorowi „ta funkcja istnieje, ale jej kod jest podany w innym miejscu”, dzięki czemu unikamy problemów z wywoływaniem funkcji przez siebie nawzajem. Ciało takiej funkcji umieszczamy wtedy poniżej funkcji `main`.

*Przykład (7.0) deklaracja funkcji przed `main`*

```
#include <stdio.h>
#include <stdlib.h>

double kwadrat_liczby(double liczba)
{
	return liczba*liczba;
}

int main() 
{
	/* kod main */
	return 0;
}

```

*Przykład (7.1) definicja funkcji po `main`*

```
#include <stdio.h>
#include <stdlib.h>

double kwadrat_liczby(double);

int main()
{
	/* kod main */
	return 0;
}

double kwadrat_liczby(double liczba)
{
	return liczba*liczba;
}

```

## **Wywołanie funkcji**
Aby wywołać funkcję, należy podać jej identyfikator, wraz z nawiasem, wewnątrz którego podamy argumenty odpowiadające kolejnym parametrom funkcji. Działanie funkcji spowoduje, że miejsce, w którym zostanie wywołana zostanie zastąpione zwracaną wartością. Można taką funkcję wywołać wewnątrz operacji arytmetycznej (o ile typ funkcji jest odpowiedni), przy operacji przypisania (jako argument, który ma zostać przypisany, nie można przypisać wartości do funkcji, ponieważ nie jest tzw. L-wartością), lub jako argument innej funkcji, instrukcji warunkowej, w której typ zwracanej wartości jest dopuszczony. Innymi słowy funkcji można użyć wszędzie tam, gdzie ma być użyta wartość, którą zwraca dana funkcja. Funkcję typu `void`, która nie zwraca wartości wywołuje się po prostu wypisując jej nazwę i argumenty.

*Przykład (7.2) wywołanie funkcji w różnych sytuacjach*

```
#include <stdio.h>
#include <stdlib.h>

double kwadrat_liczby(double);
int max(int,int);

int main()
{
	double a = kwadrat_liczby(4);
	double b = a + kwadrat_liczby(5);
	int c = max(23,10);
	printf("a=%4.0lf \nb=%4.0lf \nc=%4d",a,b,c);
	return 0;
}

double kwadrat_liczby(double liczba)
{
	return liczba*liczba;
}

int max(int a, int b)
{
	return (a>b)? a : b;
}

```

## **Przekazywanie argumentów do funkcji oraz klasa pamięci `static`** 
Argumenty przekazywane są do funkcji, w miejscu deklaracji parametrów. Aby ułatwić rozróżnienie parametru i argumentu posłużę się przykładem (7.2). Funkcja `int max(int a, int b)` ma dwa parametry a i b, natomiast w funkcji `main` w wywołaniu funkcji `max(23,10);` za argument podane jest 23 i 10. Jako argument funkcji możemy podać wartość stałą, lub zmienną. Należy pamiętać jednak, że wartość argumentu nie jest przekazywana do funkcji w oryginale, a jedynie kopiowana do parametru, przez co działanie funkcji nie wpłynie na zmienne podane w argumencie. Do sprawdzenia tego posłuży nam przykład (7.3). Jest tam również przestawiona zmienna funkcji kasy `static`. Jej działanie jest o tyle różne, od działania zwykłej zmiennej lokalnej, że obszar pamięci zarezerwowany przez tą zmienną, jest zarezerwowany przez cały czas działania programu, a ona sama deklarowana jest tylko raz. Więc linijka `static int i=1;` wykona się tyko podczas pierwszego wywołania funkcji, a w każdym kolejnym zostanie ona pominięta. Trochę tak, jakby zmienna typu `static` zachowywała się jak zmienna globalna, jednak z ograniczonym dostępem. Zmodyfikowanie zmiennej tej w dowolnym momencie, zostanie zapamiętane i zmienna ta przyjmie inną wartość również w kolejnym wywołaniu tej funkcji. 

*Przykład (7.3) wartości zmiennych wewnątrz funkcji i poza nią oraz zmienna lokalna funkcji klasy `static`*

```
#include <stdio.h>
#include <stdlib.h>

void parametry(int a, int b)
{
	static int i=1;
	a=a+1;
	b=b+3;
	printf("\nWEWNATRZ FUNCKJI wywolanie %d\n", i) ;
	printf("a=%d b=%d",a,b);
	i++;
}

int main() {
	int a=3,b=5;
	printf("\nPRZED WYWOLANIEM\n") ;
	printf("a=%d b=%d",a,b);
	
	parametry(a,b);
	
	printf("\nPO WYWOLANIU 1\n") ;
	printf("a=%d b=%d",a,b);
	
	parametry(a,b);
	
	printf("\nPO WYWOLANIU 2\n") ;
	printf("a=%d b=%d",a,b);
	return 0;
}

```

*Wynik działania programu:* 

>PRZED WYWOLANIEM
>
>a=3 b=5
>
>WEWNATRZ FUNCKJI wywolanie 1
>
>a=4 b=8
>
>PO WYWOLANIU 1
>
>a=3 b=5
>
>WEWNATRZ FUNCKJI wywolanie 2
>
>a=4 b=8
>
>PO WYWOLANIU 2
>
>a=3 b=5

To wszystkie informacje potrzebne, aby z powodzeniem stworzyć swoje pierwsze funkcje i zmienić podejście do budowania kodu. Temat ten kryje jednak zdecydowanie więcej możliwości, o których będzie w rozdziale 14, jednak, żeby je w pełni zrozumieć należy posiadać już wiedzę o wskaźnikach, co opisane jest w rozdziale 12.

## **Funkcje rekurencyjne**
Funkcje rekurencyjne to takie funkcje, które odwołują się do samej siebie. Słynne przysłowie o rekurencji mówi, że aby zrozumieć rekurencję, najpierw należy zrozumieć rekurencję. Brzmi skomplikowanie, ale wcale takie nie jest. Najłatwiej jest rekurencję wytłumaczyć na przykładzie, co stanie się zaraz. Bardzo istotą rzeczą w funkcjach rekurencyjnych jest warunek stopu i krok rekurencyjny. Jak już było wspomniane funkcja rekurencyjna musi wywoływać samą siebie, ale nie może tego wykonywać w nieskończoność. Dlatego wewnątrz funkcji rekurencyjnej jest potrzebny warunek stopu, czyli definicja wartości funkcji dla znanego argumentu. Krok rekurencyjny to kolejna bardzo ważna rzecz, jest to nic innego jak odpowiednie wywołanie funkcji rekurencyjnej wewnątrz niej z odpowiednią zmianą parametru, tak aby funkcja dążyła zawsze do warunku stopu. Jako funkcję rekurencyjną, można zdefiniować funkcję silnia

![Rysunek1](https://user-images.githubusercontent.com/71324202/143834929-27f96821-8526-40fe-afee-24855d57a9fb.png)


Gdzie przypadek, kiedy n=1 jest warunkiem stopu, a wszelkie inne wartości są warunkiem ogólnym. f(n-1) jest krokiem rekurencyjnym w kierunku warunku stopu, zakładając, że n jest podana jako nieujemna liczba całkowita. Taką funkcję reprezentuje program z przykładu (7.4).

*Przykład (7.4) funkcja silnia rekurencyjnie*

```
#include <stdio.h>
#include <stdlib.h>

unsigned silnia (unsigned);

int main() 
{
	printf("%d", silnia(3));
	return 0;
}

unsigned silnia (unsigned n)
{
/* obsłużenie wyjątku n=0 */
	if(n==0)
		return 0;
/* warunek stopu ------ 1 dla n=1 */
	if(n==1)
		return 1;
/* warunek ogólny ------ n*f(n-1)  */
	return n*silnia(n-1);
}

```

*Wynik działania programu:*

>6

Może więcej przykładów funkcji rekurencyjnej?

**Nie potrzeba**

Przykład przedstawiający problem blokowo znajduje się poniżej – schemat (7.1). W jego pierwszej części zatytułowanej jako *Wywołanie kolejnych funkcji silnia – rekurencyjnie* , mamy pokazane wywołanie wszystkich funkcji aż do uzyskania warunku stopu. W warunku stopu wartość funkcji jest znana, więc kolejna część *Obliczanie kolejnych argumentów…* pokazuje nam kolejne wykonania instrukcji `return` w postaci strzałek powrotnych. W ten sposób wartości kolejnych wywołań funkcji stają się znane, aż do momentu w którym uzyskamy wynik dla interesującego nas argumentu. 

*Schemat (7.1) działanie funkcji silnia z przykładu 7.4, dla argumentu n=4.*

![Schemat1](https://user-images.githubusercontent.com/71324202/143834927-11d727cf-d571-40df-a0d4-c460214ff30d.png)

## **Zadania do samodzielnego wykonania**
1. Stwórz funkcje max(a,b) i min(a,b), które będą zwracać większą z podanych liczb.
2. Stwórz funkcję silnia(a), która będzie iteracyjnie (przy pomocy pętli) liczyć wartość silni z podanej liczby.
3. Stwórz funkcję potega(liczba, wykładnik), która będzie iteracyjnie liczyć wartość potęgi o podanych parametrach.
4. Stwórz funkcję potega(liczba, wykładnik), która będzie rekurencyjnie liczyć wartość potęgi o podanych parametrach.
5. Korzystając z własnych funkcji stwórz kalkulator z menu dający możliwość wykonania obliczeń podanych poniżej. Każda z operacji powinna być wykonywana przez osobną funkcję/procedurę.
	1. dodawanie n liczb;
	2. odejmowanie od liczby aż do momentu podania '0';
	3. mnożenie dwóch liczb;
	4. dzielenie liczby;
	5. potęgowanie;
	6. kwadrat liczby;
	7. silnia;
6. Stwórz funkcję liczącą wartość n-tego wyrazu [Ciągu Fibonacciego](https://pl.wikipedia.org/wiki/Ci%C4%85g_Fibonacciego)
7. Stwórz funkcję liczącą sumę wszystkich wyrazów [Ciągu Fibonacciego](https://pl.wikipedia.org/wiki/Ci%C4%85g_Fibonacciego) kończąc na n-tym wyrazie.
8. Stwórz funkcję liczącą wartość n-tego wyrazu ciągu określonego wzorem:

![image](https://user-images.githubusercontent.com/71324202/143841510-fa248fbc-8e7d-4395-af52-66133199df04.png)

9. Napisz funkcje ceiling, floor i round, odzwierciedlające funkcje matematyczne sufit i podłoga oraz zaokrąglenie matematyczne (skorzystaj z jawnej konwersji typów).

***
[Poprzednia część](https://github.com/CyberMALab/Wiecej-o-typach-zmiennych-i-nie-tylko.git) | [Spis treści](https://github.com/CyberMALab/Wprowadzenie-do-programowania-w-j-zyku-ANSI-C.git) | [Następna część](https://github.com/CyberMALab/Tablice-jednowymiarowe.git)
***
&copy; Cyberspace Modelling and Analysis Laboratory
