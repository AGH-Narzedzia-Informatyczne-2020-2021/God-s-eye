## Gists

- Piotr Sokołowski
    1. [Tic tac toe](https://gist.github.com/sokoloowski/aa95cbfa15a8e3381088ea4b315e0acc)
    2. [Arduino sketch](https://gist.github.com/sokoloowski/93365f6dec794736d367893299704e8f)
    
- Tomasz Turek
    1. [Arduino string analysis](https://gist.github.com/Tom2rec/074ad085250204601162ca165ba2a2a0)
    2. [C interpreter](https://gist.github.com/Tom2rec/1af55bd9ed095bea9dee750d39ec5d1f)
    
- Sebastian Zdybiowski
    1. [TicTacToe in C and with AI](https://gist.github.com/echofoxtrotpl/526b586335e66119963576c293078a3b)
    2. [Matrix multiplication in C](https://gist.github.com/echofoxtrotpl/9bb0fc5c281c48b96d911276e786dcc4)
    
---

Wyobraź sobie narzędzie do śledzenia każdego użytkownika urządzenia z siecią Wi-Fi. Każdego posiadacza smartfona :iphone:, laptopa :computer:, tabletu.

Wyobraź sobie, że istnieje narzędzie :hammer_and_wrench:, które jest w stanie namierzyć każdego. Również Ciebie :warning:.

Wyobraź sobie narzędzie, przed którym nie da się ukryć :unlock:. Informatyczne **_Oko Boga_**...

# :eye: God's Eye

[![time tracker](https://wakatime.com/badge/github/AGH-Narzedzia-Informatyczne/God-s-eye.svg)](https://wakatime.com/badge/github/AGH-Narzedzia-Informatyczne/God-s-eye)

## :clipboard: O projekcie 

To narzędzie pozwalające na monitorowanie bezprzewodowego ruchu sieciowego :satellite:, a co za tym idzie, również śledzenie i identyfikację urządzeń oraz, z pewnym prawdopodobieństwem, ich właścicieli :pouting_face:.

Na **_Oko Boga_** składa się wiele niewielkich urządzeń (o wymiarach 20mm x 25mm) zbierających rozgłaszane siecią Wi-Fi dane.

## :bulb: Sposób działania 

Urządzenia obsługujce połączenie Wi-Fi :signal_strength: często nadają informacje o zapamiętanych sieciach oraz o swoim adresie sprzętowym MAC :id:, unikalnym dla każdego urządzenia. Nasze moduły przełączają się na bieżąco :twisted_rightwards_arrows: między trybem monitora i trybem klienta, co pozwala na zbieranie danych i przekazanie dalej :fast_forward:, przez dowolną otwartą sieć Wi-Fi, na serwer.
