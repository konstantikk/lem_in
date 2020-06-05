# lem_in
## О проекте:
 проект ориентирован на изучение основных алгоритмов на графах,
необходимо провести муравьев через ферму,
представленную в виде неориентированного графа,
кратчайшими путями и доставить всех в целости и сохранности домой


## Основные ограничения:
- в одной ноде может находится только один муравей (*кроме стартовой и финишной ноды*)
- за один ход можно передвигать неограниченное количество муравьев

## Тестовый скрипт 
[тыкай сюда, чтобы открыть тесты](https://github.com/konstantikk/lem_in/blob/master/lem_in_tests.py)
Чтобы запустить тесты необхoдим бинарник ***lem-in*** и гениратор карт ***generator.dms***

> так же не помешает наличие python3

скачать тесты

> curl  https://raw.githubusercontent.com/konstantikk/lem_in/master/lem_in_tests.py > lem_in_tests.py

как запустить?

> python3 lem_in_tests.py [флаг] [количество тестов]

возможные флаги
- --flow-one
- --flow-ten
- --flow-thousand
- --big
- --big-superposition

