# Умова задачы

Напісаць праграмы для кансольнага працэсу Admіnіstrator і кансольных працэсаў Reader і Wrіter.
Для мадэляваньня перадачы паведамленьняў ўвесьці спэцыяльныя падзеі, якія абазначаюць паведамленьне «А», «B», «C»,» D ” і канец сэансу
для працэсаў Reader Wrіter. Для паведамленьняў «C» і «D» выкарыстоўваць падзеі c ручным скідам.

Адначасова прымаць і адпраўляць паведамленьні могуць толькі два актыўных працэсу Wrіter (выкарыстоўваць
мьютекс) і два актыўных працэсу Reader (выкарыстоўваць семафор), перадача астатніх паведамленьняў ад іншых
працэсаў павінна часова блякавацца (знаходзіцца ў рэжыме чаканьня).

Працэс Admіnіstrator:
1. Ініцыялізацыя аб’ектаў сынхранізацыі;
2. запытвае ў карыстальніка колькасьць працэсаў Wrіter (Reader);
3. запытвае ў карыстальніка коль-ць адпраўленых паведамленьняў для працэсаў Wrіter і кол-ва атрыманых паведамленьняў Reader (агульная колькасьць
4. адпраўленых і прынятых паведамленьняў павінна супадаць);
5. запускае зададзенае колькасьць працэсаў Reader Wrіter;
6. прымае ад кожнага працэсу Wrіter паведамленьні й выводзіць на кансоль, затым адпраўляе іх працэсам Reader.
7. прымае ад кожнага працэсу Reader і Wrіter паведамленьне аб завяршэньні сэансу й выводзіць яго на кансоль
у адной радку.
7. завяршае сваю працу.

Працэс Wrіter:
1. сынхранізаваць працу працэсаў Wrіter з дапамогай мьютексов
2. перадачу паведамленьняў рэалізаваць з дапамогай падзеяў 
3. запытвае з кансолі паведамленьні, якое складаецца з” A ”або” B”, і перадае іх (па адным) працэсу Admіnіstrator;
4. перадае паведамленьне аб завяршэньні сэансу працэсу Admіnіstrator;
5. завяршае сваю працу.

Працэс Reader:
1. сынхранізаваць працу працэсаў Reader з дапамогай семафора
2. перадачу паведамленьняў рэалізаваць з дапамогай падзеяў 
3. прымае паведамленьні ”C”, ” D ” ад працэсу Admіnіstrator;
4. выводзіць на кансоль паведамленьня;
5. перадае паведамленьне аб завяршэньні сэансу працэсу Admіnіstrator;
6. завяршае сваю працу
