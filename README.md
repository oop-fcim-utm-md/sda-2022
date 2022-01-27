# sda-2022
примеры с занятий-семинаров и лабораторных работ для первого курса

## Как работать с git
используя этот репозиторий как пример:
1. Скопируйте код на свой компьютер с помощью команды*<br><br>
**git clone https://github.com/oop-fcim-utm-md/sda-2022.git**<br><br>
*ссылка на репозиторий берется во вкладке* **<> Code** *на странице репозитория в github*<br>
*это автоматически инициализирует git с веткой* main *в папке с локальной версией репозитория*<br>
*требует авторизации
2. После того, как внесете значительные изменения в код, cохраните их с помощью команды<br><br>
**git commit -am "commit message"**<br><br>
*где* -am - *это дополнительные параметры, обозначающие выполнение команд add и message*<br>
*в кавычках следует писать сообщение о сути изменений в новой версии репозитория, которую вы создаете таким образом*
3. Для синхронизации файлов на github с локальными используйте команду*<br><br>
**git push origin/main main**<br><br>
*где* origin/main - *это указатель на удаленную ветку (точка назначения), а* main - *на локальную (источник)*<br>
*требует авторизации
