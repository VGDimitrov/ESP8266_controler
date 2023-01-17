# ESP8266_controler
 software to PCB input/output controler
 
 The controller is designed to run and read
information from peripheral sensors, and based on the collected information to trigger four
controlled outputs. The algorithms embedded in the controller software are presented in point 2.
The controller allows access to information and control of modes via the Internet (WIFI
connectivity).
The bathroom controller monitors the humidity and temperature in the wet room. On the basis of
information collected and settings set. In AUTOMATIC mode, the controller strives to
keeps humidity within defined limits. For more precise tuning, as well as to avoid
false testimony. The system offers outdoor humidity and temperature monitoring
room
There is also an entrance for monitoring presence in the room. Suitable for a wet room
combined with toilet. Monitors for presence and after a set delay starts the ventilation.
Displays free/busy status on the display
There is also an input for a motion sensor - suitable for controlling the lighting in the
the room.
Monitors boiler temperature and based on the set settings - minimum, maximum
temperature includes heating the water. Two trigger times are possible.
There is also an outlet for hooking up heating for the room - It can work in two
the mode with a set minimum, maximum temperature or with a set holding temperature.
Monitors boiler temperature and based on the set settings - minimum, maximum
temperature includes heating the water. Two trigger times are possible.
There is also an outlet for hooking up heating for the room - It can work in two
the mode with a set minimum, maximum temperature or with a set holding temperature.

See the controller manual for more information


 Контролера е проектиран да отработва и чете информация от периферни датчици,
 и на базата на събраната информация да задейства четири
управляеми изхода. Алгоритмите заложени в софтуера на контролера са представени в точка 2.
Контролера позволява достъп до информация и контрол на режимите през интернет (WIFI
свързаност).
Контролера за баня следи влажността и температурата в мокрото помещение. На базата на
събраната информация и зададените настройки. В АВТОМАТИЧЕН режим, контролера се стреми да
подържа влажността в определение граници. За по прецизно настройване, както и за избягване на
фалшиви показания. Системата предлага следене на влажността и температура във външно
помещение (работа в режим сравнение – препоръчва се. Влажността варира в зависимост от сезона
и най вече в отоплителният сезон).
Предвиден е и вход за следене за присъствие в помещението. Подходящо за мокри помещение
комбинирани с тоалетна. Следи за присъствие и след зададено закъснение пуска вентилацията.
Визуализира на дисплея статус „Свободно“/“Заето“
Предвиден е и вход за датчик за движение – подходящ за контролиране на осветлението в
помещението.
Следи температура на Бойлер и на базата на зададените настройки – минимална, максимална
температура, включва подгряването на водата. Възможни са два времеви интервала на задействане.
Предвиден е и изход за закачане на отопление за помещението – Той може да работи в два
режима с зададена минимална, максимална температура или с зададена температура за подържане.
1.1. Изходи, използване на изходите. Панела разполага с 4 изхода. Изходите са индицират на панела
посредством светлинна индикация както и върху буквено-цифров дисплей 20/4 символа (изходи
тип ОС). Използват се допълнителни релейни модули за управление с управляващ сигнал 5V DC
(фиг 10).
- OMRON SSR G3MB-202P Solid State Relay
- 24V-380V SSR-40DA 40A 3-32V DC-AC Solid State Relay Module
- Channel 5V Relay Shield Module
- и други
1.2. Периферни датчици подържани от контролета:
- NTC Thermistor Accuracy Temperature Sensor 10K (аналогово прочитане на информацията)
- Si7021 Industrial High Precision Humidity Sensor I2C
Упътване
Контролер за Баня
Home system controler 3.19
гр. Плевен
жк. Дружба 335 вх. В ап. 12.
тел:0878 675 652
vgdimitrov@gmail.com
- BME280 Atmospheric Pressure Sensor Sensor GY-BMP280-3.3
- DS18B20 Temperature Sensor Probe WaterProof Plugable
- HTU21D Temperature and Humidity Sensor Module Temperature Sensor
- IR Датчик за присъствие (отчита ниско/високо ниво)
- Датчик за движение PIR (отчита ниско/високо ниво)
2. Управление на Контролера. Бутони за управление, IR дистанционно за управление и управление от
компютър.
2.1. Бутони за управление: Лицевият панел разполага с 5 бутона всеки от които има два режима на
сработване, кратко натискане и натискане със задържане.
- Бутон 1 (в меню – ESC „Изход“) – при кратно натискане
вкл/изкл изход 1 (DC-AC Solid State Relay Module за
управление на Бойлер). Светва червен индикатор на
бутона. При задържане на бутона (за 2+ сек) Включва
автоматичен режим на работа. Системата събира информация за температурата на Бойлера и
на базата на зададените настройки в меню „Управление на Бойлер“ - Режим 1, Режим 2
(избираеми 2 времеви режима за задействане на бойлера), както и зададените минимална
температура за вкл. И максимална температура (за изкл))
- Бутон 2 (в меню позиция надолу(-1)) - при кратно
натискане вкл/изкл изход 2 (OMRON SSR G3MB-202P Solid
State Relay). Светва зелен индикатор на бутона. Дълго
задържане на бутона (за 2+ сек) Включва автоматичен
режим на работа. Системата събира информация за температурата, влажността в банята и на
базата на зададените настройки в меню „Константи Вентилация“ – В този режим контролера
събира информация от 2 датчика за влажност и температура (един в влажното помещение и
един извън него) В настройките на режима се задава минимално и максимално изменение
на влажността. Целта е работа на системата независимо от сезона (влажността е различна).
Друг датчик (допълнителна екстра) е датчик за присъствие (PIR) – контролера следи статуса и
в зависимост от зададеното “Т Присъствие: 1“ – задейства вентилацията при наличие на
присъствие над 1 сек
- Бутон3 (в меню позиция нагоре(+1)) – При кратко натискане включва/изключва отопление в
помещението. При задържане на бутона (за 2+ сек) преминава в автоматичен режим и
подържа температурата в зададен диапазон или конкретна стойност.
- Бутон 4 (в меню – „ИЗБОР“/“ОК“, следваща позиция) – При единично натискане
включва/изключва осветлението. При задържане на бутона (за 2+ сек) преминава в
автоматичен режим. Включва осветлението при наличие на движение.
- Бутон 5 (Menu/ОК+Запис) – Извиква меню за настройки на системата. При задържане на
бутона (за 2+ сек) влиза в калибриране на бутоните. Бутона се използва за потвърждение на
вече направени настройки (ОК + запис на променливите)
2.2. Управление на контролера посредством IR дистанционно управление. Изисква се обучение на
дистанционното управление
2.3. Управление посредством достъп до браузер – Контролера притежава и опция за управление от
браузер. Функциите му са представени в табличен вид.
