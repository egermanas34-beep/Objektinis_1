# Objektinis_1
Buvo atliktas tyrimas tam, kad patikrinti, per kiek laiko yra sugeneruojami skirtingo dydzio studentu failai.

Pirma karta atlikus generavima, rezultatai buvo tokie:

studentai_1000.txt kurimo laikas: 0.0163294 s

studentai_10000.txt kurimo laikas: 0.0271894 s

studentai_100000.txt kurimo laikas: 0.25156 s

studentai_1000000.txt kurimo laikas: 2.8381 s

studentai_10000000.txt kurimo laikas: 25.1776 s

Antra karta generuojant(failai jau buvo sukurti, ju duomenys tik buvo pakeisti), rezultatas buvo toks:

studentai_1000.txt kurimo laikas: 0.0086574 s
studentai_10000.txt kurimo laikas: 0.0305348 s
studentai_100000.txt kurimo laikas: 0.216627 s
studentai_1000000.txt kurimo laikas: 2.47373 s
studentai_10000000.txt kurimo laikas: 23.5201 s
Trecia karta apibendrinimui sugeneravus failus, laikai buvo tokie:
studentai_1000.txt kurimo laikas: 0.0095088 s
studentai_10000.txt kurimo laikas: 0.0301125 s
studentai_100000.txt kurimo laikas: 0.23564 s
studentai_1000000.txt kurimo laikas: 2.34926 s
studentai_10000000.txt kurimo laikas: 24.0008 s

Toliau buvo vykdytas kitas tyrimas, kurio metu buvo tikrinama, kiek laiko uztrunka nuskaitymas is failu, rikiavimas pagal galutini pazymi, suskirstymas studentu pagal lygius(jei galutinis balas mazesnis uz 5.0, tai studentas yra priskiriamas vargseliui, jei >=5 tai smartui), jei isvedimas i failus.
atlikus si tyrima, rezultatai buvo tokie:
Failo nuskaitymas ir apdorojimas uztruko: 0.0071191 sekundziu.
studentai_1000.txt nuskaitymo ir apdorojimo laikas: 0.0081253 s
studentai_1000.txt rikiavimo laikas mazejimo tvarka su sort funkcija: 0.000624 s
studentai_1000.txt studentų lygio nustatymo laikas: 0 s
Rezultatai išsaugoti failuose vargsiukai1000.txt ir smartukai1000.txt
Duomenų išvedimas užtruko: 0.0046173 sekundžių.
studentai_1000.txt rezultatu isvedimo i faila laikas: 0.0109295 s

studentai_1000.txt visas proceso laikas: 0.0196788 s
-------------------------------------------------------------
Failo nuskaitymas ir apdorojimas uztruko: 0.0334257 sekundziu.
studentai_10000.txt nuskaitymo ir apdorojimo laikas: 0.0334257 s
studentai_10000.txt rikiavimo laikas mazejimo tvarka su sort funkcija: 0.0111871 s
studentai_10000.txt studentų lygio nustatymo laikas: 0 s
Rezultatai išsaugoti failuose vargsiukai10000.txt ir smartukai10000.txt
Duomenų išvedimas užtruko: 0.0347722 sekundžių.
studentai_10000.txt rezultatu isvedimo i faila laikas: 0.0482711 s

studentai_10000.txt visas proceso laikas: 0.0928839 s
-------------------------------------------------------------
Failo nuskaitymas ir apdorojimas uztruko: 0.438054 sekundziu.
studentai_100000.txt nuskaitymo ir apdorojimo laikas: 0.438054 s
studentai_100000.txt rikiavimo laikas mazejimo tvarka su sort funkcija: 0.096618 s
studentai_100000.txt studentų lygio nustatymo laikas: 0.0147351 s
Rezultatai išsaugoti failuose vargsiukai100000.txt ir smartukai100000.txt
Duomenų išvedimas užtruko: 0.258698 sekundžių.
studentai_100000.txt rezultatu isvedimo i faila laikas: 0.258698 s

studentai_100000.txt visas proceso laikas: 0.808105 s
-------------------------------------------------------------
Failo nuskaitymas ir apdorojimas uztruko: 2.99078 sekundziu.
studentai_1000000.txt nuskaitymo ir apdorojimo laikas: 2.99078 s
studentai_1000000.txt rikiavimo laikas mazejimo tvarka su sort funkcija: 1.24055 s
studentai_1000000.txt studentų lygio nustatymo laikas: 0.232082 s
Rezultatai išsaugoti failuose vargsiukai1000000.txt ir smartukai1000000.txt
Duomenų išvedimas užtruko: 2.34633 sekundžių.
studentai_1000000.txt rezultatu isvedimo i faila laikas: 2.34633 s

studentai_1000000.txt visas proceso laikas: 6.80974 s
-------------------------------------------------------------
Failo nuskaitymas ir apdorojimas uztruko: 30.5202 sekundziu.
studentai_10000000.txt nuskaitymo ir apdorojimo laikas: 30.5202 s
studentai_10000000.txt rikiavimo laikas mazejimo tvarka su sort funkcija: 16.125 s
studentai_10000000.txt studentų lygio nustatymo laikas: 1.9111 s
Rezultatai išsaugoti failuose vargsiukai10000000.txt ir smartukai10000000.txt
Duomenų išvedimas užtruko: 29.6563 sekundžių.
studentai_10000000.txt rezultatu isvedimo i faila laikas: 29.6563 s
 
studentai_10000000.txt visas proceso laikas: 78.2126 s

