# Scrabble
Project #8
Проект-8:Игра Scrabble:
При стартиране на програмата на екрана се изписва меню, от което играчът трябва да избере опция. 
Ако посочи, която не е посочена в менюто се изизксва ново въвеждане.
При избор на първата опция Start new game започва играта, която по подразбиране ще се състои от 10 рунда като на всеки рунд на играча се предоставят 10 букви по подразбиране. 
Той трябва да въведе дума, използвайко посочени букви. 
В зависимост от това каква дума е въвел получава съответния брой точки за този рунд. 
От играча се изисква въвеждане на дума, докато не въведе такава, която да отговаря на условията- да съдържа само малки латински букви, да съдържа само посочените букви, да бъде с дължина не по-голяма от тази на думата от речника. 
При избор на опция номер две Settings играчът трябва да избере някоя от посечените подопции. 
При избор на подопция a-играчът може да промени броя на рундовете, с които ще играе като се изисква от него да въведе новия брой рундове. 
По принцип в речника с дума има общо 50 думи, т.е. ще се играе до 50 рунда, но ако играча иска да промени този брой на повече от 50 от него се изисква да въведе нови думи в речника- например ако избере 52 рунда, то трябва да въведе още 2 думи и т.н. 
Позволява се на играча да въведе по подразбиране до 60 рунда и тогава ще трябва да въведе 10 думи още в речника, но ако избере подопция c- тя дава възможност на играча да промени този брой на число по-голямо от 60. 
Но тази опция се избира само ако играча иска играта да е с повече от 60 рунда. 
При избор на подопция b- играчът може да промени броя на буквите, които да получи от речника като по подразбиране те са 10 и може да се играя максимум с 25 букви.
Тоест той може да въведе брой на буквите не по-голям от 25. 
Ако играчът е променил настройките на играта по един от посочените начини, то при избор на опция 1- да започне нова игра, то тя започва с данните въведенети при избор на опция 2. Така всеки път когато играчът иска да направи някакви промени по играта трябва да избира опция номер 2. 
При избор на опция номер 3 Enter new word се дава право на играча да въведе нова дума в речника.
Като обаче се проверява дали не е достигнат максималния брой допустими рундове(максимален брой думи-по подразбиране 60). 
Това може да се случи тъй като при подопция a на опция 2 от менюто,ако броят на рундовете е повече от 50 се изисква въвеждане на нови думи в речника.
Ако вече е достигнат максималният брой думи не се позволява ново въвеждане освен ако не се регулира броя на рундовете.
Освен това при избор на опция 3 и подопция b от опция 2 играчът трябва да въведе точно 25 букви в речника нито повече, нито по-малко тъй като всички думи в речника са с такава дължина.
При избор на опция номер 4 Exit играта приключва.
