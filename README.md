# ApplyingFor1C
## Задача:
Код задачи: 132

На вход программе подаётся изображение некоторого графа.

Необходимо вывести количество пересечений его рёбер. Обратите внимание -- рёбра, встречающиеся в одной вершине, не дают пересечения.

Формат изображения -- png. Рёбра изображены прямыми чёрными отрезками толщиной не менее 3 пикселей. Вершины не помечены, однако гарантируется, что никакие два ребра, выходящие из одной вершины, не лежат на одной прямой. (Если отрезок кончается в точке -- там гарантированно есть вершина).

Для реализации решения можно использовать любую библиотеку для считывания изображений в двумерный массив, но запрещается использовать более расширенные возможности.

Дополнительно можете передавать в программу количество вершин в графе.

## Идея решения:
Воспользуемся методом сканирующей прямой для опредедения рёбер графа. Идём по колонкам слева направо. Цель -- корректно определить точки пересечения рёбер.

Рассмотрим колонку пикселей. Подряд идущие чёрные пиксели будем рассматривать как одну точку -- находить для них середину. Строим в этой точке окружность радиуса EPSILON (4 - 5 пикс.). Если x -- точка пересечения рёбер, то наша окружность пересекается прямыми в чётном количестве точек (хотя бы 4), при этом эти точки должны быть диаметрально противоположными. В противном случае мы находим узел.

## P. S.
За отведённое время реализована основная структура проекта, но из-за нехватки времени не были написаны тесты.

## Запуск проекта:
mkdir build

cd build

cmake ..

make

./a.out "full path to file"

## Запуск обработки картинки:
cd PictureProcessing

python3 ReadPNG.py

name
