# Objektinis_1
Buvo pravestas testas tam , kad patikrinti, su kuriuo konteineriu programa veiks greiciausiai ir kurioje vietoje vienas ar kitas konteineris geriau save parodys.
| Failo dydis | Konteineris | Nuskaitymas | Rikiavimas | Skirstymas | Bendras |
|-------------|-------------|-------------|------------|------------|---------|
| 1000        | vector      | 0.0125      | 0          | 0          | 0.0335  |
| 1000        | list        | 0.169       | 0          | 0.0006     | 0.039   |
| 1000        | deque       | 0.009       | 0          | 0.002      | 0.031   |
| 10000       | vector      | 0.0386      | 0.0081     | 0.00289    | 0.083   |
| 10000       | list        | 0.07        | 0.0029     | 0.0019     | 0.0929  |
| 10000       | deque       | 0.037       | 0.01       | 0.002      | 0.086   |
| 100000      | vector      | 0.248       | 0.078      | 0.0159     | 0.6     |
| 100000      | list        | 0.26        | 0.0476     | 0.0319     | 0.54    |
| 100000      | deque       | 0.31        | 0.123      | 0.316      | 0.68    |
| 1000000     | vector      | 2.73        | 1.14       | 0.228      | 6.49    |
| 1000000     | list        | 2.687       | 0.905      | 0.397      | 6.016   |
| 1000000     | deque       | 2.82        | 1.42       | 0.181      | 6.54    |
| 10000000    | vector      | 30.17       | 14.93      | 1.82       | 69.08   |
| 10000000    | list        | 27.225      | 13.441     | 4.313      | 67.65   |
| 10000000    | deque       | 27.38       | 18.117     | 1.84       | 70.15   |
Atlikus si testa galima apibemdrinti, kad dirbant su failais, kuriuose yra daugiau nei 100,000 irasu, std:: list konteineris yra beveik visuose parametruose efektyvesnis greicio atzvilgiu.

Taip pat buvo pravestas testas tam, kad patiktinti kaip kompiuterio komponentu apkrova skiriasi su skirtingais konteineriais bei skirtingu failu dydziais.
| Failo dydis | Konteineris | CPU% | RAM(MB) | SSD(MB/s) |   |
|-------------|-------------|------|---------|-----------|---|
| 1000        | vector      | 3.3  | 1.1     | 4.4       |   |
| 1000        | list        | 3.1  | 0.8     | 3.4       |   |
| 1000        | deque       | 3.2  | 0.8     | 4.3       |   |
| 10000       | vector      | 5.7  | 2.6     | 10.1      |   |
| 10000       | list        | 5.8  | 2.8     | 10.7      |   |
| 10000       | deque       | 5.6  | 2.2     | 9.6       |   |
| 100000      | vector      | 6    | 10.4    | 13.2      |   |
| 100000      | list        | 6.1  | 14.6    | 13.3      |   |
| 100000      | deque       | 6.1  | 15.4    | 11.8      |   |
| 1000000     | vector      | 6.2  | 119.7   | 14.6      |   |
| 1000000     | list        | 6.4  | 136.4   | 14.6      |   |
| 1000000     | deque       | 6.1  | 145.1   | 14.5      |   |
| 10000000    | vector      | 6.2  | 1375.2  | 35.3      |   |
| 10000000    | list        | 6.7  | 1679.8  | 38.5      |   |
| 10000000    | deque       | 6.2  | 1486.6  | 37.6      |   |

Atlikus testus, pastebeta, kad CPU apkrova tapr konteineriu skyresi nedaug, nes visais atvejais ji isliko panasiame intervale. Didejant failo dydziams, ryskiausiai augo RAM poreikis. Maziausia RAM naudojima rode vector, o didziausia dazniausiai deque ir list konteineriai. SSD apkrova taip pat didejo su failu dydziu. Iki 1000000 irasu skirtumai tarp konteineriu buvo nedideli, taciau ties 10000000 irasu list ir deque rode didesni SSD pralaiduma nei vector.
Todel apibendrinant galima pasakyti, kad vector konteineris yra efektyviausias dirbant su dideliais duomenu kiekiais.

Buvo atliktas testas, kurio metu buvo patikrintas keliu strategiju veikimo laikas ir kompiuterio atminties naudojimas programos studentu skirstymo i vargsiukus ir smartukus veikimo metu.
| Strategija | Konteineris | RAM(MB) | Laikas(s) | Laikas rus.(s) |
|------------|-------------|---------|-----------|----------------|
| 1          | vector      | 2874    | 68.6899   | 3.77026        |
| 1          | list        | 3287    | 70.5741   | 5.24072        |
| 1          | deque       | 2940    | 71.8816   | 3.50569        |
| 2          | vector      | 1866    | 72.6103   | 1.35363        |
| 2          | list        | 2377    | 72.4564   |  3.3041        |
| 2          | deque       | 1970    | 72.4739   | 1.59748        |
| 3          | vector      | 2732    | 74.6873   | 2.63487        |
| 3          | list        | 2582    | 74.2411   |  6.95656       |
| 3          | deque       | 2038    | 75.5814   | 2.72243        |
