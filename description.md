Problema: būtų įdomu padaryti bugnų mašiną, kur servo fiziškai daužytų kokią membraną. 

Dizainas: Servo prijungti prie arduino uno. Pagrindiniame loop yra if sąlygos ir kodo gale suskaičiuotas laukimo tarpas užtikrinima, kad vienas taktas visada būtų ~15ms.
Potenciometras keičia laukimo tarpą.

Dalys:
## Components

| Name                   | Quantity | Component              |
| ---------------------- | -------- | ---------------------- |
| U1                     | 1        | Arduino Uno R3         |
| SERVO1, SERVO2, SERVO3 | 3        | Positional Micro Servo |
| —                      | 1        | Breadboard Small       |
| D1, D2, D3             | 3        | Red LED                |
| R1, R2, R3             | 3        | 1 kΩ Resistor          |
| PIEZO2                 | 1        | Piezo                  |
| Rpot1                  | 1        | 250 kΩ Potentiometer   |
|                        |          |                        |

Schema:
![[Scheme.png]]
Kas veikia/neveikia.
Veikia trys servo, kurie gali judeti skirtingais ritmais. Neveikia, tikslus laiko valdymas ir, kai per maži laiko tarpai pradeda daryti nepilnius judesius.


Pagerinimas. Reiktų turėti fizinius servo, pasitikrinti kokiu greičiu juda, kiek jėgos sukuria, kad galimų butų pavyzdžiui nuspręsti startpos ir hitpost tiksliau. 
Galima padarytį daugiau funkcijų, kad pavyzdžiui atkartotų vartotojo ritmą arba sukurtu ritmą pagal garsą esantį microfone. Priklausomai nuo servo, reiktų prijungti baterijas.
